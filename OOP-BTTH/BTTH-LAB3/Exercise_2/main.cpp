// ===== main.cpp =====
#include <iostream>
#include "cDaGiac.h"

using namespace std;

int main(){
    DAGIAC daGiac;

    cout << "NHAP DA GIAC\n";
    daGiac.Nhap();

    cout << "\nTHONG TIN DA GIAC\n";
    daGiac.Xuat();

    cout << "\nLoai: ";
    daGiac.KiemTraLoaiDaGiac();

    cout << endl;
    daGiac.ChuVi();

    cout << endl;
    daGiac.DienTich();

    double dx, dy;
    cout << "\n\nNhap vector tinh tien (dx dy): ";
    cin >> dx >> dy;
    daGiac.TinhTien(dx, dy);

    cout << "\nSau khi tinh tien:\n";
    daGiac.Xuat();

    double goc;
    cout << "\nNhap goc quay: ";
    cin >> goc;
    daGiac.Quay(goc);

    cout << "\nSau khi quay:\n";
    daGiac.Xuat();

    double k;
    cout << "\nNhap ti le phong to: ";
    cin >> k;
    daGiac.PhongTo(k);

    cout << "\nSau khi phong to:\n";
    daGiac.Xuat();

    cout << "\nNhap ti le thu nho: ";
    cin >> k;
    daGiac.ThuNho(k);

    cout << "\nSau khi thu nho:\n";
    daGiac.Xuat();

    return 0;
}