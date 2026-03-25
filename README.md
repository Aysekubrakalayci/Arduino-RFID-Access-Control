# RFID Tabanlı Kapı Geçiş Kontrol Sistemi 🚪🔒

Bu proje, Arduino Uno ve RC522 RFID modülü kullanılarak geliştirilmiş bir güvenlik ve erişim kontrol sistemidir.
Tanımlı kartlar okutulduğunda servo motor tetiklenerek kapı mekanizmasını açar, tanımsız kartlarda ise sisteme giriş izni verilmez.

# Kullanılan Donanımlar
* Mikrodenetleyici: Arduino Uno 
* RFID Modülü: RC522 (13.56 MHz)
* Motor: Servo Motor (Kapı kilidi simülasyonu için)
* Bağlantı: Jumper kablolar ve Breadboard

## 🚀 Projenin Çalışma Mantığı
1.  Sistem bekleme modundadır.
2.  RFID kart okuyucuya yaklaştırıldığında, kartın UID (Benzersiz Kimlik) numarası okunur.
3.  Eğer UID, veritabanındaki (kod içindeki) yetkili ID ile eşleşirse:
    * Yeşil LED yanar.
    * Servo motor 90 derece dönerek kapıyı açar.
4.  Eğer UID eşleşmezse:
    * Erişim reddedilir.
    * Serial monitörde kullanıcıya red mesajı iletilir.

## 💻 Gelecek Güncellemeler (To-Do)
*  Kart ID'lerinin SD karta veya EEPROM'a kaydedilmesi.
*  Buzzer ile ses kontrolü
*  LCD ekran ile kullanıcıya karşılama mesajı gösterilmesi.
*  Birden fazla kullanıcı ile daha kompleks bir güvenli sistemi.


