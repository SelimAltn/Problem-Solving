## 🧮 Problem 4 – Sütun Toplamlarını Yeni Bir Diziye Aktarma

### 💡 Problem Tanımı:

Bu program 3x3’lük bir matrisi rastgele sayılarla doldurur, her sütunun elemanlarını toplar ve sonuçları ayrı bir diziye aktararak ekrana yazdırır.

---

### 📌 Programın İşleyişi:

1. **`RandumNamber(from, to)`**
   Belirtilen aralıkta rastgele bir sayı üretir.

2. **`FillMatrixWithRandomNumbers(arr, from, to, Rows, Cols)`**
   Matrisi verilen aralıkta rastgele sayılarla doldurur.

3. **`ColSum(arr, Rows, ColNumber)`**
   Belirtilen sütundaki elemanların toplamını döndürür.

4. **`SumMatrixColsInArry(arr, Rows, Cols, ColSums[])`**
   Her sütunun toplamını hesaplayarak `ColSums[]` dizisine aktarır.

5. **`PrintMatrix(arr, Rows, Cols)`**
   Matrisi düzgün şekilde ekrana yazdırır.

6. **`PrintColsSumArry(arr)`**
   Sütunların toplamlarını içeren diziyi ekrana yazdırır.

7. **`main()`**

   * Matris ve sütun toplamlarını tutacak dizi tanımlanır.
   * Matris rastgele doldurulur.
   * Matris ve sütun toplamları yazdırılır.

---

### ✅ Örnek Çıktı:

```
|   3     7     5   |
|   1     9     2   |
|   6     4     8   |

Col 1 Sum = 10  
Col 2 Sum = 20  
Col 3 Sum = 15  
```

---

### 🎯 Amaç:

* Matris sütunlarını işleyerek analiz etme becerisi kazanmak.
* Sütun verilerini bağımsız bir dizide toplamak.
* İleri matris işlemleri için temel oluşturmak.

---

