/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Reception
*/

#include "Reception.hpp"

namespace ARC
{
    Reception::Reception(float cook_time, int cook_per_kitchen, int ingredient_mult)
    : _cook_time(cook_time), _cook_per_kitchen(cook_per_kitchen), _ingredient_multiplier(ingredient_mult)
    {
        InitPizzaTypesList();
        InitPizzaSizesList();
        _order_id = InitOrderId();
        _ipc.MkFifo();
    }

    Reception::~Reception()
    {
        _ipc.RmFifo();
    }

    void Reception::Start()
    {

        while (42) {
            ARC::Order handle_me;
            std::cout << ">> ";
            std::string order = GetOrder();

            if (IsValidOrder(order) && ParseFullOrder(order)) {
                std::cout << "Your order is valid, sending it to our kitchens ..." << std::endl;
                handle_me = GenerateOrder(order, _order_id);
                _kitchens.push_back(new Kitchen(_order_id, _cook_per_kitchen));
            }
            else if (IsExitCommand(order)) { break; }
            else {
                std::cout << "Your order is not valid, check the menu and come back later you pussy" << std::endl;
            }

            SetOrderId(++_order_id);
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
        if (tmp.find(delim) == std::string::npos) {
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

    bool Reception::IsExitCommand(const std::string &command)
    {
        if (command.compare("exit") == 0) {
            std::cout << "Exiting plazza ..." << std::endl;
            return (true);
        }
        return (false);
    }

    ARC::PizzaType Reception::GetPizzaType(const std::string &type)
    {
        std::string tmp_type = type;
        ARC::to_lower(tmp_type);
        for (const auto &pt : _pizzaTypes) {
            std::string tmp_type_list = pt.second;
            ARC::to_lower(tmp_type_list);
            if (tmp_type_list.compare(tmp_type) == 0) { return (pt.first); }
        }
        return (ARC::Margarita);
    }

    ARC::PizzaSize Reception::GetPizzaSize(const std::string &size)
    {
        std::string tmp_size = size;
        ARC::to_lower(tmp_size);
        for (const auto &ps : _pizzaSizes) {
            std::string tmp_size_list = ps.second;
            ARC::to_lower(tmp_size_list);
            if (tmp_size_list.compare(tmp_size) == 0) { return (ps.first); }
        }
        return (ARC::S);
    }

    size_t Reception::GetPizzaCount(const std::string &count)
    {
        std::string tmp = count.substr(1, count.length());

        return (std::atoi(tmp.c_str()));
    }

    ARC::Order Reception::GenerateOrder(const std::string &order, int id)
    {
        ARC::Order ret(id);

        std::vector<std::string> full_order = ARC::split(order, "; ");
        for (auto p : full_order) {
            std::vector<std::string> order_chunk = ARC::split(p, " ");
            ARC::PizzaType ptype = GetPizzaType(order_chunk[0]);
            ARC::PizzaSize psize = GetPizzaSize(order_chunk[1]);
            size_t pcount        = GetPizzaCount(order_chunk[2]);
            for (size_t i = 0; i < pcount; i++) { ret.addPizza(ARC::Pizza(ptype, psize)); }
        }

        return (ret);
    }

    bool Reception::IsKitchenReady(int kitchen_id)
    {
        _ipc.WriteFifo("is_ready", kitchen_id);
        usleep(100);
        std::string test = _ipc.ReadFifo();

        if (test.compare("ready")) {return true;}
        return false;
    }

    void Reception::InitPizzaSizesList()
    {
        _pizzaSizes.emplace(std::make_pair(S, "S"));
        _pizzaSizes.emplace(std::make_pair(M, "M"));
        _pizzaSizes.emplace(std::make_pair(L, "L"));
        _pizzaSizes.emplace(std::make_pair(XL, "XL"));
        _pizzaSizes.emplace(std::make_pair(XXL, "XXL"));
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

    void Reception::SetOrderId(int id)
    {
        std::ofstream file_out("res/order_id");
        if (file_out.is_open()) {
            file_out << std::to_string(id) << std::endl;
            file_out.close();
        }
    }
}