# BIG CHALLENGE SDA 2025
## Menentukan 100 Kata Paling Sering dan Paling Jarang Menggunakan Heap

### Anggota Kelompok
- Nama :Ahmad Wazir Sahfikri (250810701100050)
- Nama :Rafa

---

## Deskripsi Program

Program ini dibuat untuk memenuhi tugas Big Challenge mata kuliah Struktur Data dan Algoritma.

Program bertujuan untuk menentukan:

1. 100 kata yang paling sering muncul dalam dokumen.
2. 100 kata yang paling jarang muncul dalam dokumen.

Data yang digunakan berasal dari dataset Bag of Words UCI Machine Learning Repository yang terdiri dari file:

- docword.*.txt
- vocab.*.txt

Program menghitung total frekuensi setiap kata, kemudian menggunakan struktur data Heap untuk memperoleh 100 kata dengan frekuensi terbesar dan terkecil secara efisien.

---

## Struktur Data yang Digunakan

### 1. Array

Digunakan untuk menyimpan seluruh data kata dan frekuensinya.

```c
typedef struct
{
    char word[100];
    long long frequency;
} WordFreq;
```

### 2. Min Heap

Digunakan untuk mencari 100 kata yang paling sering muncul.

Root heap selalu menyimpan frekuensi terkecil dari 100 kata terbesar yang sedang dipertahankan.

### 3. Max Heap

Digunakan untuk mencari 100 kata yang paling jarang muncul.

Root heap selalu menyimpan frekuensi terbesar dari 100 kata terkecil yang sedang dipertahankan.

---

## Algoritma yang Digunakan

### Heap

Digunakan untuk menentukan:

- 100 kata paling sering
- 100 kata paling jarang

Kompleksitas:

O(W log K)

Keterangan:

W = jumlah kata unik

K = jumlah kata yang dicari (100)

### Heap Sort

Digunakan untuk mengurutkan hasil heap sebelum ditampilkan dan disimpan ke file.

Kompleksitas:

O(n log n)

### Insertion Sort

Disediakan sebagai algoritma pengurutan sederhana sesuai materi perkuliahan.

Kompleksitas:

Best Case  : O(n)

Average    : O(n²)

Worst Case : O(n²)

---

## Cara Kerja Program

### Langkah 1

Membaca file vocabulary dan menyimpan seluruh kata ke dalam array.

### Langkah 2

Membaca file docword dan menghitung total frekuensi setiap kata berdasarkan wordID.

Contoh data:

1 61 2
1 76 1
2 61 5

Format:

docID wordID count

Program akan menjumlahkan seluruh frekuensi kata yang memiliki wordID yang sama.

### Langkah 3

Membangun Min Heap ukuran 100 untuk memperoleh kata yang paling sering muncul.

### Langkah 4

Membangun Max Heap ukuran 100 untuk memperoleh kata yang paling jarang muncul.

### Langkah 5

Melakukan Heap Sort terhadap hasil heap.

### Langkah 6

Menyimpan hasil ke file:

- most_frequent.txt
- least_frequent.txt

### Langkah 7

Menampilkan hasil dan waktu proses ke layar monitor.

---

## Menu Program

1. 100 kata paling sering

2. 100 kata paling jarang

3. Tampilkan kata paling sering

4. Tampilkan kata paling jarang

5. Keluar

---

## Struktur File

project/

├── main.c

├── file_handler.c

├── file_handler.h

├── heap.c

├── heap.h

├── sort.c

├── sort.h

├── word.h

├── vocab.kos.txt

├── docword.kos.txt

├── most_frequent.txt

├── least_frequent.txt

└── README.md

---

## Cara Compile

Linux / MacOS

gcc main.c file_handler.c heap.c sort.c -o bigchallenge

Jalankan:

./bigchallenge

Windows (MinGW)

gcc main.c file_handler.c heap.c sort.c -o bigchallenge.exe

Jalankan:

bigchallenge.exe

---

## Contoh Output

1. programming      201

2. data             189

3. algorithm        177

4. computer         165

5. software         158

...

Waktu proses : 3.214 ms

---

## Kesimpulan

Program berhasil:

- Membaca dataset Bag of Words
- Menghitung total frekuensi seluruh kata
- Menentukan 100 kata paling sering menggunakan Min Heap
- Menentukan 100 kata paling jarang menggunakan Max Heap
- Mengurutkan hasil menggunakan Heap Sort
- Menyimpan hasil ke file teks
- Menampilkan hasil dan waktu proses ke layar monitor

Program telah memenuhi spesifikasi tugas Big Challenge Struktur Data dan Algoritma.
