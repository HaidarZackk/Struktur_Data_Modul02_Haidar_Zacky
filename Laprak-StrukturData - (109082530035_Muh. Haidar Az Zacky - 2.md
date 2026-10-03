# <h1 align="center">Modul 2  PENGENALAN BAHASA C++ (BAGIAN KEDUA) </h1>
<p align="center">Muh. Haidar Az Zacky - 109082530035</p>

## Dasar Teori

### A. Array

Array adalah struktur data yang menyimpan sekumpulan nilai bertipe sama di bawah satu nama variabel. Setiap nilai (elemen) dibedakan oleh nomor urutnya yang disebut indeks. Elemen-elemen array ditempatkan secara berurutan (kontigu) di memori, sehingga komputer dapat menghitung lokasi elemen ke-*i* langsung dari alamat awal array. Itulah sebabnya akses elemen lewat indeks berlangsung cepat [1][2]. Di C++ indeks selalu dimulai dari 0, sehingga array berukuran *n* memiliki indeks sah 0 sampai *n*−1. C++ tidak memeriksa batas indeks saat program berjalan, jadi mengakses indeks di luar rentang dapat menghasilkan perilaku yang tidak terdefinisi [3][5].

Berdasarkan jumlah indeksnya, array dibagi menjadi tiga bentuk:

1. **Array satu dimensi**, dideklarasikan `tipe_data nama[ukuran];`, misalnya `int nilai[10];`. Cocok untuk daftar data sejenis seperti kumpulan nilai ujian.
2. **Array dua dimensi**, dideklarasikan `tipe_data nama[baris][kolom];`. Bentuknya seperti tabel atau matriks sehingga dipakai untuk data berpola baris-kolom. Walau digambarkan sebagai tabel, di memori data tetap tersusun berurutan baris demi baris.
3. **Array berdimensi banyak**, yaitu array dengan tiga indeks atau lebih, misalnya `int data[4][6][6];`. Cara aksesnya sama, hanya jumlah indeksnya bertambah.

### B. Pointer dan Alamat Memori

Setiap variabel menempati satu atau beberapa sel memori (RAM), dan setiap sel memiliki nomor alamat yang unik. Operator `&` ("address-of") yang diletakkan di depan nama variabel menghasilkan alamat variabel tersebut. **Pointer** adalah variabel khusus yang isinya adalah alamat memori variabel lain. Pointer dideklarasikan dengan tanda `*`, misalnya `int *p;`, dan diisi dengan `p = &x;`. Operator `*` yang dipakai di depan pointer ("dereference") mengakses nilai yang berada pada alamat tersebut [3][5].

Karena pointer juga variabel, ia memiliki alamat sendiri dan menempati memori sendiri. Dengan demikian ada tiga hal berbeda yang dapat dicetak dari satu pointer `p`: `p` (alamat yang disimpan), `&p` (alamat pointer itu sendiri), dan `*p` (nilai yang ditunjuk). Memahami ketiganya adalah kunci untuk menghindari kekeliruan yang umum terjadi pada pemula [4].

### C. Pointer dan Array

Nama array pada banyak ekspresi diperlakukan sebagai alamat elemen pertamanya, sehingga `pa = a;` sama artinya dengan `pa = &a[0];`. Dari sini berlaku aritmetika pointer: `pa + i` adalah alamat elemen `a[i]`, dan `*(pa + i)` adalah nilai elemen tersebut. Penambahan `+ 1` pada pointer tidak menambah satu byte, melainkan satu elemen sesuai ukuran tipe datanya (misalnya 4 byte untuk `int`). Dengan kata lain `a[i]` pada dasarnya adalah penulisan yang lebih mudah dibaca dari `*(a + i)` [1][5].

### D. Pointer dan String

C++ mewarisi representasi string gaya C, yaitu array `char` yang diakhiri karakter null `'\0'` sebagai penanda akhir. Konsekuensinya, string literal `"strukdat"` yang terdiri atas 8 huruf membutuhkan 9 sel (8 huruf + `'\0'`). `cin >> nama` hanya membaca sampai spasi pertama; untuk membaca satu baris penuh digunakan `getline()`. Perbedaan penting perlu diingat: `char s[] = "abc";` membuat array yang isinya boleh diubah, sedangkan `char *p = "abc";` hanya membuat pointer yang menunjuk ke konstanta string sehingga mengubah isinya menghasilkan perilaku tidak terdefinisi [5].

### E. Fungsi dan Prosedur

Fungsi adalah blok kode bernama yang menjalankan satu tugas tertentu. Manfaat utamanya adalah memecah program besar menjadi bagian kecil (modular) dan menghindari penulisan kode berulang, sehingga program lebih mudah dibaca, diuji, dan dirawat [2][3]. Bentuk umumnya adalah `tipe_keluaran nama_fungsi(daftar_parameter) { ... }`.

Fungsi yang bertipe `void` tidak mengembalikan nilai dan biasa disebut **prosedur**. Perbedaannya praktis: fungsi dipanggil untuk *mendapatkan hasil* (misalnya `maks3()`), sedangkan prosedur dipanggil untuk *melakukan aksi* (misalnya mencetak baris). Fungsi harus dideklarasikan (prototype) atau didefinisikan sebelum dipanggil agar compiler mengenali nama dan tipe parameternya.

### F. Parameter Fungsi

**Parameter formal** adalah variabel yang tertulis di definisi fungsi, sedangkan **parameter aktual** (argumen) adalah nilai atau ekspresi yang dikirim saat fungsi dipanggil. Ada tiga cara melewatkan parameter:

| Cara | Penulisan | Yang diterima fungsi | Variabel asli berubah? |
|---|---|---|---|
| *Call by value* | `void f(int x)` | Salinan nilai | Tidak |
| *Call by pointer* | `void f(int *x)`, dipanggil `f(&a)` | Alamat variabel | Ya (lewat `*x`) |
| *Call by reference* | `void f(int &x)`, dipanggil `f(a)` | Alias (nama lain) variabel asli | Ya (langsung `x`) |

Pada *call by value*, perubahan hanya terjadi pada salinan sehingga pertukaran dua variabel gagal di luar fungsi. *Call by pointer* dan *call by reference* sama-sama bekerja pada variabel asli. Bedanya, pointer membutuhkan `&` saat memanggil dan `*` saat mengakses, serta dapat bernilai `nullptr`, sedangkan reference lebih ringkas dan tidak boleh kosong sehingga umumnya dianggap lebih aman [3][5]. Penelitian tentang kesulitan belajar pemrograman juga mencatat bahwa pemahaman tentang *reference* adalah salah satu sumber miskonsepsi yang sering dialami mahasiswa pemula, sehingga latihan menelusuri nilai variabel (tracing) sangat dianjurkan [4].

## Guided

### 1. Program Array 1

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 85;
    nilai[2] = 90;
    nilai[3] = 75;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << nilai[i] << endl;
    }

    return 0;
}
```

**Penjelasan.** Baris `int nilai[5];` meminta 5 sel `int` berurutan di memori dengan indeks 0 sampai 4. Kelima sel kemudian diisi satu per satu lewat penugasan `nilai[indeks] = angka`. Perulangan `for` dengan variabel `i` dari 0 hingga `i < 5` berfungsi sebagai "penunjuk" indeks: setiap putaran mencetak `nilai[i]` lalu pindah baris dengan `endl`. Syarat `i < 5` (bukan `i <= 5`) penting karena indeks 5 tidak ada; mengaksesnya berarti membaca memori di luar array.

**Hasil yang diharapkan:** lima baris, yaitu `80`, `85`, `90`, `75`, `95`. Program ini menunjukkan pola dasar array: *deklarasi -> isi -> telusuri dengan loop*.

### 2. Program Array 2

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
    {80, 85, 90},
    {75, 80, 85},
    {90, 95, 100}
};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Penjelasan.** Array `nilai[3][3]` adalah tabel 3 baris × 3 kolom yang langsung diberi nilai awal (inisialisasi) memakai kurung kurawal bersarang; tiap pasang kurung dalam mewakili satu baris. Untuk menampilkannya dipakai dua perulangan: `i` (loop luar) memilih baris, sedangkan `j` (loop dalam) menelusuri kolom pada baris tersebut. Setiap elemen dicetak diikuti spasi, dan `endl` di luar loop dalam dipanggil tiap satu baris selesai agar tampilan berbentuk matriks. Total ada 3 × 3 = 9 kali eksekusi `cout` untuk elemen.

**Hasil yang diharapkan:**
```
80 85 90
75 80 85
90 95 100
```

### 3. Program Array 3 (Array Tiga Dimensi)

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        }
    };

    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         for (int k = 0; k < 3; k++) {
    //             cout << data[1][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    cout << data[0][1][1] << " ";// 5

    return 0;
}
```

