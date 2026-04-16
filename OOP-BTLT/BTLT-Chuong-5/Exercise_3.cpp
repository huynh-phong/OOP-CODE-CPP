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

    friend istream& operator>>(istream& in, DaThuc& p) {
        in >> p.n;
        delete[] p.a;
        p.a = new double[p.n + 1];
        for (int i = 0; i <= p.n; i++) {
            in >> p.a[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, DaThuc p) {
        for (int i = 0; i <= p.n; i++) {
            out << p.a[i];
            if (i < p.n) out << "x^" << (p.n - i) << " + ";
        }
        return out;
    }

    double giaTri(double x) {
        double s = 0;
        for (int i = 0; i <= n; i++) {
            s += a[i] * pow(x, n - i);
        }
        return s;
    }

    DaThuc operator+(DaThuc b) {
        int maxBac = max(n, b.n);
        DaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double hs1 = 0, hs2 = 0;

            if (i >= maxBac - n) hs1 = a[i - (maxBac - n)];
            if (i >= maxBac - b.n) hs2 = b.a[i - (maxBac - b.n)];

            kq.a[i] = hs1 + hs2;
        }
        return kq;
    }

    DaThuc operator-(DaThuc b) {
        int maxBac = max(n, b.n);
        DaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            double hs1 = 0, hs2 = 0;

            if (i >= maxBac - n) hs1 = a[i - (maxBac - n)];
            if (i >= maxBac - b.n) hs2 = b.a[i - (maxBac - b.n)];

            kq.a[i] = hs1 - hs2;
        }
        return kq;
    }
};

int main() {
    DaThuc p1, p2;
    cin >> p1 >> p2;

    cout << p1 << endl;
    cout << p2 << endl;

    DaThuc tong = p1 + p2;
    cout << tong << endl;

    double x;
    cin >> x;
    cout << p1.giaTri(x) << endl;

    return 0;
}