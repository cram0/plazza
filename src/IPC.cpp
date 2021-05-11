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
        int tmp;
        std::string filename;

        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);

        tmp = mkfifo(filename.c_str(), 0666);

        if (tmp == -1) {
            std::cerr << "Couldn't create FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        return (tmp);
    }

    /*
    * Delete a fifo file
    * If no id is given, it automatically deletes the reception file
    */
    int IPC::RmFifo(int id)
    {
        int tmp;
        std::string filename;

        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);

        tmp = std::remove(filename.c_str());

        if (tmp == -1) {
            std::cerr << "Couldn't remove FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        return (tmp);
    }

    /*
    * Read a fifo file then sends the result in a string
    * If no id is given, it automatically reads the reception file
    */
    std::string IPC::ReadFifo(int id)
    {
        int tmp;
        char buffer[255] = { 0 };
        std::string filename;
        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);

        tmp = open(filename.c_str(), O_RDWR);

        if (tmp == -1) {
            std::cerr << "Couldn't open FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        read(tmp, buffer, 254);
        std::string s_res = buffer;
        close(tmp);

        return (s_res);
    }

    /*
    * Writes a message in a fifo file
    * If no id is given, it automatically writes in the reception file
    */
    void IPC::WriteFifo(const std::string &msg, int id)
    {
        int tmp;
        std::string filename;
        if (id == -1)
            filename = "res/reception";
        else
            filename = "res/kitchen" + std::to_string(id);
        std::string tmp_msg = msg + "\n";

        tmp = open(filename.c_str(), O_RDWR);

        if (tmp == -1) {
            std::cerr << "Couldn't open FIFO file for kitchen id : " << std::to_string(id) << std::endl;
            std::exit(84);
        }

        write(tmp, tmp_msg.c_str(), tmp_msg.length());
        close(tmp);
    }

}