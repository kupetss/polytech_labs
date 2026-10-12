#include <iostream>
//#include <cmath>

/*Лабораторная работа №2
  Задание №19: Разработать консольное Win32 приложение для определения номера зоны на диаграмме, в которую попала точка, 
  введенная пользователем. Пользователь вводит с клавиатуры координаты Х и У некоторой точки. 
  Определить в какую из зон, согласно приведенной ниже диаграмме, в соответствии со своим вариантом с попала точка. 
  Если точка попадает на границу зон, отнести ее к зоне с большим номером.
 */

int main()
{
    setlocale(LC_ALL, "RUS");

    float x, y;
    std::cout << "Введите координаты точки x: ";
    std::cin >> x;
    std::cout << "Введите координаты точки y: ";
    std::cin >> y;

    //// маленький круг
    //if (distance_center_little_circle <= radius_little_circle && y < 0) {
    //    std::cout << "Вы попали в маленький круг" << std::endl;
    //}
    //else if (distance_center_big_circle <= radius_big_circle) {
    //    std::cout << "Вы попали в большой круг" << std::endl;
    //}

    //// прямая
    //if (y >= line) {
    //    std::cout << "Выше линии" << std::endl;
    //}
    //else {
    //    std::cout << "Ниже линии" << std::endl;
    //}

    //// первая кривая y = sqrt(-x)
    //if (x < 0 && y > first_curve) {
    //    std::cout << "Выше первой кривой" << std::endl;
    //} else if (x < 0 && y < first_curve) {
    //    std::cout << "Ниже первой кривой" << std::endl;
    //}

    //// кубическая парабола y = -(x - 1)^3
    //if (x > second_curve) {
    //    std::cout << "Справа от кривой" << std::endl;
    //} else if (x < second_curve){
    //    std::cout << "Слева от кривой" << std::endl;
    //}

    double center_little_circle_x = 0.5;
    double center_little_circle_y = 0;
    double radius_little_circle = 0.5 * 0.5;
    double distance_center_little_circle = (x - center_little_circle_x) * (x - center_little_circle_x) + (y - center_little_circle_y) * (y - center_little_circle_y);

    double radius_big_circle = 2 * 2;
    double center_big_circle_x = 0;
    double center_big_circle_y = 0;
    double distance_center_big_circle = (x - center_big_circle_x) * (x - center_big_circle_x) + (y - center_big_circle_y) * (y - center_big_circle_y);

    double slope_line = (-3 - 2) / (2 - (-3));
    double b = 2 - slope_line * (-3);
    double line = slope_line * x + b;

    double first_curve = std::sqrt(-x);
    double second_curve = 1 + std::cbrt(-y);

    if (x == 0 && y == 0) {
        std::cout << "24" << std::endl;
        return 0;
    }
    if (x >= 4 || y >= 4) {
        std::cout << "Вы попали за график" << std::endl;
        return 0;
    }

    if (y == 0) {
        if (x > 0 && x < 0.75) {
            std::cout << "19" << std::endl;
            return 0;
        }
        else if (x > 0.75 && x < 1) {
            std::cout << "20" << std::endl;
            return 0;
        }
        else if (x >= 1 && x < 1.25) {
            std::cout << "22" << std::endl;
            return 0;
        }
        else if (x >= 1.25 && x < 2) {
            std::cout << "17" << std::endl;
            return 0;
        }
        else if (x == 2) {
            std::cout << "17";
            return 0;
        }
        else if (x > 2) {
            std::cout << "4" << std::endl;
            return 0;
        }
        else if (x < 0 && x >= -1) {
            std::cout << "21" << std::endl;
            return 0;
        }
        else if (x < -1 && x >= -2) {
            std::cout << "12" << std::endl;
            return 0;
        }
        else if (x < -2) {
            std::cout << "10" << std::endl;
            return 0;
        }
    }
    else if (x == 0) {
        if (y > 0 && y <= 1) {
            std::cout << "24" << std::endl;
            return 0;
        }
        else if(y > 1 && y <= 2) {
            std::cout << "16" << std::endl;
            return 0;
        }
        else if (y > 2 ) {
            std::cout << "5" << std::endl;
            return 0;
        }
        else if (y < 0 && y > -1) {
            std::cout << "22" << std::endl;
            return 0;
        }
        else if (y <= -1 && y >= -2) {
            std::cout << "23" << std::endl;
            return 0;
        }
        else if (y < -2) {
            std::cout << "10" << std::endl;
            return 0;
        }
    }

    if (x > 0 && y > 0) {
        if (distance_center_little_circle <= radius_little_circle)
        {
            if (x > second_curve) {
                std::cout << "20" << std::endl;
                return 0;
            }
            else if (x < second_curve) {
                std::cout << "19" << std::endl;
                return 0;
            }
        }
        else if ( x < second_curve) {
            std::cout << "24" << std::endl;
            return 0;
        }
        else if (x > second_curve && distance_center_big_circle <= radius_big_circle) {
            std::cout << "16" << std::endl;
            return 0;
        }
        else if (x > second_curve) {
            std::cout << "4" << std::endl;
            return 0;
        }
        
        
    }
    if (x < 0 && y > 0) {
        if (distance_center_big_circle <= radius_big_circle) {
            if (y >= line && y < first_curve) {
                std::cout << "13" << std::endl;
                return 0;
            }
            else if (y >= line && y > first_curve) {
                std::cout << "14" << std::endl;
                return 0;
            }
            else if (y >= line && y > first_curve && x > second_curve) {
                std::cout << "15" << std::endl;
                return 0;
            }
            else if (y <= line) {
                std::cout << "12" << std::endl;
                return 0;
            }
        }
        else if (y >= line && y > first_curve && x > second_curve) {
            std::cout << "5" << std::endl;
            return 0;
        }
        else if (y >= line && y > first_curve && x < second_curve) {
            std::cout << "6" << std::endl;
            return 0;
        }
        else if (y <= line && y > first_curve) {
            std::cout << "7" << std::endl;
            return 0;
        }
        else if (y <= line && y < first_curve) {
            std::cout << "9" << std::endl;
            return 0;
        }
        else if (y > line && y < first_curve) {
            std::cout << "8" << std::endl;
            return 0;
        }
    }
    if (x < 0 && y < 0) {
        if (y >= line) {
            std::cout << "21" << std::endl;
            return 0;
        }
        else if (y < line && distance_center_big_circle <= radius_big_circle) {
            std::cout << "11" << std::endl;
            return 0;
        }
        else if (y < line) {
            std::cout << "10" << std::endl;
            return 0;
        }
        else if (y == -1 || y == -2) {
            std::cout << "23" << std::endl;
            return 0;
        }

    }
    if (x > 0 && y < 0){
        if (distance_center_big_circle <= radius_big_circle) {
            if (x > second_curve) {
                std::cout << "17" << std::endl;
                return 0;
            }
            else if (x < second_curve && y >= line) {
                std::cout << "22" << std::endl;
                return 0;
            }
            //else if (x < second_curve && y < line) {
            //    
            //    return 0;
            //}
        if (distance_center_little_circle <= radius_little_circle) {
            std::cout << "18" << std::endl;
            return 0;
        }
            std::cout << "23" << std::endl;
            return 0;
        }
        else if (x < second_curve && y < line) {
            std::cout << "1" << std::endl;
            return 0;
        }
        else if (x < second_curve && y > line && x < second_curve) {
            std::cout << "2" << std::endl;
            return 0;
        }
        else if (x < second_curve && y > line && x > second_curve) {
            std::cout << "3" << std::endl;
            return 0;
        }

    }
    system("pause");
}