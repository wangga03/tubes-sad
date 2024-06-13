const int MQ2_pin = A0;
int Rload = 1000;
float ppm = 500.0;
float a = 658.71;
float b = -2.168;

void setup(){
  Serial.begin(9600);
}

void loop(){
  float adcRaw = analogRead(MQ2_pin);
  float Rs = ((1023.0 * Rload) / adcRaw) - Rload; //resistansi sensor saat udara netral
  float Ro = Rs * exp(log(a / ppm) / b); //resistansi sensor saat terpapar Gas
  Serial.println(Ro);
  delay(500);

}