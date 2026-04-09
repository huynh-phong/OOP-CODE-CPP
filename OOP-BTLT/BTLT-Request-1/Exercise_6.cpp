#include <iostream>
using namespace std;

class SoPhuc {
private:
    float phanThuc;
    float phanAo;

public:
    SoPhuc(float thuc = 0, float ao = 0) {
        phanThuc = thuc;
        phanAo = ao;
    }

    void setPhanThuc(float thuc) {
        phanThuc = thuc;
    }

    void setPhanAo(float ao) {
        phanAo = ao;
    }

    float getPhanThuc() {
        return phanThuc;
    }

    float getPhanAo() {
        return phanAo;
    }

    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> phanThuc;
        cout << "Nhap phan ao: ";
        cin >> phanAo;
    }

    void xuat() {
        if (phanAo >= 0)
            cout << phanThuc << " + " << phanAo << "i";
        else
            cout << phanThuc << " - " << -phanAo << "i";
    }

    SoPhuc cong(SoPhuc b) {
        SoPhuc kq;
        kq.phanThuc = phanThuc + b.phanThuc;
        kq.phanAo = phanAo + b.phanAo;
        return kq;
    }

    SoPhuc tru(SoPhuc b) {
        SoPhuc kq;
        kq.phanThuc = phanThuc - b.phanThuc;
        kq.phanAo = phanAo - b.phanAo;
        return kq;
    }

    SoPhuc nhan(SoPhuc b) {
        SoPhuc kq;
        kq.phanThuc = phanThuc * b.phanThuc - phanAo * b.phanAo;
        kq.phanAo = phanThuc * b.phanAo + phanAo * b.phanThuc;
        return kq;
    }

    SoPhuc chia(SoPhuc b) {
        SoPhuc kq;
        float mau = b.phanThuc * b.phanThuc + b.phanAo * b.phanAo;

        kq.phanThuc = (phanThuc * b.phanThuc + phanAo * b.phanAo) / mau;
        kq.phanAo = (phanAo * b.phanThuc - phanThuc * b.phanAo) / mau;

        return kq;
    }
};

int main() {
    SoPhuc a, b, tong, hieu, tich, thuong;

    cout << "Nhap so phuc A:\n";
    a.nhap();

    cout << "\nNhap so phuc B:\n";
    b.nhap();

    cout << "\nSo phuc A = ";
    a.xuat();

    cout << "\nSo phuc B = ";
    b.xuat();

    tong = a.cong(b);
    hieu = a.tru(b);
    tich = a.nhan(b);

    cout << "\n\nA + B = ";
    tong.xuat();

    cout << "\nA - B = ";
    hieu.xuat();

    cout << "\nA * B = ";
    tich.xuat();

    if (b.getPhanThuc() == 0 && b.getPhanAo() == 0) {
        cout << "\nA / B: Khong hop le!";
    } else {
        thuong = a.chia(b);
        cout << "\nA / B = ";
        thuong.xuat();
    }

    cout << endl;
    return 0;
}
