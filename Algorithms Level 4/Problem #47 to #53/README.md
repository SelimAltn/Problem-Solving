
---

## 💡 Problem Tanımı

Bu proje, sistem tarihine (bugünün tarihine) göre aşağıdaki tarihsel analizleri yapan bir uygulamadır:

* Haftanın günü nedir?
* Hafta sonu mu, iş günü mü?
* Haftanın son günü mü?
* Haftanın, ayın ve yılın sonuna kaç gün kaldı?

Bu işlemler, kullanıcıdan herhangi bir tarih alınmadan **bilgisayarın sistem tarihi** üzerinden gerçekleştirilir.

---

## 📌 Programın İşleyişi

1. Program, `GetTodayDate()` fonksiyonu ile sistem tarihini elde eder.
2. Ardından aşağıdaki fonksiyonlar yardımıyla bugünkü tarih analiz edilir:

   * Haftanın günü (`DayOfWeekOrder`)
   * Gün adı (`DayShortName`)
   * Hafta sonu kontrolü (`IsWeekEnd`)
   * Haftanın son günü kontrolü (`IsEndOfWeek`)
   * İş günü kontrolü (`IsBusinessDay`)
   * Hafta sonuna kalan gün sayısı (`DaysUntilTheEndOfWeek`)
   * Ay sonuna kalan gün sayısı (`DaysUntilTheEndOfMonth`)
   * Yıl sonuna kalan gün sayısı (`DaysUntilTheEndOfYear`)
3. Elde edilen bilgiler ekrana kullanıcı dostu mesajlarla yazdırılır.

---

## ✅ Örnek Çıktı

```txt
Today is : Monday, 27/5/2024
is it end of week ?
No it is not a week end
is it Weekend ?
No it is not Weekend
is it Business Day ?
Yes it is Business Day
Days Until end of week : 5
Days Until end of month : 4
Days Until end of year : 219
```

---

## 🛠️ Kullanılan Temel Fonksiyonlar

| Fonksiyon                  | Açıklama                                     |
| -------------------------- | -------------------------------------------- |
| `GetTodayDate()`           | Sistem tarihini döner                        |
| `DayOfWeekOrder()`         | Haftanın gün indeksini verir (0 = Pazartesi) |
| `DayShortName()`           | Gün indeksine karşılık gelen gün adını döner |
| `IsWeekEnd()`              | Bugün hafta sonu mu? (Cumartesi-Pazar)       |
| `IsEndOfWeek()`            | Bugün haftanın son günü mü? (Pazar)          |
| `IsBusinessDay()`          | Bugün iş günü mü?                            |
| `DaysUntilTheEndOfWeek()`  | Haftanın sonuna kalan gün sayısı             |
| `DaysUntilTheEndOfMonth()` | Ayın sonuna kalan gün sayısı                 |
| `DaysUntilTheEndOfYear()`  | Yılın sonuna kalan toplam gün sayısı         |

---

## 🔍 Teknik Notlar

* Haftanın ilk günü olarak **Pazartesi (0)** kabul edilmiştir (ISO 8601 / Türkiye formatı).
* `DayOfWeekOrder()` fonksiyonu Zeller’s congruence algoritmasına göre özelleştirilmiştir.
* Tüm tarih işlemleri `stDate` yapısı (Day, Month, Year) üzerinden yapılmaktadır.
* Programda `ctime` kütüphanesi ile sistem tarihine erişilmektedir.

---

## 🎯 Amaç

Bu projenin amacı, sistem tarihini kullanarak temel tarihsel analizleri yapmayı öğretmek ve:

* Takvim bilgisi işleme
* Haftalık düzen analizleri
* Tarih ile ilgili fonksiyonlar yazma pratiği
  konularında deneyim kazandırmaktır.

---

