#include <iostream>
#include <iomanip>
#include "cTamGiac.h"

using namespace std;

int main()
{
    TAMGIAC tamGiac;

    cout << "Nhap thong tin tam giac:\n";
    tamGiac.Nhap();

    cout << "\nTam giac vua nhap: ";
    tamGiac.Xuat();

    cout << "\nLoai tam giac: "; 
    tamGiac.KiemTraLoaiTamGiac();
    cout << "\nChu vi: " << fixed << setprecision(2); 
    tamGiac.ChuVi();
    cout << "\nDien tich: " << fixed << setprecision(2); 
    tamGiac.DienTich();

    double dx, dy;
    cout << "\n\nNhap vector tinh tien (dx dy): ";
    cin >> dx >> dy;
    tamGiac.TinhTien(dx, dy);
    cout << "Sau khi tinh tien: ";
    tamGiac.Xuat();

    double goc;
    cout << "\nNhap goc quay (do): ";
    cin >> goc;
    tamGiac.Quay(goc);
    cout << "Sau khi quay quanh trong tam: ";
    tamGiac.Xuat();

    double tyLePhongTo;
    cout << "\nNhap ty le phong to: ";
    cin >> tyLePhongTo;
    tamGiac.PhongTo(tyLePhongTo);
    cout << "Sau khi phong to quanh trong tam: ";
    tamGiac.Xuat();

    double tyLeThuNho;
    cout << "\nNhap ty le thu nho: ";
    cin >> tyLeThuNho;
    tamGiac.ThuNho(tyLeThuNho);
    cout << "Sau khi thu nho quanh trong tam: ";
    tamGiac.Xuat();

    cout << "\n";
    return 0;
}
