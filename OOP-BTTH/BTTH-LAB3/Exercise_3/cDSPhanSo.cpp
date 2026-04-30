#include <iostream>
#include <cmath>
#include <algorithm>
#include "cDSPhanSo.h"

using namespace std;

int UCLN(int a, int b){
    a = abs(a);
    b = abs(b);

    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

bool LaSoNguyenTo(int x){
    if(x < 2) return false;

    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0) return false;
    }

    return true;
}

double GiaTri(PHANSO ps){
    return (double)ps.tu / ps.mau;
}

PHANSO Cong(PHANSO a, PHANSO b){
    PHANSO kq;
    kq.tu = a.tu * b.mau + b.tu * a.mau;
    kq.mau = a.mau * b.mau;
    kq.RutGon();
    return kq;
}

void PHANSO::Nhap(){
    do{
        cout << "Nhap tu so: ";
        cin >> tu;

        cout << "Nhap mau so: ";
        cin >> mau;

        if(mau == 0)
            cout << "Mau so phai khac 0! Nhap lai!\n";

    }while(mau == 0);

    RutGon();
}

void PHANSO::Xuat(){
    if(mau == 1)
        cout << tu;
    else
        cout << tu << "/" << mau;
}

void PHANSO::RutGon(){
    int ucln = UCLN(tu, mau);

    tu /= ucln;
    mau /= ucln;

    if(mau < 0){
        tu *= -1;
        mau *= -1;
    }
}

void DSPHANSO::Nhap(){
    cout << "Nhap so luong phan so: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Nhap phan so thu " << i+1 << ":\n";
        ds[i].Nhap();
    }
}

void DSPHANSO::Xuat(){
    for(int i = 0; i < n; i++){
        ds[i].Xuat();
        cout << " ";
    }
    cout << endl;
}

PHANSO DSPHANSO::Tong(){
    PHANSO tong = {0,1};

    for(int i = 0; i < n; i++){
        tong = Cong(tong, ds[i]);
    }

    return tong;
}

PHANSO DSPHANSO::LonNhat(){
    PHANSO max = ds[0];

    for(int i = 1; i < n; i++){
        if(GiaTri(ds[i]) > GiaTri(max))
            max = ds[i];
    }

    return max;
}

PHANSO DSPHANSO::NhoNhat(){
    PHANSO min = ds[0];

    for(int i = 1; i < n; i++){
        if(GiaTri(ds[i]) < GiaTri(min))
            min = ds[i];
    }

    return min;
}

PHANSO DSPHANSO::TuNguyenToLonNhat(){
    PHANSO kq = ds[0];
    int maxTu = -1;

    for(int i = 0; i < n; i++){
        if(LaSoNguyenTo(abs(ds[i].tu)) && abs(ds[i].tu) > maxTu){
            maxTu = abs(ds[i].tu);
            kq = ds[i];
        }
    }

    return kq;
}

void DSPHANSO::SapXepTangDan(){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(GiaTri(ds[i]) > GiaTri(ds[j]))
                swap(ds[i], ds[j]);
        }
    }
}

void DSPHANSO::SapXepGiamDan(){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(GiaTri(ds[i]) < GiaTri(ds[j]))
                swap(ds[i], ds[j]);
        }
    }
}