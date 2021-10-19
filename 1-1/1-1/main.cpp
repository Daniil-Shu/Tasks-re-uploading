#include <iostream>
#include <cmath>

using namespace std;

double GetA(const double x, const double y, const double z);
double GetB(const double x, const double y, const double z);

int main()
{
    const auto x = 0.2;
    const auto y = 0.004;
    const auto z = 1.1;

 //   const auto a = GetA(x, y, z);
    const auto a = (pow(sin(pow((pow(x, 2) + z) , 2)) , 3)) - sqrt(x/y);
    const auto b = GetB(x, y, z);

    std::cout << "x = " << x << ", y = " << y << ", z = " << z << '\n';
    std::cout << "a = " << a << ", b = " << b << endl;
    return 0;

}

double GetA(const double x, const double y, const double z)
{
    return (pow(sin(pow((pow(x, 2)+z),2)),3) ) - sqrt(x/y);
    return pow(sin(pow(x,2)),3);
}

double GetB(const double x, const double y, const double z)
{
    return pow(x, 2) / z + cos(pow((x+y), 3));
}
