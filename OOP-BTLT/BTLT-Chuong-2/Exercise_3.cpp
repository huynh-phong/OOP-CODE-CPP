#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int A[100][100], B[100][100];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    cout << "Tong:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }

    cout << "Hieu:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }

    cout << "Tich:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += A[i][k] * B[k][j];
            cout << sum << " ";
        }
        cout << endl;
    }
}