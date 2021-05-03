/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Order
*/

#include "Order.hpp"

namespace ARC {

    Order::Order()
    {

    }

    Order::Order(int id) : _id(id)
    {

    }

    Order::~Order()
    {

    }

    std::vector<ARC::Pizza> Order::getPizzas() const
    {
        return (_pizzas);
    }

    void Order::addPizza(ARC::Pizza pizza)
    {
        _pizzas.emplace_back(pizza);
    }

    void Order::removePizza(std::vector<ARC::Pizza>::const_iterator pizza)
    {
        _pizzas.erase(pizza);
    }

    int Order::getId() const
    {
        return (_id);
    }

    void Order::setId(int id)
    {
        _id = id;
    }
}