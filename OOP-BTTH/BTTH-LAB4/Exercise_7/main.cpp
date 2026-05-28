#include "CMatrix.h"

int main() {
    CMatrix A, B;

    cout << "Nhap ma tran A:\n";
    cin >> A;

    cout << "\nNhap ma tran B:\n";
    cin >> B;

    cout << "\nMa tran A:\n";
    cout << A;

    cout << "\nMa tran B:\n";
    cout << B;

    CMatrix tong = A + B;
    CMatrix hieu = A - B;
    CMatrix tich = A * B;

    cout << "\nTong hai ma tran:\n";
    cout << tong;

    cout << "\nHieu hai ma tran:\n";
    cout << hieu;

    cout << "\nTich hai ma tran:\n";
    cout << tich;

    int n;

    cout << "\nNhap so phan tu vector: ";
    cin >> n;

    float* v = new float[n];

    cout << "Nhap vector:\n";

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    float* kq = A.NhanVector(v);

    cout << "\nKet qua ma tran * vector:\n";

    for (int i = 0; i < n; i++) {
        cout << kq[i] << " ";
    }

    delete[] v;
    delete[] kq;

    return 0;
}