**Penjelasan.** Array `data[2][3][3]` adalah array tiga dimensi yang dapat dibayangkan sebagai **2 lembar tabel, masing-masing berukuran 3 baris × 3 kolom**. Indeks pertama (ukuran 2) memilih lembar, indeks kedua (ukuran 3) memilih baris, dan indeks ketiga (ukuran 3) memilih kolom. Jumlah elemennya 2 × 3 × 3 = 18. Pada inisialisasi, kurung kurawal terluar berisi dua blok (lembar 0 berisi nilai 1–9 dan lembar 1 berisi nilai 10–18), dan setiap blok berisi tiga baris `{...}` yang masing-masing memuat tiga nilai.

Baris `cout << data[0][1][1] << " ";` mengakses lembar ke-0, baris ke-1, kolom ke-1. Lembar 0 berisi baris `{1,2,3}`, `{4,5,6}`, `{7,8,9}`, sehingga baris ke-1 adalah `{4,5,6}` dan kolom ke-1 pada baris itu bernilai **5**, sesuai komentar `// 5` pada kode. Karena tidak memakai `endl`, hanya satu angka dan sebuah spasi yang tercetak.

Bagian perulangan tiga tingkat (`i`, `j`, `k`) yang diberi tanda `//` adalah **komentar**, sehingga tidak dieksekusi. Jika tanda komentarnya dihapus, loop tersebut akan mencetak seluruh isi lembar ke-1 dalam bentuk tabel 3×3 (10 11 12 / 13 14 15 / 16 17 18). Perhatikan bahwa pada kode itu variabel `i` tidak dipakai di dalam loop karena lembar yang ditampilkan tetap `data[1]`; agar semua lembar tercetak, `data[1]` perlu diganti menjadi `data[i]`. Pola ini menunjukkan aturan umum: array berdimensi *n* ditelusuri dengan *n* perulangan bersarang.

