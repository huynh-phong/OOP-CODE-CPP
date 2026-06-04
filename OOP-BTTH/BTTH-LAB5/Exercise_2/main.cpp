#include "GiaoDich.h"

int main() {
    QuanLy ql;

    ql.Nhap();

    cout << "\n===== DANH SACH =====\n";
    ql.Xuat();

    ql.DemSoLuong();

    ql.TBTienCanHo();

    ql.NhaPhoGiaTriMax();

    ql.LietKeThang122024();

    return 0;
}