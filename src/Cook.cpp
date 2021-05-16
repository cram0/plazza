/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Cook
*/

#include "Cook.hpp"

namespace ARC
{
    Cook::Cook(float cookMultiplier) : _available(true), _cookMultiplier(cookMultiplier)
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
        std::cout << "Started cooking [" << ARC::Plazza::GetPizzaTypeStr(type) << "] of size [" << ARC::Plazza::GetPizzaSizeStr(size) << "]." << std::endl;
        setAvailability(false);
        // std::cout << "Sleeping for : [" << std::to_string(type * size) << "] seconds" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds((type * size) * (int)_cookMultiplier));
        setAvailability(true);
        std::cout << "Done cooking [" << ARC::Plazza::GetPizzaTypeStr(type) << "] of size [" << ARC::Plazza::GetPizzaSizeStr(size) << "]." << std::endl;
    }

} // namespace ARC