**Hasil yang diharapkan:** `5`

### 4. Program Array 4 (Array Empat Dimensi)

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][2][2] = {
        {
            {
                {1, 2},
                {3, 4}
            },
            {
                {5, 6},
                {7, 8}
            }
        },
        {
            {
                {9, 10},
                {11, 12}
            },
            {
                {13, 14},
                {15, 16}
            }
        }
    };

    cout << data[0][0][0][0] << endl; // 1
    cout << data[1][1][1][1] << endl; // 16

    return 0;
}
```

**Penjelasan.** `data[2][2][2][2]` adalah array empat dimensi dengan 2 × 2 × 2 × 2 = 16 elemen. Setiap tambahan dimensi berarti satu tingkat kurung kurawal baru pada inisialisasi dan satu indeks baru pada pengaksesan. Struktur kurungnya terbaca dari luar ke dalam: tingkat pertama memilih indeks pertama (dua blok besar), tingkat kedua memilih indeks kedua (dua kelompok di dalam tiap blok), tingkat ketiga memilih indeks ketiga (dua pasangan `{...}`), dan nilai paling dalam adalah indeks keempat. Nilai 1 sampai 16 terisi berurutan mengikuti urutan penulisan tersebut.

Dua perintah `cout` kemudian mengakses elemen paling awal dan paling akhir. `data[0][0][0][0]` adalah elemen pertama sehingga bernilai **1**, sedangkan `data[1][1][1][1]` adalah elemen terakhir sehingga bernilai **16**. Dibandingkan program Array 3, program ini menegaskan bahwa konsep array banyak dimensi sama saja berapa pun jumlah dimensinya; yang berubah hanya jumlah indeks yang harus ditulis.

**Hasil yang diharapkan:** `1` lalu `16` (masing-masing di baris sendiri).

### 5. Program Pointer 1

```C++
#include <iostream>
using namespace std;

