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
            void GetOrder(); // Get pizza order
            void ParseOrder(); // Parse pizza order
            void PrintOrder(); // Print pizza order

        private:
            std::string _current_order;
    };
}

#endif /* !RECEPTION_HPP_ */
