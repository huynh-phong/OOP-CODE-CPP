#include <iostream>
#include <string>
using namespace std;

class cBook {
private:
    string ma, ten;
    int nam, trang;

public:
    cBook(string m = "", string t = "", int n = 0, int tr = 0) {
        ma = m;
        ten = t;
        nam = n;
        trang = tr;
    }

    void nhap() {
        cin.ignore();
        getline(cin, ma);
        getline(cin, ten);
        cin >> nam >> trang;
    }

    void xuat() {
        cout << ma << " | " << ten << " | " << nam << " | " << trang << endl;
    }

    string getMa() { return ma; }
    int getNam() { return nam; }

    void capNhat() {
        cin.ignore();
        getline(cin, ten);
        cin >> nam >> trang;
    }
};

class cListBook {
private:
    cBook *a;
    int n;

public:
    cListBook() {
        n = 0;
        a = nullptr;
    }

    ~cListBook() {
        delete[] a;
    }

    void nhap() {
        cin >> n;
        a = new cBook[n];
        for (int i = 0; i < n; i++) {
            a[i].nhap();
        }
    }

    void xuat() {
        for (int i = 0; i < n; i++) {
            a[i].xuat();
        }
    }

    void capNhatTheoMa(string ma) {
        for (int i = 0; i < n; i++) {
            if (a[i].getMa() == ma) {
                a[i].capNhat();
            }
        }
    }

    void sachMoiNhat() {
        if (n == 0) return;
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].getNam() > a[idx].getNam()) {
                idx = i;
            }
        }
        a[idx].xuat();
    }
};

int main() {
    cListBook ds;
    ds.nhap();
    ds.xuat();
    ds.sachMoiNhat();
}