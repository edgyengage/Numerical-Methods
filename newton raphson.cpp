#include <bits/stdc++.h>
using namespace std;

#define EPSILON 0.0001

double func(double x) {
    return x*x*x - x - 11;
}

double derivFunc(double x) {
    return 3*x*x - 1;
}

void newtonRaphson(double x0) {
    double h = func(x0) / derivFunc(x0);

    cout << "Iteration    x        f(x)\n";
    int iter = 1;
    while (fabs(h) >= EPSILON) {
        h = func(x0) / derivFunc(x0);
        double x1 = x0 - h;

        cout << iter << "          " << x1
             << "     " << func(x1) << endl;

        x0 = x1;
        iter++;
    }

    cout << "\nThe root is: " << x0 << endl;
}

int main() {
    double x0 = 2;
    newtonRaphson(x0);
    return 0;
}
