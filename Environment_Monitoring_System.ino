#include <LiquidCrystal.h>
#include <DHT.h>

#define DHT_Pin 7
#define DHT_Type DHT11
#define LDR_Pin A0
#define Trig_Pin 9
#define Echo_Pin 10
#define Buzzer_Pin 6

DHT dht(DHT_Pin, DHT_Type);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  pinMode(Buzzer_Pin, OUTPUT);
  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  int ldrvalue = analogRead(LDR_Pin);

  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);

  long duration = pulseIn(Echo_Pin, HIGH);
  long distance = duration * 0.0343/2;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C  ");
  lcd.setCursor(10, 0);
  lcd.print("D:");
  lcd.print(distance);
  lcd.print("cm");
  
  lcd.setCursor(0,1);
  lcd.print("L:");
  lcd.print(ldrvalue);
  lcd.setCursor(6, 1);
  lcd.print("H:");
  lcd.print(humidity);
  lcd.print("%");

  //We can also modify the below based on needs such as when temperature goes beyond a certain threshold, the buzzer is activated.
  //Or if LDR value exceeds a certain value, the buzzer gets activated.
  if(distance < 20)
  {
    tone(Buzzer_Pin, 2000);  //used for passive buzzers.
    //can use digitalWrite(Buzzer_Pin, HIGH); if the buzzer is active buzzer.
  }
  else
  {
    noTone(Buzzer_Pin); //used for passive buzzers.
    //can use digitalWrite(Buzzer_Pin, LOW); if the buzzer is active buzzer.
  }

  delay(1000);
}