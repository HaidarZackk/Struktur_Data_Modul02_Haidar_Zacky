#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int simpan = *z;
    *z = *y;
    *y = *x;
    *x = simpan;
}

void tukarReference(int &x, int &y, int &z) {
    int simpan = z;
    z = y;
    y = x;
    x = simpan;
}

void cetak(const char *keterangan, int a, int b, int c) {
    cout << keterangan << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    int a, b, c;
    cout << "Masukkan nilai a, b, c: ";
    cin >> a >> b >> c;

    int p1 = a, p2 = b, p3 = c;
    int r1 = a, r2 = b, r3 = c;

    cout << "\n=== Call by Pointer ===" << endl;
    cetak("Sebelum ditukar:", p1, p2, p3);
    tukarPointer(&p1, &p2, &p3);
    cetak("Sesudah ditukar :", p1, p2, p3);

    cout << "\n=== Call by Reference ===" << endl;
    cetak("Sebelum ditukar:", r1, r2, r3);
    tukarReference(r1, r2, r3);
    cetak("Sesudah ditukar :", r1, r2, r3);

    return 0;
}