### 💡 Problem Tanımı

Bu program, kullanıcıdan bir **yıl** bilgisi alarak o yılın:

* Artık yıl (**leap year**) olup olmadığını belirler,
* O yılın kaç **gün**, **saat**, **dakika** ve **saniye** içerdiğini hesaplayarak ekrana yazdırır.

📌 İşleyiş Adımları:

1. Yıl bilgisi kullanıcıdan alınır.
2. Eğer yıl artık yıl ise toplam gün sayısı 366, değilse 365 olarak belirlenir.
3. Gün sayısı kullanılarak:

   * Saat = gün × 24
   * Dakika = saat × 60
   * Saniye = dakika × 60
     işlemleriyle diğer değerler hesaplanır.
4. Sonuçlar kullanıcıya yazdırılır.
5. Kullanıcı isterse yeni yıl girişiyle devam edebilir.

🔍 Örnek:

* Giriş: `2024`
  Çıktı:

  ```
  Number of deys  in year [ 2024 ]is : 366
  Number of Hores in year [ 2024 ]is : 8784
  Number of min  in year [ 2024 ]is : 527040
  Number of Sec  in year [ 2024 ]is : 31622400
  ```

Amaç, bir yılın süresini farklı zaman birimlerine çevirerek kullanıcıya bilgi sunmaktır.
