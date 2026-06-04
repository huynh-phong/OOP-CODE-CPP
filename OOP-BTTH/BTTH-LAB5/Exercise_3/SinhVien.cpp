#include "SinhVien.h"

void SinhVien::Nhap() {
    cin.ignore();

    cout << "Ma SV: ";
    getline(cin, maSV);

    cout << "Ho ten: ";
    getline(cin, hoTen);

    cout << "Dia chi: ";
    getline(cin, diaChi);

    cout << "Tong tin chi: ";
    cin >> tongTinChi;

    cout << "Diem TB: ";
    cin >> diemTB;
}

void SinhVien::Xuat() const {
    cout << "\nMa SV: " << maSV;
    cout << "\nHo ten: " << hoTen;
    cout << "\nDia chi: " << diaChi;
    cout << "\nTong tin chi: " << tongTinChi;
    cout << "\nDiem TB: " << diemTB;
}

void SVCaoDang::Nhap() {
    SinhVien::Nhap();

    cout << "Diem thi tot nghiep: ";
    cin >> diemTN;
}

void SVCaoDang::Xuat() const {
    cout << "\n===== SINH VIEN CAO DANG =====";
    SinhVien::Xuat();
    cout << "\nDiem TN: " << diemTN << endl;
}

bool SVCaoDang::TotNghiep() const {
    return tongTinChi >= 120
        && diemTB >= 5
        && diemTN >= 5;
}

void SVDaiHoc::Nhap() {
    SinhVien::Nhap();

    cin.ignore();

    cout << "Ten luan van: ";
    getline(cin, tenLuanVan);

    cout << "Diem luan van: ";
    cin >> diemLuanVan;
}

void SVDaiHoc::Xuat() const {
    cout << "\n===== SINH VIEN DAI HOC =====";
    SinhVien::Xuat();

    cout << "\nTen luan van: " << tenLuanVan;
    cout << "\nDiem luan van: " << diemLuanVan << endl;
}

bool SVDaiHoc::TotNghiep() const {
    return tongTinChi >= 170
        && diemTB >= 5
        && diemLuanVan >= 5;
}

QuanLySV::~QuanLySV() {
    for (auto x : ds)
        delete x;
}

void QuanLySV::Nhap() {
    int n;
    cout << "Nhap so sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;

        cout << "\n1. Cao dang";
        cout << "\n2. Dai hoc";
        cout << "\nChon loai: ";
        cin >> loai;

        SinhVien* p = NULL;

        if (loai == 1)
            p = new SVCaoDang;
        else
            p = new SVDaiHoc;

        p->Nhap();

        ds.push_back(p);
    }
}

void QuanLySV::Xuat() {
    for (auto x : ds)
        x->Xuat();
}

void QuanLySV::DSSVTotNghiep() {
    cout << "\n===== DANH SACH TOT NGHIEP =====\n";

    for (auto x : ds)
        if (x->TotNghiep())
            x->Xuat();
}

void QuanLySV::DSSVKhongTotNghiep() {
    cout << "\n===== DANH SACH KHONG TOT NGHIEP =====\n";

    for (auto x : ds)
        if (!x->TotNghiep())
            x->Xuat();
}

void QuanLySV::SVDHDiemTBCaoNhat() {
    SVDaiHoc* maxSV = NULL;
    double mx = -1;

    for (auto x : ds) {
        SVDaiHoc* p =
            dynamic_cast<SVDaiHoc*>(x);

        if (p && p->GetDiemTB() > mx) {
            mx = p->GetDiemTB();
            maxSV = p;
        }
    }

    if (maxSV) {
        cout << "\n===== SV DAI HOC DIEM TB CAO NHAT =====\n";
        maxSV->Xuat();
    }
}

void QuanLySV::SVCDDiemTBCaoNhat() {
    SVCaoDang* maxSV = NULL;
    double mx = -1;

    for (auto x : ds) {
        SVCaoDang* p =
            dynamic_cast<SVCaoDang*>(x);

        if (p && p->GetDiemTB() > mx) {
            mx = p->GetDiemTB();
            maxSV = p;
        }
    }

    if (maxSV) {
        cout << "\n===== SV CAO DANG DIEM TB CAO NHAT =====\n";
        maxSV->Xuat();
    }
}

void QuanLySV::DemKhongTotNghiep() {
    int cd = 0;
    int dh = 0;

    for (auto x : ds) {
        if (!x->TotNghiep()) {

            if (dynamic_cast<SVCaoDang*>(x))
                cd++;

            if (dynamic_cast<SVDaiHoc*>(x))
                dh++;
        }
    }

    cout << "\nSo SV Cao dang khong tot nghiep: "
         << cd;

    cout << "\nSo SV Dai hoc khong tot nghiep: "
         << dh << endl;
}