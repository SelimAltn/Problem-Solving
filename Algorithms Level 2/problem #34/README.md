### 💡 Problem Tanımı

Bu program, kullanıcıdan bir dizi boyutu alarak 1 ile 100 arasında rastgele sayılardan oluşan bir dizi üretir. Daha sonra kullanıcıdan bir sayı alarak bu sayının dizide **bulunup bulunmadığını** kontrol eder. Eğer sayı dizide bulunursa, **indeksi ve sırası** kullanıcıya gösterilir. Bulunamazsa, kullanıcı bilgilendirilir.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan dizinin boyutu alınır (`1–100`).
2. Dizi `1–100` arası rastgele sayılarla doldurulur.
3. Dizi ekrana yazdırılır.
4. Kullanıcıdan aramak istediği eleman alınır.
5. Eleman dizide aranır:

   * Bulunursa → İndeksi ve konumu (1 tabanlı) gösterilir.
   * Bulunamazsa → Uyarı mesajı verilir.

> Not: `ElemanArama()` fonksiyonu sadece **ilk bulunan konumu** döndürür.

---

### ✅ Örnek Çıktı

```
istediniz eleman sayisi giriniiz ?  
10
[ 3,56,77,25,89,43,90,17,38,10 ]
aramak istediniz sayi giriniz 
43
elemanı bulduk 
elemanın indexi : 5
eleman konumu : 6
```

---

### 🎯 Amaç

* Rastgele sayı üretme,
* Dizilerde eleman arama işlemi,
* Kullanıcıyla etkileşimli giriş-çıkış yapma,
* Dizi indeksleme ve pozisyon farkını anlama (0 tabanlı ve 1 tabanlı sistem farkı)
  gibi temel algoritma yeteneklerini pekiştirmeyi amaçlar.
