#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc, ao;

public:
    SoPhuc(double t = 0, double a = 0) {
        thuc = t;
        ao = a;
    }

    SoPhuc operator+(SoPhuc b) {
        return SoPhuc(thuc + b.thuc, ao + b.ao);
    }

    SoPhuc operator-(SoPhuc b) {
        return SoPhuc(thuc - b.thuc, ao - b.ao);
    }

    SoPhuc operator*(SoPhuc b) {
        return SoPhuc(thuc * b.thuc - ao * b.ao,
                      thuc * b.ao + ao * b.thuc);
    }

    SoPhuc operator/(SoPhuc b) {
        double mau = b.thuc * b.thuc + b.ao * b.ao;
        return SoPhuc((thuc * b.thuc + ao * b.ao) / mau,
                      (ao * b.thuc - thuc * b.ao) / mau);
    }

    bool operator==(SoPhuc b) {
        return thuc == b.thuc && ao == b.ao;
    }

    friend istream& operator>>(istream& in, SoPhuc& x) {
        in >> x.thuc >> x.ao;
        return in;
    }

    friend ostream& operator<<(ostream& out, SoPhuc x) {
        out << x.thuc;
        if (x.ao >= 0) out << "+";
        out << x.ao << "i";
        return out;
    }
};

int main() {
    SoPhuc a, b;
    cin >> a >> b;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;

    return 0;
}