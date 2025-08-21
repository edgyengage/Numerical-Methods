#include <bits/stdc++.h>
using namespace std;

void gaussJordan(int n, vector<vector<double>> &a) {
    cout << "Augmented Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }


    for (int i = 0; i < n; i++) {

        double diag = a[i][i];
        for (int j = 0; j <= n; j++)
            a[i][j] = a[i][j] / diag;


        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = a[k][i];
                for (int j = 0; j <= n; j++)
                    a[k][j] = a[k][j] - factor * a[i][j];
            }
        }
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i+1 << " = " << a[i][n] << endl;
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

    gaussJordan(n, a);

    return 0;
}
