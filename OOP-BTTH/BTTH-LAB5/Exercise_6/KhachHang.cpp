#include "KhachHang.h"

void KhachHang::Nhap(ifstream& in) {
    getline(in >> ws, tenKH);
    in >> soLuong;
    in >> donGia;
}

double KhachHangA::TinhTien() const {
    double tienHang = soLuong * donGia;

    return tienHang * 1.1;
}

void KhachHangB::Nhap(ifstream& in) {
    KhachHang::Nhap(in);

    in >> soNamThanThiet;
}

double KhachHangB::TinhTien() const {
    double km = min(soNamThanThiet * 5.0, 50.0);

    double tienHang =
        soLuong * donGia * (100 - km) / 100;

    return tienHang * 1.1;
}

double KhachHangC::TinhTien() const {
    double tienHang =
        soLuong * donGia * 0.5;

    return tienHang * 1.1;
}

QuanLy::~QuanLy() {
    for (auto x : ds)
        delete x;
}

void QuanLy::DocFile(string tenFile) {
    ifstream in(tenFile);

    int x, y, z;
    in >> x >> y >> z;

    for (int i = 0; i < x; i++) {
        KhachHang* p = new KhachHangA;
        p->Nhap(in);
        ds.push_back(p);
    }

    for (int i = 0; i < y; i++) {
        KhachHang* p = new KhachHangB;
        p->Nhap(in);
        ds.push_back(p);
    }

    for (int i = 0; i < z; i++) {
        KhachHang* p = new KhachHangC;
        p->Nhap(in);
        ds.push_back(p);
    }

    in.close();
}

void QuanLy::GhiFile(string tenFile) {
    ofstream out(tenFile);

    double tong = 0;

    for (auto x : ds) {
        out << x->GetTen() << endl;
        out << x->TinhTien() << endl;

        tong += x->TinhTien();
    }

    out << tong;

    out.close();
}