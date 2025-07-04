### 💡 Problem Tanımı

Bu program, ASCII karakter aralıklarını kullanarak dört farklı kategoriden rastgele birer karakter üretir ve bunları ekrana yazdırır.

📌 **Karakter Kategorileri:**

1. Büyük harf (`A`–`Z`) → ASCII: 65–90
2. Küçük harf (`a`–`z`) → ASCII: 97–122
3. Özel karakter (`!`–`/`) → ASCII: 33–47
4. Rakam (`0`–`9`) → ASCII: 48–57

📌 **Programın İşleyişi:**

* `ReadNumber(form, to)` fonksiyonu verilen aralıkta rastgele sayı üretir.
* `secim(...)` fonksiyonu, istenen karakter türüne göre bu sayıyı karaktere dönüştürür.
* `Print()` fonksiyonu, her türden bir karakter üretip yazdırır.
* `srand(time(0))` ile her çalıştırmada farklı karakterler üretilmesi sağlanır.

---

### ✅ Örnek Çıktı

```
buyuk harf :R
kuçuk harf : n
karakter : #
rakam :  7
```

> Not: Üretilen karakterler her çalıştırmada değişkenlik gösterir.

---

### 🎯 Amaç

ASCII tablosu kullanarak farklı türlerde karakterlerin rastgele nasıl üretileceğini öğretmek ve `enum`, `switch`, `rand()` fonksiyonlarıyla birlikte kullanmayı pekiştirmek.
