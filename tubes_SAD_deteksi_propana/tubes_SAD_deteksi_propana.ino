const int MQ2_pin = A0;
const byte relay = 3;
int Rload = 1000;
float a = 0.403487;
float b =-1.48861;
float Rs;
float Ro = 43000; //cari nilai Ro menggunakan kodingan MQ2_mencari_Ro
float adcRaw;


void setup(){
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop(){
  adcRaw = analogRead(MQ2_pin);
  Rs = ((1023.0 * Rload) / adcRaw) - Rload; //resistansi sensor saat udara netral 
  float ppm = a * pow((Rs/Ro), b);
  Serial.print("adc Raw : ");
  Serial.println(Rs); //nilai tegangan sensor gas
  Serial.print("PPM : ");
  Serial.println(ppm); //jumlah gas yang terdeteksi dalam satuan ppm
  if(ppm >= 1000){
    digitalWrite(relay, LOW);
  }else{
    digitalWrite(relay, HIGH);
  }
  delay(1000);

}