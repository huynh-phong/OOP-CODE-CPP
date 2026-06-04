#include "NhanVien.h"

void NhanVien::Nhap() {
    cin.ignore();

    cout << "Ma NV: ";
    getline(cin, maNV);

    cout << "Ho ten: ";
    getline(cin, hoTen);

    cout << "Tuoi: ";
    cin >> tuoi;

    cin.ignore();

    cout << "SDT: ";
    getline(cin, sdt);

    cout << "Email: ";
    getline(cin, email);

    cout << "Luong co ban: ";
    cin >> luongCoBan;
}

void NhanVien::Xuat() const {
    cout << "\nMa NV: " << maNV;
    cout << "\nHo ten: " << hoTen;
    cout << "\nTuoi: " << tuoi;
    cout << "\nSDT: " << sdt;
    cout << "\nEmail: " << email;
    cout << "\nLuong co ban: " << luongCoBan;
}

void LapTrinhVien::Nhap() {
    NhanVien::Nhap();

    cout << "So gio overtime: ";
    cin >> gioOT;
}

void LapTrinhVien::Xuat() const {
    cout << "\n===== LAP TRINH VIEN =====";
    NhanVien::Xuat();
    cout << "\nSo gio OT: " << gioOT;
    cout << "\nLuong: " << TinhLuong() << endl;
}

double LapTrinhVien::TinhLuong() const {
    return luongCoBan + gioOT * 200000;
}

void KiemChungVien::Nhap() {
    NhanVien::Nhap();

    cout << "So loi phat hien: ";
    cin >> soLoi;
}

void KiemChungVien::Xuat() const {
    cout << "\n===== KIEM CHUNG VIEN =====";
    NhanVien::Xuat();
    cout << "\nSo loi: " << soLoi;
    cout << "\nLuong: " << TinhLuong() << endl;
}

double KiemChungVien::TinhLuong() const {
    return luongCoBan + soLoi * 50000;
}

QuanLy::~QuanLy() {
    for (auto x : ds)
        delete x;
}

void QuanLy::Nhap() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;

        cout << "\n1. Lap trinh vien";
        cout << "\n2. Kiem chung vien";
        cout << "\nChon: ";
        cin >> loai;

        NhanVien* p = NULL;

        if (loai == 1)
            p = new LapTrinhVien;
        else
            p = new KiemChungVien;

        p->Nhap();
        ds.push_back(p);
    }
}

void QuanLy::Xuat() {
    for (auto x : ds)
        x->Xuat();
}

double QuanLy::LuongTB() {
    if (ds.empty())
        return 0;

    double tong = 0;

    for (auto x : ds)
        tong += x->TinhLuong();

    return tong / ds.size();
}

void QuanLy::LuongThapHonTB() {
    double tb = LuongTB();

    cout << "\n===== LUONG THAP HON TB =====\n";

    for (auto x : ds)
        if (x->TinhLuong() < tb)
            x->Xuat();
}

void QuanLy::NVCaoLuongNhat() {
    if (ds.empty()) return;

    NhanVien* maxNV = ds[0];

    for (auto x : ds)
        if (x->TinhLuong() > maxNV->TinhLuong())
            maxNV = x;

    cout << "\n===== NHAN VIEN LUONG CAO NHAT =====\n";
    maxNV->Xuat();
}

void QuanLy::NVLuongThapNhat() {
    if (ds.empty()) return;

    NhanVien* minNV = ds[0];

    for (auto x : ds)
        if (x->TinhLuong() < minNV->TinhLuong())
            minNV = x;

    cout << "\n===== NHAN VIEN LUONG THAP NHAT =====\n";
    minNV->Xuat();
}

void QuanLy::LTVLuongCaoNhat() {
    LapTrinhVien* maxLTV = NULL;
    double mx = -1;

    for (auto x : ds) {
        LapTrinhVien* p =
            dynamic_cast<LapTrinhVien*>(x);

        if (p && p->TinhLuong() > mx) {
            mx = p->TinhLuong();
            maxLTV = p;
        }
    }

    if (maxLTV) {
        cout << "\n===== LTV LUONG CAO NHAT =====\n";
        maxLTV->Xuat();
    }
}

void QuanLy::KCVLuongThapNhat() {
    KiemChungVien* minKCV = NULL;
    double mn = 1e18;

    for (auto x : ds) {
        KiemChungVien* p =
            dynamic_cast<KiemChungVien*>(x);

        if (p && p->TinhLuong() < mn) {
            mn = p->TinhLuong();
            minKCV = p;
        }
    }

    if (minKCV) {
        cout << "\n===== KCV LUONG THAP NHAT =====\n";
        minKCV->Xuat();
    }
}