int main() {
    char a;
    int j;
    char arr[6];

    arr[3] = 'b';
    a = 'u';

    cout << a << endl;
    cout << &a << endl;
    cout << j << endl;
    cout << &j << endl;

    cout << &(arr[4]) << endl;

    return 0;
    
}
```

**Penjelasan.** Program mendeklarasikan tiga variabel (`a` bertipe `char`, `j` bertipe `int`, dan array `arr` berisi 6 `char`), lalu hanya mengisi `a` dan `arr[3]`. Setiap baris `cout` memperlihatkan sisi berbeda dari sebuah variabel:

- `cout << a` mencetak **isi** variabel, yaitu karakter `u`.
- `cout << &a` mencetak **alamat** `a`. Namun `&a` bertipe `char*`, dan `cout` menganggap `char*` sebagai string gaya C sehingga ia mencetak karakter mulai dari alamat itu sampai bertemu `'\0'`. Hasilnya berupa `u` yang diikuti karakter acak. Untuk melihat alamat heksadesimalnya harus dilakukan *cast*, misalnya `cout << (void*)&a;`.
- `cout << j` mencetak isi `j` yang **belum diinisialisasi**, sehingga nilainya adalah *garbage value* (nilai sisa di memori) dan bisa berbeda tiap eksekusi.
- `cout << &j` mencetak alamat `j` dalam heksadesimal, karena `&j` bertipe `int*` yang oleh `cout` ditampilkan sebagai alamat.
- `cout << &(arr[4])` juga bertipe `char*`, sehingga yang tercetak adalah string yang dimulai dari `arr[4]`. Isi `arr[4]` belum ditetapkan, jadi keluarannya tidak dapat diprediksi.

Poin pembelajarannya: operator `&` mengambil alamat, dan perlakuan `cout` terhadap pointer bergantung pada tipenya. Selain itu, variabel lokal yang tidak diisi nilai awal berbahaya karena isinya tidak pasti [3][5].

### 6. Program Pointer 2

```C++
#include <iostream>
using namespace std;

int main() {
    int x, y;
    int *px;

    x = 87;
    px = &x;
    y = *px;

    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;

    return 0;
}
```

**Penjelasan.** Alur eksekusinya bertahap: (1) `x = 87;` menyimpan 87 ke variabel `x`. (2) `px = &x;` mengisi pointer `px` dengan alamat `x`, sehingga kini `px` "menunjuk" ke `x`. (3) `y = *px;` melakukan *dereference*, yaitu mengambil nilai di alamat yang disimpan `px` (87) lalu menyalinnya ke `y`. Karena `y` hanya menerima salinan nilai, `y` adalah variabel yang berdiri sendiri dan tidak lagi terhubung ke `x`.

Pada keluaran, baris pertama dan kedua akan menampilkan **alamat yang sama** (misalnya `0x7ffe...`), karena isi `px` memang alamat `x`. Tiga baris lainnya menampilkan `87`. Nilai alamat tidak tetap karena sistem operasi menentukan lokasi memori setiap program dijalankan.

### 7. Program Pointer 3

```C++
#include <iostream>
#define MAX 5
using namespace std;

