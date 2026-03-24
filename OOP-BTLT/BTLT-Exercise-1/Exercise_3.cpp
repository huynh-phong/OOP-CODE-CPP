#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class Diem {
private:
    float x;
    float y;

public:
    void nhap(int stt) {
        cout << "Nhap toa do diem thu " << stt << " (x y): ";
        cin >> x >> y;
    }

    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }
};

class DoanThang {
private:
    Diem a;
    Diem b;

public:
    void nhap() {
        a.nhap(1);
        b.nhap(2);
    }

    double tinhKhoangCach() const {
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();
        return sqrt(dx * dx + dy * dy);
    }

    void xuat() const {
        cout << fixed << setprecision(2);
        cout << "\nKhoang cach giua hai diem la: " << tinhKhoangCach() << '\n';
    }
};

int main() {
    DoanThang dt;
    dt.nhap();
    dt.xuat();
    return 0;
}
