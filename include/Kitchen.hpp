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

class Kitchen {
    public:
        Kitchen();
        ~Kitchen();

        void restock(); // Restock based on timer member
        void receiveOrder(); // Take order, read it, populate _pizzasOrdered
        void dispatchPizzas(); // Loop on Cooks, dispatch pizzas

    private:
        std::vector<ARC::PizzaType> _pizzasOrdered;
        std::mutex _mtx;
        int _restockTimer;

};

#endif /* !KITCHEN_HPP_ */