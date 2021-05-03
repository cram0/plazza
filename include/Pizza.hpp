/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include "ARC.hpp"

namespace ARC
{
    class Pizza
    {
        public:
            Pizza(ARC::PizzaType type, ARC::PizzaSize size);
            ~Pizza();

            ARC::PizzaType GetType() const;
            void setType(ARC::PizzaType type);
            ARC::PizzaSize GetSize() const;
            void setSize(ARC::PizzaSize size);

        private:
            ARC::PizzaType _type;
            ARC::PizzaSize _size;
    };
}

#endif /* !PIZZA_HPP_ */
