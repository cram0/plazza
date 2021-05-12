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
        if (this->getPid() == 0) {
            _ipc.MkFifo(_id);
            PopulateCooks(nb_cook);
            if (_pid < 0)
                std::cerr << "Error: fork failed\n" << std::endl;
        }

        if (this->getPid() == 0) {
            update();
        }
    }

    Kitchen::~Kitchen()
    {
        _ipc.RmFifo(_id);
    }

    int Kitchen::getPid()
    {
        return (_pid);
    }

    int Kitchen::getId()
    {
        return (_id);
    }

    void Kitchen::setId(int id)
    {
        _id = id;
    }

    void Kitchen::update()
    {
        while (42) {
            sleep(1);
            int cooks_available = GetAvailableCooksCount();
            _ipc.WriteFifo("INFO " + std::to_string(_id) + " " + std::to_string(cooks_available));
        }
    }

    void Kitchen::PopulateCooks(int count)
    {
        for (int i = 0; i < count; i++) {
            _cooks.emplace_back(new Cook(_cook_multiplier));
        }
    }

    int Kitchen::GetAvailableCooksCount()
    {
        int count = 0;
        for (const auto &c : _cooks) {
            if (c->isAvailable()) { count++; }
        }
        return (count);
    }

} // namespace ARC