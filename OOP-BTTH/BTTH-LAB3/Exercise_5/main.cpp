#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main(){
    cDaThuc dt1, dt2, tong, hieu;

    cout << "NHAP DA THUC 1\n";
    dt1.Nhap();

    cout << "\nNHAP DA THUC 2\n";
    dt2.Nhap();

    cout << "\nDa thuc 1: ";
    dt1.Xuat();

    cout << "Da thuc 2: ";
    dt2.Xuat();

    double x;
    cout << "\nNhap gia tri x: ";
    cin >> x;

    cout << "P1(" << x << ") = " << dt1.TinhGiaTri(x) << endl;
    cout << "P2(" << x << ") = " << dt2.TinhGiaTri(x) << endl;

    tong = dt1.Cong(dt2);
    cout << "\nTong hai da thuc: ";
    tong.Xuat();

    hieu = dt1.Tru(dt2);
    cout << "Hieu hai da thuc: ";
    hieu.Xuat();

    return 0;
}