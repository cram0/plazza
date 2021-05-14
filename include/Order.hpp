/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Order
*/

#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <vector>

#include "Pizza.hpp"


namespace ARC
{
    class Order
    {
        public:
            Order();
            Order(int id);
            ~Order();

            std::vector<ARC::Pizza> getPizzas() const;
            void addPizza(ARC::Pizza pizza);
            void removePizza();

            int getId() const;
            void setId(int id);
        private:
            std::vector<ARC::Pizza> _pizzas;
            int _id;
    };
}

#endif /* !ORDER_HPP_ */