#include <LiquidCrystal_I2C.h>

// Pin setup
#define LDR_PIN A0
#define LED_PIN 9
#define BUZZER_PIN 8

// Light level thresholds
// Values are from 0–1023 (ADC range)
int lightThreshold = 400;   // Treat anything below this as "dark"
int brightThreshold = 800;  // Treat anything above this as "very bright"

// LCD: 16x4 display using I2C
LiquidCrystal_I2C lcd(0x27, 16, 4);

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Start LCD
  lcd.init();
  lcd.backlight();

  // Small startup message
  lcd.setCursor(0, 0);
  lcd.print("LDR System Ready");
  delay(1200);
  lcd.clear();
}

void loop() {
  // Read the current LDR value
  int ldrValue = analogRead(LDR_PIN);

  // Show readings on Serial Monitor
  Serial.print("LDR Analog: ");
  Serial.print(ldrValue);
  Serial.print(" | LowTHR: ");
  Serial.print(lightThreshold);
  Serial.print(" | HighTHR: ");
  Serial.println(brightThreshold);

  // Update LCD: Line 1 shows live LDR reading
  lcd.setCursor(0, 0);
  lcd.print("LDR:");
  lcd.print(ldrValue);
  lcd.print("   "); 

  // Line 2 shows both thresholds
  lcd.setCursor(0, 1);
  lcd.print("Low:");
  lcd.print(lightThreshold);
  lcd.print(" High:");
  lcd.print(brightThreshold);
  lcd.print(" ");

  // Decide what to do based on light level
  bool ledState = false;
  bool buzzState = false;

  if (ldrValue < lightThreshold) {
    // It's dark → turn led on, buzzer off
    ledState = true;
    buzzState = false;
  }
  else if (ldrValue > brightThreshold) {
    // Its extremely bright → led off, buzzer on
    ledState = false;
    buzzState = true;
  }
  else {
    // normal light → both remain off
    ledState = false;
    buzzState = false;
  }

  // Apply the outputs to LED and buzzer
  digitalWrite(LED_PIN, ledState);
  digitalWrite(BUZZER_PIN, buzzState);

  // Line 3: LED status
  lcd.setCursor(0, 2);
  lcd.print("LED : ");
  lcd.print(ledState ? "ON " : "OFF");

  // Line 4: Buzzer status
  lcd.setCursor(0, 3);
  lcd.print("BUZZ: ");
  lcd.print(buzzState ? "ON " : "OFF");

  delay(500);
}
