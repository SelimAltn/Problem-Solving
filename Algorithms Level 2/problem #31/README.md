### 💡 Problem Tanımı

Bu program, kullanıcıdan bir sayı alarak 1’den o sayıya kadar olan sayıları içeren bir dizi oluşturur. Daha sonra bu diziyi **rastgele bir şekilde karıştırır (shuffle)** ve hem orijinal hem de karıştırılmış halini ekrana yazdırır.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan dizinin boyutu alınır (`1–100`).
2. `Arry1Sayileri` fonksiyonu ile 1'den başlayarak sıralı bir sayı dizisi oluşturulur.
3. `Arry2` fonksiyonu, dizinin elemanlarını rastgele şekilde yer değiştirerek diziyi karıştırır.
4. `PrintMatris` fonksiyonu, hem orijinal hem de karıştırılmış diziyi ekrana yazdırır.

> Not: Karıştırma işlemi `swap(a, b)` ile rastgele iki indeks arasında yapılır.

---

### ✅ Örnek Çıktı

```
enter a number 
10
Arri1 :
1 2 3 4 5 6 7 8 9 10 
Arri2 :
5 3 10 1 8 9 2 7 6 4 
```

> Not: Çıktı her çalıştırmada farklı olacaktır çünkü karıştırma işlemi rastgeledir.

---

### 🎯 Amaç

* Dizi oluşturma ve sıralama bilgisi kazanmak,
* Rastgele sayılarla diziyi karıştırma (shuffle) algoritmasını öğrenmek,
* Fonksiyonlar ve referans kullanımı (`swap`) ile bellekteki değerlerin nasıl değiştirileceğini kavramak.
