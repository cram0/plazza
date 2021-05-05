/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

namespace ARC
{
    Kitchen::Kitchen()
    {
    }

    Kitchen::~Kitchen()
    {
    }

    void Kitchen::restock()
    {

    }

    void Kitchen::receivePizza(ARC::PizzaType)
    {
        for (const auto &cook : _cooks) {
            if (cook.first.isAvailable()) {
                // Affect pizza to the thread
                // Handle timer
                return; // Quit when 1 pizza is affected, go to the next kitchen
            }
        }
    }
}