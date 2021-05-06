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

namespace ARC
{
    class Reception
    {
        public:
            Reception();
            ~Reception();

            void Start(); // Main loop

            void MkFifoReception();
            std::string GetOrder(); // Get the line typed in by the user
            bool IsValidPizzaType(const std::string &type); // Checks if pizza type exists
            bool ParseIndividualOrder(const std::string &order); // Parse one chunk of the order
            bool ParseFullOrder(const std::string &order); // Parse pizza order
            void PrintOrder(const std::string &order); // Print pizza order
            bool IsValidOrder(const std::string &order); // Checks if order is valid with regex

            ARC::PizzaType GetPizzaType(const std::string &type);
            ARC::PizzaSize GetPizzaSize(const std::string &size);
            size_t GetPizzaCount(const std::string &count);

            ARC::Order GenerateOrder(const std::string &order, int id); // Generate an Order object for the kitchen to handle
            bool IsKitchenReady(int kitchen_id);
            void SendPizza(ARC::PizzaType type, ARC::PizzaSize size); // Sends pizza to a kitchen
            void HandleOrder(ARC::Order &order); // Handle order object


            void ManageKitchen();

            void InitPizzaSizesList();
            void InitPizzaTypesList();
            int InitOrderId();
            void SetOrderId(int id);

        private:
            std::unordered_map<PizzaType, std::string> _pizzaTypes;
            std::unordered_map<PizzaSize, std::string> _pizzaSizes;
            std::vector<int> _kitchens;
            int _order_id;
            ARC::IPC _ipc;
    };
}

#endif /* !RECEPTION_HPP_ */
