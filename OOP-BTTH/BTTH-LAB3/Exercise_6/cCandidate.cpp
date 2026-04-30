#include <iostream>
#include <algorithm>
#include "cCandidate.h"

using namespace std;

void cCandidate::Nhap(){
    cin.ignore();

    cout << "Nhap ma thi sinh: ";
    getline(cin, ma);

    cout << "Nhap ten thi sinh: ";
    getline(cin, ten);

    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);

    cout << "Nhap diem Toan: ";
    cin >> diemToan;

    cout << "Nhap diem Van: ";
    cin >> diemVan;

    cout << "Nhap diem Anh: ";
    cin >> diemAnh;
}

void cCandidate::Xuat(){
    cout << "Ma: " << ma << endl;
    cout << "Ten: " << ten << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Toan: " << diemToan << endl;
    cout << "Van: " << diemVan << endl;
    cout << "Anh: " << diemAnh << endl;
    cout << "Tong diem: " << TongDiem() << endl;
}

double cCandidate::TongDiem(){
    return diemToan + diemVan + diemAnh;
}

void cListCandidate::Nhap(){
    cout << "Nhap so luong thi sinh: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "\nNhap thi sinh thu " << i+1 << ":\n";
        ds[i].Nhap();
    }
}

void cListCandidate::Xuat(){
    for(int i = 0; i < n; i++){
        cout << "\n===== Thi sinh " << i+1 << " =====\n";
        ds[i].Xuat();
    }
}

void cListCandidate::XuatLonHon15(){
    cout << "\n===== Thi sinh co tong diem > 15 =====\n";

    for(int i = 0; i < n; i++){
        if(ds[i].TongDiem() > 15){
            ds[i].Xuat();
            cout << endl;
        }
    }
}

cCandidate cListCandidate::TongDiemCaoNhat(){
    cCandidate max = ds[0];

    for(int i = 1; i < n; i++){
        if(ds[i].TongDiem() > max.TongDiem()){
            max = ds[i];
        }
    }

    return max;
}

void cListCandidate::SapXepGiamDan(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ds[i].TongDiem() < ds[j].TongDiem()){
                swap(ds[i], ds[j]);
            }
        }
    }
}