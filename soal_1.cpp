#include <iostream>
using namespace std;

const int N = 3;

void isiMatriks(int m[N][N], char nama) {
    cout << "Masukkan elemen matriks " << nama << " (" << N << "x" << N << "):" << endl;
    for (int baris = 0; baris < N; baris++) {
        for (int kolom = 0; kolom < N; kolom++) {
            cout << nama << "[" << baris << "][" << kolom << "] = ";
            cin >> m[baris][kolom];
        }
    }
}

void tampilMatriks(const int m[N][N], const char *judul) {
    cout << "\n" << judul << endl;
    for (int baris = 0; baris < N; baris++) {
        for (int kolom = 0; kolom < N; kolom++) {
            cout << m[baris][kolom] << "\t";
        }
        cout << endl;
    }
}

void jumlahMatriks(const int a[N][N], const int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = a[i][j] + b[i][j];
}

void kurangMatriks(const int a[N][N], const int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            hasil[i][j] = a[i][j] - b[i][j];
}

void kaliMatriks(const int a[N][N], const int b[N][N], int hasil[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int total = 0;
            for (int k = 0; k < N; k++) {
                total += a[i][k] * b[k][j];
            }
            hasil[i][j] = total;
        }
    }
}

int main() {
    int A[N][N], B[N][N];
    int hasilTambah[N][N], hasilKurang[N][N], hasilKali[N][N];

    isiMatriks(A, 'A');
    cout << endl;
    isiMatriks(B, 'B');

    jumlahMatriks(A, B, hasilTambah);
    kurangMatriks(A, B, hasilKurang);
    kaliMatriks(A, B, hasilKali);

    tampilMatriks(A, "Matriks A:");
    tampilMatriks(B, "Matriks B:");
    tampilMatriks(hasilTambah, "Hasil A + B:");
    tampilMatriks(hasilKurang, "Hasil A - B:");
    tampilMatriks(hasilKali, "Hasil A x B:");

    return 0;
}