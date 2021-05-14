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
        std::cout << "COOK AVAILABLE ? " << _available << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(type * size));
        setAvailability(true);
        std::cout << "COOK AVAILABLE ? " << _available << std::endl;
    }

} // namespace ARC