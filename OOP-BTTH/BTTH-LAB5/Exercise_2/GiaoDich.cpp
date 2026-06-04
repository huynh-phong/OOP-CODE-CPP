#include "GiaoDich.h"


void GiaoDich::Nhap() {
    cin.ignore();
    cout << "Ma GD: ";
    getline(cin, maGD);

    cout << "Ngay GD (dd/mm/yyyy): ";
    getline(cin, ngayGD);

    cout << "Don gia: ";
    cin >> donGia;

    cout << "Dien tich: ";
    cin >> dienTich;
}

void GiaoDich::Xuat() const {
    cout << "Ma GD: " << maGD
         << "\nNgay GD: " << ngayGD
         << "\nDon gia: " << donGia
         << "\nDien tich: " << dienTich;
}


void GiaoDichDat::Nhap() {
    GiaoDich::Nhap();

    cout << "Loai dat (A/B/C): ";
    cin >> loaiDat;
}

void GiaoDichDat::Xuat() const {
    cout << "\n=== GIAO DICH DAT ===\n";
    GiaoDich::Xuat();
    cout << "\nLoai dat: " << loaiDat;
    cout << "\nThanh tien: " << ThanhTien() << endl;
}

double GiaoDichDat::ThanhTien() const {
    if (loaiDat == 'A')
        return dienTich * donGia * 1.5;

    return dienTich * donGia;
}


void GiaoDichNhaPho::Nhap() {
    GiaoDich::Nhap();

    cin.ignore();

    cout << "Loai nha (cao cap/thuong): ";
    getline(cin, loaiNha);

    cout << "Dia chi: ";
    getline(cin, diaChi);
}

void GiaoDichNhaPho::Xuat() const {
    cout << "\n=== GIAO DICH NHA PHO ===\n";
    GiaoDich::Xuat();

    cout << "\nLoai nha: " << loaiNha;
    cout << "\nDia chi: " << diaChi;
    cout << "\nThanh tien: " << ThanhTien() << endl;
}

double GiaoDichNhaPho::ThanhTien() const {
    if (loaiNha == "thuong")
        return dienTich * donGia * 0.9;

    return dienTich * donGia;
}


void GiaoDichCanHo::Nhap() {
    GiaoDich::Nhap();

    cin.ignore();

    cout << "Ma can: ";
    getline(cin, maCan);

    cout << "Tang: ";
    cin >> tang;
}

void GiaoDichCanHo::Xuat() const {
    cout << "\n=== GIAO DICH CAN HO ===\n";
    GiaoDich::Xuat();

    cout << "\nMa can: " << maCan;
    cout << "\nTang: " << tang;
    cout << "\nThanh tien: " << ThanhTien() << endl;
}

double GiaoDichCanHo::ThanhTien() const {
    if (tang == 1)
        return dienTich * donGia * 2;

    if (tang >= 15)
        return dienTich * donGia * 1.2;

    return dienTich * donGia;
}


QuanLy::~QuanLy() {
    for (auto x : ds)
        delete x;
}

void QuanLy::Nhap() {
    int n;
    cout << "Nhap so giao dich: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;

        cout << "\n1. Dat";
        cout << "\n2. Nha pho";
        cout << "\n3. Can ho";
        cout << "\nChon: ";
        cin >> loai;

        GiaoDich* p = NULL;

        if (loai == 1)
            p = new GiaoDichDat;
        else if (loai == 2)
            p = new GiaoDichNhaPho;
        else
            p = new GiaoDichCanHo;

        p->Nhap();
        ds.push_back(p);
    }
}

void QuanLy::Xuat() {
    for (auto x : ds)
        x->Xuat();
}

void QuanLy::DemSoLuong() {
    int dat = 0, nha = 0, canho = 0;

    for (auto x : ds) {
        if (dynamic_cast<GiaoDichDat*>(x))
            dat++;
        else if (dynamic_cast<GiaoDichNhaPho*>(x))
            nha++;
        else if (dynamic_cast<GiaoDichCanHo*>(x))
            canho++;
    }

    cout << "\nSo GD Dat: " << dat;
    cout << "\nSo GD Nha Pho: " << nha;
    cout << "\nSo GD Can Ho: " << canho << endl;
}

void QuanLy::TBTienCanHo() {
    double tong = 0;
    int dem = 0;

    for (auto x : ds) {
        GiaoDichCanHo* p =
            dynamic_cast<GiaoDichCanHo*>(x);

        if (p) {
            tong += p->ThanhTien();
            dem++;
        }
    }

    if (dem)
        cout << "\nTrung binh thanh tien can ho = "
             << tong / dem << endl;
}

void QuanLy::NhaPhoGiaTriMax() {
    GiaoDichNhaPho* maxGD = NULL;
    double mx = -1;

    for (auto x : ds) {
        GiaoDichNhaPho* p =
            dynamic_cast<GiaoDichNhaPho*>(x);

        if (p && p->ThanhTien() > mx) {
            mx = p->ThanhTien();
            maxGD = p;
        }
    }

    if (maxGD) {
        cout << "\nNha pho co gia tri lon nhat:\n";
        maxGD->Xuat();
    }
}

void QuanLy::LietKeThang122024() {
    cout << "\nDanh sach giao dich thang 12/2024:\n";

    for (auto x : ds) {
        string ngay = x->GetNgay();

        if (ngay.substr(3, 7) == "12/2024")
            x->Xuat();
    }
}