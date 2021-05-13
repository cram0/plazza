/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <signal.h>

#include "Cook.hpp"
#include "IPC.hpp"

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

            void PopulateCooks(int count);
            int GetAvailableCooksCount();

        protected:
        private:
            pid_t _pid;
            int _id;
            int _nb_cook;
            int _cook_multiplier;

            std::vector<ARC::Cook *> _cooks;
            ARC::IPC _ipc;
    };

} // namespace ARC

#endif /* !KITCHEN_HPP_ */
