/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** main
*/

#include "Reception.hpp"
#include "PzArgparser.hpp"
#include "PzSignal.hpp"
#include "PzCleaner.hpp"

int main(int argc, char **argv)
{
    try {
        ARC::PzArgparser parser(argc, argv);
        ARC::PzCleaner cleaner;
        ARC::Reception recep(std::atof(argv[1]), std::atoi(argv[2]), std::atoi(argv[3]));
        recep.Start();
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(84);
    }


    return (0);
}