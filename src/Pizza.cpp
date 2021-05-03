/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Pizza
*/

#include "Pizza.hpp"


namespace ARC
{
    Pizza::Pizza(ARC::PizzaType type, ARC::PizzaSize size) : _type(type), _size(size)
    {

    }

    Pizza::~Pizza()
    {

    }

    ARC::PizzaType Pizza::GetType() const
    {
        return (_type);
    }

    void Pizza::setType(ARC::PizzaType type)
    {
        _type = type;
    }

    ARC::PizzaSize Pizza::GetSize() const
    {
        return (_size);
    }

    void Pizza::setSize(ARC::PizzaSize size)
    {
        _size = size;
    }
}