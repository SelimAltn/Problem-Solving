## 📅 İki Tarihin Eşitliğini Kontrol Etme

---

### 💡 Problem Tanımı

Kullanıcıdan iki farklı tarih bilgisi alınır ve bu iki tarihin **tamamen aynı olup olmadığı** kontrol edilir. Gün, ay ve yıl bilgileri birebir aynıysa tarihler eşittir kabul edilir.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan iki tarih alınır (`day`, `month`, `year`).
2. `IsDate1EqualDate2()` fonksiyonu ile bu iki tarih karşılaştırılır.
3. Eşitlik durumu ekrana yazdırılır:

   * Eğer gün, ay ve yıl tümüyle eşitse → eşit kabul edilir.
   * Herhangi bir farklılık varsa → eşit değildir.

---

### ✅ Örnek Çıktı

**Girdi:**

```
Please enter a Day  
15  
Please enter a month  
6  
Please enter a year  
2024  
Please enter a Day  
15  
Please enter a month  
6  
Please enter a year  
2024  
```

**Çıktı:**

```
Yes, Date1 is Equal To Date2.
```

---

### 🎯 Amaç

Bu problem, tarihsel verilerle çalışırken **karşılaştırma mantığını** kavratmayı ve `struct`, `input validation` gibi temel C++ konularını uygulamayı hedefler. Ayrıca koşullu mantık (`ternary if` zinciri) ile fonksiyon yazımı pratiği kazandırır.
