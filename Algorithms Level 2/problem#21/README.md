### 💡 Problem Tanımı

Bu program, kullanıcıdan bir sayı alarak o sayı kadar **Windows ürün anahtarı formatında** rastgele büyük harflerden oluşan lisans anahtarları üretir ve ekrana yazdırır.

📌 **Anahtar Formatı:**

* Her anahtar 4 bloktan oluşur.
* Her blokta 4 adet büyük harf (A–Z) yer alır.
* Bloklar `-` ile ayrılır.
* Örnek: `ABCD-KLMN-WXYZ-QWER`

📌 **Programın İşleyişi:**

* Kullanıcı, kaç anahtar üretileceğini belirler.
* `NumberRandum(65, 90)` fonksiyonu ile ASCII tablosuna göre büyük harfler rastgele üretilir.
* İç içe döngülerle her anahtar satır satır oluşturulur.

---

### ✅ Örnek Çıktı

```
Enter a number 
2
1. anahtar : ZKTL-NBVE-WQAR-XUZP
2. anahtar : QWER-HTYU-ZXCV-BNML
```

> Not: Üretilen değerler her çalıştırmada farklıdır.

---

### 🎯 Amaç

Rastgele karakter üretme, ASCII kullanımı, iç içe döngüler ve biçimlendirilmiş çıktı üretimi gibi temel programlama kavramlarını pekiştirmektir.
