#include <iostream>
#include <iomanip>
using namespace std;

const int UKURAN = 10;

int cariMinimum(const int data[], int n) {
    int terkecil = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < terkecil) {
            terkecil = data[i];
        }
    }
    return terkecil;
}

int cariMaksimum(const int data[], int n) {
    int terbesar = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > terbesar) {
            terbesar = data[i];
        }
    }
    return terbesar;
}

void hitungRataRata(const int data[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += data[i];
    }
    double rata = static_cast<double>(total) / n;
    cout << "Jumlah seluruh elemen = " << total << endl;
    cout << "Nilai rata-rata       = " << fixed << setprecision(2) << rata << endl;
}

void tampilArray(const int data[], int n) {
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << (i < n - 1 ? ", " : "");
    }
    cout << endl;
}

int main() {
    int arrA[UKURAN] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int pilihan = -1;

    while (pilihan != 0) {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                tampilArray(arrA, UKURAN);
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA, UKURAN) << endl;
                break;
            case 3:
                cout << "Nilai minimum  = " << cariMinimum(arrA, UKURAN) << endl;
                break;
            case 4:
                hitungRataRata(arrA, UKURAN);
                break;
            case 0:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    }
    return 0;
}