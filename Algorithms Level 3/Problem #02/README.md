## 🧮 Problem 2 – Her Satırın Toplamını Hesaplama

### 💡 Problem Tanımı:

Bu program 3x3’lük bir matrisi rastgele sayılarla doldurur ve daha sonra her satırın elemanlarını toplayarak ekrana yazdırır.

---

### 📌 Programın İşleyişi:

1. `RandumNamber(int from, int to)`
   Belirtilen aralıkta rastgele bir tam sayı üretir.

2. `FillMatrixWithRandomNumbers(...)`
   Matrisi rastgele sayılarla doldurur.

3. `RowSum(arr, RowNumber, Cols)`
   Verilen satırın (RowNumber) tüm sütunları üzerindeki elemanları toplar ve sonucu döner.

4. `PrintEachRowSum(...)`
   Tüm satırlar için sırayla toplam hesaplayarak ekrana yazar.

5. `PrintMatrix(...)`
   Matrisi düzgün formatta yazdırır.

6. `main()`

   * 3x3 matris oluşturulur.
   * Matris rastgele sayılarla doldurulur.
   * Matris ekrana yazdırılır.
   * Her satırın toplamı yazdırılır.

---

### ✅ Örnek Çıktı:

```
|   2     7     3   |
|   4     5     1   |
|   9     6     8   |

Row 1 Sum = 12  
Row 2 Sum = 10  
Row 3 Sum = 23  
```

---

### 🎯 Amaç:

* Matrislerle işlem yapma pratiği kazanmak.
* Satır-sütun kavramlarını pekiştirmek.
* `rand()`, `setw()` ve `time()` fonksiyonlarıyla çalışmaya devam etmek.

---

