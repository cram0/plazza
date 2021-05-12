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

    void Cook::cookPizza(ARC::PizzaType type, ARC::PizzaSize size)
    {
        setAvailability(false);
        auto start_time = std::chrono::high_resolution_clock::now();
        auto end_time = start_time + std::chrono::milliseconds(((int)type + ((int)size)) * 1000);

        do {
            std::this_thread::yield();
        } while (std::chrono::high_resolution_clock::now() < end_time);
        setAvailability(true);
    }

} // namespace ARC