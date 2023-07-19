

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
int total = 0;
int count_prod = 0;
int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
int beep = 4;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.clear();
  lcd.begin();  // initialize the LCD

  lcd.backlight(); // Turn on the blacklight and print a message.
  lcd.print("Bosco Grip Karts");
  delay (3000);
  lcd.clear();
  lcd.print("   Welcome to");
  delay (1500);
  lcd.clear();
  lcd.print("  Supermarket");
  delay (1500);
  lcd.clear();
  lcd.print("  Plz add item");
  delay (1500);
  lcd.clear();
  pinMode(beep, OUTPUT);


}


void loop()
{

  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  delay(5000);   // Here after detectig an ID ..Reader will wait for 5 sec so that customer
  // while customer brings close card..it wont print same ID again n again.
  //.Will wait for 5 sec before next reading

  Serial.println();// it brings cursor to new line..so that new ID comes on new line..on monitor


  content.toUpperCase();
  if (content.substring(1) == "70 37 70 38") //change here the UID of the card/cards that you want to give access
  {
    if (p1 == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("AmulButter added");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);



      lcd.setCursor(0, 1);
      lcd.print("Price: 30.00 INR    ");
      delay(2000);
      lcd.clear();
      total = total + 30;
      count_prod++;
      p1 = p1 + 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");
      delay (2000);
      lcd.clear();
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("AmulButterRemove");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Price:-30.00INR     ");
      delay(2000);
      lcd.clear();
      total = total - 30;
      count_prod--;
      p1 = p1 - 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");
      delay (2000);
      lcd.clear();
    }

  }

  else if (content.substring(1) == "60 8D C9 3A")
  {
    if (p2 == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("Sugar added");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);



      lcd.setCursor(0, 1);
      lcd.print("Price: 10.00 INR    ");
      delay(2000);
      lcd.clear();
      total = total + 10;
      count_prod++;
      p2 = p2 + 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");
      delay (2000);
      lcd.clear();
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("Sugar Remove");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Price:-10.00INR     ");
      delay(2000);
      lcd.clear();
      total = total - 10;
      count_prod--;
      p2 = p2 - 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");

      delay (2000);
      lcd.clear();
    }

  }

  else if (content.substring(1) == "B3 5E F5 00")
  {
    if (p3 == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("Oil added");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);



      lcd.setCursor(0, 1);
      lcd.print("Price: 85.00 INR    ");
      delay(2000);
      lcd.clear();
      total = total + 85;
      count_prod++;
      p3 = p3 + 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");
      delay (2000);
      lcd.clear();
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("Oil Remove");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Price:-85.00INR     ");
      delay(2000);
      lcd.clear();
      total = total - 85;
      count_prod--;
      p3 = p3 - 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");

      delay (2000);
      lcd.clear();
    }

  }

  else if (content.substring(1) == "80 EA C3 3A")
  {
    if (p4 == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("Tea added");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);



      lcd.setCursor(0, 1);
      lcd.print("Price:25.00 INR    ");
      delay(2000);
      lcd.clear();
      total = total + 25;
      count_prod++;
      p4 = p4 + 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");
      delay (2000);
      lcd.clear();
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("Tea Remove");
      digitalWrite(beep, HIGH);
      delay(1000);
      digitalWrite(beep, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Price:-25.00INR     ");
      delay(2000);
      lcd.clear();
      total = total - 25;
      count_prod--;
      p4 = p4 - 1;
      lcd.print("Total:");
      lcd.print(total);
      lcd.print("INR");

      delay (2000);
      lcd.clear();
    }

  }

  else if (content.substring(1) == "40 84 BD 3A")
  {



    lcd.print("Total:");
    lcd.print(total);
    lcd.print("INR");
    delay (3000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Please pay");
    lcd.setCursor(0, 1);
    lcd.print("at counter");
    delay(2000);
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Thanks");

    lcd.setCursor(0, 1);
    lcd.print("For Visiting ");
    delay(2000);
    lcd.clear();

    lcd.print("**********");
    lcd.clear();

  }

  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Product");
    lcd.setCursor(0, 1);
    lcd.print("not found");
    delay(2000);
    lcd.clear();
  }
}
