/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** PzCleaner
*/

#include "PzCleaner.hpp"

namespace ARC
{
    PzCleaner::PzCleaner()
    {
        CleanResources();
    }

    PzCleaner::~PzCleaner()
    {

    }

    void PzCleaner::CleanResources()
    {
        std::remove("res/reception");
    }

} // namespace ARC
