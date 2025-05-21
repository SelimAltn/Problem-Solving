💡 **Problem Tanımı**
Bu program, kullanıcıdan bir tarih (gün, ay, yıl) alarak verilen tarihe **bir gün ekleyen** iki farklı yöntemi gösterir. Tarihin sonunda gelen ay veya yıl değişimini doğru şekilde işleyerek, geçerli yeni tarihi hesaplar. Özellikle **ayın son günü** ve **yılın son ayı** gibi özel durumlar dikkate alınmıştır.

---

📌 **Programın İşleyişi**

1. Kullanıcıdan sırasıyla gün, ay ve yıl bilgisi alınır.
2. `AddOneDay` fonksiyonu klasik `if` bloklarıyla bir gün ekler.
3. `AddOneDay2` fonksiyonu ise aynı işlemi **ternary (koşullu) operatör** ile daha kısa şekilde gerçekleştirir.
4. Her iki fonksiyon da sonucu `Sdate` yapısı olarak döndürür ve ekrana yazdırılır.

---

✅ **Örnek Çıktı**

```
Please enter a Day
31
Please enter a month
12
Please enter a year
2023
(1) Date after adding one day is : 1/1/2024
(2) Date after adding one day is : 1/1/2024
```

---

🎯 **Amaç**

* Yapısal veri tipi (`struct`) kullanarak tarih verisini yönetmek.
* Tarih işlemleri için `if-else` ve `ternary operator` kullanımı örneği sunmak.
* Ayın ve yılın son gününü doğru şekilde algılayarak bir gün ekleme işlemini güvenilir biçimde gerçekleştirmek.
* Alternatif çözüm yollarını karşılaştırarak farklı programlama yaklaşımlarını pekiştirmek.
