//
// Created by Андрей on 30.06.2022.
//
#include <iostream>
#include <cstdio>
#include "overflow.h"





void speedometer (){
    double speed = 0;
    double speed_delta;

    do {

        std::cout << "Input speed: ";
        std::cin >>speed_delta;
        //system ("CLS");
        while (overflow()){std::cin >> speed_delta;}
        while (speed+speed_delta < -0) {
            std::cout << "Wrong speed. Enter a negative difference no greater than the speed ";
            std::cin >> speed_delta;
            while (overflow()){std::cin >> speed_delta;}
        }
        while (speed+speed_delta >150.0) {
            std::cout << "Wrong speed. Enter the difference at which the speed will be no more than 150 km/h";
            std::cin >>speed_delta;
            while (overflow()){std::cin >> speed_delta;}
        }
        speed += speed_delta;
        char speed_str [100];
        std::sprintf(speed_str, "%.1f", speed);
        std::cout << "Speed: " << speed_str<< std::endl;
    }while (speed != 0);
}