#include <iostream>
#include "Nhanvien.h"

using namespace std;

int main(){
    int n;
    cout<<"** Nhap So Luong Nhan Vien **"<<endl;
    cin>>n;

    NHANVIEN* ds[100];
    for(int i=0;i<n;i++){
    int loai;
    cout<<"** Nhan Vien Thu "<<i+1<<" **"<<endl;
    cout<<"Loai 1: Nhan Vien Van Phong"<<endl;
    cout<<"Loai 2: Nhan Vien San Xuat"<<endl;
    cout<<"Loai 3: Nhan Vien Quan Ly"<<endl;
    cout<<"Chon Loai: "; cin>>loai;
    if (loai == 1)
            ds[i] = new NHANVIENVP();
        else if (loai == 2)
            ds[i] = new NHANVIENSX();
        else
            ds[i] = new NHANVIENQL();

        ds[i]->Nhap();
    }

    cout<<"** DANH SACH NHAN VIEN **"<<endl;
    for(int i=0; i<n; i++){
        cout<<endl<<"** Nhan Vien "<<i+1<<": ";
        ds[i]->Xuat();
    }

    double TongLuong = 0;
    for(int i=0;i<n;i++){
        TongLuong += ds[i]->TinhLuong();
    }
    cout<<endl<<"Tong Luong Cong Ty La: "<<TongLuong<<endl;

    string TimNV;
    cin.ignore();
    cout<<"Nhap Ho Ten Nhan Vien Can Tim: ";
    getline(cin,TimNV);
    bool TimThay = false;

    for(int i=0;i<n;i++)
    if(ds[i]->getHoTen() == TimNV){
    cout<<endl<<"Thong Tin Nhan Vien Can Tim"<<endl;
    ds[i]->Xuat();
    TimThay = true;
    }
    if(!TimThay) cout<<"Khong Tim Thay Nhan Vien!";

    return 0;
}