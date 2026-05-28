#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class NhanVien {
protected:
    string maNV, hoTen, sdt, email;
    int tuoi;
    double luongCoBan;

public:
    virtual void Nhap() {
        cin.ignore();

        cout << "Nhap ma nhan vien: ";
        getline(cin, maNV);

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cin.ignore();

        cout << "Nhap so dien thoai: ";
        getline(cin, sdt);

        cout << "Nhap email: ";
        getline(cin, email);

        cout << "Nhap luong co ban: ";
        cin >> luongCoBan;
    }

    virtual double TinhLuong() = 0;

    virtual void Xuat() {
        cout << left << setw(10) << maNV
             << setw(20) << hoTen
             << setw(10) << tuoi
             << setw(15) << sdt
             << setw(25) << email
             << setw(15) << luongCoBan
             << setw(15) << TinhLuong();
    }

    virtual ~NhanVien() {}
};

class LapTrinhVien : public NhanVien {
private:
    int gioOT;

public:
    void Nhap() override {
        NhanVien::Nhap();

        cout << "Nhap so gio overtime: ";
        cin >> gioOT;
    }

    double TinhLuong() override {
        return luongCoBan + gioOT * 200000;
    }

    void Xuat() override {
        cout << "\n[Lap Trinh Vien] ";
        NhanVien::Xuat();
        cout << setw(10) << gioOT;
    }
};

class KiemChungVien : public NhanVien {
private:
    int soLoi;

public:
    void Nhap() override {
        NhanVien::Nhap();

        cout << "Nhap so loi phat hien duoc: ";
        cin >> soLoi;
    }

    double TinhLuong() override {
        return luongCoBan + soLoi * 50000;
    }

    void Xuat() override {
        cout << "\n[Kiem Chung Vien] ";
        NhanVien::Xuat();
        cout << setw(10) << soLoi;
    }
};

int main() {
    vector<NhanVien*> ds;
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int loai;

        cout << "\n===== NHAN VIEN " << i + 1 << " =====";
        cout << "\n1. Lap trinh vien";
        cout << "\n2. Kiem chung vien";
        cout << "\nChon loai nhan vien: ";
        cin >> loai;

        NhanVien* nv;

        if (loai == 1)
            nv = new LapTrinhVien();
        else
            nv = new KiemChungVien();

        nv->Nhap();
        ds.push_back(nv);
    }

    cout << "\n\n===== DANH SACH NHAN VIEN =====\n";

    for (int i = 0; i < ds.size(); i++) {
        ds[i]->Xuat();
        cout << endl;
    }

    double tongLuong = 0;

    for (int i = 0; i < ds.size(); i++) {
        tongLuong += ds[i]->TinhLuong();
    }

    double luongTB = tongLuong / ds.size();

    cout << "\nLuong trung binh: " << luongTB << endl;

    cout << "\n===== NHAN VIEN CO LUONG THAP HON TRUNG BINH =====\n";

    for (int i = 0; i < ds.size(); i++) {
        if (ds[i]->TinhLuong() < luongTB) {
            ds[i]->Xuat();
            cout << endl;
        }
    }

    for (int i = 0; i < ds.size(); i++) {
        delete ds[i];
    }

    return 0;
}