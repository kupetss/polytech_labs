#include <iostream> // ввод и вывод (cin, cout)
#include <iomanip> // форматирование вывода (setprecision)
#include <cmath> // математические функции (fabs, log, sqrt)
#include "tasks.h"
/*
    Лабораторная работа №3, вариант 19
    Сумма ряда: x - 1/2 * x^3/3 + 1*3/(2*4) * x^5/5 - 1*3*5/(2*4*6) * x^7/7 + ...
    Контрольная функция: ln(x + sqrt(1 + x^2)), |x| < 1
*/
using namespace std; //чтобы не писать std::

static double read_x()
{
    double x; // init x
    cout << "Введите x (|x| < 1): "; // output text to input x
    cin >> x; // input x
    return x;
}

static bool check_x(double x)
{
    return fabs(x) < 1;
}

static double calc_next_power_part(double power_part, int n, double x)
{
    return power_part * (-(2.0 * n + 1) / (2.0 * n + 2) * x * x);
}

static double calc_term(double power_part, int n)
{
    return power_part / (2 * n + 1);
}

static double calc_series_sum(double x, double epsilon)
{
    // Член ряда с номером n:  term = powerPart / (2n + 1),
    // где powerPart = (-1)^n * (1*3*...*(2n-1)) / (2*4*...*(2n)) * x^(2n+1)
    double power_part = x; //иниц-ия части члена без деления на (2n+1), при n = 0
    double term = x; //иниц-ия переменной первого члена
    double series_sum = 0; //иниц-ия переменной суммы
    int n = 0; //кол-во итераций

    while (fabs(term) >= epsilon) //повторять пока модуль текущего члена больше или равен точности
    {
        series_sum += term; // добавить текущий член к сумме
        power_part = calc_next_power_part(power_part, n, x); // рекуррентно вычислить часть следующего члена
        n++; //увеличить счетчик итераций
        term = calc_term(power_part, n); // вычислить следующий член
    }

    return series_sum;
}

static int calc_terms_count(double x, double epsilon)
{
    double power_part = x;
    double term = x;
    int n = 0;

    while (fabs(term) >= epsilon)
    {
        power_part = calc_next_power_part(power_part, n, x);
        n++;
        term = calc_term(power_part, n);
    }

    return n;
}

static double calc_exact_value(double x)
{
    return log(x + sqrt(1 + x * x));
}

static double calc_error(double series_sum, double exact_value)
{
    return fabs(series_sum - exact_value);
}

void lab3()
{
    setlocale(LC_ALL, "RUS");

    const double epsilon = 0.0001; //иниц-ия переменной точности
    double x = read_x();

    if (!check_x(x)) // проверка на корректность х
    {
        cout << "Ряд сходится только при |x| < 1" << endl; // сообщение об ошибке
        return; // завершение программы при неверном x
    }

    double series_sum = calc_series_sum(x, epsilon);
    int n = calc_terms_count(x, epsilon);
    double exact_value = calc_exact_value(x); //вычисление контрольного значения

    cout << fixed << setprecision(6); // вывод 6 знаков после запятой
    cout << "Сумма ряда:" << series_sum << endl; //вывод суммы
    cout << "Точное значение:" << exact_value << endl; //вывод контрольного значения
    cout << "Погрешность:" << calc_error(series_sum, exact_value) << endl; // вывод разницы между контрольным и фактическим значениями
    cout << "Количество слагаемых:" << n << endl; // вывод количества членов
}