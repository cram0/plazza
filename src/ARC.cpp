/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** ARC
*/

#include "ARC.hpp"

namespace ARC
{
    void to_upper(std::string &string) {
        std::for_each(string.begin(), string.end(), [](char &c) {
            c = std::toupper(c);
        });
    }

    void to_lower(std::string &string) {
        std::for_each(string.begin(), string.end(), [](char &c) {
            c = std::tolower(c);
        });
    }

} // namespace ARC