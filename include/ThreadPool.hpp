/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** ThreadPool
*/

#ifndef THREADPOOL_HPP_
#define THREADPOOL_HPP_

#include <vector>
#include <thread>

#include "Cook.hpp"
namespace ARC
{
    class ThreadPool {
        public:
            ThreadPool(int count);
            ~ThreadPool();

            void AddCooks(ARC::Cook &cook, int type = -1, int size = -1);
            int GetAvailableCooksCount();

        private:
            int _t_count_max;

            std::vector<std::thread> _pool;
    };
} // namespace ARC

#endif /* !THREADPOOL_HPP_ */
