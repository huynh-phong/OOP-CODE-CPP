#include <algorithm>
#include <ctime>
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

class cArray {
private:
    int n;
    int* a;

public:
    cArray(int size) {
        n = size;
        a = new int[n];

        for (int i = 0; i < n; ++i) {
            a[i] = rand() % 201 - 100;
        }
    }

    ~cArray() {
        delete[] a;
    }

    void xuat() const {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    bool timSoAmLonNhat(int& ketQua) const {
        bool timThay = false;
        ketQua = numeric_limits<int>::min();

        for (int i = 0; i < n; ++i) {
            if (a[i] < 0 && a[i] > ketQua) {
                ketQua = a[i];
                timThay = true;
            }
        }

        return timThay;
    }

    int demSoLanXuatHien(int x) const {
        int dem = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                ++dem;
            }
        }
        return dem;
    }

    bool kiemTraGiamDan() const {
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] < a[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void sapXepTangDan() {
        sort(a, a + n);
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    while (n <= 0) {
        cout << "So phan tu phai lon hon 0.\n";
        cout << "Nhap lai:\n";
        cin>>n;
    }

    cArray arr(n);

    cout << "\nMang ngau nhien ban dau:\n";
    arr.xuat();

    int soAmLonNhat;
    if (arr.timSoAmLonNhat(soAmLonNhat)) {
        cout << "So am lon nhat trong mang: " << soAmLonNhat << '\n';
    } else {
        cout << "Mang khong co so am.\n";
    }

    int x;
    cout << "Nhap so nguyen x can dem: ";
    cin >> x;
    cout << "So lan xuat hien cua " << x << ": " << arr.demSoLanXuatHien(x) << '\n';

    if (arr.kiemTraGiamDan()) {
        cout << "Mang dang giam dan.\n";
    } else {
        cout << "Mang khong giam dan.\n";
    }

    arr.sapXepTangDan();
    cout << "Mang sau khi sap xep tang dan:\n";
    arr.xuat();

    return 0;
}
