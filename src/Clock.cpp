/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Clock
*/

#include "Clock.hpp"

namespace ARC
{
    Clock::Clock()
    {
        _clock = clock();
    }

    Clock::~Clock()
    {

    }

    double Clock::GetElapsedTime()
    {
        return ((double)(clock() - _clock) / CLOCKS_PER_SEC);
    }

    void Clock::Restart()
    {
        _clock = clock();
    }
} // namespace ARC