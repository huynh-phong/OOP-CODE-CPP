#include <iostream>
using namespace std;

bool namNhuan(int y) {
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int soNgayTrongThang(int m, int y) {
    if (m == 2) return namNhuan(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

int main() {
    int d, m, y;
    cout << "Nhap ngay thang nam: ";
    cin >> d >> m >> y;

    d++;
    if (d > soNgayTrongThang(m, y)) {
        d = 1;
        m++;
        if (m > 12) {
            m = 1;
            y++;
        }
    }

    cout << "Ngay ke tiep: " << d << "/" << m << "/" << y;
}