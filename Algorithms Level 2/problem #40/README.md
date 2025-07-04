### 💡 Problem Tanımı

Bu program, sabit uzunlukta ve tekrar eden elemanlar içeren bir diziyi alır (`arrSource`) ve içerisindeki **yalnızca farklı (distinct)** elemanları başka bir diziye (`arrDestination`) kopyalar. Amaç, bir diziden tekrarsız elemanları ayıklayarak yeni bir dizi oluşturmaktır.

---

### 📌 Programın İşleyişi

1. `FillArray()` fonksiyonu ile `arrSource` adlı kaynak dizi sabit olarak doldurulur.

   ```
   [10, 10, 10, 50, 50, 70, 70, 70, 70, 90]
   ```
2. `CopyDistinctNumbersToArray()` fonksiyonu:

   * Kaynak diziyi dolaşır.
   * Her elemanı `arrDestination` dizisinde kontrol eder.
   * Eğer daha önce eklenmemişse (`IsNumberInArray()` ile kontrol), ekler.
3. `PrintArray()` fonksiyonu her iki diziyi yazdırır.

---

### ✅ Örnek Çıktı

```
Array 1 elements:
10 10 10 50 50 70 70 70 70 90 

Array 2 distinct elements:
10 50 70 90 
```

---

### 🎯 Amaç

Bu problem ile:

* Tekrar eden elemanları filtreleme,
* Dizide eleman arama (`linear search`),
* Fonksiyonel tasarım,
* Referansla uzunluk takibi (`int& arrLength`),
* Temiz ve modüler yapı oluşturma
  gibi temel dizi algoritma becerileri kazandırılır.

Ayrıca bu yapı, **veri temizleme** ve **küme oluşturma** mantığını anlamak için oldukça faydalıdır.
