
## 💡 Problem Tanımı

Bu program, kullanıcıdan alınan bir tarih aralığının (başlangıç ve bitiş tarihleri) **kaç gün sürdüğünü** hesaplar.
İsteğe bağlı olarak, bitiş tarihi dahil edilerek de toplam süre belirlenebilir.

Bu hesaplama genellikle şu alanlarda gereklidir:

* Tatil süresi hesaplama
* Rezervasyon sistemleri
* Proje planlaması ve görev süresi belirleme
* Tarihsel veri analizleri

---

## 📌 Programın İşleyişi

1. Kullanıcıdan bir periyot (başlangıç ve bitiş tarihleri) alınır.
2. `GetDifferenceInDays()` fonksiyonu ile bu iki tarih arasındaki fark, takvim günü olarak hesaplanır.
3. Fonksiyon opsiyonel olarak `IncludeEndDay = true` gönderilirse, sonuç +1 artırılır.
4. Sonuç iki şekilde ekrana yazdırılır:

   * Bitiş tarihi dahil değil
   * Bitiş tarihi dahil

---

## ✅ Örnek Çıktı

```txt
Enter Period 1 : 
Enter Start Date :
Please enter a Day
1
Please enter a month
5
Please enter a year
2024
Enter End Date :
Please enter a Day
10
Please enter a month
5
Please enter a year
2024

Peroid Length is : 9
Peroid Length (Including End Date) is : 10
```

---

## 🧠 Kullanılan Fonksiyonlar

| Fonksiyon                 | Görevi                                                      |
| ------------------------- | ----------------------------------------------------------- |
| `ReadDate()`              | Gün, ay, yıl tarihini alır                                  |
| `SwapDates()`             | Tarih sıralaması tersse düzeltir                            |
| `IncreaseDateByOneDays()` | Verilen tarihi bir gün ilerletir                            |
| `GetDifferenceInDays()`   | İki tarih arasındaki farkı gün olarak verir                 |
| `PeriodLength()`          | `GetDifferenceInDays`'i çağırarak periyot süresini hesaplar |

---

## 🛠️ Önemli Kontroller

* Tarihler sıralı değilse (`date1 > date2`) otomatik olarak yerleri değiştirilir.
* Bitiş tarihi dahil edilip edilmediği, `IncludeEndDay` parametresiyle esnektir.
* Tarih ilerletme işlemleri, `IsLastDayInMonth()` ve `IsLastMonthInYear()` gibi yardımcı kontrollerle yapılır. Bu da ay/yıl geçişlerini doğru şekilde yönetir.

---

## 📌 Kullanılan Veri Yapıları

```cpp
struct stDate {
	short Day, Month, Year;
};

struct stPeriod {
	stDate StartDate, EndDate;
};
```

---

## 🎯 Amaç

Bu çalışmanın amacı:

* Tarihlerle işlem yapabilme becerisi kazanmak
* Tarihler arasında sıralama, fark bulma ve tarih ilerletme algoritmalarını öğrenmek
* Gerçek hayatta sıkça karşılaşılan zaman aralığı hesaplamalarına temel oluşturmak

---

