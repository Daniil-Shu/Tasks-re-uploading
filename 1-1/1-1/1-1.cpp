#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief Функция для расчета a
 * \param x Параметр x
 * \param y Параметр y
 * \param z Параметр z
 * \return значение a
 */
double GetA(const double x, const double y, const double z);
/**
 * \brief Функция для расчета b
 * \param x Параметр x
 * \param y Параметр y
 * \param z Параметр z
 * \return значение b
 */
double GetB(const double x, const double y, const double z);


/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */

int main()
{
    const auto x = 0.2;
    const auto y = 0.004;
    const auto z = 1.1;

    cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';

    const auto a = (pow(sin(pow((pow(x, 2) + z), 2)), 3)) - sqrt(x / y);

    cout << a << endl;

    const auto b = pow(x, 2) / z + cos(pow((x + y), 3));

    cout << b << endl;
}