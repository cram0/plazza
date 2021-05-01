/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Reception
*/

#include "Reception.hpp"

namespace ARC
{
    Reception::Reception()
    {

    }

    Reception::~Reception()
    {

    }

    void Reception::Start()
    {
        while (42) {
            GetOrder();
            IsValidOrder(_current_order);
        }
    }

    void Reception::GetOrder()
    {
        std::getline(std::cin, _current_order);
    }

    void Reception::ParseOrder()
    {

    }

    void Reception::PrintOrder()
    {
        std::cout << _current_order << std::endl;
    }
}