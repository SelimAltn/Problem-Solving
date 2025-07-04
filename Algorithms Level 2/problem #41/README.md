### 💡 Problem Tanımı

Bu program, kullanıcıdan **6 adet iki basamaklı sayı (10–99 arası)** alır ve bu sayıları bir diziye yerleştirir. Daha sonra, bu dizinin **simetrik (palindromik) olup olmadığını** kontrol eder. Yani dizinin baştan ve sondan aynı sırayla okunup okunmadığını belirler.

---

### 📌 Programın İşleyişi

1. `EnterAnumber()` fonksiyonu:

   * 10–99 aralığında sayılar girilmesini zorunlu kılar.
   * Yanlış giriş yapılırsa uyarı vererek tekrar ister.
2. `Dizi()` fonksiyonu:

   * 6 adet sayı alarak diziye ekler.
3. `DiziYazma()` fonksiyonu:

   * Dizinin tüm elemanlarını ekrana yazdırır.
4. `KontrolEdici()` fonksiyonu:

   * Dizinin palindrom (simetrik) olup olmadığını kontrol eder.
   * `Dizi[i] != Dizi[length - i - 1]` kontrolü ile yapılır.
   * Simetrikse: “mükemmel sayılara sahip” mesajı,
   * Değilse: “mükemmel sayılara sahip değil” mesajı verir.

---

### ✅ Örnek Çıktı

#### Giriş:

```
Enter a 1. number
11
Enter a 2. number
22
Enter a 3. number
33
Enter a 4. number
33
Enter a 5. number
22
Enter a 6. number
11
```

#### Çıktı:

```
11 22 33 33 22 11 
Bu Dizi Mukemmel Sayilara Sahip Hem Baştan Hemde Tersten Ayni Şekilde okunuyorlar !
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Dizi girişi ve doğrulaması (validasyon),
* Palindrom dizi kontrolü (baştan ve sondan karşılaştırma),
* Fonksiyonel programlama yapısı ile bölünmüş görevler
* Kullanıcıdan güvenli veri alma ve hata kontrolü

gibi birçok temel ve orta düzey algoritma becerisini kazandırmayı hedefler. Aynı zamanda **simetrik veri kontrolü** gibi sık kullanılan mantıksal desenlerin pratikte nasıl uygulanacağını öğretir.
