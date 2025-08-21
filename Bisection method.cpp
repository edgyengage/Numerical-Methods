#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;
}

void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval\n";
        return;
    }

    double c;
    while ((b - a) >= tol) {
        c = (a + b) / 2;
        cout << "a=" << a << " b=" << b << " c=" << c << " f(c)=" << f(c) << "\n";

        if (f(c) == 0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }

    cout << "Root approx: " << c << "\n";
}

int main() {
    bisection(1, 2, 0.001);
    return 0;
}
