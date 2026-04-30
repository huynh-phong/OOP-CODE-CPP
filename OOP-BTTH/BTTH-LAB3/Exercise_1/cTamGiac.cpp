#include <iostream>
#include <cmath>
#include <algorithm>
#include "cTamGiac.h"
#define EPS 1e-6

using namespace std;

void QuayDiem(DIEM &P, float goc) {
    float rad = goc * 3.14159265 / 180.0;

    float xMoi = P.x * cos(rad) - P.y * sin(rad);
    float yMoi = P.x * sin(rad) + P.y * cos(rad);

    P.x = xMoi;
    P.y = yMoi;
}

bool ktbang(double a, double b){
    return fabs(a-b) < EPS;
}
double TinhCanh(DIEM A, DIEM B){
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

bool TAMGIAC::KiemTraHopLe(){
    double AB = TinhCanh(A,B);
    double BC = TinhCanh(B,C);
    double CA = TinhCanh(A,C);

    if(AB + BC <= CA) return false;
    if(AB + CA <= BC) return false;
    if(BC + CA <= AB) return false;

    return true;
}

void DIEM::Nhap(){
    cout<<"\nNhap x:";
    cin>>x;
    cout<<"Nhap y:";
    cin>>y;
}

void DIEM::Xuat() {
    cout << "(" << x << ", " << y << ")";
}

void TAMGIAC::Nhap(){
    do{
    cout<<"Nhap diem A(x,y)";
    A.Nhap();
    cout<<"Nhap diem B(x,y)";
    B.Nhap();
    cout<<"Nhap diem C(x,y)";
    C.Nhap();
    if(!KiemTraHopLe()){
        cout<<"Tam Giac khong hop le! Nhap lai!";
    }
    } while(!KiemTraHopLe());
}

void TAMGIAC::Xuat(){
    cout << "A";
    A.Xuat();
    cout << " B";
    B.Xuat();
    cout << " C";
    C.Xuat();
}

void TAMGIAC::KiemTraLoaiTamGiac(){
    double AB = TinhCanh(A,B);
    double BC = TinhCanh(B,C);
    double CA = TinhCanh(A,C);

    bool deu = ktbang(AB,BC) && ktbang(BC,CA);
    bool can = ktbang(AB,BC) || ktbang(BC,CA) || ktbang(AB,CA);
    bool vuong = ktbang(AB*AB + BC*BC, CA*CA) ||
                 ktbang(AB*AB + CA*CA, BC*BC) ||
                 ktbang(BC*BC + CA*CA, AB*AB);
    if (deu)
        cout << "La tam giac deu";
    else if (vuong && can)
        cout << "La tam giac vuong can";
    else if (vuong)
        cout << "La tam giac vuong";
    else if (can)
        cout << "La tam giac can";
    else 
        cout << "La tam giac thuong";
}

void TAMGIAC::ChuVi(){
    double AB = TinhCanh(A,B);
    double BC = TinhCanh(B,C);
    double CA = TinhCanh(A,C);

    double P = AB + BC + CA;

    cout<<"Chu vi tam giac la: "<<P;
}
void TAMGIAC::DienTich(){
    double AB = TinhCanh(A,B);
    double BC = TinhCanh(B,C);
    double CA = TinhCanh(A,C);

    double P = (AB + BC + CA)/2;
    double S = sqrt(P*(P - AB)*(P - BC)*(P - CA));

    cout<<"Dien tich tam giac la: "<<S;

}
void TAMGIAC::TinhTien(double dx, double dy){
    A.x += dx;
    A.y += dy;

    B.x += dx;
    B.y += dy;

    C.x += dx;
    C.y += dy;
}
void TAMGIAC::Quay(double goc){
    QuayDiem(A, goc);
    QuayDiem(B, goc);
    QuayDiem(C, goc);
}
void TAMGIAC::PhongTo(double k){
    A.x *= k; A.y *= k;
    B.x *= k; B.y *= k;
    C.x *= k; C.y *= k;
}

void TAMGIAC::ThuNho(double k){
    if(k != 0){
        A.x /= k; A.y /= k;
        B.x /= k; B.y /= k;
        C.x /= k; C.y /= k;
    }
}