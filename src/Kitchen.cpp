/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

namespace ARC
{
    Kitchen::Kitchen(int id, int nb_cook, int multiplier) : _id(id), _nb_cook(nb_cook), _cook_multiplier(multiplier)
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

    void Kitchen::CookPizza(ARC::PizzaType type, ARC::PizzaSize size)
    {
        auto start_time = std::chrono::high_resolution_clock::now();
        auto end_time = start_time + std::chrono::milliseconds(((int)type + ((int)size)) * 1000);

        do {
            std::this_thread::yield();
        } while (std::chrono::high_resolution_clock::now() < end_time);
    }

    void Kitchen::CookSomething(int type, int size)
    {
        if (type == -1 || size == -1)
            return;
        else {
            CookPizza((ARC::PizzaType)type, (ARC::PizzaSize)size);
        }
    }

    // TODO FIX ÇA
    void Kitchen::CheckForAvailableCooks()
    {
        for (auto &c : _cooks) {
            if (c.first->isAvailable()) {
                for (auto &pb : _pizza_buffer) {
                    if (pb.first != -1) {
                        c.first->setAvailability(false);
                        c.second = std::thread(&Kitchen::CookSomething, this, pb.first, pb.second);
                        c.second = std::thread(&Kitchen::CookSomething, this, -1, -1);
                        c.second.join();
                        c.first->setAvailability(true);
                        pb.first = -1;
                        pb.second = -1;
                    }
                }
            }
        }
    }

    void Kitchen::update()
    {
        while (42) {
            usleep(500000);
            int buffer_slot_count = GetBufferEmptySlotCount();
            UpdatePizzaBuffer();
            CheckForAvailableCooks();
            _ipc.WriteFifo("INFO " + std::to_string(_id) + " " + std::to_string(buffer_slot_count));
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
                pb.first = std::atoi(message_tab[1].c_str());
                pb.second = std::atoi(message_tab[2].c_str());
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
            _cooks.emplace_back(std::make_pair(new ARC::Cook(_cook_multiplier), std::thread(&Kitchen::CookSomething, this, -1, -1)));
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

} // namespace ARC