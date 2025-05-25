
---

## 💡 Problem Tanımı

Bu program, kullanıcıdan alınan bir tarih ve bir tarih aralığı (periyot) üzerinden, **verilen tarihin bu aralığa dahil olup olmadığını** kontrol eder.

Bu tür kontroller; rezervasyon sistemleri, akademik takvimler, sınav planları, abonelik geçerliliği gibi birçok gerçek dünya senaryosunda hayati öneme sahiptir.

---

## 📌 Programın İşleyişi

1. Kullanıcıdan bir tarih aralığı (başlangıç ve bitiş tarihleri) alınır.
2. Ardından ayrı bir tarih (kontrol edilecek tarih) girilir.
3. `IsDateWithinPeriod()` fonksiyonu ile bu tarih, aralık içinde mi kontrol edilir.
4. Sonuç kullanıcıya `"Yes, Date is within period"` veya `"No, Date is Not within period"` olarak gösterilir.

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

Enter Date to check
Please enter a Day
5
Please enter a month
5
Please enter a year
2024

Yes, Date is within period
```

---

## 🔍 Kullanılan Fonksiyonlar

| Fonksiyon                 | Açıklama                                                       |
| ------------------------- | -------------------------------------------------------------- |
| `ReadDate()`              | Kullanıcıdan tarih okur                                        |
| `ReadPeriod()`            | Başlangıç ve bitiş tarihinden oluşan bir tarih aralığı alır    |
| `IncreaseDateByOneDays()` | Tarihi bir gün ileri alır                                      |
| `IsDate1AfterDate2()`     | Tarih karşılaştırması yapar (sonra mı?)                        |
| `ISDate1BeforeDate2()`    | Tarih karşılaştırması yapar (önce mi?)                         |
| `SwapDates()`             | Tarihleri büyükten küçüğe sıralar                              |
| `GetDifferenceInDays()`   | İki tarih arasındaki farkı gün olarak hesaplar                 |
| `IsDateWithinPeriod()`    | Verilen bir tarihin aralık içinde olup olmadığını kontrol eder |

---

## 🧠 Önemli Detaylar

* Program, tarihleri sıralama kontrolü içerdiği için `SwapDates` fonksiyonu ile ters girişlerde hata oluşmaz.
* Tarih aralığına hem başlangıç hem bitiş tarihi dahildir.
* Tarihler karşılaştırılırken `day/month/year` bileşenleri sırayla kontrol edilir.

---

## 🛠️ Kullanılan Veri Yapıları

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

Bu problemin çözülmesindeki ana hedef:

* Tarih karşılaştırmaları konusunda pratik kazanmak,
* Tarih kontrolü gerektiren sistemlerin temellerini anlamak,
* Yapısal veri tipleri (`struct`) ile programlamada modülerliği artırmak.

Bu yapı, zaman tabanlı karar verme işlemleri için sağlam bir altyapı sunar.

---

