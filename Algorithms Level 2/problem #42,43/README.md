### 💡 Problem Tanımı

Bu program, kullanıcıdan `0–100` arasında bir sayı alarak bu uzunlukta rastgele sayılardan oluşan bir dizi üretir. Daha sonra bu dizideki **tek** ve **çift** sayıları ayrı ayrı analiz eder:

* Tek ve çift sayıların kendi alt dizileri oluşturulur.
* Her grubun toplam eleman sayısı ve toplam değeri hesaplanır.
* Tüm bilgiler ekrana yazdırılır.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan dizinin uzunluğu alınır (`0–100` arası).
2. Dizi `1–100` arasında rastgele sayılarla doldurulur.
3. Dizi yazdırılır.
4. `TekSayilarinSayisini()` fonksiyonu:

   * Tek sayıları ayrı bir diziye ekler.
   * Toplam sayısını ve toplamını hesaplar.
5. `CiftSayilarinSayisini()` fonksiyonu:

   * Çift sayılar için aynı işlemi yapar.

---

### ✅ Örnek Çıktı

```
İstediniz Matrisin Sayisini Giriniz
15
{ 27 14 91 62 33 70 8 9 55 99 10 38 67 12 81 }
Tek Sayilarin Dizisi : { 27 91 33 9 55 99 67 81 }
Bu dizide Tek Sayilarin Sayısının : 8
Bu dizide Tek Sayilarin Toplami : 462


Cift Sayilarin Dizisi : { 14 62 70 8 10 38 12 }
Bu dizide Cift Sayilarin Sayısının : 7
Bu dizide Cift Sayilarin Toplami : 214
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Rastgele sayı üretme ve dizi oluşturma,
* Tek ve çift sayıları filtreleme,
* Alt dizi oluşturma ve analiz etme,
* Fonksiyonlarla ayrık görevleri yapılandırma
  gibi temel dizi işlemleri ve veri analizi konularında uygulamalı pratik kazandırır. Ayrıca çıktıyı kullanıcıya açıklayıcı şekilde sunmayı da öğretir.
