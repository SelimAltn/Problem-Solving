### 💡 Problem Tanımı

Bu program, kullanıcıdan sürekli olarak bir sayı alır ve bu sayının **mutlak değerini (absolute value)** hesaplayarak ekrana yazdırır. Program sonsuz döngü içinde çalışır ve kullanıcı çıkış yapmadığı sürece yeni girişleri kabul etmeye devam eder.

---

### 📌 Programın İşleyişi

1. `İnput()` fonksiyonu ile kullanıcıdan bir tamsayı alınır.
2. `MutlakDiger()` fonksiyonu:

   * Sayının mutlak değeri `if` yapısıyla hesaplanır:

     * Eğer sayı negatifse (`number < 0`), `-1` ile çarpılır.
     * Pozitif veya 0 ise olduğu gibi bırakılır.
   * Hem orijinal sayı hem de sonucu ekrana yazdırılır:
     `My abs : |orijinal| = mutlak değer`
3. `main()` fonksiyonu `while (true)` döngüsüyle sürekli çalışır.

---

### ✅ Örnek Çıktı

```
Enter a Number : 
-42
My abs : |-42| = 42

Enter a Number : 
0
My abs : |0| = 0

Enter a Number : 
17
My abs : |17| = 17
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Koşullu ifadelerle (if-else) mutlak değer hesaplamayı,
* Giriş/çıkış işlemleri yapmayı,
* Döngüler ile sürekli çalışan etkileşimli program yazmayı
  öğretir. Ayrıca matematiksel bir kavram olan **|x| = x veya -x** prensibini kod üzerinden pekiştirmeyi amaçlar.
