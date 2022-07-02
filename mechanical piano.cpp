//
// Created by Андрей on 02.07.2022.
//
#include <iostream>
#include <string>
using namespace std;

bool correct_input (int n){
    string str = to_string(n);
    for(int i = 0; i<str.length();i++){
        if (str[i] - '0' >7 || str[i] - '0' <1) return true;
    }
    return false;
}
enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

void piano (){
    int melody [12];
    for (int i = 1; i<=12 ; i++) {
        cout << "input combination #" << i <<": ";
        cin >> melody [i-1];
        while (correct_input(melody [i-1])){cout << "note cannot have a value greater than 7 and less than 1\nInput again: ";
        cin >> melody [i-1];}
    }
for (int i =0; i<12; i++){
     string str = to_string (melody[i]);
     for (int j = 0; j< str.length(); j++){
       int notes = 1<<(str[j] -'1');
         if (notes&DO) std::cout << "DO ";
         if (notes&RE) std::cout << "RE ";
         if (notes&MI) std::cout << "MI ";
         if (notes&FA) std::cout << "FA ";
         if (notes&SOL) std::cout << "SOL ";
         if (notes&LA) std::cout << "LA ";
         if (notes&SI) std::cout << "SI ";
     }
     cout << endl;
}
}