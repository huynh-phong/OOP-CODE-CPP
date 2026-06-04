#include <iostream>
#include <vector>
#include <string>
#include "cNhanVien.h"

using namespace std;

int main() {
    vector<NHANVIENSANXUAT> dsSX;
    vector<NHANVIENVANPHONG> dsVP;

    int n, m;

    cout << "Nhap so nhan vien san xuat: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        NHANVIENSANXUAT nv;
        cout << "\nNhap nhan vien san xuat thu " << i + 1 << ":\n";
        nv.Nhap();
        nv.TinhLuong();
        dsSX.push_back(nv);
    }

    cout << "\nNhap so nhan vien van phong: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        NHANVIENVANPHONG nv;
        cout << "\nNhap nhan vien van phong thu " << i + 1 << ":\n";
        nv.Nhap();
        nv.TinhLuong();
        dsVP.push_back(nv);
    }

    double tongLuong = 0;

    cout << "\n DANH SACH NHAN VIEN SAN XUAT \n";
    double minLuongSX = dsSX[0].GetLuong();
    string tenMinSX = dsSX[0].GetHoTen();

    for (auto nv : dsSX) {
        nv.Xuat();
        tongLuong += nv.GetLuong();

        if (nv.GetLuong() < minLuongSX) {
            minLuongSX = nv.GetLuong();
            tenMinSX = nv.GetHoTen();
        }
        cout << "----------------------\n";
    }

    cout << "\n DANH SACH NHAN VIEN VAN PHONG \n";
    int maxTuoi = dsVP[0].TinhTuoi();
    string tenMaxTuoi = dsVP[0].GetHoTen();

    for (auto nv : dsVP) {
        nv.Xuat();
        tongLuong += nv.GetLuong();

        if (nv.TinhTuoi() > maxTuoi) {
            maxTuoi = nv.TinhTuoi();
            tenMaxTuoi = nv.GetHoTen();
        }
        cout << "----------------------\n";
    }

    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;
    cout << "Nhan vien san xuat luong thap nhat: " << tenMinSX << endl;
    cout << "Nhan vien van phong tuoi cao nhat: " << tenMaxTuoi << endl;

    return 0;
}