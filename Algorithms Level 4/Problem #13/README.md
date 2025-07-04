
## 📅 Tarih Karşılaştırma Problemi

---

### 💡 Problem Tanımı

Kullanıcıdan iki tarih alınarak, birinci tarihin ikinci tarihten sonra olup olmadığı kontrol edilmek istenmektedir. Amaç, iki tarih arasında kronolojik olarak karşılaştırma yaparak doğru sonucu kullanıcıya bildirmektir.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan sırasıyla iki farklı tarih bilgisi (gün, ay, yıl) alınır.
2. `IsDate1AfterDate2` fonksiyonu yardımıyla birinci tarih ikinci tarihten sonra mı, önce mi olduğuna karar verilir.
3. Sonuç kullanıcıya yazılı olarak bildirilir.

---

### ✅ Örnek Çıktı

**Girdi:**

```
Please enter a Day  
15  
Please enter a month  
4  
Please enter a year  
2024  
Please enter a Day  
10  
Please enter a month  
3  
Please enter a year  
2024  
```

**Çıktı:**

```
yes Date 2 is less than Date 1
```

---

### 🎯 Amaç

Tarih karşılaştırma mantığını öğrenmek ve `struct`, `input validation`, ve `mantıksal kontrol` gibi temel C++ yapılarını pekiştirmek. Özellikle tarihsel verilerle çalışırken karşılaştırma işlemlerinin dikkat gerektirdiği vurgulanır.
