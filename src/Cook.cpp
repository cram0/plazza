/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Cook
*/

#include "Cook.hpp"

namespace ARC
{
    Cook::Cook(int cookMultiplier) : _available(true), _cookMultiplier(cookMultiplier)
    {

    }

    Cook::~Cook()
    {

    }

    bool Cook::isAvailable() const
    {
        return (_available);
    }

    void Cook::setAvailability(bool state)
    {
        _available = state;
    }

    void Cook::cookPizza(int type, int size)
    {
        if (type == -1 || size == -1) { return; }
        setAvailability(false);
        // auto start_time = std::chrono::high_resolution_clock::now();
        // auto end_time = start_time + std::chrono::milliseconds(((int)type + ((int)size)) * 1000);

        // do {
        //     std::this_thread::yield();
        // } while (std::chrono::high_resolution_clock::now() < end_time);
        std::this_thread::sleep_for(std::chrono::seconds(20));
        setAvailability(true);
    }

} // namespace ARC