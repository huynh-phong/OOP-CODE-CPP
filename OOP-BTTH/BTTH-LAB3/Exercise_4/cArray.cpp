#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include "cArray.h"

using namespace std;

bool LaSoNguyenTo(int x){
    if(x < 2) return false;

    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0)
            return false;
    }

    return true;
}

void cArray::TaoMangNgauNhien(){
    srand(time(0));

    cout << "Nhap so luong phan tu: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        a[i] = rand() % 100 + 1;
    }
}

void cArray::Xuat(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int cArray::DemX(int x){
    int dem = 0;

    for(int i = 0; i < n; i++){
        if(a[i] == x)
            dem++;
    }

    return dem;
}

bool cArray::KiemTraTangDan(){
    for(int i = 0; i < n - 1; i++){
        if(a[i] > a[i+1])
            return false;
    }

    return true;
}

int cArray::TimLeNhoNhat(){
    int minLe = -1;

    for(int i = 0; i < n; i++){
        if(a[i] % 2 != 0){
            if(minLe == -1 || a[i] < minLe)
                minLe = a[i];
        }
    }

    return minLe;
}

int cArray::TimSoNguyenToLonNhat(){
    int maxNT = -1;

    for(int i = 0; i < n; i++){
        if(LaSoNguyenTo(a[i]) && a[i] > maxNT)
            maxNT = a[i];
    }

    return maxNT;
}

void cArray::SapXepTangDan(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

void cArray::SapXepGiamDan(){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j])
                swap(a[i], a[j]);
        }
    }
}