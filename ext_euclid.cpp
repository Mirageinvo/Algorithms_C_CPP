#include <iostream>
#include <string>

//Thanks to https://www.eolymp.com/ru/blogs/posts/18

using namespace std;

int ext_euclid(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x2, y2;
    int d = ext_euclid(b, a % b, x2, y2);
    x = y2;
    y = x2 - (a / b) * y2;
    return d;
}

int main() {
    int a, b, c, x, y, gcd;
    scanf("%d%d%d", &a, &b, &c);
    gcd = ext_euclid(a, b, x, y);
    if (c % gcd == 0) {
        x *= c / gcd;
        y *= c / gcd;
        cout << "x = " << x << " + " << b << " * k" << endl << "y = " << y << " - " << a << " * k" << endl;
    }
    else {
        cout << "There is no solution since" << c << "is not divisible by gcd = " << gcd << endl;
    }
    return 0;
}