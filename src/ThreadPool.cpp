/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** ThreadPool
*/

#include "ThreadPool.hpp"

namespace ARC
{
    ThreadPool::ThreadPool(int count) : _t_count_max(count)
    {

    }

    ThreadPool::~ThreadPool()
    {
        for (size_t i = 0; i < _pool.size(); i++) {
            _pool[i].join();
        }
    }

    void ThreadPool::AddCooks(ARC::Cook *cook, int type, int size)
    {
        _pool.push_back(std::thread(&ARC::Cook::cookPizza, cook, type, size));
    }

    int ThreadPool::GetAvailableCooksCount()
    {
        return (_t_count_max - _pool.size());
    }
} // namespace ARC