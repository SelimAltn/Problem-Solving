
---

## 💡 Problem Tanımı

Verilen iki tarih (gün, ay, yıl) arasında geçen gün sayısını hesaplayan bir program yazılması istenmektedir. Fark, ilk tarihten ikinci tarihe kadar olan **takvim günleri** cinsinden hesaplanır. Ayrıca isteğe bağlı olarak "son gün dahil" seçeneğiyle bir gün daha eklenebilir.

---

## 📌 Programın İşleyişi

Kullanıcıdan iki tarih alınır. Ardından bu tarihler arasındaki farkı dört farklı algoritma ile hesaplayan dört yöntem uygulanır. Her yöntem aynı sonucu verir fakat yaklaşımları farklıdır.

---

## ✅ Örnek Çıktı

```
Please enter a Day
1
Please enter a month
1
Please enter a year
2024
Please enter a Day
1
Please enter a month
2
Please enter a year
2024
Difference is 31 Day(s)
Difference (Including End Day) is: 32 Day(s)
```

---

## 🔄 Kullanılan 4 Yöntem

---

### 1️⃣ Yöntem: **Toplama ile Fark Hesabı (Swap ve Karşılaştırma Destekli)**

```cpp
short GetDifferenceInDays(stDate date1, stDate date2)
```

* İki tarih arasında doğrudan yıl, ay ve gün bazında fark toplayarak gün cinsinden hesap yapar.
* Eğer birinci tarih ikinci tarihten küçükse, `SwapDates()` fonksiyonu ile tarihlerin yerini değiştirir.
* Ardından:

  * Yıl farkı gün cinsinden toplanır (her yılın 365 veya 366 gün oluşuna göre).
  * Ay farkı toplanır.
  * Gün farkı eklenir.
* `IstDate1EqualDate2()` fonksiyonu ile eşitlik kontrolü yapılır.
* `IstDate1AfterDate2()` fonksiyonu ile sıralama kontrolü yapılır ve gerekirse tarihler `SwapDates()` ile değiştirilir.

**Avantajı:**

* Geriye doğru tarih hesaplamalarını da destekler.
* Kod basittir ve farklı tarih giriş senaryolarında güvenilir sonuç verir.

**Dezavantajı:**

* Ay ve yıl farkları manuel toplandığı için fazla tarih işlemi içeren senaryolarda daha kompleks çözümlere göre daha az esneklik sağlar.

---

### 2️⃣ Yöntem: **Tarihi Gün Gün İlerletme (AddOneDay)**

```cpp
while (IstDate1BeforeDate2(date1, date2)) {
    days++;
    date1 = AddOneDay(date1);
}
```

* Daha küçük olan tarihi her seferinde bir gün ileri alarak diğerine eşitlenene kadar döngü kurar.
* Her adımda gün sayısı bir artırılır.
* `AddOneDay()` fonksiyonu her durumda doğru günü üretir.
* **Avantajı:** Yıl/ay geçişleri otomatik olarak doğru işlenir.
* **Dezavantajı:** Performansı zayıftır. Büyük tarih aralıklarında yavaştır.

---

### 3️⃣ Yöntem: **Yıla Göre Artırmalı Fark Hesabı (Döngüsel ve Gelişmiş)**

```cpp
while (Date1.Year != Date2.Year)
```

* Yıl farkı kadar kalan günler ve ikinci yılın başından hedef tarihe kadar olan günler toplanır.
* Farklı yıllar arasında kalan günler yıl yıl azaltılır.
* **Avantajı:** Farklı yıllarda hassas ve optimize sonuç verir.
* **Dezavantajı:** Karmaşık yapıda olduğu için anlaşılması zaman alabilir.

---

### 4️⃣ Yöntem: **Başlangıç Gününden Toplam Gün Hesabı (Linear Days Counter)**

```cpp
short NumberOfDaysFromBeginningOfYear(...)
```

* Her iki tarihi yılın başlangıcından itibaren geçen gün sayısına çevirir.
* Ardından yıl farklarını toplayarak toplam farkı elde eder.
* `for` döngüsüyle yıl bazında ilerlenir.
* **Avantajı:** Performanslı ve kısa kod ile doğruluk sağlar.
* **Dezavantajı:** Tarihler ters girilirse negatif sonuç dönebilir (ek kontrol gerekebilir).

---

## 🎯 Amaç

Bu çalışmanın amacı, aynı problemi farklı algoritmalarla çözerek tarih hesaplamalarında kullanılabilecek çeşitli yaklaşımları karşılaştırmak ve en uygun olanını seçebilmektir. Farklı çözüm yollarının avantajlarını ve dezavantajlarını görmek; algoritma analizi, tarihsel veri işleme ve tarih aritmetiği konularında sağlam bir temel oluşturmayı amaçlamaktadır.

---

