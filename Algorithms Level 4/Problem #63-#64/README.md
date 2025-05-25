
## 💡 Problem Tanımı

Bu problemde kullanıcıdan bir tarihi `"gg/aa/yyyy"` formatında alıp, bu tarihi hem `string` olarak hem de yapı (`struct`) biçiminde işlemek amaçlanmaktadır. Uygulama, iki yönlü dönüşüm yapar:

1. **String → Struct (`stDate`)**
2. **Struct (`stDate`) → String**

Bu dönüşümler tarih verileriyle daha sağlıklı çalışmayı ve kontrol mekanizmaları kurmayı sağlar.

---

## 📌 Programın İşleyişi

Program iki ana problemi çözmek için yapılandırılmıştır:

### 🔁 Problem 1 – Tarih Dizesini Yapıya Çevirme (`StringDateToStructDate`)

* Kullanıcı `"gg/aa/yyyy"` formatında bir tarih girişi yapar.
* Bu tarih `SplitString()` fonksiyonu ile `/` sembolü üzerinden parçalanır.
* `stoi()` fonksiyonu ile gün, ay ve yıl parçaları `short` türüne dönüştürülür.
* Bu bilgiler bir `stDate` yapısına atanır.

```cpp
stDate StringDateToStructDate(string dateString)
```

---

### 🔁 Problem 2 – Yapıyı Tarih Dizesine Çevirme (`StructDateToStringDate`)

* Önceki aşamada oluşan `stDate` yapısı, tekrar string'e dönüştürülerek ekrana yazdırılır.
* `to_string()` fonksiyonu ile sayısal değerler string'e çevrilip `/` ile birleştirilir.

```cpp
string StructDateToStringDate(stDate date)
```

---

## ✅ Örnek Girdi / Çıktı

```
Please Enter Date dd / mm / yyyy
10/03/2024

Day: 10
Month: 3
Year: 2024

You Entered: 10/3/2024
```

---


## 🎯 Amaç

Bu problem, tarih verileriyle çalışırken veri tipleri arasında nasıl dönüştürme yapılacağını öğretmeyi amaçlar. Özellikle kullanıcıdan gelen string veriyi güvenli ve yapılandırılmış biçime çevirmenin önemi vurgulanmaktadır.

---
