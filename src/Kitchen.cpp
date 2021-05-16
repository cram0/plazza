/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

namespace ARC
{
    Kitchen::Kitchen(int id, int nb_cook, float multiplier) : _id(id), _nb_cook(nb_cook), _cook_multiplier(multiplier), _cooks_pool(nb_cook)
    {
        _pid = fork();
        signal(SIGPIPE, SIG_IGN);
        if (this->getPid() == 0) {
            _ipc.MkFifo(_id);
            InitBufferList(nb_cook);
            PopulateCooks(nb_cook);
            if (_pid < 0)
                std::cerr << "Error: fork failed\n" << std::endl;
            update();
        }
    }

    Kitchen::~Kitchen()
    {
        _ipc.RmFifo(_id);
        kill(_pid, SIGKILL);
    }

    int Kitchen::getPid() const
    {
        return (_pid);
    }

    int Kitchen::getId() const
    {
        return (_id);
    }

    void Kitchen::setId(int id)
    {
        _id = id;
    }

    void Kitchen::CheckForAvailableCooks()
    {
        if (_cooks_pool.GetAvailableCooksCount() >= 1) {
            for (auto &pb : _pizza_buffer) {
                if (pb.first != -1) {
                    ARC::Cook &cook = GetAvailableCook();
                    _cooks_pool.AddCooks(cook, pb.first, pb.second);
                    pb.first = -1;
                    pb.second = -1;
                    return;
                }
            }
        }
        if (_cooks_pool.GetAvailableCooksCount() == _nb_cook) {
            if (_clock.GetElapsedTime() >= 5.0) {
                _should_close = true;
            }
        }
        else {
            _clock.Restart();
        }
    }

    void Kitchen::update()
    {
        while (42) {
            if (_should_close) {
                usleep(1000);
                _ipc.WriteFifo("REMOVE " + std::to_string(_id));
            }
            else {
                UpdatePizzaBuffer();
                usleep(1000);
                CheckForAvailableCooks();
                usleep(1000);
                int buffer_slot_count = GetBufferEmptySlotCount();
                usleep(1000);
                _ipc.WriteFifo("INFO " + std::to_string(_id) + " " + std::to_string(buffer_slot_count));
            }
        }
    }

    void Kitchen::UpdatePizzaBuffer()
    {
        std::string message = _ipc.ReadFifo(_id);
        std::vector<std::string> message_tab = ARC::split(message, "\n");
        HandleMessage(message_tab);
    }

    void Kitchen::ReadCookMessage(const std::string &message)
    {
        std::vector<std::string> message_tab = ARC::split(message, " ");
        for (auto &pb : _pizza_buffer) {
            if (pb.first == -1) {
                std::cout << "Adding pizza to Kitchen ID " << std::to_string(_id) << " of type [" << ARC::Plazza::GetPizzaTypeStr(std::atoi(message_tab[1].c_str())) << "]" << " and size [" << ARC::Plazza::GetPizzaSizeStr(std::atoi(message_tab[2].c_str())) << "]" << std::endl;
                pb.first = std::atoi(message_tab[1].c_str());
                pb.second = std::atoi(message_tab[2].c_str());
                break;
            }
        }
    }

    bool Kitchen::IsCookMessage(const std::string &message)
    {
        if ((message.length() >= 4) && (strncmp(message.c_str(), "COOK", 4) == 0)) { return (true); }
        return (false);
    }

    bool Kitchen::IsInformationMessage(const std::string &message)
    {
        if ((message.length() >= 4) && (strncmp(message.c_str(), "INFO", 4) == 0)) { return (true); }
        return (false);
    }

    void Kitchen::ParseMessage(const std::string &message)
    {
        if (IsInformationMessage(message)) { return; }
        if (IsCookMessage(message)) { ReadCookMessage(message);}
    }

    void Kitchen::HandleMessage(const std::vector<std::string> &tab)
    {
        for (const auto &t : tab) {
            ParseMessage(t);
        }
    }

    void Kitchen::PopulateCooks(int count)
    {
        for (int i = 0; i < count; i++) {
            _cooks.emplace_back(Cook(_cook_multiplier));
        }
    }

    void Kitchen::InitBufferList(int count)
    {
        for (int i = 0; i < count; i++) {
            _pizza_buffer.emplace_back(-1, -1);
        }
    }

    int Kitchen::GetBufferEmptySlotCount()
    {
        int count = 0;
        for (const auto &pb : _pizza_buffer) {
            if (pb.first == -1) { count++; }
        }
        return (count);
    }

    ARC::Cook &Kitchen::GetAvailableCook()
    {
        for (auto &c : _cooks) {
            if (c.isAvailable()) { return (c); }
        }
        return (_cooks[0]);
    }

} // namespace ARC