#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MaTran {
private:
    int m, n;
    int **a;

public:
    MaTran(int r = 0, int c = 0) {
        m = r; n = c;
        a = new int*[m];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
            for (int j = 0; j < n; j++) a[i][j] = 0;
        }
    }

    ~MaTran() {
        for (int i = 0; i < m; i++) delete[] a[i];
        delete[] a;
    }

    void nhap() {
        cin >> m >> n;
        a = new int*[m];
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
    }

    void randomMT() {
        cin >> m >> n;
        a = new int*[m];
        srand(time(0));
        for (int i = 0; i < m; i++) {
            a[i] = new int[n];
            for (int j = 0; j < n; j++)
                a[i][j] = rand() % 100;
        }
    }

    void xuat() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    MaTran operator+(MaTran b) {
        MaTran kq(m, n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                kq.a[i][j] = a[i][j] + b.a[i][j];
        return kq;
    }

    MaTran operator*(MaTran b) {
        MaTran kq(m, b.n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < b.n; j++) {
                kq.a[i][j] = 0;
                for (int k = 0; k < n; k++)
                    kq.a[i][j] += a[i][k] * b.a[k][j];
            }
        return kq;
    }
};

int main() {
    MaTran A, B;

    A.nhap();
    B.nhap();

    MaTran tong = A + B;
    tong.xuat();

    MaTran tich = A * B;
    tich.xuat();

    return 0;
}