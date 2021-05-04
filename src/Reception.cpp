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
        InitPizzaTypesList();
        _order_id = InitOrderId();
    }

    Reception::~Reception()
    {

    }

    void Reception::Start()
    {
        while (42) {
            std::cout << ">> ";
            std::string order = GetOrder();
            if (IsValidOrder(order) && ParseFullOrder(order)) {
                std::cout << "Your order is valid, sending it to our kitchens ..." << std::endl;
                ARC::Order order();
            }
            else {
                std::cout << "Your order is not valid, check the menu and come back later you pussy" << std::endl;
            }
        }
    }

    std::string Reception::GetOrder()
    {
        std::string order;
        std::getline(std::cin, order);

        return (order);
    }

    bool Reception::IsValidPizzaType(const std::string &type)
    {
        std::string tmp_type = type;
        ARC::to_lower(tmp_type);

        for (const auto &p : _pizzaTypes) {
            std::string tmp_list_type = p.second;
            ARC::to_lower(tmp_list_type);
            if (tmp_type.compare(tmp_list_type) == 0) { return (true); }
        }
        return (false);
    }

    bool Reception::ParseIndividualOrder(const std::string &order)
    {
        std::string tmp = order;
        std::string delim = " ";
        std::string token;
        size_t pos = 0;

        if ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            return (IsValidPizzaType(token));
        }
        return (false);
    }

    bool Reception::ParseFullOrder(const std::string &order)
    {
        std::string tmp = order;
        std::string delim = ";";
        std::string token;
        size_t pos = 0;

        // If there is only one chunk in the order (Fantasia XL x1)
        if (tmp.find(";") == std::string::npos) {
            return (ParseIndividualOrder(tmp));
        }

        // If there are multiple chunks in the order (Regina XL x1; Margarita S x5; Regina M x9)
        while ((pos = tmp.find(delim)) != std::string::npos) {
            token = tmp.substr(0, pos);
            if (!ParseIndividualOrder(token)) { return (false); }
            tmp.erase(0, pos + delim.length() + 1);
        }
        return (ParseIndividualOrder(tmp));
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

    void Reception::InitPizzaTypesList()
    {
        _pizzaTypes.emplace(std::make_pair(Regina, "Regina"));
        _pizzaTypes.emplace(std::make_pair(Margarita, "Margarita"));
        _pizzaTypes.emplace(std::make_pair(Americana, "Americana"));
        _pizzaTypes.emplace(std::make_pair(Fantasia, "Fantasia"));
    }

    int Reception::InitOrderId()
    {
        std::ifstream file_in("res/order_id");
        if (file_in.is_open()) {
            std::string line;
            getline(file_in, line);
            file_in.close();
            return (std::atoi(line.c_str()));
        }
        else {
            std::ofstream file_out("res/order_id");
            if (file_out.is_open()) {
                file_out << "0" << std::endl;
                file_out.close();
            }
        }
        return (0);
    }

    void Reception::SetOrderId()
    {
        
    }
}