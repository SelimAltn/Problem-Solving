## 💡 Problem Tanımı

Kullanıcıdan alınan bir tarih bilgisi (`gg/aa/yyyy` formatında) üzerinde işlem yaparak bu tarihi istenilen farklı formatlarda yazdıran bir program geliştirilmiştir. Bu problem sayesinde tarih yapısının parçalanması, biçimlendirilmesi ve özelleştirilmiş formatlarla sunulması öğretilmektedir.

---

## 📌 Programın İşleyişi

### 🔄 Adım 1: `String → stDate` Dönüşümü

* Kullanıcıdan alınan tarih, `SplitString()` fonksiyonu ile `'/'` karakteri üzerinden bölünerek gün, ay ve yıl ayrıştırılır.
* Bu veriler `stDate` yapısına atanır.

```cpp
stDate StringToDate(string DateString);
```

---

### 🔄 Adım 2: `stDate → String` Dönüşümü (Biçimlendirilmiş)

* Tarih bilgisi, verilen formata göre (örn: `"dd/mm/yyyy"`, `"yyyy-mm-dd"` gibi) `FormateDate()` fonksiyonu ile biçimlendirilir.
* Fonksiyon `"dd"`, `"mm"` ve `"yyyy"` kalıplarını tarih bileşenleriyle değiştirerek özel format üretir.

```cpp
string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy");
```

---

### ⚙️ Yardımcı Fonksiyonlar

* `SplitString()`: Verilen bir stringi belirli bir ayırıcıya göre parçalar.
* `ReplaceWordInString()`: String içinde geçen belirli alt stringleri yenileriyle değiştirir.

---

## ✅ Örnek Girdi / Çıktı

```
Please Enter Date dd / mm / yyyy ? 
01/03/2025

01/03/2025
2025/01/03
03/01/2025
03-01-2025
01-03-2025
Day:01, Month:03,Year:2025
```

---

## 🎯 Amaç

Bu uygulamanın temel amacı tarih verisini sadece yapısal olarak işlemekle kalmayıp, kullanıcı ihtiyaçlarına göre esnek formatlarla yazdırmayı sağlamaktır. Özellikle kullanıcı arayüzü, raporlama ya da tarih bazlı veri sunumlarında farklı formatlara ihtiyaç duyulduğunda bu yapı oldukça kullanışlıdır.

---

## 🧩 Ekstra Bilgilendirme

* `FormateDate()` fonksiyonu `"dd"`, `"mm"`, `"yyyy"` kelimelerini sırayla değiştirir. Eğer bu alt kelimeler birden fazla geçerse, tüm tekrarları değiştirir.
* `SplitString()` fonksiyonu geneldir; başka ayırıcılar (örneğin `-`) için de çalışabilir.

---

