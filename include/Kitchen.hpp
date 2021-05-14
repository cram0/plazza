/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <signal.h>

#include <map>

#include "Cook.hpp"
#include "IPC.hpp"
#include "ThreadPool.hpp"

namespace ARC
{
    class Kitchen {
        public:
            Kitchen(int id, int nb_cook, int multiplier);
            ~Kitchen();

            int getPid() const ;
            int getId() const ;
            void setId(int id);
            void update();

            void ReadCookMessage(const std::string &message);
            bool IsCookMessage(const std::string &message);
            bool IsInformationMessage(const std::string &message);
            void ParseMessage(const std::string &message);
            void HandleMessage(const std::vector<std::string> &tab);
            void UpdatePizzaBuffer();
            void CheckForAvailableCooks();
            void PopulateCooks(int count);
            void InitBufferList(int count);
            int GetBufferEmptySlotCount();

            ARC::Cook &GetAvailableCook();

            int Test();

        protected:
        private:
            pid_t _pid;
            int _id;
            int _nb_cook;
            int _cook_multiplier;

            // std::vector<ARC::Cook *> _cooks;
            // std::vector<std::pair<ARC::Cook *, std::thread>> _cooks;

            std::vector<ARC::Cook> _cooks;
            ARC::ThreadPool _cooks_pool;
            std::vector<std::pair<int, int>> _pizza_buffer;

            ARC::IPC _ipc;
    };

} // namespace ARC

#endif /* !KITCHEN_HPP_ */
