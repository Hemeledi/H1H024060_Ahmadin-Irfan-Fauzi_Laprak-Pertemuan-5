// Struct data sensor
struct readings {
  int temp;
  int h;
};

// Variabel data
readings dataSensor;

// Pin LED
int ledTemp = 8;
int ledHum = 9;

// Timer
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {

  Serial.begin(9600);

  pinMode(ledTemp, OUTPUT);
  pinMode(ledHum, OUTPUT);
}

void loop() {

  unsigned long currentMillis = millis();

  // Simulasi pembacaan sensor tiap 1 detik
  if (currentMillis - previousMillis >= interval) {

    previousMillis = currentMillis;

    // Simulasi data sensor
    dataSensor.temp = 54;
    dataSensor.h = 30;

    // ===== Tampilan Serial =====
    Serial.print("temp = ");
    Serial.println(dataSensor.temp);

    Serial.print("humidity = ");
    Serial.println(dataSensor.h);

    Serial.println("----------------");

    // ===== LED Temperatur =====
    digitalWrite(ledTemp, HIGH);
    delay(200);
    digitalWrite(ledTemp, LOW);

    // ===== LED Humidity =====
    digitalWrite(ledHum, HIGH);
    delay(200);
    digitalWrite(ledHum, LOW);
  }
}