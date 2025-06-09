# Evaluating Romberg and Gauss Quadrature Methods in Root Mean Square Calculation of Electrical Current

**Nama**: Aliya Rizqiningrum Salamun <br>
**NPM** : 2306161813
---

## **Abstrak**

Root Mean Square (RMS) adalah ukuran fundamental dalam analisis sinyal, khususnya dalam konteks arus listrik AC, karena merepresentasikan nilai rata-rata yang setara dengan daya disipasi pada beban resistif. Menghitung nilai RMS sering kali memerlukan teknik integrasi numerik dari kuadrat sinyal. <br>

Laporan ini mengeksplorasi penerapan **dua metode integrasi** yaitu **Romberg Integration** dan **Gauss Quadrature**. Kedua metode ini diuji untuk menghitung RMS dari sinyal arus listrik, dibandingkan dengan metode tradisional seperti Trapezoidal Rule dan Simpson ⅓ Rule pada tugas Pemrograman B.

**Kata Kunci**: Root Mean Square (RMS), Romberg Integration, Gauss Quadrature, dan Sinyal Arus Listrik.

---

## **Rumus RMS**

Perhitungan RMS melibatkan integral dari kuadrat fungsi sinyal selama satu periode, diikuti dengan pembagian oleh periode tersebut, dan kemudian akar kuadrat dari hasilnya. Secara matematis, **RMS dari fungsi waktu f(t) selama interval [T1, T2]** diberikan oleh formula berikut:

$$\text{RMS} = \sqrt{\frac{1}{T_2 - T_1} \int_{T_1}^{T_2} [f(t)]^2 dt}$$

Dimana,
* $f(t)$ adalah fungsi sinyal 
* $i(t)$ adalah arus listrik.
* $v(t)$) adalah tegangan listrik.
* $T_2 - T_1$ adalah periode integrasi. 

Dalam banyak kasus praktis, fungsi sinyal $f(t)$ bisa jadi kompleks atau tidak memiliki bentuk analitik yang mudah diintegrasikan secara eksak. Karenanya, metode integrasi numerik menjadi sangat diperlukan untuk menghitung nilai integral tersebut. 

---
## **Definisi Metode Numerik**

### **Gauss Quadrature**

Gauss Quadrature adalah *teknik integrasi numerik yang menghasilkan perkiraan integral yang sangat akurat dengan menggunakan sejumlah kecil titik evaluasi*. Metode ini didasarkan pada pemilihan titik-titik (nodes) dan bobot (weights) secara optimal sehingga integral polinomial hingga derajat tertentu dapat dihitung secara eksak. Dalam program ini, implementasi Gauss Quadrature mendukung 2, 3, 4, dan 5 titik.

### **Romberg Integration**

Romberg Integration adalah *metode ekstrapolasi Richardson yang digunakan untuk meningkatkan akurasi hasil dari metode integrasi* numerik lainnya, seperti aturan trapesium. Metode ini secara iteratif menghasilkan perkiraan integral yang lebih baik dengan menggabungkan hasil dari aturan trapesium komposit dengan ukuran langkah yang berbeda. Romberg Integration dikenal karena konvergensinya yang cepat.

Rumus umum untuk ekstrapolasi Richardson yang digunakan dalam Romberg Integration adalah sebagai berikut:

$$I_{j,k} = \frac{4^k \cdot I_{j+1,k-1} - I_{k-1}}{4^k - 1}$$
---

## **Komputasi dari Metode Numerik**

Proyek ini mengimplementasikan **dua metode numerik** yaitu **Gauss Quadrature** dan **Romberg Integration** untuk menghitung nilai Root Mean Square (RMS) dari sinyal arus listrik. 

**Sinyal arus** yang digunakan dalam Studi Kasus ini adalah $$i(t) = 5 \sin(2 \pi t)$$ Tujuan utama dari program ini adalah untuk membandingkan akurasi dan efisiensi kedua metode dalam konteks perhitungan RMS arus listrik.

#### **Penjelasan mengenai program**
| **Gauss Quadrature** | **Romberg Integration** |
|----------------------|-------------------------|
| Menghitung RMS dari sinyal arus listrik sinusoidal, dengan mengintegrasikan kuadrat sinyal menggunakan titik dan bobot optimal. Program menguji hasil RMS dengan berbagai jumlah titik evaluasi dan membandingkannya dengan nilai RMS analitis, menunjukkan peningkatan akurasi seiring bertambahnya titik evaluasi. | Menghitung RMS dari sinyal arus listrik sinusoidal. Metode ini meningkatkan akurasi integral dengan memperbaiki hasil Trapezoidal Rule melalui ekstrapolasi Richardson. Program menghitung nilai RMS dari sinyal arus dan membandingkannya dengan nilai RMS analitis. Proses iterasi dihentikan ketika hasilnya cukup akurat, berdasarkan kriteria kesalahan relatif yang ditentukan. |

