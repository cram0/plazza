/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <mutex>

namespace ARC
{
    class Mutex
    {
        public:
            Mutex();
            ~Mutex();

            std::mutex *get();
            void lock();
            void unlock();
            void tryLock();

        private:
            std::mutex _mtx;
    };
}

#endif /* !MUTEX_HPP_ */
