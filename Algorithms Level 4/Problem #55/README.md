
## 💡 Problem Tanımı

Bu program, bir kişinin belirli sayıda iş günü sürecek tatiline hangi tarihte döneceğini hesaplar. Kullanıcıdan tatilin başlangıç tarihi ve tatil süresi (iş günü cinsinden) alınır. Hesaplamalar yalnızca **hafta içi günlerini (Pazartesi–Cuma)** içerir. Hafta sonları (Cumartesi, Pazar) atlanır.

Ayrıca, hesaplama iki farklı yöntemle yapılır ve karşılaştırılır:

1. Klasik doğrusal kontrol (geliştirilmiş)
2. Optimize edilmiş hızlı yöntem

---

## 📌 Programın İşleyişi

1. Kullanıcıdan tatil başlangıç tarihi alınır (`ReadDate` fonksiyonu ile).

2. Tatil süresi (sadece iş günü olarak) alınır (`ReadNumber` fonksiyonu ile).

3. İki farklı yöntemle tatilden dönüş tarihi hesaplanır:

   * `CalculateVacationReturnDate()`

     * Gelişmiş kontrol içerir, haftasonuna denk gelen başlangıç ve dönüş tarihlerini de atlar.
   * `CalculateVacationReturnDateFaster()`

     * Daha kısa ve hızlı bir yaklaşım, sadece iş günü sayısı üzerinden ilerler.

4. Her iki dönüş tarihi gün adıyla birlikte yazdırılır.

---

## ✅ Örnek Çıktı

```txt
Vacation Starts : 
Please enter a Day
24
Please enter a month
5
Please enter a year
2024
Please Enter vacation days ? 
5
Return date : Wednesday, 29/5/2024
Return date (faster): Wednesday, 29/5/2024
```

---

## 🛠️ Kullanılan Temel Fonksiyonlar

| Fonksiyon                             | Açıklama                                   |
| ------------------------------------- | ------------------------------------------ |
| `ReadDate()`                          | Tarih girişini alır                        |
| `IncreaseDateByOneDays()`             | Tarihi bir gün ileri alır                  |
| `IsWeekEnd()`                         | Gün hafta sonu mu kontrol eder             |
| `IsBusinessDay()`                     | Gün bir iş günü mü kontrol eder            |
| `CalculateVacationReturnDate()`       | İş günü sayısına göre dönüş tarihini bulur |
| `CalculateVacationReturnDateFaster()` | Aynı işlemi daha kısa ve hızlı yapar       |
| `DayOfWeekOrder()` + `DayShortName()` | Haftanın gün adını verir                   |

---

## ⚙️ Teknik Notlar

* Haftanın ilk günü: **Pazartesi = 0**, hafta sonu: **Cumartesi = 5**, **Pazar = 6**
* Tatil başlangıcı haftasonuna denk gelirse otomatik olarak bir sonraki iş gününe atlanır.
* Dönüş tarihi de iş gününe denk gelecek şekilde ayarlanır.
* Her iki yöntemin verdiği sonuç karşılaştırılır. Eğer farklılık varsa hatalı hesaplama anlaşılır.

---

## 🎯 Amaç

Bu problem, kullanıcı tarafından belirlenen sayıda iş günü süresince bir tatilin hangi tarihte biteceğini hesaplayarak şu konularda pratik sağlar:

* Tarih arttırma ve karşılaştırma algoritmaları
* İş günü/hafta sonu ayrımı yapabilme
* Tarih bazlı algoritmaların hem doğru hem de optimize biçimde uygulanması

---
