/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Cook
*/

#include "Cook.hpp"

namespace ARC
{
    Cook::Cook(int _cookMultiplier) : _available(true)
    {

    }

    // DN
    Cook::~Cook()
    {

    }

    // MB
    bool Cook::isAvailable() const
    {
        return (_available);
    }

    void Cook::setAvailability(bool state)
    {
        _available = state;
    }

    // DN
    void Cook::cookPizza(ARC::PizzaType type, ARC::PizzaSize size)
    {
        _available = false;
        auto start_time = std::chrono::high_resolution_clock::now();
        auto end_time = start_time + std::chrono::milliseconds((int)type + ((int)size));

        do {
            std::this_thread::yield();
        } while (std::chrono::high_resolution_clock::now() < end_time);
        _available = true;
    }

} // namespace ARC