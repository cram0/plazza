/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <string>
#include <iostream>
#include <unordered_map>
#include <fstream>

#include "ARC.hpp"
#include "Order.hpp"

namespace ARC
{
    class Reception
    {
        public:
            Reception();
            ~Reception();

            void Start(); // Main loop

            std::string GetOrder(); // Get the line typed in by the user
            bool IsValidPizzaType(const std::string &type); // Checks if pizza type exists
            bool ParseIndividualOrder(const std::string &order); // Parse one chunk of the order
            bool ParseFullOrder(const std::string &order); // Parse pizza order
            void PrintOrder(const std::string &order); // Print pizza order
            bool IsValidOrder(const std::string &order); // Checks if order is valid with regex

            void InitPizzaTypesList();
            int InitOrderId();
            void SetOrderId();

        private:
            std::unordered_map<PizzaType, std::string> _pizzaTypes;
            int _order_id;
    };
}

#endif /* !RECEPTION_HPP_ */
