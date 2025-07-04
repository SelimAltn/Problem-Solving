### 💡 Problem Tanımı

Bu program, kullanıcıdan bir dizi boyutu alır ve 1 ile 100 arasında rastgele sayılarla bir dizi oluşturur. Ardından bu dizideki **asal sayıları** tespit ederek ayrı bir diziye kopyalar ve her iki diziyi ekrana yazdırır.

📌 **Programın İşleyişi:**

1. Kullanıcıdan dizi boyutu alınır (`1–100` arası).
2. İlk dizi rastgele sayılarla (`1–100` arası) doldurulur.
3. `kontrol()` fonksiyonu kullanılarak her sayının asal olup olmadığı kontrol edilir.
4. Asal sayılar ikinci diziye aktarılır.
5. Her iki dizi ekrana yazdırılır.

📌 **Asal Sayı Kontrolü:**
Bir sayının asal olması için sadece 1 ve kendisine bölünebilmesi gerekir. Program, 2’den sayının yarısına kadar olan bölme işlemleriyle asal sayı kontrolü yapar.

---

### ✅ Örnek Çıktı

```
enter a Arry size ? 
10
asıl matris : 
56 13 9 23 44 17 20 89 7 38 
2. : 
13 23 17 89 7 
```

> Not: Sayılar her çalıştırmada farklı üretilecektir.

---

### 🎯 Amaç

Dizi içerisindeki asal sayıların filtrelenmesini öğretmek; enum kullanımı, fonksiyonel ayrım, dizilerde kopyalama ve kullanıcı girdisine göre dinamik işlem yapmayı pekiştirmek.
