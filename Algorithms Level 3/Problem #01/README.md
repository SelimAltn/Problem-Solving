## 🧮 Problem 1 – Rastgele Sayılarla Matris Oluşturma ve Yazdırma

### 💡 Problem Tanımı:

Bu program 3x3 boyutunda bir matris oluşturur, her hücresine belirli aralıkta rastgele tam sayılar atar ve bu matrisi biçimli şekilde ekrana yazdırır.

---

### 📌 Programın İşleyişi:

1. `RandumNamber(int from, int to)`
   Belirtilen aralıkta rastgele bir sayı üretir.

2. `FillMatrixWithRandomNumbers(int arr[3][3], int from, int to, short Rows, short Cols)`
   Matrisin tüm elemanlarını verilen aralıkta rastgele sayılarla doldurur.

3. `PrintMatrix(int arr[3][3], short Rows, short Cols)`
   Matrisi `setw` kullanarak düzgün sütun aralıkları ile yazdırır.

4. `main()` fonksiyonu:

   * `srand(time(0))` ile rastgelelik başlatılır.
   * 3x3 boyutunda matris oluşturulur.
   * Matris rastgele sayılarla doldurulur ve yazdırılır.

---

### ✅ Örnek Çıktı:

```
|   7     2     6   |
|   9     1     3   |
|   4     8     5   |
```

*(Not: Her çalıştırmada farklı bir matris oluşur.)*

---

### 🎯 Amaç:

* Çok boyutlu dizilerde temel işlemleri uygulamak.
* `rand()`, `setw`, ve `time(0)` fonksiyonlarını kullanma pratiği yapmak.
* Matrisi satır ve sütunlarıyla birlikte düzenli yazdırmayı öğrenmek.

---