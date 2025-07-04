### 🧮 Proje: Matematik Test Oyunu (Soru Üretici & Değerlendirici)

---

### 📌 Problem Tanımı

Bu C++ konsol projesi, kullanıcıya dinamik olarak matematiksel işlemlerden oluşan sorular üretir ve cevaplarını değerlendirir. Kullanıcıdan seviyeye ve soru türüne göre rastgele oluşturulmuş işlemleri çözmesi beklenir. Sonuç olarak, toplam doğru/yanlış cevap sayısı ile birlikte başarı durumu gösterilir.

---

### 🛠️ Programın Temel Özellikleri

#### 🔹 Oyun Akışı:

1. **Soru Sayısı Girişi**
   Kullanıcıdan 1–1000 arasında kaç soru çözmek istediği alınır.
2. **Seviye ve Soru Tipi Seçimi**

   * Seviye:

     * 1: Kolay (0–15)
     * 2: Orta (16–70)
     * 3: Zor (70–120)
     * 4: Karışık (0–120)
   * Soru Tipi:

     * 1: Toplama
     * 2: Çıkarma
     * 3: Çarpma
     * 4: Bölme
     * 5: Karışık
3. **Soru Üretimi ve Değerlendirme**
   Her soru:

   * Rastgele sayılarla oluşturulur.
   * İşleme göre sonuç hesaplanır.
   * Kullanıcıdan cevap alınır.
   * Doğruysa skor artar, yanlışsa renk değişerek uyarı verilir.
4. **Sonuç Ekranı**

   * Toplam soru sayısı
   * Doğru cevap sayısı
   * Yanlış cevap sayısı
   * Başarılı veya başarısız değerlendirmesi (renkli çıktı)

---

### ✅ Örnek Oyun Akışı

```
Lutfen Cevablamak İstediniz Soruların Sayısını Giriniz 
> 3

-----------------------------------------
       Math Oyunla Hoşgeldiniz 
-----------------------------------------
{    1.KOLAY,  2.ORTA , 3.ZOR , 4.MİX        }
LUTFEN SORULARIN SEVİYESİNİ SEÇİNİZ : 1

{    1.TOPLAMA,  2.ÇIKARTMA , 3.ÇARPIMA , 4.BÖLME, 5.MİX        }
LUTFEN SORULARIN TİPİNİ SEÇİNİZ : 5

1. SORU : 12*4 ? 
> 48
Cevabınız Doğru

2. SORU : 8-14 ?
> -6
Cevabınız Doğru

3. SORU : 3+9 ?
> 13
Yalnış Cevab

Sorulan Soruların Sayısı : 3  
Sorulan DOğru Soruların Sayısı : 2  
Sorulan Yalnış Soruların Sayısı : 1  
Başardınız ! ✅
```

---

### 🎯 Amaç

Bu proje ile kullanıcı:

* Dört işlem pratiği yapar,
* Seviye ve tür bazlı soru çözerek zorluk ayarı ile çalışır,
* Hatalarını görerek öğrenme şansı yakalar.

Ayrıca geliştirici olarak:

* Fonksiyonlara ayrılmış modüler yapı,
* Kullanıcı girişi doğrulama (validasyon),
* Rastgele sayı üretimi (`rand()`),
* Temiz kullanıcı deneyimi için renkli ekran desteği (`system("color")`)
* `switch-case`, `char` işlemleri gibi C++ temelleri
  üzerinde kapsamlı bir pekiştirme kazanılır.

---

### 🗂️ Dosya Bilgisi

* **Dosya Adı**: `math_quiz_game.cpp`
* **Kategori**: Konsol Eğitim Oyunu
* **Seviye**: Orta Seviye

---

### 🔧 Geliştirme Önerileri

* **Zaman sınırı** eklenerek refleks testi yapılabilir.
* **Skor kaydı** dosyaya yazılarak geçmiş performans gösterilebilir.
* **Seçim menüsü görselleştirilebilir** (örneğin ASCII kutucuklar).
* **Negatif bölme hatalarına** karşı koruma eklenebilir (`number2 != 0`).
* **Sesli geri bildirim** (beep sesi veya "Correct!" / "Wrong!") eklenebilir.

---

Bu proje hem oyunlaştırma hem de algoritmik düşünmeyi birlikte sunan başarılı bir öğrenim aracıdır.
