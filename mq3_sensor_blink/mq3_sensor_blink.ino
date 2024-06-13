#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Mendefinisikan pin yang digunakan
const int sensorPin = A0; // Pin sensor terhubung ke pin analog A0
const int ledPin = 13;    // LED indikator terhubung ke pin digital 13

 // You should get Auth Token in the Blynk App.
 // Go to the Project Settings (nut icon).
 char auth[] = "XD3xuUPIoXMiAqSUkyr7P1IApx6-6dsK";

 // Your WiFi credentials.
 // Set password to "" for open networks.
 char ssid[] = "hai";
 char pass[] = "wggggw123";

 BlynkTimer timer;


void setup() {
  Serial.begin(9600);     // Memulai komunikasi serial dengan baudrate 9600
  pinMode(ledPin, OUTPUT);// Mengatur pin LED sebagai output
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L,send2Blink);
}

void send2Blink(){

  int sensorValue = analogRead(sensorPin); // Membaca nilai analog dari sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Mengkonversi nilai analog menjadi tegangan (0-5V)
  float alcoholPPM = map(voltage, 0.0, 5.0, 0, 500); // Menghitung konsentrasi alkohol (dalam ppm)
  float alcoholValue = (voltage/5)*500;
  Blynk.virtualWrite(V0, alcoholValue); 
  // Blynk.virtualWrite(V4, 300); 
  // Blynk.virtualWrite(V2, 3); 
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Membaca nilai analog dari sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Mengkonversi nilai analog menjadi tegangan (0-5V)
  float alcoholPPM = map(voltage, 0.0, 5.0, 0, 500); // Menghitung konsentrasi alkohol (dalam ppm)

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue); // Mencetak konsentrasi alkohol ke Serial Monitor
  Serial.println();
  Serial.print("Alkohol PPM: ");
  Serial.println(alcoholPPM); // Mencetak konsentrasi alkohol ke Serial Monitor
  Serial.println();
  Serial.print("Voltage: ");
  Serial.println(voltage); // Mencetak konsentrasi alkohol ke Serial Monitor
  Serial.println();

  // Mengaktifkan LED jika konsentrasi alkohol melebihi batas tertentu
  if (alcoholPPM > 100) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  // Blynk.virtualWrite(V0, 10); 
  Blynk.run();
  timer.run();
  delay(1000); // Delay untuk menghindari pembacaan yang terlalu cepat
}
