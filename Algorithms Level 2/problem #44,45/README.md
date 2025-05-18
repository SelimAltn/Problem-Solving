### 💡 Problem Tanımı

Bu program, kullanıcıdan 0 ile 100 arasında bir sayı alarak bu uzunlukta **pozitif ve negatif değerler içerebilecek** rastgele bir dizi oluşturur. Ardından bu diziyi analiz ederek:

* Pozitif sayıların bir alt dizisini oluşturur,
* Negatif sayıların bir alt dizisini oluşturur,
* Her bir grubun sayısını ve toplam değerini hesaplar ve ekrana yazdırır.

---

### 📌 Programın İşleyişi

1. **Giriş**:

   * Kullanıcıdan `0–100` arasında dizi uzunluğu alınır.
2. **Dizi Üretimi**:

   * `DiziOlusturma()` fonksiyonu `-100` ile `100` aralığında rastgele sayılar üretir.
   * `0` sayısı üretilmez (kontrol vardır).
3. **Pozitif Sayı Analizi**:

   * `PozitifSayilerininSayaci()` fonksiyonu:

     * Pozitif elemanları yeni diziye aktarır.
     * Toplam sayı ve toplam değeri hesaplar.
4. **Negatif Sayı Analizi**:

   * `NegatifSayilerininSayaci()` fonksiyonu:

     * Negatif elemanları yeni diziye aktarır.
     * Toplam sayı ve toplam değeri hesaplar.
5. **Çıktı**:

   * Rastgele üretilen dizinin tamamı ve alt diziler formatlı olarak yazdırılır.

---

### ✅ Örnek Çıktı

```
istediniz Arri Uzunlu Giriniz :
15
{ 50 -22 18 74 -61 99 -13 87 -4 -98 1 62 41 -17 8 }

Pozitif Sayilar : { 50 18 74 99 87 1 62 41 8 }
pozitif Sayıların Sayısı : 9
Poziti Sayıların Toplamı : 440

Negatif Sayilar : { -22 -61 -13 -4 -98 -17 }
Negatif Sayıların Sayısı : 6
Negatif Sayıların Toplamı : -215
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Pozitif ve negatif sayıların ayrımını yapma,
* Alt diziler oluşturma ve veri filtreleme,
* Toplam ve sayım yapma işlemleri,
* Fonksiyonel tasarım ve temiz çıktı üretimi

gibi önemli algoritmik yetenekleri kazandırır. Aynı zamanda **koşullu dizi bölme** ve **istatistiksel veri analizi** pratiği sunar.
