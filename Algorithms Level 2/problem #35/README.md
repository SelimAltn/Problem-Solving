### 💡 Problem Tanımı

Bu program, kullanıcıdan bir dizi boyutu alarak rastgele sayılardan oluşan bir dizi oluşturur ve ardından kullanıcıya bu dizide **istediği sayının olup olmadığını** sorgulama imkânı verir. Kullanıcı istediği kadar sayı sorgulaması yapabilir; her sorguda sayı bulunursa olumlu mesaj, bulunamazsa olumsuz mesaj verilir.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan dizi boyutu alınır (`1–100`).
2. Dizi `1–100` arası rastgele sayılarla doldurulur.
3. Dizi ekrana yazdırılır.
4. Kullanıcı, dizide aramak istediği bir sayı girer.
5. Sayı dizide bulunuyorsa `"elemani bulduk (:)"`, bulunmuyorsa `"elemanı yok :("` mesajı verilir.
6. Bu sorgulama süreci sonsuz döngü ile devam eder (kullanıcı işlemi elle sonlandırır).

---

### ✅ Örnek Çıktı

```
istediniz eleman sayisi giriniiz ?  
8
[ 12,87,45,21,66,39,3,90 ]
aramak istediniz sayi giriniz 
45
 elemani bulduk (:

aramak istediniz sayi giriniz 
7
elemanı yok :(
```

---

### 🎯 Amaç

Bu problem, kullanıcıya:
- Rastgele dizi üretme,
- Dizi içerisinde eleman arama,
- Fonksiyonel ayrım ve mantıksal kontrol (`bool` dönüş),
- Sonsuz döngüde sürekli kullanıcı etkileşimi

gibi temel programlama kavramlarını uygulamalı olarak öğretir. Ayrıca `"arama işlemlerinde"` bulunan/bulunmayan durumu ayırt etme ve bu sonucu kullanıcıya açıkça ifade etme yetisi kazandırır.