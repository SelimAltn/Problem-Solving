
---

## 📆 Problem: Günlük Tarihi Hesaplama (Tarihten Gün Sırası ve Geri Dönüş)

### 📌 Açıklama

Bu projede bir tarih (gün, ay, yıl) bilgisinden hareketle o tarihin yıl içerisindeki kaçıncı gün olduğunu hesaplıyoruz. Ardından, bu gün sıra numarasından tekrar tam tarih bilgisine (gün/ay/yıl) geri dönüyoruz.

---

## 🧾 Çözüm Dosyaları

Bu problem **iki farklı yöntemle** çözülmüştür. Her yöntem farklı bir algoritma yaklaşımına dayanır:

### 🟢 1. Yöntem – `method1.cpp`

* `calculateDayOfYear()` fonksiyonu ile gün sırasını hesaplar.
* `calculateDateFromDayOfYear()` fonksiyonu içinde birikimli gün sayısı (`accumulatedDays`) üzerinden çalışır.
* Ay ay ilerleyerek `accumulatedDays >= dayOfYear` koşulunda uygun tarihi bulur.
* Değişkenler doğrudan `short` tipindedir.

### 🔵 2. Yöntem – `method2.cpp`

* Aynı şekilde gün sırasını `calculateDayOfYear()` ile hesaplar.
* Ancak `calculateDateFromDayOfYear()` fonksiyonu özel bir `struct Sdate` ile tarihi döndürür.
* Her ayın gününü `RemainingDays` ile karşılaştırarak ilerler.
* Kod organizasyonu bakımından daha yapısal ve geri dönüşlüdür (`Sdate` struct’ı ile).

---

## 🔧 Ortak Fonksiyonlar

| Fonksiyon Adı               | Açıklama                                                    |
| --------------------------- | ----------------------------------------------------------- |
| `ReadNumber(...)`           | Belirtilen aralıkta kullanıcıdan güvenli sayısal giriş alır |
| `IsLeapYear(year)`          | Verilen yılın artık yıl olup olmadığını kontrol eder        |
| `NumberOfDayesInMonth(...)` | Verilen ay ve yıl için o ayın gün sayısını döndürür         |
| `calculateDayOfYear(...)`   | Verilen tarih için yılın kaçıncı günü olduğunu hesaplar     |

---

## 💻 Örnek Girdi / Çıktı

### Girdi:

```
Please enter a Day
29
Please enter a month
2
Please enter a year
2000
```

### Çıktı:

```
Number of days the beginning of the year is 60
Date for [60] is 29/2/2000
```

---

## 🎯 Amaç

* Tarihsel hesaplamalarda **gün dönüşümü** işlemlerini uygulamalı olarak öğrenmek.
* Farklı algoritma yapıları ile **aynı sorunun birden fazla çözümünü** geliştirme pratiği yapmak.
* Fonksiyonel yapı, struct kullanımı ve modüler programlamaya aşinalık kazanmak.

---

## 📂 Dosya Yapısı

| Dosya Adı     | Açıklama                              |
| ------------- | ------------------------------------- |
| `method1.cpp` | Klasik for-döngüsü yaklaşımıyla çözüm |
| `method2.cpp` | Yapısal struct tabanlı çözüm          |

---

