#include <iostream>
#include "cNhanVienSX.h"

using namespace std;

int main(){
    cListNhanVienSX ds;

    cout << "NHAP DANH SACH NHAN VIEN SAN XUAT\n";
    ds.Nhap();

    cout << "\nTOAN BO DANH SACH\n";
    ds.Xuat();

    cNhanVienSX minLuong = ds.LuongThapNhat();
    cout << "\nNHAN VIEN LUONG THAP NHAT\n";
    minLuong.Xuat();

    cout << "\nTong luong cong ty phai tra: "
         << ds.TongLuong() << endl;

    cNhanVienSX lonTuoi = ds.TuoiCaoNhat();
    cout << "\nNHAN VIEN LON TUOI NHAT\n";
    lonTuoi.Xuat();

    ds.SapXepTangDanTheoLuong();
    cout << "\nDANH SACH TANG DAN THEO LUONG\n";
    ds.Xuat();

    return 0;
}