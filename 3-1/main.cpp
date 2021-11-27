#include <iostream>
#include <cmath>

using namespace std;

/**
*\brief Функция для расчета y
* \param x Параметр x
* \return Значение функции
*/
double GetY(double x);
/**
* \brief Возможность подсчёта функции в точке x
* \param x - точка x
* \return true, если функция определена в точке x
*/
bool isCalculated(const double x);

/**
* \brief точка входа в программу
* \return Код ошибки(0 - успех)
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    const int LOW_BOUND = 0;
    const double UP_BOUND = 0.8;
    const double step = 0.05;
    double x = LOW_BOUND;

    cout << fixed;
    for (x; x <= UP_BOUND; x += step)
    {
        if (isCalculated(x))
            cout << "x: " << x << " | y: " << GetY(x) << '\n';
        else
            cout << "x: " << x << "| невозможно посчитать функцию в данной точке\n";
    }
    return 0;
}

double GetY(const double x)
{
    return tan(x) - 1 / 3 * pow(tan(x), 3) + 1 / 5 * pow(tan(x), 5) - 1 / 3;
}

bool isCalculated(const double x)
{
    return (x >= std::numeric_limits<double>::min());
}