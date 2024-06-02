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
        // TODO : Uncomment when the functions are reimplemented because for now
        // we have an illegal instruction error
        // CheckCookingTime(argv[1]);
        // CheckCPK(argv[2]);
        // CheckIngredientRegen(argv[3]);
    }

    PzArgparser::~PzArgparser()
    {

    }

    void PzArgparser::PrintUsage()
    {
        std::cout << "Plazza\n\n";
        std::cout << "USAGE :\n";
        std::cout << "\t./plazza cooking_time_multiplier number_of_cooks_per_kitchen ingredient_cooldown\n";
        std::cout << "\nEXPLANATION :\n";
        std::cout << "\tcooking_time_multiplier : Time multiplier for the pizzas cooking time (time between 0 and 1 is allowed)\n";
        std::cout << "\tnumber_of_cooks_per_kitchen : Amount of cooks per kitchen\n";
        std::cout << "\tingredient_cooldown : Cooldown in ms (milliseconds) for an ingredient to be generated in the ingredient box\n";
        std::cout << "\nEXAMPLE :\n";
        std::cout << "\t./plazza 2 5 2000" << std::endl;
    }

    void PzArgparser::CheckArgCount(int count)
    {
        if (count != 4 && count != 2)
            throw PzError(std::cerr, "./plazza : Wrong amount of argument, use -h for more info.");
        if (count == 2) {
            PrintUsage();
            std::exit(0);
        }
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
