### 💡 Problem Tanımı

Bu program, kullanıcıdan ondalıklı (float) bir sayı alarak bu sayıya uygulanan üç farklı **yuvarlama işlemini** simüle eder:

1. **Round (Matematiksel Yuvarlama)**
2. **Floor (Aşağı Yuvarlama)**
3. **Ceil (Yukarı Yuvarlama)**

Kullanıcı menüden bir işlem seçer ve sonuç ona göre hesaplanıp ekrana yazdırılır. Sayı negatif veya pozitif olsa bile kurallar doğru şekilde uygulanır.
not : bu Problem toplam #47+#48+#49 temsil eder 

---

### 📌 Programın İşleyişi:

* Kullanıcıdan ondalıklı bir sayı alınır (örneğin: `-2.7`, `3.14`, `5.5`).
* Sayı tam ve küsuratlı kısmına ayrılır.
* Kullanıcı aşağıdaki işlemlerden birini seçer:

  1. **Round:**

     * `x.5` ve üstü değerler bir üst tam sayıya, altı ise bir alt tam sayıya yuvarlanır.
     * Örn: `3.7` → `4`, `2.3` → `2`, `-2.5` → `-3`
  2. **Floor (Float olarak adlandırılmış):**

     * Sayı daima aşağıya yuvarlanır (en yakın küçük tam sayı).
     * Örn: `3.7` → `3`, `-2.3` → `-3`
  3. **Ceil:**

     * Sayı daima yukarıya yuvarlanır (en yakın büyük tam sayı).
     * Örn: `3.1` → `4`, `-2.8` → `-2`

---

### ✅ Örnek Çıktı

```
****************************************
MENU : 
1.ROUND :  
2.FLOAT :  
3.CEİL :  
****************************************
1
Enter A number
-3.6
İn Rounbd :  = -4
```

```
****************************************
MENU : 
1.ROUND :  
2.FLOAT :  
3.CEİL :  
****************************************
2
Enter A number
3.7
İn Float :  = 3
```

```
****************************************
MENU : 
1.ROUND :  
2.FLOAT :  
3.CEİL :  
****************************************
3
Enter A number
-2.2
İn Ceil :  = -2
```

---

### 🎯 Amaç

Ondalıklı sayılarla çalışma, sayıyı tam ve küsurat kısmına ayırma, farklı yuvarlama kurallarını uygulama ve koşullu yapıların kontrolünü geliştirmektir. Özellikle **matematiksel yuvarlama işlemlerini elle gerçekleştirme** mantığını öğretmeyi hedefler.
