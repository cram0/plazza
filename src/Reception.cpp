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
            std::string order = GetOrder();
            if (IsValidOrder(order)) {
                ParseOrder(order);
            }
        }
    }

    std::string Reception::GetOrder()
    {
        std::string order;
        std::getline(std::cin, order);

        return (order);
    }

    void Reception::ParseOrder(const std::string &order)
    {
        std::string tmp = order;
        std::string delim = ";";
        std::string token;
        size_t pos = 0;
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            std::cout << token << std::endl;
            tmp.erase(0, pos + delim.length() + 1);
        }
        std::cout << tmp << std::endl;
    }

    void Reception::PrintOrder(const std::string &order)
    {
        std::cout << order << std::endl;
    }

    bool Reception::IsValidOrder(const std::string &order)
    {
        std::regex const pattern { R"([a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*(; [a-zA-Z]+ (S|M|L|XL|XXL) x[1-9][0-9]*)*)" };
        return (std::regex_match(order, pattern));
    }
}