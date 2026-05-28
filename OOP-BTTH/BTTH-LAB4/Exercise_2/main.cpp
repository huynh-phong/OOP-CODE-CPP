#include "PhanSo.h"

int main() {
    PHANSO a, b;

    cout << "Nhap phan so a:\n";
    cin >> a;

    cout << "\nNhap phan so b:\n";
    cin >> b;

    cout << "\nPhan so a = " << a << endl;
    cout << "Phan so b = " << b << endl;

    cout << "\nTong: " << a + b << endl;
    cout << "Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << endl;
    cout << "Thuong: " << a / b << endl;

    if (a == b)
        cout << "\na bang b\n";
    else
        cout << "\na khac b\n";

    if (a > b)
        cout << "a > b\n";
    else if (a < b)
        cout << "a < b\n";
    else
        cout << "a = b\n";

    return 0;
}