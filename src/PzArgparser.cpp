/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** PzArgparser
*/

#include "PzArgparser.hpp"
#include "PzError.hpp"
#include "ARC.hpp"

namespace ARC
{
    PzArgparser::PzArgparser(int argc, char **argv)
    {
        CheckArgCount(argc);
        CheckCookingTime(argv[1]);
        CheckCPK(argv[2]);
        CheckIngredientRegen(argv[3]);
    }

    PzArgparser::~PzArgparser()
    {

    }

    void PzArgparser::CheckArgCount(int count)
    {
        if (count != 4)
            throw PzError(std::cerr, "./plazza : Wrong amount of argument, use -h for more info.");
    }

    void PzArgparser::CheckCookingTime(const std::string &time)
    {
        if (!ARC::is_digit(time))
            throw PzError(std::cerr, "./plazza : Wrong cooking time.");

        std::string::size_type size;
        float f_time = 0;

        if ((f_time = std::stof(time, &size)) < 0)
            throw PzError(std::cerr, "./plazza : Cooking time of negative value.");
    }

    void PzArgparser::CheckCPK(const std::string &count)
    {
        if (!ARC::is_digit(count))
            throw PzError(std::cerr, "./plazza : Wrong amount of cook.");

        std::string::size_type size;
        int i_cooks = 0;

        if ((i_cooks = std::stoi(count, &size)) <= 0)
            throw PzError(std::cerr, "./plazza : Cooks amount is negative.");
    }

    void PzArgparser::CheckIngredientRegen(const std::string &time)
    {
        if (!ARC::is_digit(time))
            throw PzError(std::cerr, "./plazza : Wrong ingredient regen cooldown.");

        std::string::size_type size;
        int i_cooks = 0;

        if ((i_cooks = std::stoi(time, &size)) <= 0)
            throw PzError(std::cerr, "./plazza : ingredient regen cooldown is negative.");
    }

} // namespace ARC
