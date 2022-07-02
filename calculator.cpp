//
// Created by Андрей on 02.07.2022.
//
#include <iostream>
#include <sstream>
using namespace std;

void calculator (){
    string buffer;
    cin >> buffer;
    stringstream buffer_stream (buffer);
double a;
double b;
unsigned char operation;
buffer_stream >> a >> operation >> b;
double result;

switch (operation){
    case '/': result = a / b; break;
    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*': result = a * b; break;
    default : result = 0; cout << "the calculator can't do operations other than */+-"; break;
}
cout << "= " << result;
}
