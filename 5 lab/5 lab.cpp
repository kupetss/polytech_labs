#include <iostream>
#include <clocale>
#include "tasks.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;
    std::cout << "Номер лабораторной (1-4): ";
    std::cin >> choice;

    switch (choice) {
    case 1: lab1(); break;
    case 2: lab2(); break;
    case 3: lab3(); break;
    case 4: lab4(); break;
    default: std::cout << "Нет такой лабораторной" << std::endl;
    }

    system("pause");
    return 0;
}