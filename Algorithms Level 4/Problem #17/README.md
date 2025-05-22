💡 **Problem Tanımı**
Bu program, kullanıcı tarafından girilen iki tarih arasındaki **gün farkını hesaplar**. Program hem klasik matematiksel yaklaşım hem de tarihler üzerinde art arda birer gün ilerleyerek çalışan bir simülasyon yaklaşımıyla iki farklı çözüm sunar.
Kullanıcıdan iki tarih alınır ve bu tarihler arasındaki mutlak gün farkı hesaplanarak kullanıcıya sunulur.

---

📌 **Programın İşleyişi**
Program iki farklı yöntemle çalışmaktadır:

### 🧮 1. Yöntem – Matematiksel Yaklaşım:

* İki tarih arasındaki yıl, ay ve gün farkı doğrudan hesaplanır.
* Önce yıllar arasında kaç gün olduğu belirlenir (artık yıllar dahil).
* Sonra ay ve gün farkları toplanır.
* Tarihlerin hangisinin büyük olduğu kontrol edilir ve fark pozitif olarak hesaplanır.

### 🔄 2. Yöntem – Adım Adım İlerleme:

* Küçük olan tarihten başlanarak her seferinde bir gün artırılarak ikinci tarihe ulaşılır.
* Kaç adımda ulaşıldığı hesaplanır.
* Opsiyonel olarak bitiş günü de dahil edilip edilmeyeceği kontrol edilebilir (`IncludeEndDay` parametresi).

---

✅ **Örnek Çıktı**

```
Please enter a Day
28
Please enter a month
2
Please enter a year
2020
Please enter a Day
1
Please enter a month
3
Please enter a year
2020
Diffrence is 2 Day (s)
Diffrence (Including End Day) is: 3 Day (s)
```

---

🎯 **Amaç**

* Tarih karşılaştırması yapabilme yeteneğini geliştirmek.
* Artık yıl kontrolü, ay gün sayıları ve tarih ilerletme gibi tarihsel işlemleri yönetmek.
* Aynı sonuca ulaşan farklı algoritmaların kıyaslamasını yapmak.
* `struct`, `bool`, `loop`, `conditional logic`, `modüler fonksiyon kullanımı` gibi temel konuları pekiştirmek.
