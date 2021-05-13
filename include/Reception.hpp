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
#include "Kitchen.hpp"
#include "IPC.hpp"
#include "Process.hpp"
#include "PzError.hpp"

namespace ARC
{
    class Reception
    {
        public:
            Reception(float cook_time, int cook_per_kitchen, int ingredient_mult);
            ~Reception();

            void Start(); // Main loop

            std::string GetOrder(); // Get the line typed in by the user
            bool IsValidPizzaType(const std::string &type); // Checks if pizza type exists
            bool ParseIndividualOrder(const std::string &order); // Parse one chunk of the order
            bool ParseFullOrder(const std::string &order); // Parse pizza order
            void PrintOrder(const std::string &order); // Print pizza order
            bool IsValidOrder(const std::string &order); // Checks if order is valid with regex
            bool IsExitCommand(const std::string &command); // Checks if the order isnt an order but an exit command instead
            bool IsStatusCommand(const std::string &command); // Checks if the order isnt an order but a status request instead

            void GetKitchenInfo();
            void CloseAllRemainingKitchen();

            ARC::PizzaType GetPizzaType(const std::string &type);
            ARC::PizzaSize GetPizzaSize(const std::string &size);
            size_t GetPizzaCount(const std::string &count);

            ARC::Order GenerateOrder(const std::string &order, int id); // Generate an Order object for the kitchen to handle
            bool IsKitchenReady(int kitchen_id);

            void ManageKitchen();

            void InitPizzaSizesList();
            void InitPizzaTypesList();
            int InitOrderId();
            void SetOrderId(int id);

        private:
            std::unordered_map<PizzaType, std::string> _pizzaTypes;
            std::unordered_map<PizzaSize, std::string> _pizzaSizes;

            std::vector<ARC::Kitchen *> _kitchens;

            std::unordered_map<int, std::string> _kitchens_state;

            ARC::IPC _ipc;
            int _order_id;

            float _cook_time;
            int _cook_per_kitchen;
            int _ingredient_multiplier;
    };
}

#endif /* !RECEPTION_HPP_ */
