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

#include "ARC.hpp"

namespace ARC
{
    class Reception
    {
        public:
            Reception();
            ~Reception();

            void Start(); // Main loop
            std::string GetOrder(); // Get pizza order
            void ParseOrder(const std::string &order); // Parse pizza order
            void PrintOrder(const std::string &order); // Print pizza order
            bool IsValidOrder(const std::string &order); // Checks if order is valid with regex

        private:
    };
}

#endif /* !RECEPTION_HPP_ */
