#include <iostream>
#include <cmath>
#include "tasks.h"

/*Лабораторная работа №2
  Задание №19: Разработать консольное Win32 приложение для определения номера зоны на диаграмме, в которую попала точка,
  введенная пользователем. Пользователь вводит с клавиатуры координаты Х и У некоторой точки.
  Определить в какую из зон, согласно приведенной ниже диаграмме, в соответствии со своим вариантом с попала точка.
  Если точка попадает на границу зон, отнести ее к зоне с большим номером.
 */

static const double radius_little_circle = 0.25;
static const double radius_big_circle = 4;

static void read_point(float& x, float& y)
{
    std::cout << "Введите координаты точки x: ";
    std::cin >> x;
    std::cout << "Введите координаты точки y: ";
    std::cin >> y;
}

static void calc_figures(float& x, float& y, double& distance_center_little_circle, double& distance_center_big_circle,
    double& line, double& first_curve, double& second_curve)
{
    // Маленький круг: (x-0.5)^2 + y^2 = 0.25
    double center_little_circle_x = 0.5;
    double center_little_circle_y = 0;
    distance_center_little_circle = (x - center_little_circle_x) * (x - center_little_circle_x) + (y - center_little_circle_y) * (y - center_little_circle_y);

    // Большой круг: x^2 + y^2 = 4
    double center_big_circle_x = 0;
    double center_big_circle_y = 0;
    distance_center_big_circle = (x - center_big_circle_x) * (x - center_big_circle_x) + (y - center_big_circle_y) * (y - center_big_circle_y);

    // Прямая: y = -x - 1  =>  line = -x - 1
    line = -x - 1;

    // Первая кривая: y = sqrt(-x)
    first_curve = std::sqrt(-x);

    // Вторая кривая: y = -(x-1)^3
    second_curve = -std::pow(x - 1, 3);
}

static bool check_axis(float& x, float& y)
{
    if (x == 0 && y == 0) {
        std::cout << "24" << std::endl;
        return true;
    }
    if (x > 3 || y > 3 || x < -3 || y < -3) {
        std::cout << "Вы попали за график" << std::endl;
        return true;
    }

    if (y == 0) {
        if (x > 0 && x < 1) {
            std::cout << "19" << std::endl;
            return true;
        }
        else if (x == 1) {
            std::cout << "20" << std::endl;
            return true;
        }
        else if (x > 1 && x <= 2) {
            std::cout << "17" << std::endl;
            return true;
        }
        else if (x > 2) {
            std::cout << "4" << std::endl;
            return true;
        }
        else if (x < 0 && x >= -1) {
            std::cout << "21" << std::endl;
            return true;
        }
        else if (x < -1 && x >= -2) {
            std::cout << "12" << std::endl;
            return true;
        }
        else if (x < -2) {
            std::cout << "10" << std::endl;
            return true;
        }
    }
    else if (x == 0) {
        if (y > 0 && y <= 1) {
            std::cout << "24" << std::endl;
            return true;
        }
        else if (y > 1 && y <= 2) {
            std::cout << "16" << std::endl;
            return true;
        }
        else if (y > 2) {
            std::cout << "5" << std::endl;
            return true;
        }
        else if (y < 0 && y > -1) {
            std::cout << "22" << std::endl;
            return true;
        }
        else if (y <= -1 && y >= -2) {
            std::cout << "23" << std::endl;
            return true;
        }
        else if (y < -2) {
            std::cout << "10" << std::endl;
            return true;
        }
    }
    return false;
}

