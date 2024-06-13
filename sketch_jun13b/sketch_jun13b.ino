const int sensorPin = A0; // Pin analog tempat VRL terhubung
const int RL_VALUE = 10000; // Nilai RL dalam ohm (10 kΩ)
const int Vcc = 5; // Tegangan suplai sensor (5V)

// Nilai Ro perlu diukur dengan menggunakan gas referensi pada konsentrasi yang diketahui
const float Ro = 4000.2; // Sesuaikan dengan nilai Ro yang diukur sebelumnya

void setup() {
  Serial.begin(9600); // Mulai komunikasi serial pada baud rate 9600
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Baca nilai analog dari sensor
  float VRL = (sensorValue / 1023.0) * Vcc; // Konversi nilai analog ke tegangan
  float Rs = (Vcc / VRL - 1) * RL_VALUE; // Hitung Rs
  
  float ratio = Rs / Ro; // Hitung rasio Rs/Ro
  
  // Gunakan persamaan atau tabel kalibrasi untuk mengonversi rasio ke ppm
  // Misalkan menggunakan persamaan logaritmik sederhana berdasarkan datasheet
  float ppm = pow(10, (log10(ratio) - 0.6) / -0.2);
  
  Serial.print("Rs: ");
  Serial.print(Rs);
  Serial.print(" ohm, ");
  Serial.print("Concentration: ");
  Serial.print(ppm);
  Serial.println(" ppm");
  
  delay(1000); // Tunggu 1 detik sebelum pembacaan berikutnya
}