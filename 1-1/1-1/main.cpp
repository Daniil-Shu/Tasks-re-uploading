#include <iostream>
#include <cmath>

using namespace std;

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
