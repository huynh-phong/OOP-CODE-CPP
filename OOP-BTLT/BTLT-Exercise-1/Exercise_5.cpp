#include <iostream>
#include <limits>
#include <string>
#include <cctype>

using namespace std;

class cHocSinh {
private:
    string ma;
    string hoTen;
    string gioiTinh;
    int namSinh;
    float diemTrungBinh;

    string nhapChuoiKhongRong(const string& thongBao) {
        string giaTri;
        do {
            cout << thongBao;
            getline(cin >> ws, giaTri);
            if (giaTri.empty()) {
                cout << "Du lieu khong duoc de trong. Vui long nhap lai.\n";
            }
        } while (giaTri.empty());
        return giaTri;
    }

    bool chuaSo(const string& s) {
        for (char c : s) {
            if (isdigit(static_cast<unsigned char>(c))) {
                return true;
            }
        }
        return false;
    }

    string nhapChuoiKhongCoSo(const string& thongBao) {
        string giaTri;
        do {
            cout << thongBao;
            getline(cin >> ws, giaTri);

            if (giaTri.empty()) {
                cout << "Du lieu khong duoc de trong. Vui long nhap lai.\n";
            } else if (chuaSo(giaTri)) {
                cout << "Du lieu khong duoc chua so. Vui long nhap lai.\n";
                giaTri.clear();
            }
        } while (giaTri.empty());

        return giaTri;
    }

    int nhapNamSinhHopLe() {
        int nam;
        while (true) {
            cout << "Nhap nam sinh: ";
            cin >> nam;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nam sinh phai la so nguyen. Vui long nhap lai.\n";
                continue;
            }

            if (nam < 1900 || nam > 2026) {
                cout << "Nam sinh phai trong khoang 1900 den 2026. Vui long nhap lai.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return nam;
        }
    }

    float nhapDiemHopLe() {
        float diem;
        while (true) {
            cout << "Nhap diem trung binh: ";
            cin >> diem;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Diem trung binh phai la so. Vui long nhap lai.\n";
                continue;
            }

            if (diem < 0 || diem > 10) {
                cout << "Diem trung binh phai nam trong khoang 0 den 10. Vui long nhap lai.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return diem;
        }
    }

public:
    void nhap() {
        ma = nhapChuoiKhongRong("Nhap ma hoc sinh: ");
        hoTen = nhapChuoiKhongCoSo("Nhap ho ten: ");
        gioiTinh = nhapChuoiKhongCoSo("Nhap gioi tinh: ");
        namSinh = nhapNamSinhHopLe();
        diemTrungBinh = nhapDiemHopLe();
    }

    void xuat() const {
        cout << "Ma: " << ma << '\n';
        cout << "Ho ten: " << hoTen << '\n';
        cout << "Gioi tinh: " << gioiTinh << '\n';
        cout << "Nam sinh: " << namSinh << '\n';
        cout << "Diem trung binh: " << diemTrungBinh << '\n';
    }

    float getDiemTrungBinh() const {
        return diemTrungBinh;
    }

    int getNamSinh() const {
        return namSinh;
    }

    string getHoTen() const {
        return hoTen;
    }
};

int main() {
    cHocSinh hs1, hs2;

    cout << "Nhap thong tin hoc sinh thu 1:\n";
    hs1.nhap();

    cout << "\nNhap thong tin hoc sinh thu 2:\n";
    hs2.nhap();
    
    cout<<"\nBANG THONG TIN HOC SINH\n";
    cout << "\nThong tin hoc sinh 1:\n";
    hs1.xuat();

    cout << "\nThong tin hoc sinh 2:\n";
    hs2.xuat();  
    cout << "\nKET QUA SO SANH\n\n";
    if (hs1.getDiemTrungBinh() > hs2.getDiemTrungBinh()) {
        cout << hs1.getHoTen() << ": co diem trung binh cao hon.\n";
    } else if (hs1.getDiemTrungBinh() < hs2.getDiemTrungBinh()) {
        cout << hs2.getHoTen() << ": co diem trung binh cao hon.\n";
    } else {
        cout << "Hai hoc sinh co diem trung binh bang nhau.\n";
    }

    if (hs1.getNamSinh() > hs2.getNamSinh()) {
        cout << hs1.getHoTen() << " co tuoi nho hon.\n";
    } else if (hs1.getNamSinh() < hs2.getNamSinh()) {
        cout << hs2.getHoTen() << " co tuoi nho hon.\n";
    } else {
        cout << "Hai hoc sinh bang tuoi nhau.\n";
    }

    return 0;
}
