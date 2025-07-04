
---

## 💡 Problem Tanımı

Kullanıcının doğum tarihi ile bilgisayarın sistem tarihini karşılaştırarak, doğumdan bugüne kadar geçen gün sayısını hesaplayan bir C++ programı geliştirilmiştir.

Bu program, tarih aritmetiği ve sistem tarihine erişim konularını kapsar. Kullanıcıdan bir tarih (gün, ay, yıl) alınır, ardından sistem saatinden güncel tarih elde edilir ve iki tarih arasındaki fark gün cinsinden hesaplanır. İsteğe bağlı olarak "son gün dahil" özelliği de eklenebilir.

---

## 📌 Programın İşleyişi

* `ReadDate()` fonksiyonu kullanıcıdan geçerli bir tarih alır.
* `GetTodayDate()` fonksiyonu sistem saatini okuyarak bugünkü tarihi döndürür.
* `DeferenceBetweenDate1AndDate()` fonksiyonu iki tarih arasındaki farkı hesaplar:

  * Önce yıl bazında fark hesaplanır.
  * Ardından her iki tarihin yıl içindeki gün karşılığı belirlenerek aradaki fark alınır.
* Gün cinsinden fark ekrana yazdırılır.

---

## ✅ Örnek Çıktı

```
Please Enter Your Date Of Birth
Please enter a Day
15
Please enter a month
5
Please enter a year
2000
Your Age is :  9132 Day (s)
```

---

## 🛠️ Kullanılan Yapılar

* `struct stDate` : Tarihi temsil eden veri yapısı (`Day`, `Month`, `Year`).
* `localtime()` : Sistem tarihini almak için kullanılan C++ zaman fonksiyonu.
* `NumberOfDayesInMonth()`, `IsLeapYear()` : Tarih hesaplamaları için yardımcı fonksiyonlar.
* `#pragma warning(disable : 4996)` : Visual Studio'nun `localtime()` uyarısını bastırmak için kullanıldı.

---

## 🧠 Notlar

* `localtime()` fonksiyonu Visual Studio'da güvensiz olarak kabul edildiğinden dolayı `#pragma warning(disable : 4996)` ile uyarılar devre dışı bırakılmıştır. Alternatif olarak `localtime_s()` kullanılabilir.
* `NumberOfDayesInMonth` ismindeki yazım hatası (Dayes → Days) yalnızca isim düzeyinde olup fonksiyonun çalışmasını etkilemez, ancak daha doğru bir adlandırma önerilir.

---

## 🎯 Amaç

Bu uygulamanın amacı, sistem tarihi ile kullanıcı girişi arasında geçen süreyi güvenilir ve doğru bir şekilde gün cinsinden hesaplayabilen bir algoritma geliştirmektir. Aynı zamanda sistem zamanına erişim ve tarih işlemleri konularında temel pratik kazandırmayı hedefler.

---

İstersen bu açıklamayı `README.md` formatında da verebilirim.
