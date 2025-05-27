İşte verdiğiniz probleme özel, her zamanki yapıya uygun hazırlanmış **README** dosyası:

---

## 🧮 Problem 5 – Sütun Toplamlarını `vector` ile Hesaplama ve Yazdırma

### 💡 Problem Tanımı:

Bu program, 3x3'lük bir matrisin sütunlarının toplamlarını hesaplar ve bu toplamları bir `vector` yapısına kaydederek ekrana yazdırır. Rastgele sayılarla doldurulan matris, hem gösterim hem de veri işleme için kullanılır.

---

### 📌 Programın İşleyişi:

1. **`RandumNamber(from, to)`**
   Belirtilen aralıkta rastgele bir sayı üretir.

2. **`FillMatrixWithRandomNumbers(arr)`**
   Matrisi 1 ile 100 arasında rastgele sayılarla doldurur.

3. **`PrintMatris(arr)`**
   Matrisi biçimli bir şekilde ekrana yazdırır.

4. **`ColSums(vSum, arr)`**

   * Sütunların toplamını hesaplar.
   * Toplamları `vSum` adlı `vector<int>` yapısına ekler.
   * Ardından `PrintSums(vSum)` fonksiyonu çağrılarak yazdırılır.

5. **`PrintSums(vSum)`**
   `vSum` dizisini okuyarak sütun toplamlarını satır satır ekrana yazdırır.

---

### ✅ Örnek Çıktı:

```
|  41       9       66       |
|  32       5       77       |
|  84       1       20       |



Satirlarin toplami : 
Row 1.      157
Row 2.      15
Row 3.      163
```

---

### 🎯 Amaç:

* Matris verilerinin `vector` yapısıyla işlenmesini öğrenmek.
* Sütun toplamlarını dinamik bir yapıda depolamak.
* C++'ta vektör kullanımı ve matris işlemlerini pekiştirmek.

---

Not: `Row` yerine `Column` yazmak daha uygun olurdu çünkü toplananlar aslında sütunlardır. Ancak metin böyle yazıldığı için aynen bırakılmıştır.
