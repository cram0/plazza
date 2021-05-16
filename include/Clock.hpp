/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include <ctime>

#include <iostream>

namespace ARC
{
    class Clock {
        public:
            Clock();
            ~Clock();
            double GetElapsedTime();
            void Restart();

        protected:
        private:
            clock_t _clock;

    };
} // namespace ARC

#endif /* !CLOCK_HPP_ */
