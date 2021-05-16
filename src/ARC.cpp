/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** ARC
*/

#include "ARC.hpp"

namespace ARC
{
    void to_upper(std::string &string) {
        std::for_each(string.begin(), string.end(), [](char &c) {
            c = std::toupper(c);
        });
    }

    void to_lower(std::string &string) {
        std::for_each(string.begin(), string.end(), [](char &c) {
            c = std::tolower(c);
        });
    }

    std::vector<std::string> split(std::string str, std::string token) {
        std::vector<std::string> result;

        while (str.size()) {
            size_t index = str.find(token);
            if (index != std::string::npos) {
                result.push_back(str.substr(0, index));
                str = str.substr(index+token.size());
                if (str.size() == 0) result.push_back(str);
            }
            else {
                result.push_back(str);
                str = "";
            }
        }
        return result;
    }

    bool is_digit(const std::string &string) {
        std::for_each(string.begin(), string.end(), [](const char &c) {
            if (!isdigit(c)) { return (false); }
        });
        return (true);
    }

    namespace Plazza
    {
        std::string GetPizzaTypeStr(int type)
        {
            switch (type) {
                case 1:
                    return ("Regina");
                case 2:
                    return ("Margarita");
                case 4:
                    return ("Americana");
                case 8:
                    return ("Fantasia");
                default:
                    return ("UNKNOWN PIZZA");
            }
        }

        std::string GetPizzaSizeStr(int size)
        {
            switch (size) {
                case 1:
                    return ("S");
                case 2:
                    return ("M");
                case 4:
                    return ("L");
                case 8:
                    return ("XL");
                case 16:
                    return ("XXL");
                default:
                    return ("UNKNOWN SIZE");
            }
        }
    } // namespace Plazza



} // namespace ARC