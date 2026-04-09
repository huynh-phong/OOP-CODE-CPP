#include <iomanip>
#include <iostream>

using namespace std;

class DuongTron {
private:
    float x;
    float y;
    float banKinh;
    static constexpr double PI = 3.141592653589793;

public:
    void nhap() {
        cout << "Nhap toa do tam (x y): ";
        cin >> x >> y;

        cout << "Nhap ban kinh: ";
        cin >> banKinh;
    }

    double tinhChuVi() const {
        return 2 * PI * banKinh;
    }

    double tinhDienTich() const {
        return PI * banKinh * banKinh;
    }

    void xuat() const {
        cout << fixed << setprecision(2);
        cout << "Tam I(" << x << ", " << y << ")\n";
        cout << "Ban kinh: " << banKinh << '\n';
        cout << "Chu vi: " << tinhChuVi() << '\n';
        cout << "Dien tich: " << tinhDienTich() << '\n';
    }
};

int main() {
    DuongTron dt;
    dt.nhap();
    dt.xuat();
    return 0;
}