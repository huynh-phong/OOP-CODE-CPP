#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int n;
    double *a;

public:
    DaThuc(int bac = 0) {
        n = bac;
        a = new double[n + 1];
        for (int i = 0; i <= n; i++) a[i] = 0;
    }

    ~DaThuc() {
        delete[] a;
    }

    void nhap() {
        cin >> n;
        delete[] a;
        a = new double[n + 1];
        for (int i = 0; i <= n; i++) {
            cin >> a[i];
        }
    }

    void xuat() {
        for (int i = 0; i <= n; i++) {
            cout << a[i];
            if (i < n) cout << "x^" << (n - i) << " + ";
        }
        cout << endl;
    }

    double giaTri(double x) {
        double s = 0;
        for (int i = 0; i <= n; i++) {
            s += a[i] * pow(x, n - i);
        }
        return s;
    }

    DaThuc cong(DaThuc other) {
        int maxBac = max(n, other.n);
        DaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double hs1 = 0, hs2 = 0;

            if (i >= maxBac - n) hs1 = a[i - (maxBac - n)];
            if (i >= maxBac - other.n) hs2 = other.a[i - (maxBac - other.n)];

            kq.a[i] = hs1 + hs2;
        }

        return kq;
    }

    DaThuc tru(DaThuc other) {
        int maxBac = max(n, other.n);
        DaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double hs1 = 0, hs2 = 0;

            if (i >= maxBac - n) hs1 = a[i - (maxBac - n)];
            if (i >= maxBac - other.n) hs2 = other.a[i - (maxBac - other.n)];

            kq.a[i] = hs1 - hs2;
        }

        return kq;
    }
};

int main() {
    DaThuc p1, p2;

    p1.nhap();
    p2.nhap();

    p1.xuat();
    p2.xuat();

    DaThuc tong = p1.cong(p2);
    tong.xuat();

    return 0;
}