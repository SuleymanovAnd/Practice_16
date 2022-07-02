//
// Created by Андрей on 30.06.2022.
//
#include <iostream>

bool overflow ( ){

    if (! std::cin){
        std::cout <<"Ошибка ввода. Введите заново: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');

        return true;
    } else {return false;}
}