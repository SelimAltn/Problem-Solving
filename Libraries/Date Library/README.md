# 📚 Date Library – C++ Tarih İşleme Kütüphanesi

## 💡 Genel Bakış

Bu kütüphane, C++ dilinde tarih ve dönem (period) işlemlerini kapsamlı ve modüler şekilde gerçekleştirmek amacıyla oluşturulmuştur. Projede daha önce ayrı ayrı geliştirilen ve test edilen problemlerden elde edilen tüm işlevler, bu kütüphane altında bütünleştirilmiş ve tekrarsız şekilde sadeleştirilmiştir.

## 🛠️ Kapsam ve Özellikler

* Tarihlerle ilgili temel işlemler (arttırma, azaltma, karşılaştırma)
* Dönem (başlangıç–bitiş) analizleri ve çakışma kontrolü
* İş günü, hafta sonu, yılbaşı vb. özel günlerle ilgili kontroller
* Takvim bastırma, gün/hafata/yıl farkı hesaplamaları
* Kullanımı kolaylaştıran okuma/yazma fonksiyonları

## 🧱 Yapı

```
project/
│
├── main.cpp           # Kütüphane kullanım örnekleri
├── Date.h             # Fonksiyon prototipleri, veri yapıları, enumlar
└── Date.cpp           # Fonksiyonların implementasyonları
```

Tüm kodlar `Date` adında bir namespace altında organize edilmiştir. Bu sayede isim çakışmaları önlenmiş, modüler yapı korunmuştur.

## ⚙️ Kullanım

```cpp
#include "Date.h"

using namespace Date;

int main() {
    stDate today = GetTodayDate();
    PrintDate("Bugünün tarihi:", today);
    return 0;
}
```

## 🧪 Test Edilen Problemler

Bu kütüphane, daha önce çözülmüş ve her biri ayrı bir `README.md` dosyası ile belgelenmiş 50'dan fazla farklı tarih probleminden derlenmiştir. Fonksiyonlar bu problemlerde test edilmiş, optimize edilmiş ve tekrar eden kodlar temizlenmiştir.

## 📌 Notlar

* Kod yapısı C++ standartlarına uygundur.
* Genişletilebilir ve dış projelerde kullanılabilir durumdadır.
* Gerekli olan her şey `Date.h` ve `Date.cpp` içinde tanımlıdır. Dış bağımlılık yoktur.

---

