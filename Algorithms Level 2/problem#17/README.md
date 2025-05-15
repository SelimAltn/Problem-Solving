### 💡 Problem Tanımı

Bu program, kullanıcıdan 3 harfli büyük harflerden oluşan bir **şifre** alır ve tüm olası kombinasyonları deneyerek bu şifreyi **brute-force (kaba kuvvet)** yöntemiyle bulur.

📌 **Programın Kuralları:**

* Şifre yalnızca büyük harflerden (`A`–`Z`) oluşmalıdır ve uzunluğu 3 karakterdir.
* Program, `'AAA'`’dan başlayarak tüm 3 harfli kombinasyonları dener.
* Her denemede hem denenen kelime hem de deneme sayısı ekrana yazdırılır.
* Şifre bulunduğunda, toplam deneme sayısı ve şifre ekrana yazılır.

---

### ✅ Örnek Çıktı

```
enter a pasoord 
AAC
DENEME SAYI : 0 kelime is : AAA
DENEME SAYI : 1 kelime is : AAB
 sifre bulundu : AAC
 DenemeSayisi : 2
```

---

### 🎯 Amaç

Kaba kuvvet algoritmasıyla şifre çözüm mantığını öğretmek; karakter kombinasyonu üretme, karşılaştırma ve sayaç mantığını pekiştirmek.
