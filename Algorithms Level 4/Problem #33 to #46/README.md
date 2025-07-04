

## 💡 Problem Tanımı

Bu proje, bir tarihten farklı zaman dilimlerinin (gün, hafta, ay, yıl, on yıl, yüzyıl, bin yıl) **çıkartılması** işlemini gerçekleştiren bir tarih hesaplama sistemidir. Kullanıcı tarafından girilen başlangıç tarihi üzerinden adım adım çeşitli zaman azaltmaları yapılarak her adımın sonucu ekrana yazdırılır.
Kod, art arda 33. Problemden 46. Probleme kadar olan tüm tarih artırma problemlerini kapsayan tek bir programda toplanmıştır.
Bu kod, 20–32. problemler arasında yer alan tarih artırım uygulamasının **"azaltma" (geçmişe gitme)** versiyonudur.

---

## 📌 Programın İşleyişi

1. Kullanıcıdan bir tarih alınır.

2. Aşağıdaki işlemler sırayla yapılır:

   * 1 gün çıkarılır
   * 10 gün çıkarılır
   * 1 hafta çıkarılır
   * 10 hafta çıkarılır
   * 1 ay çıkarılır
   * 5 ay çıkarılır
   * 1 yıl çıkarılır (faster)
   * 10 yıl çıkarılır
   * 10 yıl çıkarılır (faster)
   * 1 on yıl (decade) çıkarılır
   * 10 on yıl çıkarılır
   * 10 on yıl çıkarılır (faster)
   * 1 yüzyıl çıkarılır
   * 1 bin yıl çıkarılır

3. Her adımın sonucu ekranda `Gün/Ay/Yıl` formatında yazdırılır.

---

## ✅ Örnek Çıktı

```txt
Please enter a Day
15
Please enter a month
5
Please enter a year
2024
Date After :
01-Subtracting one day is : 14/5/2024
02-Subtracting 10 day is : 4/5/2024
03-Subtracting One Week is : 27/4/2024
04-Subtracting 10 Week is : 17/2/2024
05-Subtracting One Month is : 17/1/2024
06-Subtracting 10 Month is : 17/3/2023
07-Subtracting One Year is : 17/3/2022
08-Subtracting 10 Years is : 17/3/2012
09-Subtracting 10 Years is (faster) : 17/3/2002
10-Subtracting One Decade is : 17/3/1992
11-Subtracting 10 Decade is : 17/3/1892
12-Subtracting 10 Decade is (faster): 17/3/1792
13-Subtracting One Century is : 17/3/1692
14-Subtracting One Millennium is : 17/3/692
```

---

## 🛠️ Kullanılan Fonksiyonlar

| Fonksiyon Adı                     | Açıklama                                |
| --------------------------------- | --------------------------------------- |
| `DecreaseDateByOneDay()`          | Tarihten 1 gün çıkarır                  |
| `DecreaseDateByXDays(X)`          | Tarihten X gün çıkarır                  |
| `DecreaseDateByOneWeek()`         | 7 gün çıkarır                           |
| `DecreaseDateByXWeeks(X)`         | X hafta (X×7 gün) çıkarır               |
| `DecreaseDateByOneMonth()`        | 1 ay çıkarır, gün uyumunu kontrol eder  |
| `DecreaseDateByXMonths(X)`        | X ay çıkarır                            |
| `DecreaseDateByOneyearFaster()`   | 1 yıl çıkarır, artık yıl kontrolü yapar |
| `DecreaseDateByXyears(X)`         | X yıl çıkarır (ay ay geri giderek)      |
| `DecreaseDateByXyearsFaster(X)`   | X yıl çıkarır (optimize edilmiş)        |
| `DecreaseDateByOneDecade()`       | 10 yıl çıkarır                          |
| `DecreaseDateByXDecades(X)`       | X on yıl çıkarır                        |
| `DecreaseDateByXDecadesFaster(X)` | X on yıl çıkarır (optimize edilmiş)     |
| `DecreaseDateByOneCentury()`      | 100 yıl çıkarır                         |
| `DecreaseDateByOneMillennium()`   | 1000 yıl çıkarır                        |

---

## ⚙️ Teknik Detaylar

* Şubat 29 özel durumu kontrol edilmiştir.

  * Eğer hedef yıl artık yıl değilse, tarih 1 Mart’a ayarlanır.
* Tüm işlemler `stDate` yapısı ile çalışır ve `Gün/Ay/Yıl` formatında çıktı verir.
* Kod yapısında hem okunabilirlik hem de modülerlik ön planda tutulmuştur.

---

## 🎯 Amaç

Bu çalışmanın amacı, tarih hesaplamalarında kullanılan azaltma işlemlerinin hem adım adım hem de optimize edilmiş yollarla nasıl uygulanacağını öğretmektir. Ayrıca zaman yapılarıyla çalışırken karşılaşılabilecek durumları (örneğin artık yıl, ay sonları, yıl sonları) doğru şekilde yönetme pratiği kazandırır.

---

