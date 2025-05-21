Aşağıda bu problem için detaylı ve düzenli bir açıklama yer almaktadır:

---

## 📅 Ayın ve Yılın Son Günü Kontrolü

---

### 💡 Problem Tanımı

Kullanıcıdan bir tarih alınır. Girilen tarihteki gün ve ay bilgisi kullanılarak:

* Bu gün, ait olduğu ayın **son günü mü**?
* Bu ay, yılın **son ayı mı**?

sorularının yanıtı hesaplanır ve kullanıcıya gösterilir.

---

### 📌 Programın İşleyişi

1. `ReadNumber()` fonksiyonu ile kullanıcıdan sırasıyla gün, ay ve yıl bilgileri alınır.
2. `IsLeapYear()` fonksiyonu, yılın artık yıl olup olmadığını kontrol eder.
3. `NumberOfDayesInMonth()` fonksiyonu, ilgili ayın kaç gün çektiğini belirler.
4. `IsLastDayInMonth()` fonksiyonu, girilen günün ayın son günü olup olmadığını kontrol eder.
5. `IsLastMonthInYear()` fonksiyonu, girilen ayın yılın son ayı (Aralık) olup olmadığını kontrol eder.
6. Sonuçlar kullanıcıya yazdırılır.

---

### ✅ Örnek Çıktı

**Girdi:**

```
Please enter a Day  
31  
Please enter a month  
12  
Please enter a year  
2024  
```

**Çıktı:**

```
yes, Day is Last day in month  
yes, month is Last month in Year  
```

---

### 🎯 Amaç

Bu uygulama, kullanıcıdan alınan tarih verisiyle **ay sonu ve yıl sonu tespiti** yapmayı öğretmeyi amaçlar. Aynı zamanda:

* Koşullu ifadeler (ternary operator)
* Fonksiyonlara sorumluluk dağıtımı
* Tarihsel hesaplama mantığı

gibi programlama becerilerini pekiştirir.
