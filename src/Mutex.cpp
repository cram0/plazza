/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Mutex
*/

#include "Mutex.hpp"

namespace ARC
{
    Mutex::Mutex()
    {

    }

    Mutex::~Mutex()
    {

    }

    std::mutex *Mutex::get()
    {
        return (&_mtx);
    }

    void Mutex::lock()
    {
        _mtx.lock();
    }

    void Mutex::unlock()
    {
        _mtx.unlock();
    }

    void Mutex::tryLock()
    {
        _mtx.try_lock();
    }


} // namespace ARC