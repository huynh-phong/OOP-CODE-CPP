#include "CVector.h"

int main() {
    CVector v1, v2;

    cout << "Nhap vector thu 1:\n";
    cin >> v1;

    cout << "\nNhap vector thu 2:\n";
    cin >> v2;

    cout << "\nVector 1: ";
    cout << v1;

    cout << "\nVector 2: ";
    cout << v2;

    CVector tong = v1 + v2;
    CVector hieu = v1 - v2;

    cout << "\n\nTong 2 vector: ";
    cout << tong;

    cout << "\nHieu 2 vector: ";
    cout << hieu;

    cout << "\nTich vo huong: ";
    cout << v1 * v2;

    cout << "\n\nDo dai vector 1: ";
    cout << v1.DoDai();

    return 0;
}