int main() {
    int i, j;
    float nilai_total, rata_rata;
    float nilai[MAX];

    static int nilai_tahun[MAX][MAX] = {
        {0, 2, 2, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 3, 3, 3, 0},
        {4, 4, 0, 0, 4},
        {5, 0, 0, 0, 5}
    };

    for (i = 0; i < MAX; i++) {
        cout << "masukkan nilai ke-" << i + 1 << endl;
        cin >> nilai[i];
    }

    cout << "\ndata nilai siswa :\n";

    for (i = 0; i < MAX; i++)
        cout << "nilai k-" << i + 1 << "=" << nilai[i] << endl;

    cout << "\n nilai tahunan : \n";

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << nilai_tahun[i][j];
        cout << "\n";
    }

    return 0;
}
```

**Penjelasan.** Program menggabungkan array satu dan dua dimensi dengan ukuran ditentukan oleh konstanta makro `MAX` bernilai 5. Dengan memakai `MAX`, ukuran array cukup diubah di satu tempat. Bagian pertama membaca 5 bilangan `float` dari keyboard ke `nilai[]` memakai `cin` di dalam loop; teks "masukkan nilai ke-" memakai `i + 1` supaya pengguna melihat penomoran mulai dari 1, walau indeks array dimulai dari 0. Bagian kedua mencetak ulang data tersebut. Bagian ketiga mencetak `nilai_tahun[5][5]` memakai loop bersarang; array ini dideklarasikan `static` dan sudah diisi nilai awal, sehingga membentuk pola angka berupa matriks 5×5. Variabel `nilai_total` dan `rata_rata` dideklarasikan tetapi belum dipakai pada program ini (compiler dapat memberi peringatan *unused variable*, namun program tetap berjalan).

**Hasil bagian terakhir:**
```
02200
01110
03330
44004
50005
```

### 8. Program Pointer 4

```C++
#include <iostream>
using namespace std;

int main() {
    char nama[] = "strukdat";

    cout << nama << endl;
    cout << nama[3] << endl;

    return 0;
}
```

**Penjelasan.** `char nama[] = "strukdat";` membuat array karakter yang ukurannya ditentukan otomatis oleh compiler, yaitu 9 elemen (8 huruf ditambah `'\0'`). `cout << nama` mencetak seluruh string karena untuk array `char`, `cout` membaca karakter dari awal sampai menemui `'\0'`. Sementara `nama[3]` hanya mengakses satu karakter pada indeks 3. Dengan indeks dari nol (s=0, t=1, r=2, u=3), karakter yang tercetak adalah `u`.

**Hasil yang diharapkan:** `strukdat` lalu `u`.

### 9. Program Fungsi

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c);

int main() {
    int x, y, z;
    cout << "masukkan nilai bilangan ke-1 = ";
    cin >> x;
    cout << "masukkan nilai bilangan ke-2 =";
    cin >> y;
    cout << "masukkan nilai bilangan ke-3 =";
    cin >> z;
    cout << "nilai maksimumnya adalah = " << maks3(x, y, z);
    return 0;
}

int maks3(int a, int b, int c) {
    int temp_max = a;
    if (b > temp_max)
        temp_max = b;
    if (c > temp_max)
        temp_max = c;
    return (temp_max);
}
```

