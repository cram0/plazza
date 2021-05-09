/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** PzError
*/

#include "PzError.hpp"

namespace ARC
{
    PzError::PzError(std::ostream &stream, std::string const& message) : _stream(stream), _message(message)
    {

    }

    PzError::~PzError() throw()
    {

    }

    char const* PzError::what() const throw()
    {
        return (_message.c_str());
    }

} // namespace ARC
