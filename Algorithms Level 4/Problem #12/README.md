## 💡 Problem Tanımı

Kullanıcıdan bir tarih (gün, ay, yıl) ve eklemek istediği gün sayısı alınır. Bu bilgiye dayanarak, girilen tarihten itibaren kaç gün geçince hangi tarihe ulaşıldığı hesaplanır. Problem, hem artık yılları hem de ayların gün sayılarını doğru şekilde dikkate almalıdır.

---

## 📌 Programın İşleyişi

Bu problem **iki farklı yöntemle** çözülmüştür:

### 🔹 1. Yöntem – Yılbaşı Gün Sırası Yöntemi

* Önce girilen tarih yılbaşından itibaren kaçıncı gün olduğu hesaplanır (`calculateDayOfYear`).
* Girilen gün sayısı bu sıraya eklenir.
* Yıl sonunu geçerse, artık yıllar dikkate alınarak yeni yıl ve kalan gün hesabı yapılır.
* Yeni tarih `calculateDateFromDayOfYear` fonksiyonuyla oluşturulur.

### 🔹 2. Yöntem – Yapı Tabanlı Gün Gün İlerletme

* Kullanıcının girdiği tarih `struct Sdate` yapısıyla alınır.
* Tarih, doğrudan gün gün ilerletilerek ay ve yıl geçişleriyle güncellenir.
* Her ay sonunda günler sıfırlanır, ay arttırılır. Aralık ayı sonrası yıl arttırılır.
* Son tarih `DateAddDayes` fonksiyonuyla hesaplanır.

---

## ✅ Örnek Çıktı

### Girdi:

```
Day     : 29  
Month   : 2  
Year    : 2000  
Add Days: 365
```

### Çıktı:

```
Number of days the beginning of the year is 60  
Date after adding [365] days is 28/2/2001
```

---

## 🎯 Amaç

Bu problemin amacı, tarih hesaplamalarını doğru şekilde gerçekleştirebilmek, artık yıl mantığını kavramak ve kullanıcıdan alınan girdiye göre zaman üzerinde doğru işlemler yapabilmektir. Ayrıca iki farklı algoritma yaklaşımıyla aynı problemi çözerek yazılımsal düşünme becerisi ve algoritma çeşitliliği kazandırmak hedeflenmiştir.
