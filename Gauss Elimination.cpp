#include <bits/stdc++.h>
using namespace std;

void gaussElimination(int n, vector<vector<double>> &a) {


    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }


    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }



    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n+1));



    cout << "Enter augmented matrix (coefficients + constants):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    gaussElimination(n, a);

    return 0;
}
