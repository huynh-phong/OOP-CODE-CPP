#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class PhanSo {
public:
    int tu, mau;

    void nhap() {
        cout << "Nhap tu: ";
        cin >> tu;
        do {
            cout << "Nhap mau (!=0): ";
            cin >> mau;
        } while (mau == 0);
    }

    void xuat() {
        cout << tu << "/" << mau << " ";
    }

    double giaTri() {
        return (double)tu / mau;
    }

    void rutGon() {
        int a = abs(tu), b = abs(mau);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        tu /= a;
        mau /= a;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
};

class arrPhanSo {
private:
    PhanSo *a;
    int n;

public:
    arrPhanSo() {
        n = 0;
        a = nullptr;
    }

    ~arrPhanSo() {
        delete[] a;
    }

    void nhap() {
        cout << "Nhap n: ";
        cin >> n;
        a = new PhanSo[n];
        for (int i = 0; i < n; i++) {
            cout << "Phan so " << i + 1 << ":\n";
            a[i].nhap();
            a[i].rutGon();
        }
    }

    void xuat() {
        cout << "Danh sach: ";
        for (int i = 0; i < n; i++)
            a[i].xuat();
        cout << endl;
    }

    void taoNgauNhien() {
        cout << "Nhap n: ";
        cin >> n;
        a = new PhanSo[n];

        srand(time(0));
        for (int i = 0; i < n; i++) {
            a[i].tu = rand() % 100 + 1;
            a[i].mau = rand() % 99 + 1;
            a[i].rutGon();
        }
    }

    PhanSo maxPhanSo() {
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].giaTri() > a[idx].giaTri())
                idx = i;
        }
        return a[idx];
    }

    bool laNguyenTo(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

    int demTuNguyenTo() {
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (laNguyenTo(a[i].tu))
                dem++;
        }
        return dem;
    }

    void sapXepTang() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i].giaTri() > a[j].giaTri()) {
                    PhanSo temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
};

int main() {
    arrPhanSo ds;

    ds.nhap();
    ds.xuat();

    cout << "Phan so lon nhat: ";
    PhanSo max = ds.maxPhanSo();
    max.xuat();
    cout << endl;

    cout << "So phan so co tu la so nguyen to: "
         << ds.demTuNguyenTo() << endl;

    ds.sapXepTang();
    cout << "Sau khi sap xep:\n";
    ds.xuat();

    return 0;
}