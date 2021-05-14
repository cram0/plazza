/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "ARC.hpp"

#include <chrono>
#include <thread>

namespace ARC
{
    class Cook {
        public:
            Cook(int _cookMultiplier);
            ~Cook();
            void setAvailability(bool state);

            bool isAvailable() const;
            void cookPizza(ARC::PizzaType type, ARC::PizzaSize size);

        private:
            int _cookMultiplier;
            bool _available;
            std::thread _t_cook;
    };
} // namespace ARC

#endif /* !COOK_HPP_ */