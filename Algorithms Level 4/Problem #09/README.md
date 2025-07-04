### 💡 Problem Tanımı

Bu program, kullanıcıdan bir **yıl** bilgisi alır ve bu yıla ait **12 ayın tamamının takvimini** haftalık düzende ekrana yazdırır. Her ay kendi başlığı altında, **hafta Pazartesi ile başlayacak şekilde hizalanmış** olarak gösterilir. Ayrıca, ay ve yıl bilgisi başlık olarak yazılır, günler ise alt alta düzgün biçimde yerleştirilir.

---

### 📌 Programın Özellikleri

* Kullanıcıdan yıl bilgisi istenir (`1–3000` arası).
* Her ay için:

  * Ay adı ve yıl başlık olarak yazdırılır.
  * Gün isimleri: `Mon Tue Wed Thu Fri Sat Sun` olarak sıralanır.
  * Günler, Zeller’s algoritması kullanılarak haftalık düzende hizalanır.
  * Artık yıl kontrolü sayesinde Şubat ayı 28 veya 29 gün olarak işlenir.
* `printf` fonksiyonuyla her hücre sabit genişlikte yazılır (`%4d`) ve düzenli görünüm sağlanır.

---

### ✅ Örnek Çıktı

```
==============================
        Calendar - 2024
==============================

----------- January 2024 -----------
 Mon  Tue  Wed  Thu  Fri  Sat  Sun
  1    2    3    4    5    6    7 
  8    9   10   11   12   13   14 
 15   16   17   18   19   20   21 
 22   23   24   25   26   27   28 
 29   30   31 
-------------------------------

----------- February 2024 -----------
 Mon  Tue  Wed  Thu  Fri  Sat  Sun
           1    2    3    4 
  5    6    7    8    9   10   11 
 12   13   14   15   16   17   18 
 19   20   21   22   23   24   25 
 26   27   28   29 
-------------------------------

... [Tüm aylar benzer şekilde devam eder]
```

---

### 🎯 Amaç

Kullanıcının tarih bilgilerini kullanarak **bir yılın tam takvimini** yazdırmayı öğrenmesi; Zeller’s algoritmasıyla haftanın gününü hesaplama, iç içe döngülerle formatlı çıktı oluşturma, `printf` ile hizalama ve artık yıl mantığını uygulama gibi temel ve ileri düzey programlama becerilerini birleştirmesini sağlamaktır.
