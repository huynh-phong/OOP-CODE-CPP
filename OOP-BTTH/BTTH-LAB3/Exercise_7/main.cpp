#include <iostream>
#include "cNhanVienVP.h"

using namespace std;

int main(){
    cListNhanVienVP ds;

    cout << "NHAP DANH SACH NHAN VIEN\n";
    ds.Nhap();

    cout << "\nTOAN BO DANH SACH\n";
    ds.Xuat();

    cNhanVienVP maxLuong = ds.LuongCaoNhat();
    cout << "\nNHAN VIEN LUONG CAO NHAT\n";
    maxLuong.Xuat();

    cout << "\nTong luong cong ty phai tra: "
         << ds.TongLuong() << endl;

    cNhanVienVP lonTuoi = ds.TuoiCaoNhat();
    cout << "\nNHAN VIEN LON TUOI NHAT\n";
    lonTuoi.Xuat();

    ds.SapXepTangDanTheoLuong();
    cout << "\nDANH SACH TANG DAN THEO LUONG\n";
    ds.Xuat();

    return 0;
}