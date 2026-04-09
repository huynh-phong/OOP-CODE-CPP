#include <iostream>
using namespace std;

int main() {
    int t1, m1, t2, m2;
    cout << "Nhap phan so 1: "; cin >> t1 >> m1;
    cout << "Nhap phan so 2: "; cin >> t2 >> m2;

    cout << "Tong: " << t1*m2 + t2*m1 << "/" << m1*m2 << endl;
    cout << "Hieu: " << t1*m2 - t2*m1 << "/" << m1*m2 << endl;
    cout << "Tich: " << t1*t2 << "/" << m1*m2 << endl;
    cout << "Thuong: " << t1*m2 << "/" << m1*t2 << endl;
}