

## 💡 Problem Tanımı

Bu program, kullanıcıdan alınan iki tarih arasındaki ilişkiyi belirler:

* Birinci tarih, ikinci tarihten önce mi?
* Birinci tarih, ikinci tarihten sonra mı?
* Yoksa iki tarih birbirine eşit mi?

Program, bu karşılaştırma sonucunu kullanıcıya bir enum değeri olarak verir:

* `-1` → Birinci tarih **önce**
* ` 0` → İki tarih **eşit**
* `+1` → Birinci tarih **sonra**

---

## 📌 Programın İşleyişi

1. Kullanıcıdan iki tarih alınır:

   * `ReadDate()` fonksiyonu ile (gün, ay, yıl ayrı ayrı alınır)
2. Tarihler, üç farklı yardımcı fonksiyon ile kıyaslanır:

   * `IsDate1EqualDate2()` – eşit mi?
   * `IsDate1AfterDate2()` – sonra mı?
   * `IsDate1BeforeDate2()` – önce mi?
3. Karşılaştırma sonucu `CompareDates()` fonksiyonu tarafından `enum enDateCompare` değerine dönüştürülür.
4. Sonuç konsola yazdırılır.

---

## ✅ Örnek Çıktı

```txt
Enter date 1: 
Please enter a Day
20
Please enter a month
5
Please enter a year
2024
Enter date 2: 
Please enter a Day
19
Please enter a month
5
Please enter a year
2024

Compare Result = 1
```

📌 Bu durumda `1` değeri, **ilk tarih ikinci tarihten sonradır** anlamına gelir.

---

## 🔢 Kullanılan Enum

```cpp
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
```

Bu `enum` sayesinde kod daha okunabilir hale gelir ve karşılaştırma sonucu sade bir sayı yerine anlamlı bir değer olur.

---

## 🛠️ Kullanılan Temel Fonksiyonlar

| Fonksiyon              | Açıklama                                        |
| ---------------------- | ----------------------------------------------- |
| `ReadDate()`           | Tarih girişi yapar                              |
| `IsDate1EqualDate2()`  | İki tarih eşit mi kontrol eder                  |
| `IsDate1AfterDate2()`  | İlk tarih daha sonra mı kontrol eder            |
| `ISDate1BeforeDate2()` | İlk tarih daha önce mi kontrol eder             |
| `CompareDates()`       | Yukarıdaki 3 fonksiyonu kullanarak sonucu döner |

---

## 🎯 Amaç

Bu problemin amacı, tarih yapılarıyla işlem yapmayı öğrenmek ve:

* Tarih karşılaştırması yapmak
* Koşul ve `enum` kullanımıyla program kontrolünü geliştirmek
* Fonksiyonel programlama alışkanlıkları kazanmak

---
