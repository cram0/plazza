/*
** EPITECH PROJECT, 2021
** B-CCP-400-NCE-4-1-theplazza-julien.augugliaro
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

class Cook {
    public:
        Cook();
        ~Cook();

        bool isAvailable() const;

    private:
        int _timerWorking;
};

#endif /* !COOK_HPP_ */