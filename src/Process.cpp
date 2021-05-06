/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Process
*/

#include "Process.hpp"

namespace ARC
{
    Process::Process()
    {
        _pid = fork();
        if (_pid < 0)
            std::cerr << "Error: fork failed\n" << std::endl;
    }

    Process::~Process()
    {
    }

    pid_t Process::getPid() const
    {
        return _pid;
    }
}