### 💡 Problem Tanımı

Bu program, 1 ile 10 arasında rastgele üretilen 3 farklı sayıyı ekrana yazdırır. Her sayı, standart kural olan `[alt sınır, üst sınır]` aralığında olacak şekilde üretilir.

📌 **Programın Kuralları:**

* `srand(time(0))` ifadesiyle her çalıştırmada farklı sayılar üretilmesi sağlanır.
* `ReadNumber(form, to)` fonksiyonu, verilen aralıkta bir rastgele sayı döndürür.
* `Print1_10RastgeleSayiler` fonksiyonu, bu sayıları 3 kez çağırarak çıktı verir.

---

### ✅ Örnek Çıktı

```
1. number : 3
2. number : 9
3. number : 7
```

> Not: Çıktılar her çalıştırmada farklı olacaktır.

---

### 🎯 Amaç

Belirli bir aralıkta rastgele sayı üretmeyi ve bu sayıları kullanıcıya sunmayı öğrenmek; ayrıca `rand()`, `srand()`, `time(0)` fonksiyonlarının kullanımını pekiştirmek.
