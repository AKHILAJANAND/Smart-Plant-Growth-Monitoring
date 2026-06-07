// Smart Plant Growth Monitoring System
// ESP32 + HC-SR04 + SMA Filtering

#define TRIG_PIN 4
#define ECHO_PIN 2

const float SENSOR_HEIGHT = 40.0; // cm

float heightReadings[6];
int indexReading = 0;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("Plant Growth Monitoring System Started");
}

void loop() {

  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Distance calculation (cm)
  float distance = duration * 0.0343 / 2.0;

  // Plant height calculation
  float plantHeight = SENSOR_HEIGHT - distance;

  // Store reading
  heightReadings[indexReading] = plantHeight;
  indexReading++;

  Serial.print("Raw Plant Height: ");
  Serial.print(plantHeight);
  Serial.println(" cm");

  // Apply SMA after collecting 6 readings
  if (indexReading >= 6) {

    float sum = 0;

    for (int i = 0; i < 6; i++) {
      sum += heightReadings[i];
    }

    float smaHeight = sum / 6.0;

    Serial.println("-----------------------");
    Serial.print("SMA Filtered Height: ");
    Serial.print(smaHeight);
    Serial.println(" cm");
    Serial.println("-----------------------");

    indexReading = 0;
  }

  // Measurement every 10 seconds
  delay(10000);
}
