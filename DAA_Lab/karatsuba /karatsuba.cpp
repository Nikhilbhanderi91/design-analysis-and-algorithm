// karatsuba
#include <iostream>
#include <cmath>
using namespace std;
long long karatsuba(long long x, long long y)
{
    if (x < 10 || y < 10)
    {
        return x * y;
    }
    /* Calculates the size of the numbers. */
    int m = max(to_string(x).length(), to_string(y).length());
    long long m2 = m / 2;
    long long power = pow(10, m2);

    /* Split the digit sequences in the middle. */
    long long a = x / power;
    long long b = x % power;
    long long c = y / power;
    long long d = y % power;

    /* 3 recursive calls made to numbers approximately half the size. */
    long long ac = karatsuba(a, c);
    long long bd = karatsuba(b, d);
    long long ab_cd = karatsuba(a + b, c + d) - ac - bd;

    return (ac * pow(10, m2*2)) + (ab_cd * pow(10, m2)) + bd;
}
int main()
{
    long long x, y;
    cout << "Enter first number";
    cin >> x;
    cout << "Enter second number";
    cin >> y;
    string result = to_string(karatsuba(x, y));
    cout << x << "*" << y << "=" << result;
    return 0;
}
