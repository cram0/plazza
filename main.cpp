/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** main
*/

#include "Plazza.hpp"
#include "Reception.hpp"
#include "PzArgparser.hpp"
#include "PzSignal.hpp"

int main(int argc, char **argv)
{
    try {
        ARC::PzArgparser parser(argc, argv);
        ARC::Reception recep(std::atof(argv[1]), std::atoi(argv[2]), std::atoi(argv[3]));
        recep.Start();
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(84);
    }


    return (0);
}