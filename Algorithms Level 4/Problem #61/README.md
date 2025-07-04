

## 💡 Problem Tanımı

Bu programın amacı, iki farklı tarih aralığı (periyot) arasındaki **örtüşen (kesişen) gün sayısını** hesaplamaktır.

Program, hem temel bir yöntemle hem de daha **optimize edilmiş (faster)** bir yöntemle bu hesaplamayı yapar. Böylece farklı algoritma yaklaşımlarının kıyaslanması mümkün olur.

---

## 📌 Programın İşleyişi

1. Kullanıcıdan iki ayrı tarih aralığı (başlangıç ve bitiş tarihleri) alınır.
2. `OverlapDaysCount()` fonksiyonu ile klasik döngü yöntemiyle örtüşme gün sayısı hesaplanır.
3. `OverlapDaysCountFaster()` fonksiyonu ile daha kısa süreli periyot üzerinden optimizasyon yapılır.
4. Sonuçlar kullanıcıya hem normal hem hızlı yöntemle gösterilir.

---

## ✅ Örnek Çıktı

```txt
Enter Period 1 : 
Enter Start Date :
Please enter a Day
5
Please enter a month
5
Please enter a year
2024
Enter End Date :
Please enter a Day
15
Please enter a month
5
Please enter a year
2024

Enter Period 2 :
Enter Start Date :
Please enter a Day
10
Please enter a month
5
Please enter a year
2024
Enter End Date :
Please enter a Day
20
Please enter a month
5
Please enter a year
2024

OverLap Days is : 6
OverLap Days is (faster) : 6
```

---

## 🧠 Kullanılan Fonksiyonlar

| Fonksiyon Adı             | Açıklama                                                                         |
| ------------------------- | -------------------------------------------------------------------------------- |
| `OverlapDays_Classic()`   | İlk periyodun günlerini sırayla kontrol eder, eğer diğer periyot içindeyse sayar |
| `OverlapDays_Optimized()` | Kısa periyodu baz alır ve yalnızca onun üzerinden kontrol yapar                  |
| `OverlapDays_Math()`      | Örtüşen aralığın başlangıcı ve bitişini hesaplar, doğrudan farkı döner           |

---

## 📌 Örtüşme Durumları

İki periyot **örtüşür**:

* Eğer biri diğerinin içinde başlıyor veya bitiyor
* Veya herhangi bir noktada çakışıyorlarsa

Örtüşme **olmaz**:

* Eğer biri diğerinden tamamen önce bitiyorsa

---

## 🎯 Amaç

Bu program sayesinde:

* Tarihlerle çalışma, kıyaslama ve aralık kontrolü pratiği yapılır.
* Gerçek dünya senaryolarında karşılaşılabilecek rezervasyon, izin takibi, randevu yönetimi gibi uygulamalarda kritik bir altyapı oluşturulur.
* Hem doğru hem de performanslı algoritmaların farkı anlaşılır.

---


