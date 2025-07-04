### 💡 Problem Tanımı

Bu program, kullanıcıdan bir dizi boyutu alarak 1 ile 100 arasında rastgele sayılardan oluşan bir dizi (`arri1`) oluşturur. Ardından, bu dizideki **asal sayı** olan elemanları başka bir diziye (`arri2`) kopyalar. Son olarak her iki dizi de ekrana yazdırılır.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan dizinin boyutu alınır (`1–100` arası).
2. `arri1` dizisi rastgele `1–100` arasında sayılarla doldurulur.
3. Her bir eleman için asal sayı kontrolü yapılır:

   * Eğer sayı asal ise `arri2` dizisine eklenir.
4. Hem orijinal (`arri1`) hem de sadece asal sayılardan oluşan (`arri2`) diziler ekrana yazdırılır.



### ✅ Örnek Çıktı

```
enter arri size : 
10
Arri 1 :{ 6,13,55,29,12,41,38,2,77,17}
Arri 2 :{ 13,29,41,2,17}
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Asal sayı kontrolü algoritması,
* Rastgele dizi oluşturma,
* Filtreleme mantığı ile yeni dizi üretme,
* Fonksiyonel ve modüler programlama (enum kullanımı dâhil)

gibi temel ve orta seviye algoritma yeteneklerini kazandırmayı amaçlar. Özellikle **asal sayı filtreleme** uygulamalarda sıkça karşılaşılan mantıksal bir problemdir.
