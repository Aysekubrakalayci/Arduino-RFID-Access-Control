#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10
#define SERVO_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);
Servo motor;

/*DECIMAL UID*/
byte allowedUID[] = {219, 226, 128, 5};
byte allowedUIDSize = 4;   // UID kaç sayıysa (4)

bool isAuthorized() {
  if (rfid.uid.size != allowedUIDSize) return false;

  for (byte i = 0; i < allowedUIDSize; i++) {
    if (rfid.uid.uidByte[i] != allowedUID[i]) {
      return false;
    }
  }
  return true;
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  motor.attach(SERVO_PIN);
  motor.write(0);

  Serial.println("RFID DECIMAL sistem hazir...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  Serial.print("Okunan UID (DEC): ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print(" ");
  }
  Serial.println();

  if (isAuthorized()) {
    Serial.println(" Başarılı Giriş, Kapi acildi! ✅");
    motor.write(180);
    delay(3000);
    motor.write(0);
  } else {
    Serial.println("Yetkisiz Kart!! ❌");
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  delay(1000);
}

