# BIG CHALLENGE SDA 2025
## Menentukan K Kata Paling Sering dan Paling Jarang Menggunakan Heap

### Anggota Kelompok
- Ahmad Wazir Sahfikri (250810701100050)
- Rafa  (250810701100)

---

## Deskripsi Program

Program ini dibuat untuk memenuhi tugas Big Challenge mata kuliah Struktur Data dan Algoritma.

Program bertujuan untuk menentukan:

1. 100 kata yang paling sering muncul dalam dokumen.
2. 100 kata yang paling jarang muncul dalam dokumen.

Data diambil dari dataset Bag of Words UCI Machine Learning Repository yang terdiri dari file:

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
