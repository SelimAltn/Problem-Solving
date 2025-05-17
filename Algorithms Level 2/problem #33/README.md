### 💡 Problem Tanımı

Bu program, kullanıcıdan bir sayı alarak o sayı kadar **Windows ürün anahtarı formatında** rastgele anahtarlar üretir ve her birini ekrana yazdırır. Anahtarlar büyük harflerden oluşur ve format olarak `XXXX-XXXX-XXXX-XXXX` şeklindedir.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan kaç adet lisans anahtarı oluşturulacağı alınır (`1–100`).
2. Her anahtar:

   * 4 bloktan oluşur.
   * Her blok 4 büyük harften oluşur (`A–Z`, ASCII: 65–90).
   * Bloklar `-` ile ayrılır.
3. `TEST()` fonksiyonu bir blok üretir.
4. `PrintDizi()` fonksiyonu bu blokları birleştirerek anahtarı oluşturur.
5. `PrintWindosAnahtrarlari()` ile her anahtar ekrana yazdırılır.

---

### ✅ Örnek Çıktı

```
Enter a number 
3
[1] : XJMA-QUET-BKZW-PLHR
[2] : WNRI-MQLK-ZYUJ-HVBD
[3] : EKPL-TWCN-VBAZ-KYUJ
```

> Not: Her çalıştırmada anahtarlar rastgele oluşur.

---

### 🎯 Amaç

Bu problem, kullanıcıya:

* Karakter üretimi (`rand()` ve ASCII kullanımı),
* String birleştirme ve formatlama,
* Dizi ve döngü yapılarıyla veri üretme ve yazdırma

konularında pratik yaptırmayı hedefler. Gerçek dünya uygulamalarına benzer yapısıyla üretici algoritma mantığını pekiştirir.
