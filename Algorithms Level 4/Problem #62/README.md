İşte bu problem için örnek bir **README** dosyası açıklamalarıyla birlikte:

---

## 💡 Problem Tanımı

Kullanıcının girdiği tarih değerinin **geçerli bir tarih (valid date)** olup olmadığını kontrol eden bir program geliştirilmiştir.

Tarih bilgilerinin doğruluğu; gün, ay, yıl sınırlarının yanı sıra, **aylara göre geçerli gün sayısı** ve **artık yıl kontrolü** ile sağlanır.

---

## 📌 Programın İşleyişi

1. Kullanıcıdan gün, ay ve yıl bilgisi alınır.
2. `IsValidDate()` fonksiyonu aşağıdaki kriterlere göre tarihi doğrular:

   * Ay değeri 1 ile 12 arasında olmalı
   * Gün değeri o aya göre geçerli aralıkta olmalı (örn. Şubat için 28 veya 29)
   * Yıl değeri 1 ve üzeri olmalı

---

## ✅ Örnek Çıktı

**Girdi:**

```
Please enter a Day
31
Please enter a month
4
Please enter a year
2024
```

**Çıktı:**

```
No date is not a valid date
```

Çünkü Nisan ayı sadece 30 gün çeker.

---

## 🔍 Kullanılan Fonksiyonlar

### `bool IsLeapYear(short year)`

* Yılın artık yıl olup olmadığını kontrol eder.
* Kurallar: 400'e tam bölünürse artık yıldır. 100'e bölünüp 400'e bölünmüyorsa değildir. 4'e bölünüyorsa artık yıldır.

### `short NumberOfDayesInMonth(short month, short year)`

* Her ayın gün sayısını verir. Şubat ayı için artık yıl kontrolü içerir.

### `bool IsValidDate(stDate date)`

* Gün, ay, yıl değerlerinin sınırlarını kontrol eder.
* Ay'a göre geçerli gün aralığında olup olmadığını doğrular.

---

## 🎯 Amaç

Bu problem, tarih bilgisi doğrulama gibi günlük yaşamda sık karşılaşılan bir kontrol mekanizmasını öğretmeyi amaçlar. Tarih bazlı verilerin hatalı girilmesini önlemek için temel seviye validasyon sağlar.

---