**Penjelasan.** Baris `int maks3(int a, int b, int c);` di bagian atas adalah *prototype*, yaitu pemberitahuan kepada compiler bahwa fungsi `maks3` ada dan menerima tiga `int`, sehingga fungsi boleh dipanggil di `main()` sebelum definisinya ditulis. Di dalam fungsi, algoritmanya adalah pencarian maksimum sederhana: anggap `a` yang terbesar (`temp_max = a`), bandingkan dengan `b`, lalu dengan `c`, dan perbarui `temp_max` setiap kali ditemukan nilai yang lebih besar. Nilai akhirnya dikembalikan dengan `return`. Pada pemanggilan `maks3(x, y, z)`, `x, y, z` adalah parameter aktual sedangkan `a, b, c` adalah parameter formal; nilai disalin (*call by value*), jadi `x, y, z` di `main()` tidak berubah.

**Contoh:** masukan `4`, `9`, `6` menghasilkan `nilai maksimumnya adalah = 9`.

### 10. Program Procedure

```C++
#include <iostream>
using namespace std;

void tulis(int x);

int main() {
    int jum;
    cout << "jumlah baris kata = ";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x) {
    for (int i = 0; i < x; i++)
        cout << "baris ke-" << i + 1 << endl;
}
```

**Penjelasan.** `tulis` bertipe `void` sehingga merupakan prosedur: ia melakukan pekerjaan (mencetak teks) tetapi tidak mengembalikan nilai, dan itu sebabnya pemanggilannya `tulis(jum);` berdiri sendiri sebagai satu pernyataan tanpa menampung hasil. Parameter `x` menerima salinan nilai `jum`. Perulangan `for` berjalan sebanyak `x` kali dan mencetak `baris ke-` diikuti `i + 1`, sehingga penomoran tampil mulai dari 1 walaupun `i` dimulai dari 0. Memisahkan pencetakan ke dalam prosedur membuat `main()` lebih ringkas dan prosedur dapat dipakai ulang.

**Contoh:** masukan `3` menghasilkan `baris ke-1`, `baris ke-2`, `baris ke-3`.

## Unguided

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
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
```

### Output Unguided 1 :

##### Output 1
![Output_1-1](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_1/Output-Unguided1-1.png)
![Output_1-2](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_1/Output-Unguided1-2.png)
![Output_1-3](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_1/Output-Unguided1-3.png)
![Output_1-4](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_1/Output-Unguided1-4.png)

**Penjelasan.** Pada program ini setiap pekerjaan dipisah menjadi prosedur sendiri sehingga `main()` hanya mengatur urutan langkahnya: `isiMatriks()` untuk input, `jumlahMatriks()`, `kurangMatriks()`, dan `kaliMatriks()` untuk perhitungan, serta `tampilMatriks()` untuk output. Ukuran matriks disimpan pada konstanta `N = 3`, sehingga ukuran bisa diubah tanpa menyunting banyak baris. Array dikirim ke prosedur sebagai parameter; di C++ array selalu dikirim berupa alamat, bukan salinan, sehingga ketika `jumlahMatriks()` mengisi `hasil[i][j]`, array `hasilTambah` di `main()` ikut terisi. Parameter masukan diberi kata kunci `const` agar prosedur tidak sengaja mengubah matriks A dan B.

- **Penjumlahan dan pengurangan** dilakukan elemen demi elemen: `hasil[i][j] = a[i][j] ± b[i][j]`, dengan dua loop bersarang (baris dan kolom).
- **Perkalian** menggunakan aturan perkalian matriks: elemen `hasil[i][j]` adalah jumlah dari perkalian baris ke-*i* matriks A dengan kolom ke-*j* matriks B. Karena itu dibutuhkan loop ketiga (`k`) yang menjumlahkan `a[i][k] * b[k][j]` ke dalam variabel `total`. Variabel `total` dibuat ulang bernilai 0 untuk setiap elemen hasil agar hasil perhitungan sebelumnya tidak ikut terjumlahkan.
- Tidak seperti penjumlahan, perkalian matriks **tidak bersifat komutatif** (A×B umumnya berbeda dari B×A).

**Contoh pengujian.** Dengan A = [[1,2,3],[4,5,6],[7,8,9]] dan B = [[9,8,7],[6,5,4],[3,2,1]]:

| Operasi | Baris 1 | Baris 2 | Baris 3 |
|---|---|---|---|
| A + B | 10 10 10 | 10 10 10 | 10 10 10 |
| A − B | −8 −6 −4 | −2 0 2 | 4 6 8 |
| A × B | 30 24 18 | 84 69 54 | 138 114 90 |

Contoh perhitungan elemen pertama perkalian: (1×9) + (2×6) + (3×3) = 9 + 12 + 9 = 30.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
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
```

