
---

## 💡 Problem Tanımı

İki tarih (gün, ay, yıl) arasındaki gün farkını hesaplayan bir programın 2. yöntemi üzerine odaklanılmıştır. Bu yöntemde, küçük tarihten büyük tarihe doğru günü gününe ilerlenerek fark hesaplanır. Ancak bu versiyonda yapılan güncellemenin amacı **kodun ana algoritmasına dokunmadan**, ek kontrol ve yardımcı fonksiyonlarla **ters tarih girişlerini de destekleyecek şekilde davranışı zenginleştirmek** ve **gelişmiş tarih işleme pratiği** yapmaktır.

---

## 📌 Programın İşleyişi

* Kullanıcıdan iki tarih alınır (`ReadDate()`).
* `GetDifferenceInDays()` fonksiyonu çağrılarak tarihler arasındaki fark hesaplanır.
* Önce tarihler karşılaştırılır; eğer birinci tarih ikinci tarihten büyükse, `SwapDates()` fonksiyonu ile yerleri değiştirilir.
* Tarih gün gün `AddOneDay()` fonksiyonu ile ilerletilir ve adım sayısı sayılır.
* "Include End Day" parametresi true olarak verilirse bir gün daha eklenir.
* Fark pozitif ya da negatif olabilir (ilk tarih daha büyükse fark negatif döner).

---

## ✅ Örnek Çıktı

```
Please enter a Day
5
Please enter a month
6
Please enter a year
2024
Please enter a Day
1
Please enter a month
6
Please enter a year
2024
Diffrence is -4 Day(s)
Diffrence (Including End Day) is: -5 Day(s)
```

---

## 🛠️ Yapılan Değişiklikler

Bu sürüm, 17. problemin 2. yöntemine aşağıdaki **eklemeler** ile geliştirilmiştir:

* `SwapDates(stDate& date1, stDate& date2)` fonksiyonu eklendi:

  * Tarihlerin yerini değiştirmeye yarar.
* `SawpFlagValue` (swap durumunu tutan işaretçi) eklendi:

  * Eğer tarihler yer değiştirdiyse fark sonunda `-1` ile çarpılarak negatif sonuç döner.
* `IncludeEndDay` parametresi aktifse, ek olarak 1 gün daha dahil edilir.

**Not:** Kodun ana algoritması hiç değiştirilmeden bu düzenlemeler yapılmıştır. Bu, **temiz kod yazımı**, **ek modül tasarımı**, ve **davranış genişletme** açısından faydalı bir egzersizdir.

---

## 🧪 Test Senaryoları

| Tarih 1    | Tarih 2    | Sonuç |
| ---------- | ---------- | ----- |
| 01.06.2024 | 05.06.2024 | 4     |
| 05.06.2024 | 01.06.2024 | -4    |
| 01.06.2024 | 01.06.2024 | 0     |

---

## 🎯 Amaç

Bu çalışma, daha önce geliştirilen bir yöntemin işlevselliğini **bozmadan** nasıl geliştirilebileceğini ve **tarih işlemlerinin daha akıllıca** yapılabilmesini göstermek için hazırlanmıştır. Böylece hem yazılım sürdürülebilirliği hem de algoritma esnekliği gibi önemli yazılım mühendisliği konuları pekiştirilmiş olur.

---