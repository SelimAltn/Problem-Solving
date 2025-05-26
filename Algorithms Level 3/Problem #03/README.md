
## 🧮 Problem 3 – Satır Toplamlarını Yeni Bir Diziye Aktarma

### 💡 Problem Tanımı:

Bu program 3x3’lük bir matrisi rastgele sayılarla doldurur, her satırın elemanlarını toplar ve sonuçları ayrı bir diziye aktararak ekrana yazdırır.

---

### 📌 Programın İşleyişi:

1. **`RandumNamber(from, to)`**
   Belirtilen aralıkta rastgele bir sayı üretir.

2. **`FillMatrixWithRandomNumbers(arr, from, to, Rows, Cols)`**
   Matrisi verilen aralıkta rastgele sayılarla doldurur.

3. **`RowSum(arr, RowNumber, Cols)`**
   Belirtilen satırdaki elemanların toplamını döndürür.

4. **`SumMatrixRowsInArry(arr, Rows, Cols, RowsSums)`**
   Her satırın toplamını hesaplayarak `RowsSums[]` dizisine aktarır.

5. **`PrintMatrix(arr, Rows, Cols)`**
   Matrisi düzgün formatta ekrana yazdırır.

6. **`PrintRowsSumArry(arr)`**
   Satırların toplamlarını içeren diziyi ekrana yazdırır.

7. **`main()`**

   * Matris ve toplamları tutacak dizi tanımlanır.
   * Matris rastgele doldurulur.
   * Matris ve satır toplamları yazdırılır.

---

### ✅ Örnek Çıktı:

```
|   7     2     3   |
|   1     4     5   |
|   6     8     2   |

Row 1 Sum = 12  
Row 2 Sum = 10  
Row 3 Sum = 16  
```

---

### 🎯 Amaç:

* Matrislerin satırlarıyla tek tek çalışmayı öğrenmek.
* Fonksiyonlar aracılığıyla diziler arasında veri taşımayı pekiştirmek.
* Sonuçları başka bir dizide toplama tekniğini uygulamak.

---

