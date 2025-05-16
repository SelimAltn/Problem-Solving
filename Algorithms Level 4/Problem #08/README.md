### 💡 Problem Tanımı

Bu program, kullanıcıdan **ay ve yıl** bilgisi alarak o aya ait **takvimi haftalık düzende** ekrana yazdırır. Takvim, **hafta Pazartesi ile başlayacak** şekilde biçimlendirilir. Ay ismi ve günler hizalı olarak gösterilir ve her hafta bir satıra yerleştirilir.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan ay (`1–12`) ve yıl (`1–3000`) alınır.
2. Girilen yıla göre ilgili ayın gün sayısı hesaplanır (Artık yıl kontrolü de dahil).
3. Ayın ilk gününün haftanın hangi gününe denk geldiği belirlenir.
4. Takvim başlığı ve gün isimleri yazdırılır.
5. Günler, **printf** ile sabit genişlikte hizalanarak takvim şeklinde ekrana yerleştirilir.

### ✅ Örnek Çıktı

```
------------------May------------------

  Mon  Tue  Wed  Thu  Fri  Sat  Sun
               1    2    3    4    5
   6    7    8    9   10   11   12
  13   14   15   16   17   18   19
  20   21   22   23   24   25   26
  27   28   29   30   31
--------------------------------------

```

---

### 🎯 Amaç

Kullanıcının tarihsel verilerle çalışarak bir takvim oluşturmasını sağlamak. Özellikle `printf` fonksiyonu ile **hizalı ve biçimli çıktı üretimi**, hafta başlangıcını değiştirme ve döngüyle düzenli yapı kurma yetilerini geliştirmek.