#include <iostream>
#include "cCandidate.h"

using namespace std;

int main(){
    cListCandidate ds;

    cout << "NHAP DANH SACH THI SINH\n";
    ds.Nhap();

    cout << "\nTOAN BO DANH SACH\n";
    ds.Xuat();

    ds.XuatLonHon15();

    cCandidate max = ds.TongDiemCaoNhat();
    cout << "\nTHI SINH CO TONG DIEM CAO NHAT\n";
    max.Xuat();

    ds.SapXepGiamDan();
    cout << "\nDANH SACH GIAM DAN THEO TONG DIEM\n";
    ds.Xuat();

    return 0;
}