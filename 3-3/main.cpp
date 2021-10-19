#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
* \brief Расчёт рекурентного выражения
* \param n Индекс члена ряда
* \return Значение рекурентного соотношения
*/
double recurrent(const double x, const size_t n);

/**
* \brief Расчёт экспоненты
* \param x Аргумент экспоненты
* \return Значение экспоненты
*/
double getExponent(const double x);

/**
* \brief Расчёт суммы ряда
* \param x Аргумент экспоненты
* \param eps точность расчёта
* \return Значение суммы ряда
*/
double getSum(const double x, const double eps);

int main()
{
    const double LOWER_BOUND = 0.1, UPPER_BOUND = 1, STEP = 0.1, EPS = pow(10, -4), WIDTH = 10;

    cout << setw(WIDTH) << "Exponent(x)" << " | " << setw(WIDTH) << "Sum\n";

    for (double x = LOWER_BOUND; x <= UPPER_BOUND; x += STEP)
    {
        cout << setw(WIDTH) << getExponent(x) << " | " << setw(WIDTH) << getSum(x, EPS) << "\n";
    }

    return 0;
}

double recurrent(const double x, const size_t n)
{
    return pow(x, 2) / ((2 * n + 1) * (2 * n + 2));
}

double getSum(const double x, const double eps)
{
    double previous = 1;
    double sum = previous;
    double current;

    for (size_t n = 0; abs(previous) > eps; n++)
    {
        current = recurrent(x, n) * previous;
        previous = current;

        sum += previous;
    }

    return sum;
}

double getExponent(const double x)
{
    return (exp(x) + exp(-x)) / 2;
}

