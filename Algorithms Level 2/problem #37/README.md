### 💡 Problem Tanımı

Bu program, kullanıcıdan bir dizi boyutu alarak rastgele sayılarla bir dizi (`arri1`) oluşturur ve ardından bu dizinin tüm elemanlarını **başka bir diziye (`arri2`) kopyalar**. Programın sonunda hem orijinal hem de kopyalanmış dizi ekrana yazdırılır.

---

### 📌 Programın İşleyişi

1. Kullanıcıdan dizinin boyutu alınır.
2. `arri1` dizisi, `1–100` arasında rastgele sayılarla doldurulur.
3. `arri1` dizisindeki her eleman, `AriiEkleme` fonksiyonu ile sırayla `arri2` dizisine kopyalanır.
4. Her iki dizi ayrı ayrı formatlı şekilde ekrana yazdırılır.

> Not: `AriiEkleme` fonksiyonu ile kopyalama işlemi manuel olarak yapılmıştır. Bu, temel veri yapısı pratiği için tercih edilmiştir.

---

### ✅ Örnek Çıktı

```
enter arri size ?
5
matris 1 :
[ 13,66,22,48,90 ]
matris 2 :
[ 13,66,22,48,90 ]
```

---

### 🎯 Amaç

Bu problem kullanıcıya:

* Rastgele sayı üretme,
* Dizileri oluşturma ve kopyalama,
* Eleman eklemeyi ayrı fonksiyonla gerçekleştirme (modüler yaklaşım),
* Referans ile değişken güncellemeyi (`int&`)
  öğretmeyi amaçlar.

Özellikle veri kopyalama işlemi temel algoritmaların temsili olduğu için, dizi yönetimi konusuna giriş için faydalıdır.
