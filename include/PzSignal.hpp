/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** PzSignal
*/

#ifndef PZSIGNAL_HPP_
#define PZSIGNAL_HPP_

#include <csignal>
#include <iostream>

namespace ARC
{
    class PzSignal
    {
        public:
            PzSignal();
            ~PzSignal();

            static void GetSigCont(int code);

        private:
    };
}

#endif /* !PZSIGNAL_HPP_ */
