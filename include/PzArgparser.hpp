/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** PzArgparser
*/

#ifndef PZARGPARSER_HPP_
#define PZARGPARSER_HPP_

#include <string>
#include <iostream>

namespace ARC
{
    class PzArgparser
    {
        public:
            PzArgparser(int argc, char **argv);
            ~PzArgparser();

            void PrintUsage();

            void CheckArgCount(int count);
            void CheckCookingTime(const std::string &time);
            void CheckCPK(const std::string &count);
            void CheckIngredientRegen(const std::string &time);


        protected:
        private:
    };
} // namespace ARC

#endif /* !PZARGPARSER_HPP_ */
