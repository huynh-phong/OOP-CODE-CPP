#include "DaThuc.h"

int main() {
    DaThuc dt1, dt2;

    cout << "Nhap da thuc thu 1:\n";
    cin >> dt1;

    cout << "\nNhap da thuc thu 2:\n";
    cin >> dt2;

    cout << "\nDa thuc 1: ";
    cout << dt1;

    cout << "\nDa thuc 2: ";
    cout << dt2;

    DaThuc tong = dt1 + dt2;
    DaThuc hieu = dt1 - dt2;

    cout << "\n\nTong hai da thuc: ";
    cout << tong;

    cout << "\nHieu hai da thuc: ";
    cout << hieu;

    float x;
    cout << "\n\nNhap x = ";
    cin >> x;

    cout << "Gia tri da thuc 1 tai x = " << x << " la: "
         << dt1.TinhGiaTri(x);

    return 0;
}