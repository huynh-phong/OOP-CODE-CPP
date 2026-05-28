#include "SoPhuc.h"
#include <iostream>
using namespace std;
SoPhuc::SoPhuc(double t, double a) {
    thuc = t;
    ao = a;
}

istream& operator>>(istream& in, SoPhuc& sp) {
    cout << "\nNhap phan thuc: ";
    in >> sp.thuc;
    cout << "Nhap phan ao: ";
    in >> sp.ao;

    return in;
}

ostream& operator<<(ostream& out, const SoPhuc& sp) {
    out << sp.thuc;
    if (sp.ao >= 0)
        out << " + " << sp.ao << "i";
    else
        out << " - " << -sp.ao << "i";
    return out;
}


SoPhuc SoPhuc::operator+(const SoPhuc& other) const {
    return SoPhuc(thuc + other.thuc, ao + other.ao);
}

SoPhuc SoPhuc::operator-(const SoPhuc& other) const {
    return SoPhuc(thuc - other.thuc, ao - other.ao);
}

SoPhuc SoPhuc::operator*(const SoPhuc& other) const {
    return SoPhuc(
        thuc * other.thuc - ao * other.ao,
        thuc * other.ao + ao * other.thuc
    );
}

SoPhuc SoPhuc::operator/(const SoPhuc& other) const {
    double mau = other.thuc * other.thuc + other.ao * other.ao;

    return SoPhuc(
        (thuc * other.thuc + ao * other.ao) / mau,
        (ao * other.thuc - thuc * other.ao) / mau
    );
}

bool SoPhuc::operator==(const SoPhuc& other) const {
    return (thuc == other.thuc && ao == other.ao);
}

bool SoPhuc::operator!=(const SoPhuc& other) const {
    return !(*this == other);
}