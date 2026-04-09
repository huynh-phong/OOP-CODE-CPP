#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int tu, mau;
    cout << "Nhap tu so: "; cin >> tu;
    cout << "Nhap mau so: "; cin >> mau;

    int g = gcd(abs(tu), abs(mau));
    tu /= g;
    mau /= g;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }

    cout << "Phan so rut gon: " << tu << "/" << mau;
}