#### **Fitur**
| **Implementasi Metode** | **Analisis** | **Output** |
|:---:|:---:|:---:|
| Gauss Quadrature (2, 3, 4, 5 titik) | Perbandingan RMS dengan solusi analitis | Output hasil perhitungan RMS untuk setiap metode |
| Romberg Integration | Parameter toleransi error dan iterasi maksimum | Menampilkan RMS teoritis untuk perbandingan |


---

## **Hasil Eksperimen**

Program akan menampilkan hasil perhitungan RMS untuk metode Gauss Quadrature dengan jumlah titik yang berbeda, serta hasil dari Romberg Integration. Semua hasil akan dibandingkan dengan nilai RMS teoritis (analitis) dari sinyal arus yang diberikan.

Hasil output yang diberikan adalah,

```
-------------------------------------------------
     Perhitungan RMS menggunakan Gauss Quadrature
-------------------------------------------------
RMS (Gauss 2-point): 4.85310 A
RMS (Gauss 3-point): 2.42394 A
RMS (Gauss 4-point): 3.75122 A
RMS (Gauss 5-point): 3.50594 A
RMS Teoritis (Analitis): 3.53553 A
-------------------------------------------------

-------------------------------------------------
     Perhitungan RMS menggunakan Romberg Integration
-------------------------------------------------
RMS (Romberg Integration): 3.53553 A
RMS Teoritis (Analitis): 3.53553 A
-------------------------------------------------
```
---

## **Visualisasi**
![image](https://hackmd.io/_uploads/ByIARR7mll.png)

![image](https://hackmd.io/_uploads/HkIz1yE7xx.png)
---

## **Struktur Kode**

Program ini terdiri dari dua file `gauss_quadratue.cpp` dan `romberg_integration.cpp` yang merupakan implementasi kedua metode. Berikut adalah penjelasan singkat mengenai **struktur dan fungsi utama dalam kode**:

### Gauss_Quadrature.cpp

```cpp
double gaussQuadrature(std::function<double(double)> func, double a, double b, int n_points) {
    // Fungsi utama untuk melakukan integrasi menggunakan metode Gauss-Legendre Quadrature. Menerima fungsi yang akan diintegrasikan (`func`), batas bawah (`a`), batas atas (`b`), dan jumlah titik (`n_points`).
}

double current_signal(double t) {
    // Mendefinisikan fungsi sinyal arus `i(t) = 5 * sin(2 * PHI * t)`.
}

double func_to_integrate(double t) {
    // Mendefinisikan fungsi `f(t) = i(t)^2` yang akan diintegrasikan untuk perhitungan RMS.
}

int main() {
    // Bagian ini menginisialisasi parameter, memanggil `gaussQuadrature` dengan jumlah titik yang berbeda, dan menampilkan hasil RMS.
}
```

### Romberg_Integration.cpp

```cpp
double trapezoidalRule(std::function<double(double)> func, double a, double b, int n) {
    // Fungsi pembantu untuk menghitung integral menggunakan aturan trapesium komposit.
}

double rombergIntegration(std::function<double(double)> func, double a, double b, double es, int maxit) {
    // Fungsi utama untuk melakukan integrasi menggunakan Romberg Integration. Menerima fungsi (`func`), batas integral (`a`, `b`), toleransi error (`es`), dan iterasi maksimum (`maxit`).
}

double current_signal(double t) {
    // Mendefinisikan fungsi sinyal arus `i(t) = 5 * sin(2 * PHI * t)` (sama dengan bagian Gauss Quadrature).
}

double func_to_integrate(double t) {
    // Mendefinisikan fungsi `f(t) = i(t)^2` yang akan diintegrasikan untuk perhitungan RMS (sama dengan bagian Gauss Quadrature).
}

int main() {
    // Bagian ini menginisialisasi parameter untuk Romberg Integration, memanggil `rombergIntegration`, dan menampilkan hasil RMS.
}
```
---

## **Kesimpulan Analisis**

1. **Romberg Integration**: Memberikan hasil yang paling akurat dengan error hampir nol (0.00000 A).

2. **Gauss Quadrature**: Akurasi bervariasi tergantung jumlah titik:
   - **2-point**: Error terbesar (1.31757 A)
   - **3-point**: Error besar (1.11159 A)
   - **4-point**: Error sedang (0.21569 A)
   - **5-point**: Error terkecil untuk Gauss (0.02959 A)

3. **Rekomendasi**: Untuk perhitungan RMS sinyal sinusoidal, **Romberg Integration** memberikan hasil terbaik, sedangkan **Gauss Quadrature** memerlukan minimal 5 titik untuk akurasi yang memadai.


## **Referensi**

[1] S. Chapra and R. Canale, “Numerical Methods for Engineers SEVENTH EDITION,” June 2025. Available: https://gdcboysang.ac.in/About/Droid/uploads/Numerical%20Methods.pdf

