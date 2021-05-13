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

    }

    IPC::~IPC()
    {

    }

    /*
    * Creates a fifo file
    * If no id is given, it automatically creates the reception file
    */
    int IPC::MkFifo(int id)
    {
        int fd;
        std::string filename;

        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);

        fd = mkfifo(filename.c_str(), 0666);

        if (fd == -1) {
            std::cerr << "Couldn't create FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        return (fd);
    }

    /*
    * Delete a fifo file
    * If no id is given, it automatically deletes the reception file
    */
    int IPC::RmFifo(int id)
    {
        int fd;
        std::string filename;

        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);

        fd = std::remove(filename.c_str());

        if (fd == -1) {
            std::cerr << "Couldn't remove FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        return (fd);
    }

    /*
    * Read a fifo file then sends the result in a string
    * If no id is given, it automatically reads the reception file
    */
    std::string IPC::ReadFifo(int id)
    {
        int fd;
        char buffer[4096] = {0};
        std::string filename;
        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);

        fd = open(filename.c_str(), O_RDONLY);

        if (fd == -1) {
            std::cerr << "Couldn't open FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        if (read(fd, buffer, 4096) == 0) {
            close(fd);
            return (std::string(""));
        }
        else {
            close(fd);
            std::string s_res = buffer;
            return (s_res);
        }
    }

    /*
    * Writes a message in a fifo file
    * If no id is given, it automatically writes in the reception file
    */
    void IPC::WriteFifo(const std::string &msg, int id)
    {
        int fd;
        std::string filename;
        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);
        std::string fd_msg = msg + "\n";

        fd = open(filename.c_str(), O_WRONLY);

        if (fd == -1) {
            std::cerr << "Couldn't open FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        int tmp = write(fd, fd_msg.c_str(), fd_msg.length());

        if (tmp == -1) {
            std::fprintf(stdout, "Couldn't write to FIFO file on kitchen id : %s\n", std::to_string(id).c_str());
        }

        close(fd);
    }
}