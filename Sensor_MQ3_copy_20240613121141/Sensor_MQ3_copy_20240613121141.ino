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

const int MQ2_pin = A0;
const byte relay = 3;
int Rload = 1000;
float a = 658.71;
float b = -2.168;
float Rs;
float Ro = 74190.0; //cari nilai Ro menggunakan kodingan MQ2_mencari_Ro
float adcRaw; 


void setup() {
  Serial.begin(9600);     // Memulai komunikasi serial dengan baudrate 9600
  pinMode(ledPin, OUTPUT);// Mengatur pin LED sebagai output
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L,send2Blink);
}

void send2Blink(){

  adcRaw = analogRead(MQ2_pin);
  Rs = ((1023.0 * Rload) / adcRaw) - Rload; //resistansi sensor saat udara netral 
  float ppm = a * pow((Rs/Ro), b);
  Blynk.virtualWrite(V0, adcRaw); 
  // Blynk.virtualWrite(V4, 300); 
  // Blynk.virtualWrite(V2, 3); 
}

void loop() {
  adcRaw = analogRead(MQ2_pin);
  Rs = ((1023.0 * Rload) / adcRaw) - Rload; //resistansi sensor saat udara netral 
  float ppm = a * pow((Rs/Ro), b);
  Serial.print("adc Raw : ");
  Serial.println(adcRaw); //nilai tegangan sensor gas
  Serial.print("PPM : ");
  Serial.println(ppm); //jumlah gas yang terdeteksi dalam satuan ppm

  // Blynk.virtualWrite(V0, 10); 
  Blynk.run();
  timer.run();
  delay(1000); // Delay untuk menghindari pembacaan yang terlalu cepat
}
