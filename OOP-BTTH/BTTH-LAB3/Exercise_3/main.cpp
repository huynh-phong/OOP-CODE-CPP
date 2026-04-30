#include <iostream>
#include "cDSPhanSo.h"

using namespace std;

int main(){
    DSPHANSO ds;

    cout << "NHAP DANH SACH PHAN SO\n";
    ds.Nhap();

    cout << "\nDanh sach vua nhap:\n";
    ds.Xuat();

    PHANSO tong = ds.Tong();
    cout << "\nTong cac phan so: ";
    tong.Xuat();

    PHANSO lonNhat = ds.LonNhat();
    cout << "\nPhan so lon nhat: ";
    lonNhat.Xuat();

    PHANSO nhoNhat = ds.NhoNhat();
    cout << "\nPhan so nho nhat: ";
    nhoNhat.Xuat();

    PHANSO ntLonNhat = ds.TuNguyenToLonNhat();
    cout << "\nPhan so co tu nguyen to lon nhat: ";
    ntLonNhat.Xuat();

    ds.SapXepTangDan();
    cout << "\n\nDanh sach tang dan:\n";
    ds.Xuat();

    ds.SapXepGiamDan();
    cout << "\nDanh sach giam dan:\n";
    ds.Xuat();

    return 0;
}