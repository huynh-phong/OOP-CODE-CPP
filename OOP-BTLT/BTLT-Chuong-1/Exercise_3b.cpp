#include <iostream>
using namespace std;

int main() {
    int t1, m1, t2, m2;
    cout << "Nhap phan so 1: "; cin >> t1 >> m1;
    cout << "Nhap phan so 2: "; cin >> t2 >> m2;

    if (t1 * m2 > t2 * m1)
        cout << "Phan so lon hon: " << t1 << "/" << m1;
    else
        cout << "Phan so lon hon: " << t2 << "/" << m2;
}