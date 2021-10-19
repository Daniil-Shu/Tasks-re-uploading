#include <iostream>
#include <cmath>

using namespace std;

double GetFirst (const double x);
double GetSecond (const double x, const double a);

int main()
{
    const double a = 20.3;
    double x;
    cout << "Введите число \n";
    cin >> x;
    if (x > 1)
    {
        auto first = GetFirst(x);
        cout << first;
    }

    else
    {
        auto second = GetSecond(x,a);
        cout << second;
    }
}

double GetFirst (double x)
{
    return log10(x + 1);
}

double GetSecond (double x, double a)
{
    return sin(2) * sqrt(abs(a * x));
}
