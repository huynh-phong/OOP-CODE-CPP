#include "NhanVien.h"

int main() {
    QuanLy ql;

    ql.Nhap();

    cout << "\n===== DANH SACH NHAN VIEN =====\n";
    ql.Xuat();

    ql.LuongThapHonTB();

    ql.NVCaoLuongNhat();

    ql.NVLuongThapNhat();

    ql.LTVLuongCaoNhat();

    ql.KCVLuongThapNhat();

    return 0;
}