#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    PhanSo(int t = 0, int m = 1) {
        tu = t;
        mau = m;
    }

    int LayTu() { return tu; }
    int LayMau() { return mau; }

    void GanTu(int t) { tu = t; }
    void GanMau(int m) { mau = m; }

    void Nhap() {
        cin >> tu >> mau;
    }

    void Xuat() {
        cout << tu << "/" << mau;
    }

    bool operator>(PhanSo b) {
        return tu * b.mau > b.tu * mau;
    }

    PhanSo operator+(PhanSo b) {
        return PhanSo(tu * b.mau + b.tu * mau, mau * b.mau);
    }
};

class DSPhanSo {
private:
    PhanSo *a;
    int n;

public:
    DSPhanSo() {
        n = 0;
        a = nullptr;
    }

    ~DSPhanSo() {
        delete[] a;
    }

    void nhap() {
        cin >> n;
        a = new PhanSo[n];
        for (int i = 0; i < n; i++) {
            a[i].Nhap();
        }
    }

    PhanSo maxPS() {
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[idx]) idx = i;
        }
        return a[idx];
    }

    PhanSo tong() {
        PhanSo s(0,1);
        for (int i = 0; i < n; i++) {
            s = s + a[i];
        }
        return s;
    }

    void xuat() {
        for (int i = 0; i < n; i++) {
            a[i].Xuat();
            cout << " ";
        }
        cout << endl;
    }
};

int main() {
    DSPhanSo ds;
    ds.nhap();

    PhanSo max = ds.maxPS();
    max.Xuat();
    cout << endl;

    PhanSo s = ds.tong();
    s.Xuat();

    return 0;
}