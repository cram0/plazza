/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** IPC
*/

#include "IPC.hpp"


namespace ARC
{
    IPC::IPC()
    {
        // Suck my fat fucking nuts
    }

    IPC::~IPC()
    {

    }

    int IPC::MkFifo(int id)
    {
        int tmp;
        std::string filename = "res/kitchen" + std::to_string(id);

        tmp = mkfifo(filename.c_str(), 0666);

        if (tmp == -1) {
            std::cerr << "Couldn't create FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        return (tmp);
    }

    int IPC::RmFifo(int id)
    {
        int tmp;
        std::string filename = "res/kitchen" + std::to_string(id);

        tmp = std::remove(filename.c_str());

        if (tmp == -1) {
            std::cerr << "Couldn't remove FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        return (tmp);
    }

    std::string IPC::ReadFifo(int id)
    {
        int tmp;
        char buffer[255] = { 0 };
        std::string filename = "res/kitchen" + std::to_string(id);

        tmp = open(filename.c_str(), O_WRONLY);

        if (tmp == -1) {
            std::cerr << "Couldn't open FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        read(tmp, buffer, 255);
        std::string s_res = buffer;

        return (s_res);
    }

    void IPC::WriteFifo(int id, std::string msg)
    {
        int tmp;
        std::string filename = "res/kitchen" + std::to_string(id);
        std::string tmp_msg = msg + "\n";

        tmp = open(filename.c_str(), O_WRONLY);

        if (tmp == -1) {
            std::cerr << "Couldn't open FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        write(tmp, tmp_msg.c_str(), tmp_msg.length());
        close(tmp);
    }
}