### 🎮 Proje: Taş-Kağıt-Makas Oyunu (Konsol Versiyonu)

---

### 📌 Problem Tanımı

Bu proje, kullanıcının bilgisayara karşı **"Taş-Kağıt-Makas"** oyunu oynayabileceği basit bir konsol tabanlı uygulamadır. Oyun kaç tur oynanacağı ile başlar, her turda kullanıcı ve bilgisayar seçim yapar, sonuçlar karşılaştırılır ve sonunda detaylı bir özet ekranı sunulur.

---

### 🛠️ Programın Temel Özellikleri

#### 🔸 Giriş ve Karşılama:

* Oyuncuya hoş geldin mesajı gösterilir.
* Oyuncudan **1–10 arası tur sayısı** istenir.

#### 🔸 Oyun Mekaniği:

* Her turda kullanıcıdan bir seçim alınır:

  * `1 = Taş`
  * `2 = Kağıt`
  * `3 = Makas`
* Bilgisayar rastgele bir seçim yapar (`rand()` fonksiyonu ile).
* Seçimler karşılaştırılır ve sonuç anında gösterilir.
* Kazanan tura göre skorlar güncellenir.
* Ekran rengi:

  * Yeşil: Kullanıcı kazandı
  * Kırmızı: Bilgisayar kazandı
  * Sarı: Berabere

#### 🔸 Oyun Sonu Özeti:

* Toplam tur sayısı
* Kullanıcının kazandığı tur sayısı
* Bilgisayarın kazandığı tur sayısı
* Beraberlik sayısı
* Son kazanan (kim daha çok kazandıysa)

#### 🔸 Tekrar Oynama:

* Oyun bittikten sonra kullanıcıya tekrar oynamak isteyip istemediği sorulur.
* Eğer isterse ekran temizlenir (`system("cls")`) ve yeni oyun başlatılır.

---

### ✅ Örnek Oyun Akışı

```
--------------------------------------------
Taş-Makas-Kağaıt Oyunla Hoşgeldiniz 
--------------------------------------------
Lütfen Kaç Kere Oynamak İstediniz tur Sayısını Giriniz : 3

----------- 1. TUR --------------
{ 1.TAŞ 2.KAĞIT 3.MAKAS }
Oynamak İstediniz Seçimi Numara Olarak Yazınız : 1
          (1.Player Kazandı)
1.Player :TAŞ ------  2.Player : MAKAS

----------- 2. TUR --------------
{ 1.TAŞ 2.KAĞIT 3.MAKAS }
Oynamak İstediniz Seçimi Numara Olarak Yazınız : 2
          (BİLGİSAYAR Kazandı)
1.Player :KAĞIT ------  2.Player : MAKAS

----------- 3. TUR --------------
{ 1.TAŞ 2.KAĞIT 3.MAKAS }
Oynamak İstediniz Seçimi Numara Olarak Yazınız : 2
          (Berabere)
1.Player :KAĞIT ------  2.Player : KAĞIT

---------------------------------------------
               Oyunun Özeti : 
---------------------------------------------
Tur  Sayısı :    3
1.Player Oyun Kazanma Sayısı :   1
2.Player Oyun Kazanma Sayısı :   1
Berabere Oyun Sayısı :   1
Son Kazanan :    Beraberlik
Yeni Oyun Oynamak İstiyormusunuz ? (evet : 1 , Hayır :0 )
```

---

### 🎯 Amaç

Bu proje şu kazanımları hedefler:

* Koşullu yapılar (`if-else`)
* Rastgele sayı üretimi (`rand`)
* Döngüler ve kullanıcı etkileşimi
* Fonksiyonel programlama (görev ayrımı)
* Renkli ekran çıkışı (`system("color")`)
* Konsol temizleme ve tekrar oynama yapısı (`system("cls")`)
* Basit yapay zekaya karşı oyun mantığı

---

### 🧠 Geliştirilebilecek Özellikler

* Skorların dosyaya kaydedilmesi
* Kullanıcının adıyla giriş yapması
* Gelişmiş grafik veya GUI versiyonu (SFML, SDL vs.)
* Karakter animasyonu veya ses efekti desteği

---

### 🗂️ Dosya Bilgisi

* **Dosya Adı**: `tas_kagit_makas.cpp`
* **Kategori**: Konsol Oyun Projesi
* **Seviye**: Başlangıç-Orta

---

> Bu proje, C++ öğrenmeye başlayanlar için hem eğlenceli hem de kapsamlı bir pekiştirme uygulamasıdır. Mantık, koşul, rastgelelik ve kullanıcı arayüzü deneyimi açısından oldukça öğreticidir.
