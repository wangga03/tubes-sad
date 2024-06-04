// Mendefinisikan pin yang digunakan
const int sensorPin = A0; // Pin sensor terhubung ke pin analog A0
const int ledPin = 13;    // LED indikator terhubung ke pin digital 13

void setup() {
  Serial.begin(9600);     // Memulai komunikasi serial dengan baudrate 9600
  pinMode(ledPin, OUTPUT);// Mengatur pin LED sebagai output
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Membaca nilai analog dari sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Mengkonversi nilai analog menjadi tegangan (0-5V)
  // float alcoholPPM = map(voltage, 0.0, 5.0, 0, 500); // Menghitung konsentrasi alkohol (dalam ppm)

  float alcoholPPM = (voltage/5.0)*500;
  

  // Serial.print("Sensor Value: ");
  // Serial.println(sensorValue); // Mencetak konsentrasi alkohol ke Serial Monitor
  // Serial.println();
  // Serial.print("Alkohol PPM: ");
  // Serial.println(alcoholPPM); // Mencetak konsentrasi alkohol ke Serial Monitor
  // Serial.println();
  // Serial.print("Voltage: ");
  // Serial.println(voltage); // Mencetak konsentrasi alkohol ke Serial Monitor
  // Serial.println();

  // Mengirim data :

  Serial.print(sensorValue);
  Serial.print(" ");
  Serial.print(alcoholPPM);
  Serial.print(" ");
  Serial.print(voltage);
  Serial.print("\n");


  // Mengaktifkan LED jika konsentrasi alkohol melebihi batas tertentu
  if (alcoholPPM > 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // Delay untuk menghindari pembacaan yang terlalu cepat
}
