
## 💡 Problem Tanımı

Bu uygulama, bir tarih üzerine çeşitli zaman birimleri (gün, hafta, ay, yıl, on yıl, yüzyıl, bin yıl) ekleyerek yeni tarihleri hesaplayan kapsamlı bir tarih artırım sistemidir. Kod, art arda 20. Problemden 32. Probleme kadar olan tüm tarih artırma problemlerini kapsayan tek bir programda toplanmıştır.

---

## 📌 Programın İşleyişi

* Kullanıcıdan bir başlangıç tarihi alınır (`ReadDate()`).
* Ardından tarih sırasıyla:

  * 1 gün
  * X gün
  * 1 hafta
  * X hafta
  * 1 ay
  * X ay
  * 1 yıl
  * X yıl
  * Daha hızlı X yıl
  * 1 on yıl (dekad)
  * X on yıl (dekad)
  * Daha hızlı X on yıl
  * 1 yüzyıl (century)
  * 1 bin yıl (millennium)
    kadar artırılır ve her adımda güncellenmiş tarih ekrana yazdırılır.

---

## ✅ Örnek Çıktı

```
Please enter a Day
15
Please enter a month
5
Please enter a year
2024
Date After :
01-Adding one day is : 16/5/2024
02-Adding 10 day is : 26/5/2024
03-Adding One Week is : 2/6/2024
04-Adding 10 Week is : 11/8/2024
05-Adding One Month is : 11/9/2024
06-Adding 10 Month is : 11/2/2025
07-Adding One Year is : 11/2/2026
08-Adding 10 Years is : 11/2/2036
09-Adding 10 Years is (faster) : 11/2/2046
10-Adding One Decade is : 11/2/2056
11-Adding 10 Decade is : 11/2/2156
12-Adding 10 Decade is (faster): 11/2/2256
13-Adding One Century is : 11/2/2356
14-Adding One Millennium is : 11/2/3356
```

---

## 🧠 Öne Çıkan Fonksiyonlar

| Fonksiyon                         | Açıklama                       |
| --------------------------------- | ------------------------------ |
| `IncreaseDateByOneDays()`         | Tarihe 1 gün ekler             |
| `IncreaseDateByXDays(int X)`      | Tarihe X gün ekler             |
| `IncreaseDateByOneWeek()`         | 7 gün artırır                  |
| `IncreaseDateByXWeeks(int X)`     | X hafta ekler                  |
| `IncreaseDateByOneMonth()`        | Ay ekler, ay sonu uyumu sağlar |
| `IncreaseDateByXMonths(int X)`    | X ay ekler                     |
| `IncreaseDateByOneyearFaster()`   | 1 yıl ekler (daha hızlı yol)   |
| `IncreaseDateByXyears(int X)`     | X yıl ekler                    |
| `IncreaseDateByXyearsFaster(X)`   | X yıl ekler (optimize)         |
| `IncreaseDateByOneDecade()`       | 10 yıl ekler                   |
| `IncreaseDateByXDecades(X)`       | X dekad ekler                  |
| `IncreaseDateByXDecadesFaster(X)` | X dekad ekler (optimize)       |
| `IncreaseDateByOneCentury()`      | 100 yıl artırır                |
| `IncreaseDateByOneMillennium()`   | 1000 yıl artırır               |

---

## ⚙️ Teknik Detaylar

* Şubat 29 kontrolü yapılmıştır: Eğer artık yıl olmayan bir yıla gidiliyorsa, tarih 1 Mart’a ayarlanır.
* Tarih formatı `Gün/Ay/Yıl` şeklinde yazdırılır.
* Her adımda tarih güncellenir ve bir sonraki artırım o tarih üzerinden yapılır.

---

## 🎯 Amaç

Bu çalışmanın amacı, tarih işlemleriyle ilgili tüm temel kavramları tek bir uygulama içerisinde toparlamak ve gün, hafta, ay, yıl, on yıl, yüzyıl ve bin yıl gibi farklı düzeydeki zaman artırmalarını uygulamalı olarak göstermektir. Aynı zamanda bu yapı sayesinde tarih artırma algoritmalarının performans farkları da görülebilir (örneğin hızlı ve yavaş yıl ekleme yöntemleri karşılaştırılabilir).

---

