### 💡 Problem Tanımı

Bu program, kullanıcıdan bir tarih alır (**gün, ay ve yıl**) ve bu tarihin içinde bulunduğu yılın **başlangıcından itibaren kaçıncı gün** olduğunu hesaplar. Hesaplama, **artık yıl kontrolü** yapılarak Şubat ayı için doğru gün sayısı ile gerçekleştirilir.

---

### 📌 Programın İşleyişi

* Kullanıcıdan gün (`1–31`), ay (`1–12`) ve yıl (`1–3000`) bilgisi alınır.
* Her ayın kaç gün çektiği sabit bir dizide tutulur. Şubat için `IsLeapYear()` fonksiyonu ile 28 veya 29 gün olarak değerlendirme yapılır.
* 1 Ocak’tan başlayarak girilen tarihe kadar olan tüm günler toplanır.
* Toplam gün sayısı ekrana yazdırılır.

---

### ✅ Örnek Çıktı

```
Please enter a Day
15
Please enter a month
3
Please enter a year
2024
Number of days the begining of the year is 75
```

> Açıklama:
> Ocak = 31 gün
> Şubat = 29 gün (2024 artık yıl)
> Mart = 15 gün → **Toplam: 31 + 29 + 15 = 75**

---

### 🎯 Amaç

Bir tarihin yılbaşından itibaren kaçıncı gün olduğunu hesaplamayı öğretmek. Ayrıca artık yıl mantığını doğru uygulama, döngü ve dizi yapılarıyla toplama işlemlerini pekiştirme amacı taşır.
