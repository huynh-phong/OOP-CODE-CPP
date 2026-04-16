#include <iostream>
#include <cmath>
using namespace std;

class DonThuc {
private:
    double a;
    int b;

public:
    DonThuc(double hs = 0, int bac = 0) {
        a = hs;
        b = bac;
    }

    void nhap() {
        cin >> a >> b;
    }

    void xuat() {
        cout << a << "x^" << b;
    }

    double giaTri(double x) {
        return a * pow(x, b);
    }

    DonThuc daoHam() {
        if (b == 0) return DonThuc(0, 0);
        return DonThuc(a * b, b - 1);
    }

    DonThuc cong(DonThuc other) {
        if (b != other.b) return DonThuc(0, 0);
        return DonThuc(a + other.a, b);
    }
};

int main() {
    DonThuc d1, d2;

    d1.nhap();
    d2.nhap();

    DonThuc tong = d1.cong(d2);

    tong.xuat();
}