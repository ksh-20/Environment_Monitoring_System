# Environment_Monitoring_System

This project uses an Arduino to monitor environmental parameters such as temperature, humidity, light intensity, and distance. It incorporates the following components:

DHT11: Temperature and Humidity Sensor

LDR: Light Dependent Resistor for light intensity detection

Ultrasonic Sensor (HC-SR04): Distance measurement

Buzzer: Alerts based on certain conditions (like distance)

The data is displayed on a 16x2 LCD screen, and a buzzer is triggered when an object is detected within a certain range by the ultrasonic sensor.

Components Required
Arduino Uno Board

DHT11 Sensor module

Light Dependent Resistor (LDR) or LDR module

HC-SR04 Ultrasonic Sensor module

Buzzer (Passive or Active) or Buzzer module

16x2 LCD

Jumper wires and breadboard

Connections
DHT11 Sensor:

VCC to 5V

GND to GND

Data to Pin 7 on Arduino

LDR:

One end to 5V

Other end to Analog Pin A0 (with a resistor to GND)

HC-SR04 Ultrasonic Sensor:

VCC to 5V

GND to GND

Trigger to Pin 9

Echo to Pin 10

Buzzer:

Positive pin to Pin 6

Negative pin to GND

LCD:

Follow the standard pinout for the LiquidCrystal library (pins 12, 11, 5, 4, 3, 2 for the control and data pins).

Libraries Required:
DHT sensor library: For reading temperature and humidity data from the DHT11 sensor.

LiquidCrystal library: For controlling the LCD screen.

We can install these libraries directly through the Arduino IDE:

DHT sensor library: Go to Sketch > Include Library > Manage Libraries > Search for "DHT sensor" and install it.

LiquidCrystal library: This is built-in with the Arduino IDE.

Code Description:
Setup-
DHT Sensor: The DHT11 sensor is initialized on pin 7 using the DHT library. The sensor reads temperature and humidity values which are displayed on the LCD.

LDR (Light Dependent Resistor): The LDR value is read through an analog pin (A0), indicating the light intensity. This value is also displayed on the LCD.

Ultrasonic Sensor: The ultrasonic sensor is connected to pins 9 (Trig) and 10 (Echo). The distance measurement is computed and shown on the LCD. If an object is detected within 20 cm, the buzzer will sound.

LCD: The LCD displays temperature, humidity, light intensity, and distance readings.

Buzzer: The buzzer is triggered when the distance is less than 20 cm.

Code Logic-
Temperature and Humidity: The DHT11 sensor reads the temperature in Celsius and humidity in percentage. These values are displayed on the first line of the LCD.

Light Intensity (LDR): The LDR value is displayed on the second line of the LCD.

Distance Measurement: The ultrasonic sensor calculates the distance based on the time it takes for the echo signal to return. If the distance is less than 20 cm, a buzzer is activated.

Buzzer: The buzzer sounds at 2000 Hz when an object is detected within 20 cm. It is silenced if the distance exceeds 20 cm.

Working-
LCD Display: The LCD shows temperature (°C), humidity (%), light intensity (LDR value), and distance (cm).

Buzzer: When an object is detected within a 20 cm range, the buzzer activates. You can adjust the threshold based on your needs by changing the value in the code (if(distance < 20)).

Future Enhancements-
Threshold for Temperature or Humidity: The buzzer can also be activated if the temperature or humidity exceeds a certain threshold.

Cloud Integration: The data can be sent to a cloud platform for remote monitoring.

Data Logging: Store the sensor readings on an SD card or send them to a serial monitor for logging.
