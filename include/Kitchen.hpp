/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <vector>
#include <thread>
#include <mutex>

#include "Pizza.hpp"
#include "Cook.hpp"

namespace ARC
{
    class Kitchen {
        public:
            Kitchen();
            ~Kitchen();

            void restock(); // Restock based on timer member
            bool canCookMore(); /// Check if atleast one cook is available
            void receivePizza(ARC::PizzaType); // Take order, read it, populate _pizzasOrdered

        private:
            std::vector<ARC::PizzaType> _pizzasOrdered;
            std::vector<std::pair<Cook, std::thread>> _cooks;
            std::mutex _mtx;
            int _restockTimer;
    };
}

#endif /* !KITCHEN_HPP_ */