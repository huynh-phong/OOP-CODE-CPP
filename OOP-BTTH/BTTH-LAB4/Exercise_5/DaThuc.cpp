#include "DaThuc.h"
#include <cmath>

DaThuc::DaThuc() {
    bac = 0;
    heso = new float[1];
    heso[0] = 0;
}

DaThuc::DaThuc(int bac) {
    this->bac = bac;
    heso = new float[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heso[i] = 0;
    }
}

DaThuc::DaThuc(const DaThuc& dt) {
    bac = dt.bac;
    heso = new float[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heso[i] = dt.heso[i];
    }
}

DaThuc::~DaThuc() {
    delete[] heso;
}

void DaThuc::Nhap() {
    cout << "Nhap bac da thuc: ";
    cin >> bac;

    delete[] heso;
    heso = new float[bac + 1];

    for (int i = bac; i >= 0; i--) {
        cout << "Nhap he so bac " << i << ": ";
        cin >> heso[i];
    }
}

void DaThuc::Xuat() const {
    for (int i = bac; i >= 0; i--) {
        cout << heso[i];

        if (i > 0)
            cout << "x^" << i << " + ";
    }
}

float DaThuc::TinhGiaTri(float x) const {
    float tong = 0;

    for (int i = 0; i <= bac; i++) {
        tong += heso[i] * pow(x, i);
    }

    return tong;
}

DaThuc DaThuc::operator+(const DaThuc& dt) const {
    int maxBac = max(bac, dt.bac);
    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        float a = (i <= bac) ? heso[i] : 0;
        float b = (i <= dt.bac) ? dt.heso[i] : 0;

        kq.heso[i] = a + b;
    }

    return kq;
}

DaThuc DaThuc::operator-(const DaThuc& dt) const {
    int maxBac = max(bac, dt.bac);
    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        float a = (i <= bac) ? heso[i] : 0;
        float b = (i <= dt.bac) ? dt.heso[i] : 0;

        kq.heso[i] = a - b;
    }

    return kq;
}

istream& operator>>(istream& in, DaThuc& dt) {
    dt.Nhap();
    return in;
}

ostream& operator<<(ostream& out, const DaThuc& dt) {
    dt.Xuat();
    return out;
}