### Output Unguided 2 :

##### Output 2
![Output_2-1](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_2/Output-Unguided2-1.png)

**Penjelasan.** Soal meminta dua versi: berbasis pointer dan berbasis reference, masing-masing untuk tiga variabel. Karena dua variabel saja hanya butuh satu penyimpanan sementara, tiga variabel diselesaikan dengan pola **rotasi ke kanan**: nilai `z` disimpan dulu ke `simpan`, lalu `z` diisi nilai `y`, `y` diisi nilai `x`, dan terakhir `x` diisi nilai `simpan` (nilai `z` semula). Urutan penugasan ini harus dari belakang ke depan; jika dibalik, nilai pertama tertimpa sebelum sempat disalin.

- **`tukarPointer(int *x, int *y, int *z)`** menerima alamat variabel, dipanggil dengan `tukarPointer(&p1, &p2, &p3)`. Seluruh akses nilai memakai `*` (dereference), sehingga yang berubah adalah variabel asli di `main()`.
- **`tukarReference(int &x, int &y, int &z)`** menerima alias dari variabel asli. Parameter `x, y, z` diperlakukan seperti variabel biasa dan dipanggil cukup dengan `tukarReference(r1, r2, r3)`; hasil akhirnya identik dengan versi pointer namun sintaksnya lebih sederhana.
- Nilai awal disalin ke dua kelompok variabel (`p1..p3` dan `r1..r3`) supaya kedua metode diuji dari kondisi awal yang sama dan hasilnya dapat dibandingkan langsung.

**Contoh pengujian.** Masukan `10 20 30` menghasilkan `a = 30, b = 10, c = 20` pada kedua metode. Kesamaan hasil ini membuktikan bahwa *call by pointer* dan *call by reference* sama-sama mampu mengubah variabel di luar fungsi, tidak seperti *call by value*.

### 3. Program menu array (cariMinimum, cariMaksimum, hitungRataRata)

```C++
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
```

### Output Unguided 3 :

