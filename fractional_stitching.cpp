//
// Created by Андрей on 02.07.2022.
//
#include <iostream>
using namespace std;
int count_symbol (int part){
    int count = 0;
    do {
        count ++;
        part /= 10;
    } while (part != 0);

    return count;
}

void stitching (){
    cout << "Enter the integer part of a fractional number: ";
    string integer_part;
    cin >> integer_part;

    cout << "Enter the fractional part of the number: ";
    string fractional_part;
    cin >> fractional_part;

    double stitched_number;
    if (stod(fractional_part) >0 && stod(fractional_part)<1){
        stitched_number = stod (integer_part)+ stod(fractional_part);
    } else {
        double divider = 1;
        for (int i = count_symbol (stoi (fractional_part)); i > 0 ; i--){
            divider *= 10;
        }
        cout << stod(fractional_part) << "  "<<divider << endl;
        stitched_number = stod (integer_part) + (stod(fractional_part) / divider);
    }
    cout << "Your number: " << stitched_number;
}