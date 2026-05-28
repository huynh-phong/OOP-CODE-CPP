#include "CVector.h"
#include <cmath>

CVector::CVector() {
    n = 0;
    a = NULL;
}

CVector::CVector(int n) {
    this->n = n;
    a = new float[n];

    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

CVector::CVector(const CVector& v) {
    n = v.n;
    a = new float[n];

    for (int i = 0; i < n; i++) {
        a[i] = v.a[i];
    }
}

CVector::~CVector() {
    delete[] a;
}

void CVector::Nhap() {
    cout << "Nhap so chieu: ";
    cin >> n;

    delete[] a;
    a = new float[n];

    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void CVector::Xuat() const {
    cout << "(";

    for (int i = 0; i < n; i++) {
        cout << a[i];

        if (i != n - 1)
            cout << ", ";
    }

    cout << ")";
}

float CVector::DoDai() const {
    float tong = 0;

    for (int i = 0; i < n; i++) {
        tong += a[i] * a[i];
    }

    return sqrt(tong);
}

CVector CVector::operator+(const CVector& v) const {
    CVector kq(n);

    if (n != v.n) {
        cout << "Khong cung so chieu!\n";
        return kq;
    }

    for (int i = 0; i < n; i++) {
        kq.a[i] = a[i] + v.a[i];
    }

    return kq;
}

CVector CVector::operator-(const CVector& v) const {
    CVector kq(n);

    if (n != v.n) {
        cout << "Khong cung so chieu!\n";
        return kq;
    }

    for (int i = 0; i < n; i++) {
        kq.a[i] = a[i] - v.a[i];
    }

    return kq;
}

float CVector::operator*(const CVector& v) const {
    if (n != v.n) {
        cout << "Khong cung so chieu!\n";
        return 0;
    }

    float tong = 0;

    for (int i = 0; i < n; i++) {
        tong += a[i] * v.a[i];
    }

    return tong;
}

istream& operator>>(istream& in, CVector& v) {
    v.Nhap();
    return in;
}

ostream& operator<<(ostream& out, const CVector& v) {
    v.Xuat();
    return out;
}