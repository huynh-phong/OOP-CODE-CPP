#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class cArray {
private:
    int *a;
    int n;

public:
    cArray() {
        n = 0;
        a = nullptr;
    }

    ~cArray() {
        delete[] a;
    }

    void nhap() {
        cout << "Nhap n: ";
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void xuat() {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    int demX(int x) {
        int dem = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == x) dem++;
        return dem;
    }

    bool tangDan() {
        for (int i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1]) return false;
        return true;
    }

    int leNhoNhat() {
        int min = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != 0) {
                if (min == -1 || a[i] < min)
                    min = a[i];
            }
        }
        return min;
    }

    void sapXepTang() {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j])
                    swap(a[i], a[j]);
    }
};

int main() {
    cArray arr;
    arr.nhap();
    arr.xuat();
}