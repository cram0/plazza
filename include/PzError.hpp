/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** PzError
*/

#ifndef PZERROR_HPP_
#define PZERROR_HPP_

#include <string>
#include <exception>

namespace ARC
{
    class PzError : public std::exception
    {
        public:
            PzError(std::ostream &stream, std::string const& message);
            ~PzError() throw();

            const char *what() const throw();
        private:
            std::ostream &_stream;
            std::string _message;
    };
} // namespace ARC

#endif /* !PZERROR_HPP_ */
