#include "CMatrix.h"

CMatrix::CMatrix() {
    dong = cot = 0;
    a = NULL;
}

CMatrix::CMatrix(int dong, int cot) {
    this->dong = dong;
    this->cot = cot;

    a = new float*[dong];

    for (int i = 0; i < dong; i++) {
        a[i] = new float[cot];

        for (int j = 0; j < cot; j++) {
            a[i][j] = 0;
        }
    }
}

CMatrix::CMatrix(const CMatrix& mt) {
    dong = mt.dong;
    cot = mt.cot;

    a = new float*[dong];

    for (int i = 0; i < dong; i++) {
        a[i] = new float[cot];

        for (int j = 0; j < cot; j++) {
            a[i][j] = mt.a[i][j];
        }
    }
}

CMatrix::~CMatrix() {
    for (int i = 0; i < dong; i++) {
        delete[] a[i];
    }

    delete[] a;
}

void CMatrix::Nhap() {
    cout << "Nhap so dong: ";
    cin >> dong;

    cout << "Nhap so cot: ";
    cin >> cot;

    a = new float*[dong];

    for (int i = 0; i < dong; i++) {
        a[i] = new float[cot];

        for (int j = 0; j < cot; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void CMatrix::Xuat() const {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            cout << a[i][j] << "\t";
        }

        cout << endl;
    }
}

CMatrix CMatrix::operator+(const CMatrix& mt) const {
    CMatrix kq(dong, cot);

    if (dong != mt.dong || cot != mt.cot) {
        cout << "Khong cung kich thuoc!\n";
        return kq;
    }

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            kq.a[i][j] = a[i][j] + mt.a[i][j];
        }
    }

    return kq;
}

CMatrix CMatrix::operator-(const CMatrix& mt) const {
    CMatrix kq(dong, cot);

    if (dong != mt.dong || cot != mt.cot) {
        cout << "Khong cung kich thuoc!\n";
        return kq;
    }

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            kq.a[i][j] = a[i][j] - mt.a[i][j];
        }
    }

    return kq;
}

CMatrix CMatrix::operator*(const CMatrix& mt) const {
    if (cot != mt.dong) {
        cout << "Khong nhan duoc!\n";
        return CMatrix();
    }

    CMatrix kq(dong, mt.cot);

    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < mt.cot; j++) {

            float tong = 0;

            for (int k = 0; k < cot; k++) {
                tong += a[i][k] * mt.a[k][j];
            }

            kq.a[i][j] = tong;
        }
    }

    return kq;
}

float* CMatrix::NhanVector(float v[]) const {
    float* kq = new float[dong];

    for (int i = 0; i < dong; i++) {

        kq[i] = 0;

        for (int j = 0; j < cot; j++) {
            kq[i] += a[i][j] * v[j];
        }
    }

    return kq;
}

istream& operator>>(istream& in, CMatrix& mt) {
    mt.Nhap();
    return in;
}

ostream& operator<<(ostream& out, const CMatrix& mt) {
    mt.Xuat();
    return out;
}