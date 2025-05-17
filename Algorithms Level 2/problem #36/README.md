### 💡 Problem Tanımı

Bu program, kullanıcıya **dinamik şekilde sayı ekleyebileceği bir dizi** oluşturma imkânı sunar. Kullanıcı sayı girdikçe dizide saklanır, her girişten sonra kullanıcıya yeni bir sayı daha eklemek isteyip istemediği sorulur. İşlem tamamlandığında tüm sayılar ekrana yazdırılır.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan 1 ile 100 arasında bir sayı alınır.
2. Her sayı, diziye eklenir.
3. Her girişten sonra kullanıcıya şu soru sorulur:
   `"başka sayi eklemek istermisiniz ? (1,0 ile cevabla)"`
4. Kullanıcı `1` girerse giriş devam eder, `0` girerse işlem sona erer.
5. Tüm girilen sayılar alt alta yazdırılır.

---

### ✅ Örnek Çıktı

```
enter a number 
45
başka sayi eklemek istermisiniz ? (1,0 ile cevabla)
1
enter a number 
32
başka sayi eklemek istermisiniz ? (1,0 ile cevabla)
0
45 32
```

---

### 🎯 Amaç

Bu program, kullanıcıya:

* Dinamik giriş yapmayı,
* Kullanıcı onayıyla döngüyü kontrol etmeyi,
* `cin` doğrulama (`cin.good()`, `cin.clear()`, `cin.ignore()`) ile güvenli giriş almayı,
* Fonksiyonlara referansla (`&sayac`) veri geçirmeyi öğretmeyi amaçlar.

Gerçek dünya etkileşimlerinde menü-tabanlı veri girişi ve kontrol akışı kurma pratiği kazandırır.