static bool check_top(float& x, float& y, double& distance_center_little_circle, double& distance_center_big_circle,
    double& line, double& first_curve, double& second_curve)
{
    if (x > 0 && y > 0) {
        if (distance_center_little_circle <= radius_little_circle)
        {
            if (x > second_curve) {
                std::cout << "20" << std::endl;
                return true;
            }
            else if (x < second_curve) {
                std::cout << "19" << std::endl;
                return true;
            }
        }
        else if (x < second_curve) {
            std::cout << "24" << std::endl;
            return true;
        }
        else if (x > second_curve && distance_center_big_circle <= radius_big_circle) {
            std::cout << "16" << std::endl;
            return true;
        }
        else if (!distance_center_big_circle <= radius_big_circle) {
            std::cout << "4" << std::endl;
            return true;
        }
        else if (x == 0.24 && y == 0.4) {
            std::cout << "24" << std::endl;
            return true;
        }
    }
    if (x < 0 && y > 0) {
        if (distance_center_big_circle <= radius_big_circle) {

            if (y >= second_curve) {
                std::cout << "15" << std::endl;
                return true;
            }
            else if (y >= first_curve && y < second_curve) {
                std::cout << "14" << std::endl;
                return true;
            }
            else if (y >= line && y < first_curve) {
                std::cout << "13" << std::endl;
                return true;
            }

            else if (y < line) {
                std::cout << "12" << std::endl;
                return true;
            }
        }
        if (y <= line && y <= first_curve) {
            std::cout << "9" << std::endl;
            return true;
        }
        else if (y > line && y <= first_curve) {
            std::cout << "8" << std::endl;
            return true;
        }
        else if (y <= line && y > first_curve) {
            std::cout << "7" << std::endl;
            return true;
        }
        else if (y > line && y > first_curve && y < second_curve) {
            std::cout << "6" << std::endl;
            return true;
        }
        else if (y > second_curve) {
            std::cout << "5" << std::endl;
            return true;
        }
        // Прямая и круг
        else if (x == -1.823 && y == 0.823) {
            std::cout << "13" << std::endl;
            return true;
        }
        // Прямая и первая кривая
        else if (x == -2.618 && y == 1.618) {
            std::cout << "9" << std::endl;
            return true;
        }
        // Круг и первая кривая
        else if (x == -1.562 && y == 1.250) {
            std::cout << "14" << std::endl;
            return true;
        }
        // Круг и вторая кривая
        else if (x == -0.255 && y == 1.977) {
            std::cout << "15" << std::endl;
            return true;
        }
    }
    return false;
}

static bool check_bottom(float& x, float& y, double& distance_center_little_circle, double& distance_center_big_circle,
    double& line, double& second_curve)
{
    if (x < 0 && y < 0) {
        if (y >= line) {
            std::cout << "21" << std::endl;
            return true;
        }
        else if (y < line && distance_center_big_circle <= radius_big_circle) {
            std::cout << "11" << std::endl;
            return true;
        }
        else if (!distance_center_big_circle <= radius_big_circle) {
            std::cout << "10" << std::endl;
            return true;
        }
    }
    if (x > 0 && y < 0) {
        if (distance_center_big_circle <= radius_big_circle) {

            if (distance_center_little_circle <= radius_little_circle) {
                std::cout << "18" << std::endl;
                return true;
            }
            else if (y > second_curve) {
                std::cout << "17" << std::endl;
                return true;
            }
            else if (y <= second_curve && y > line) {
                std::cout << "22" << std::endl;
                return true;
            }
            else if (y <= line) {
                std::cout << "23" << std::endl;
                return true;
            }

        }
        if (y >= second_curve) {
            std::cout << "3" << std::endl;
            return true;
        }
        else if (y < second_curve && y >= line) {
            std::cout << "2" << std::endl;
            return true;
        }
        else if (y < line) {
            std::cout << "1" << std::endl;
            return true;
        }
        // Прямая и большой круг
        else if (x == 0.823 && y == -1.823) {
            std::cout << "23" << std::endl;
            return true;
        }
        // Вторая кривая и большой круг
        else if (x == 1.877 && y == -0.674) {
            std::cout << "17" << std::endl;
            return true;
        }
    }
    return false;
}

void lab2()
{
    setlocale(LC_ALL, "RUS");

    float x, y;
    double distance_center_little_circle, distance_center_big_circle, line, first_curve, second_curve;

    read_point(x, y);

    if (check_axis(x, y))
        return;

    calc_figures(x, y, distance_center_little_circle, distance_center_big_circle, line, first_curve, second_curve);

    if (check_top(x, y, distance_center_little_circle, distance_center_big_circle, line, first_curve, second_curve))
        return;

    check_bottom(x, y, distance_center_little_circle, distance_center_big_circle, line, second_curve);
}