##### Output 3
![Output_3-1](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_3/Output-Unguided3-1.png)
![Output_3-2](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_3/Output-Unguided3-2.png)
![Output_3-3](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_3/Output-Unguided3-3.png)
![Output_3-4](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_3/Output-Unguided3-4.png)
![Output_3-5](https://github.com/HaidarZackk/Struktur_Data_Modul02_Haidar_Zacky/blob/main/SS_SOAL_3/Output-Unguided3-5.png)

**Penjelasan.** Program ini mengolah array `arrA` yang berisi 10 bilangan. Setiap tugas dipisahkan sesuai ketentuan soal: dua *function* yang mengembalikan nilai (`cariMinimum()` dan `cariMaksimum()`) dan satu *procedure* bertipe `void` (`hitungRataRata()`) yang langsung mencetak hasilnya. Satu prosedur tambahan, `tampilArray()`, dibuat untuk menu nomor 1.

- **`cariMaksimum()` dan `cariMinimum()`** memakai teknik pencarian linear (*sequential scan*). Elemen pertama dijadikan kandidat awal, kemudian loop dari indeks 1 membandingkan tiap elemen dengan kandidat dan menggantinya bila ditemukan yang lebih besar (untuk maksimum) atau lebih kecil (untuk minimum). Seluruh elemen diperiksa tepat sekali sehingga waktu prosesnya sebanding dengan jumlah data. Hasilnya dikembalikan lewat `return`.
- **`hitungRataRata()`** menjumlahkan semua elemen ke `total` (214), lalu membaginya dengan jumlah elemen. Agar pembagian tidak dibulatkan menjadi bilangan bulat, `total` diubah dulu menjadi `double` dengan `static_cast<double>`. Hasil ditampilkan dengan dua angka desimal memakai `fixed` dan `setprecision(2)`.
- **Parameter `const int data[]`** menegaskan bahwa fungsi hanya membaca array, dan jumlah elemen `n` dikirim terpisah karena array yang dikirim ke fungsi hanya berupa alamat awal sehingga ukurannya tidak ikut terbawa.
- **`switch-case`** memilih aksi sesuai nomor menu, dan `default` menangani masukan di luar pilihan. Perulangan `while (pilihan != 0)` membuat menu tampil berulang sampai pengguna memilih `0` untuk keluar.

**Hasil yang diharapkan** untuk `arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}`:

| Menu | Hasil |
|---|---|
| 1 | `11, 8, 5, 7, 12, 26, 3, 54, 33, 55` |
| 2 | Nilai maksimum = 55 |
| 3 | Nilai minimum = 3 |
| 4 | Jumlah = 214, rata-rata = 21.40 |

## Kesimpulan

Praktikum Modul 2 memperlihatkan bahwa kemampuan C++ dalam mengelola data bertumpu pada dua hal: cara data disusun di memori dan cara kode dikelompokkan menjadi unit-unit kecil.

Dari sisi data, array menyimpan elemen sejenis secara berurutan sehingga dapat diakses cepat melalui indeks, baik pada satu dimensi (daftar), dua dimensi (tabel atau matriks), maupun lebih. Praktik membuat operasi matriks 3×3 menunjukkan bahwa pengolahan array dua dimensi hampir selalu membutuhkan loop bersarang, dan perkalian matriks membutuhkan satu tingkat loop tambahan. Pointer melengkapi gambaran ini dengan membuka akses ke alamat tempat data berada: `&` mengambil alamat dan `*` mengambil nilai, sementara string ternyata hanya array karakter yang ditutup `'\0'`. Contoh pada Pointer 1 juga memberi pelajaran bahwa variabel yang belum diinisialisasi berisi nilai acak, dan `cout` memperlakukan `char*` sebagai string, bukan sebagai alamat.

Dari sisi struktur program, fungsi dan prosedur membuat program lebih modular dan mudah diuji. Fungsi digunakan bila diperlukan nilai balik (`cariMaksimum`, `cariMinimum`), sedangkan prosedur cukup bila yang dibutuhkan hanya aksi atau tampilan (`hitungRataRata`, `tulis`). Pada pelewatan parameter, *call by value* hanya menyalin nilai sehingga tidak dapat mengubah variabel pemanggil; sebaliknya *call by pointer* dan *call by reference* dapat melakukannya, sebagaimana terbukti pada penukaran tiga variabel yang memberi hasil sama pada kedua metode. Dalam penggunaan sehari-hari, *reference* terasa lebih ringkas dan lebih aman, sedangkan pointer tetap penting karena merupakan dasar bagi struktur data dinamis yang akan dipelajari pada modul berikutnya.

## Referensi

[1] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). *Data Structures and Algorithms in C++* (2nd ed.). Hoboken, NJ: John Wiley & Sons. ISBN 978-0-470-38327-8.
<br>[2] Patil, V. H. (2012). *Data Structures Using C++*. New Delhi: Oxford University Press. ISBN 978-0-19-806623-1.
<br>[3] Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Upper Saddle River, NJ: Addison-Wesley.
<br>[4] Qian, Y., & Lehman, J. (2017). Students' Misconceptions and Other Difficulties in Introductory Programming: A Literature Review. *ACM Transactions on Computing Education, 18*(1), Article 1, 1–24. https://doi.org/10.1145/3077618
<br>[5] Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C++* (4th ed.). Boston: Pearson.
