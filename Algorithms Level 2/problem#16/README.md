### 💡 Problem Tanımı

Bu program, `'A'` harfinden `'Z'` harfine kadar olan tüm büyük harfleri kullanarak 3 harfli tüm kombinasyonları üretir ve ekrana yazdırır.

📌 **Programın Kuralları:**

* Üç katmanlı iç içe döngü ile `AAA`'dan `ZZZ`'ye kadar tüm kombinasyonlar üretilir.
* Her harf ASCII karşılığı üzerinden (`65–90`) alınır.
* Her kombinasyon `"AAA", "AAB", ..., "ZZZ"` şeklinde üretilir ve aralarında boşlukla yazdırılır.
* `Kelime` her döngü sonunda sıfırlanır.

---

### ✅ Örnek Çıktı (ilk birkaç çıktı)

```
AAA  AAB  AAC  ...  AAZ  ABA  ABB  ...  ZZZ
```

(Toplam 26 × 26 × 26 = **17.576** adet kombinasyon)

---

### 🎯 Amaç

ASCII kodlarını ve iç içe döngü kullanımını pekiştirerek karakter tabanlı kombinasyon üretimini öğretmek. Özellikle string işlemleri ve dizilim mantığını geliştirmek.
