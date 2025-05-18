### 💡 Problem Tanımı

Bu program, kullanıcıdan sürekli olarak bir sayı alır ve o sayının **karekökünü (√)** hesaplayarak ekrana yazdırır. Program, sonsuz döngü ile çalışır ve kullanıcı yeni giriş yaptıkça karekök hesaplamaya devam eder.

---

### 📌 Programın İşleyişi

1. `ReadNumber()` fonksiyonu kullanıcıdan bir sayı alır.
2. `Sqrt()` fonksiyonu:

   * Girilen sayının karekökü `pow(number, 0.5)` ifadesi ile hesaplanır.
   * Sonuç ekrana yazdırılır.
3. `main()` fonksiyonu `while (true)` döngüsü ile sürekli `Sqrt()` fonksiyonunu çağırır.

> Not: `pow(a, 0.5)` → `√a` işlemini temsil eder.

---

### ✅ Örnek Çıktı

```
Kokumu Almak İstediniz Sayi Giriniz : 
25
 --> = 5

Kokumu Almak İstediniz Sayi Giriniz : 
2
 --> = 1.41421
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Matematiksel fonksiyon kullanımı (`pow`) ile karekök hesaplamayı,
* Sürekli çalışan kullanıcı etkileşimli sistem oluşturmayı,
* Temel `float` ve `cin` kullanımıyla sayı işlemlerini öğrenmeyi
  amaçlar.

Ayrıca `pow(x, 0.5)` yerine dilersen `sqrt(x)` fonksiyonu da doğrudan kullanılabilir (`<cmath>` kütüphanesiyle).
