#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHT_PIN 2       // Pin number for DHT11
#define DHT_TYPE DHT11   // DHT sensor type
#define MQ_PIN A0        // Pin number for MQ2 sensor
#define BUZZER_PIN 8     // Pin number for the buzzer
#define GREEN_LED 9      // Pin number for the green LED
#define BLUE_LED 10      // Pin number for the blue LED
#define RED_LED 11       // Pin number for the red LED

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address and dimensions based on your LCD
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  lcd.begin(16, 2);  // Initialize the LCD
  Serial.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Wait for sensors to stabilize
  delay(2000);
}

void loop() {
  // Display "Pollution Monitoring System" for 2 seconds
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pollution Monitoring");
  lcd.setCursor(0, 1);
  lcd.print("System");
  delay(2000);

  while (true) {
    int gasValue = analogRead(MQ_PIN);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gas: ");
    lcd.print(gasValue);

    lcd.setCursor(0, 1);
    if (gasValue > 100) {
      lcd.print("Air Quality: Poor");
      digitalWrite(BUZZER_PIN, HIGH);
      blinkAlternately(BLUE_LED, RED_LED);  // Blink blue and red LEDs alternately and fast
      digitalWrite(GREEN_LED, LOW);       // Turn off green LED
    } else {
      lcd.print("Air Quality: Good");
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(GREEN_LED, HIGH);  // Turn on green LED
      digitalWrite(BLUE_LED, LOW);    // Turn off blue LED
      digitalWrite(RED_LED, LOW);     // Turn off red LED
    }

    delay(2000);

    // Display temperature and humidity values on LCD
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // Check if the read values are valid (non-NaN)
    if (!isnan(temperature) && !isnan(humidity)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(temperature);
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("Humidity: ");
      lcd.print(humidity);
      lcd.print("%");

      Serial.print("Temperature: ");  // Output temperature to Serial Monitor
      Serial.println(temperature);
      Serial.print("Humidity: ");     // Output humidity to Serial Monitor
      Serial.println(humidity);

      delay(2000);
    } else {
      Serial.println("Error reading from DHT sensor!");
    }
  }
}

// Function to blink two LEDs alternately and fast
void blinkAlternately(int pin1, int pin2) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    delay(100);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    delay(100);
  }
}
