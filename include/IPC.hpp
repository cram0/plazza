/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** IPC
*/

#ifndef IPC_HPP_
#define IPC_HPP_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#include <string>
#include <iostream>
#include <cstdio>
#include <fstream>

namespace ARC
{
    class IPC {
        public:
            IPC();
            ~IPC();

            int MkFifo(int id = -1);
            int RmFifo(int id = -1);
            std::string ReadFifo(int id = -1);
            void WriteFifo(const std::string &msg, int id = -1);

        private:
    };
}

#endif /* !IPC_HPP_ */
