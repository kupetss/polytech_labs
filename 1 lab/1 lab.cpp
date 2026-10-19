#include <iostream>
#include <locale>
#include <iomanip>

/* Лабораторная работа №1
    Задание №19: Написать программу вычисления энерговооруженности автомобиля с точностью до 2-го знака после запятой.
    Форма ввода-вывода данных представлена ниже.
    Ввод:
        Объем и количество цилиндров двигателя: ...
        Мощность снимаемая с одного цилиндра: ...
        Масса автомобиля: ...
    Вывод:
        Энерговооруженность автомобиля массой ... с двигателем мощностью ... составляет ...
  */

  /*Формула:
      Энерговооруженность = v * n / m
      Мощность двигателя = v × n
      где:
          v - мощность снимаемая с одного цилиндра
          n - количество цилиндров
          m - масса автомобиля
  */

#define DEMO

int main()
{
    setlocale(LC_ALL, "RUS");

    double celinderVolume; // Объем цилиндров двигателя
    int celinderCount;     // Количество цилиндров двигателя
    double celinderPower;  // Мощность одного целиндра
    double carMass;        // Масс автомобиля
    double CarEnergyPower; // Энерговооруженность
    double carPower;       // Мощность двигателя

#ifdef DEMO
    std::cout
        << "Программа для вычисления энерговооруженности автомобиля." << std::endl
        << "Необходимо ввести вводные данные." << std::endl;

    std::cout << "Введите объем цилиндров двигателя: ";
    std::cin >> celinderVolume;

    std::cout << "Введите количество цилиндров двигателя: ";
    std::cin >> celinderCount;

    std::cout << "Введите мощность снимаемая с одного цилиндра: ";
    std::cin >> celinderPower;

    std::cout << "Введите массу автомобиля: ";
    std::cin >> carMass;

    CarEnergyPower = celinderPower * celinderCount / carMass;
    carPower = celinderPower * celinderCount;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl << "Энерговооруженность автомобиля массой " << carMass << " с двигателем мощностью " << carPower << " составляет " << CarEnergyPower << std::endl;
#else
    printf("Программа для вычисления энерговооруженности автомобиля.\n"
        "Необходимо ввести вводные данные.\n");

    printf("Введите объем цилиндров двигателя: ");
    scanf_s("%lf", &celinderVolume);

    printf("Введите количество цилиндров двигателя: ");
    scanf_s("%d", &celinderCount);

    printf("Введите мощность снимаемая с одного цилиндра: ");
    scanf_s("%lf", &celinderPower);

    printf("Введите массу автомобиля: ");
    scanf_s("%lf", &carMass);

    CarEnergyPower = celinderPower * celinderCount / carMass;
    carPower = celinderPower * celinderCount;

    printf("Энерговооруженность автомобиля массой %.2f с двигателем мощностью %.2f составляет %.2f\n", carMass, carPower, CarEnergyPower);
#endif 
    system("pause");
}