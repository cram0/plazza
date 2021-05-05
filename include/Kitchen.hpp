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
#include "Mutex.hpp"

namespace ARC
{
    class Kitchen {
        public:
            Kitchen();
            ~Kitchen();

        private:
            std::vector<ARC::PizzaType> _pizzasOrdered;
            ARC::Mutex _mtx;
            int _restockTimer;
    };
}

#endif /* !KITCHEN_HPP_ */