/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Process
*/

#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include <sys/types.h>
#include <unistd.h>
#include <iostream>

namespace ARC
{
    class Process {
        public:
            Process();
            ~Process();

            pid_t getPid() const;

        private:
            pid_t _pid;
    };
}

#endif /* !PROCESS_HPP_ */
