/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** ARC
*/

#ifndef ARC_HPP_
#define ARC_HPP_

#include <iostream>
#include <string>
#include <regex>

namespace ARC {

    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };
};

#endif /* !ARC_HPP_ */
