/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** PzSignal
*/

#include "PzSignal.hpp"


namespace ARC
{
    PzSignal::PzSignal()
    {
        std::signal(SIGCONT, &GetSigCont);
    }

    PzSignal::~PzSignal()
    {

    }

    void PzSignal::GetSigCont(int code)
    {
        std::cout << "Received CTRL + C" << std::endl;

    }

} // namespace ARC
