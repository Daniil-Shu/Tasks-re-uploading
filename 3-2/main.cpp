#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Расчёт рекурентного выражения
* \param k Индекс члена ряда
* \return Значение рекурентного соотношения
*/
double Recurrent(const size_t k);

/**
* \brief Расчёт суммы ряда
* \param n Колличество членов ряда
* \return Значение суммы
*/
double GetSum(const size_t n);

/**
* \brief Расчёт суммы ряда
* \param eps Точность расчёта
* \return Значение суммы
*/
double GetSum(const double eps);

int main()
{
    cout << "Введите количество членов n в последовательности:\n";
    size_t n;
    cin >> n;
    cout << "Сумма ряда = " << GetSum(n) << '\n';
    cout << "Введите точность e:\n";
    double eps;
    cin >> eps;
    cout << "Сумма ряда с точностью " << eps << " = " << GetSum(eps);

    return 0;
}

double Recurrent(size_t k) {
    return 1.0 / ((2 * k + 1) * (2 * k + 2));
}

double GetSum(size_t n) {
    double previous = 1;
    double sum = 0;
    double current;

    for (size_t k = 0; k < n; k++) {
        sum += previous;
        current = Recurrent(k) * previous;
        previous = current;
    }
    return sum;
}

double GetSum(const double eps) {
    double previous = 1;
    double sum = previous;
    double current;

    for (size_t k = 0; abs(previous) > eps; k++) {
        current = Recurrent(k) * previous;
        previous = current;
        sum += previous;
    }

    return sum;
}
