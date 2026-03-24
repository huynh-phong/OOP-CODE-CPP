#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

class HocSinh {
private:
    string hoTen;
    float diemToan;
    float diemVan;

public:
    void nhap() {
        cout << "Nhap ho ten hoc sinh: ";
        getline(cin, hoTen);

        cout << "Nhap diem Toan: ";
        cin >> diemToan;

        cout << "Nhap diem Van: ";
        cin >> diemVan;
    }

    float tinhDiemTrungBinh() const {
        return (diemToan + diemVan) / 2.0f;
    }

    string xepLoai() const {
        float dtb = tinhDiemTrungBinh();

        if (dtb >= 8.0f) {
            return "Gioi";
        }
        if (dtb >= 6.5f) {
            return "Kha";
        }
        if (dtb >= 5.0f) {
            return "Trung binh";
        }
        return "Yeu";
    }

    void xuat() const {
        cout << "Ho ten: " << hoTen << '\n';
        cout << "Diem Toan: " << diemToan << '\n';
        cout << "Diem Van: " << diemVan << '\n';
        cout << fixed << setprecision(2);
        cout << "Diem trung binh: " << tinhDiemTrungBinh() << '\n';
        cout << "Xep loai: " << xepLoai() << '\n';
    }
};

int main() {
    HocSinh hs;
    hs.nhap();
    hs.xuat();
    return 0;
}
