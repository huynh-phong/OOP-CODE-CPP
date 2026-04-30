#include <iostream>
#include <cmath>
#include <algorithm>
#include "cDaGiac.h"
#define EPS 1e-6

using namespace std;

bool ktBang(double a, double b){
    return fabs(a - b) < EPS;
}

double TinhCanh(DIEM A, DIEM B){
    return sqrt((A.x - B.x)*(A.x - B.x) +
                (A.y - B.y)*(A.y - B.y));
}

void QuayDiem(DIEM &P, double goc){
    double rad = goc * 3.14159265 / 180.0;

    double xMoi = P.x * cos(rad) - P.y * sin(rad);
    double yMoi = P.x * sin(rad) + P.y * cos(rad);

    P.x = xMoi;
    P.y = yMoi;
}

void DIEM::Nhap(){
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}

void DIEM::Xuat(){
    cout << "(" << x << ", " << y << ")";
}

void DAGIAC::Nhap(){
    do{
        cout << "Nhap so diem: ";
        cin >> n;

        for(int i = 0; i < n; i++){
            cout << "Nhap diem " << char('A'+i) << ":\n";
            nDiem[i].Nhap();
        }

        if(!KiemTraHopLe()){
            cout << "Da giac khong hop le! Nhap lai!\n";
        }

    }while(!KiemTraHopLe());
}

void DAGIAC::Xuat(){
    for(int i = 0; i < n; i++){
        cout << "Diem " << char('A'+i) << ": ";
        nDiem[i].Xuat();
        cout << endl;
    }
}

bool DAGIAC::KiemTraHopLe(){
    if(n < 3) return false;

    for(int i = 0; i < n; i++){
        if(ktBang(nDiem[i].x, nDiem[(i+1)%n].x) &&
           ktBang(nDiem[i].y, nDiem[(i+1)%n].y))
            return false;
    }

    return true;
}

void DAGIAC::KiemTraLoaiDaGiac(){
    if(n == 3) cout << "Day la tam giac";
    else if(n == 4) cout << "Day la tu giac";
    else if(n == 5) cout << "Day la ngu giac";
    else if(n == 6) cout << "Day la luc giac";
    else cout << "Day la da giac " << n << " canh";
}

void DAGIAC::ChuVi(){
    double P = 0;

    for(int i = 0; i < n; i++){
        P += TinhCanh(nDiem[i], nDiem[(i+1)%n]);
    }

    cout << "Chu vi da giac la: " << P;
}

void DAGIAC::DienTich(){
    double S = 0;

    for(int i = 0; i < n; i++){
        int j = (i+1)%n;

        S += nDiem[i].x * nDiem[j].y -
             nDiem[j].x * nDiem[i].y;
    }

    S = fabs(S) / 2.0;

    cout << "Dien tich da giac la: " << S;
}

void DAGIAC::TinhTien(double dx, double dy){
    for(int i = 0; i < n; i++){
        nDiem[i].x += dx;
        nDiem[i].y += dy;
    }
}

void DAGIAC::Quay(double goc){
    for(int i = 0; i < n; i++){
        QuayDiem(nDiem[i], goc);
    }
}

void DAGIAC::PhongTo(double k){
    if(k <= 0) return;

    for(int i = 0; i < n; i++){
        nDiem[i].x *= k;
        nDiem[i].y *= k;
    }
}

void DAGIAC::ThuNho(double k){
    if(k <= 0) return;

    for(int i = 0; i < n; i++){
        nDiem[i].x /= k;
        nDiem[i].y /= k;
    }
}