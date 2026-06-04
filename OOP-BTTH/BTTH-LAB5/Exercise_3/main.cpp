#include "SinhVien.h"

int main() {
    QuanLySV ql;

    ql.Nhap();

    cout << "\n===== DANH SACH SINH VIEN =====\n";
    ql.Xuat();

    ql.DSSVTotNghiep();

    ql.DSSVKhongTotNghiep();

    ql.SVDHDiemTBCaoNhat();

    ql.SVCDDiemTBCaoNhat();

    ql.DemKhongTotNghiep();

    return 0;
}