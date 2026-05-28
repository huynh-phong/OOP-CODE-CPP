#include "PhanSO.h"
#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

PHANSO::PHANSO(int t,int m){
    tu=t; mau=m;
    if(mau==0)
    mau=1;
    RutGon();
}

void PHANSO::RutGon(){
    int u=UCLN(tu,mau);
    tu/=u; mau/=u;
    if(mau<0){
        tu=-tu;
        mau=-mau;
    }
}

istream& operator>>(istream& in, PHANSO& ps){
    cout<<"Nhap tu so: ";
    in >> ps.tu;
    cout<<"Nhap mau so: ";
    in >> ps.mau;
    while(ps.mau == 0){
        cout<<"\nMau phai khac 0! Nhap lai: ";
        in >> ps.mau;
    }
    ps.RutGon();
    return in;

}

ostream& operator<<(ostream& out,const PHANSO& ps){
    if(ps.mau==0)
    out << ps.tu;
    else
    out << ps.tu << "/" << ps.mau;
    return out;

}

PHANSO PHANSO::operator+(const PHANSO& other) const {
    return PHANSO(tu*other.mau + other.tu*mau,mau*other.mau);
}

PHANSO PHANSO::operator-(const PHANSO& other) const {
    return PHANSO(tu*other.mau - other.tu*mau,mau*other.mau);
}

PHANSO PHANSO::operator*(const PHANSO& other) const {
    return PHANSO(tu*other.tu,mau*other.mau);
} 

PHANSO PHANSO::operator/(const PHANSO& other) const {
    return PHANSO(tu*other.mau,mau*other.tu);
}

bool PHANSO::operator==(const PHANSO& other) const {
    return (tu==other.tu && mau==other.mau);
} 

bool PHANSO::operator>(const PHANSO& other) const {
    return (tu*other.mau > mau*other.tu);
}

bool PHANSO::operator<(const PHANSO& other) const {
    return (tu*other.mau < mau*other.tu);
}