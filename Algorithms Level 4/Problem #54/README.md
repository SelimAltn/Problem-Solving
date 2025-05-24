
## 💡 Problem Tanımı

Bu uygulama, iki tarih arası tatil süresi boyunca kaç adet **iş günü (business day)** olduğunu hesaplayan bir tarih analiz programıdır.

Kullanıcı, tatilin başlangıç ve bitiş tarihlerini girdikten sonra:

* Hangi günlerde tatil başladığını ve bittiğini öğrenir,
* Tatil süresince kaç günün iş günü (hafta içi) olduğunu öğrenir.

---

## 📌 Programın İşleyişi

1. Kullanıcıdan iki tarih alınır:

   * Tatilin başlangıç tarihi
   * Tatilin bitiş tarihi

2. Tarih doğrulaması yapılır:

   * İlk tarih, ikinci tarihten önce olmalıdır.
   * Aynı tarih girilirse uyarı verilir.

3. `ActionVactationDays()` fonksiyonu çalıştırılır:

   * Başlangıç tarihinden bitiş tarihine kadar olan her gün kontrol edilir.
   * Sadece **iş günleri (Pazartesi–Cuma)** sayılır.
   * Cumartesi ve Pazar günleri atlanır (`continue` mantığı uygulanır).

4. Gün adları (örneğin "Monday") kullanıcıya gösterilir.

---

## ✅ Örnek Çıktı

```txt
Vacation Starts : 
Please enter a Day
27
Please enter a month
5
Please enter a year
2024
Vacation Ends : 
Please enter a Day
2
Please enter a month
6
Please enter a year
2024
Vaction From : Monday, 27/5/2024
Vaction To : Sunday, 2/6/2024
Action Vactation Days is : 5
```

---

## 🛠️ Kullanılan Temel Fonksiyonlar

| Fonksiyon Adı             | Açıklama                                     |
| ------------------------- | -------------------------------------------- |
| `IsLeapYear()`            | Artık yıl kontrolü                           |
| `NumberOfDayesInMonth()`  | Ayın gün sayısını döner                      |
| `IsBusinessDay()`         | Günün hafta içi olup olmadığını döner        |
| `DayOfWeekOrder()`        | Haftanın gün indeksini verir (0 = Pazartesi) |
| `IncreaseDateByOneDays()` | Tarihi 1 gün artırır                         |
| `IsDate1BeforeDate2()`    | Tarih karşılaştırması yapar                  |
| `ActionVactationDays()`   | Tatildeki iş günü sayısını döner             |

---

## ⚙️ Teknik Detaylar

* Haftanın ilk günü olarak **Pazartesi = 0**, hafta sonu **Cumartesi = 5** ve **Pazar = 6** olarak tanımlanmıştır.
* Tatil bitiş tarihi dahil **değildir**, sadece `date1 < date2` aralığı taranır.
* Girdi kontrolü yapılır: yanlış tarih sıralamasında kullanıcı tekrar tarih girer.

---

## 🎯 Amaç

Bu problemin amacı, kullanıcıdan alınan iki tarih arası **yalnızca iş günlerini sayan** algoritmayı geliştirmek ve:

* Tarih karşılaştırma
* Tarih artırma
* Haftanın günü hesaplama
  gibi işlemleri fonksiyonel yapılarla pratiğe dökmektir.

---