#include <iostream>
#include <cmath>
using namespace std;

float f(float x) {
    return pow(x, 3) - 4 * x + 1;
}

void secant(float s1, float s2, float E) {
    float x0, x_new, c;
    float n = 0;

    if (f(s1) * f(s2) < 0) {
        do {
            x0 = (s1 * f(s2) - s2 * f(s1)) / (f(s2) - f(s1));
            c = f(s1) * f(x0);

            s1 = s2;
            s2 = x0;

            n++;

            if (c == 0)
                break;

            x_new = (s1 * f(s2) - s2 * f(s1)) / (f(s2) - f(s1));

        } while (fabs(x_new - x0) >= E);

        cout << "Root is approximately = " << x0 << endl;
        cout << "Total iterations = " << n << endl;
    } else {
        cout << "Invalid input range, try different values.\n";
    }
}

int main() {
    float s1 = 0, s2 = 1, E = 0.0001;
    secant(s1, s2, E);
    return 0;
}
