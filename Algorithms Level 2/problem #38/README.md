### 💡 Problem Tanımı

Bu program, kullanıcıdan bir dizi boyutu alarak 1 ile 100 arasında rastgele tam sayılardan oluşan bir dizi (`arri1`) üretir. Ardından bu dizideki **yalnızca tek sayı** olan elemanları yeni bir diziye (`arri2`) kopyalar ve her iki diziyi kullanıcıya gösterir.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan dizinin boyutu alınır (`1–100` arası).
2. `arri1` dizisi, rastgele sayılarla doldurulur (`1–100` arası).
3. `arri1` dizisindeki **tek sayılar**, `arri2` dizisine aktarılır.
4. Hem `arri1` hem de `arri2` dizileri formatlı şekilde ekrana yazdırılır.

> Not: Dizi yazımı `Arri 1 : { ... }` formatında yapılır.

---

### ✅ Örnek Çıktı

```
enter arri size : 
10
Arri 1 :{ 17,82,45,64,39,28,9,73,54,91}
Arri 2 :{ 17,45,39,9,73,91}
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Rastgele sayı üretimi (`rand()`),
* Tek/sayı kontrolü (`% 2 != 0`),
* Dizi filtreleme ve kopyalama işlemi,
* Referansla uzunluk güncelleme (`int &size2`)

gibi dizi temelli veri işleme yeteneklerini kazandırmayı hedefler. Ayrıca çıktı biçimlendirme ile kullanıcı deneyimini iyileştirme pratikleri de içerir.
