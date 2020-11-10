/*
   TUTORIAL SENSOR JARAK ULTRASONIC PADA ARDUINO
   GABUNG DENGAN LED

   Pinout
   VCC Ultrasoonic -> VCC
   GND Ultrasonic -> GND
   Trig Ultrasonic -> SDA (A4)
   Echo ultrasonic -> SCL (A5)

   D4 -> Led Merah
   D5 -> Led Hijau
   D6 -> Led Biru
   D7 -> Led Kuning
*/

#define TRIGGER A4
#define ECHO A5
#define merah 4 
#define hijau 5 
#define biru 6 
#define kuning 7
long durasi, cm;

void setup() {
  pinMode(TRIGGER, OUTPUT); //set menjadi OUTPUT
  pinMode(ECHO, INPUT); //set menjadi INPUT
  pinMode(merah, OUTPUT); //set menjadi OUTPUT
  pinMode(kuning, OUTPUT); //set menjadi OUTPUT
  pinMode(hijau, OUTPUT); //set menjadi OUTPUT
  pinMode(biru, OUTPUT); //set menjadi OUTPUT
  Serial.begin(115200); //memulai komunikasi serial pada baud rate 115200
  Serial.println("Mencoba Sensor Jarak Ultrasonic pada Arduino");
}

void loop() {
  //kirim ping
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  //baca echo pantulan
  durasi = pulseIn(ECHO, HIGH);

  //konversi waktu durasi ke jarak
  cm = (durasi / 2) / 29.1;

  Serial.println("Jarak : " + String(cm) + " cm"); //tampilkan pada serial monitor
  nyalakanLed(cm);
  delay(250);  //jeda waktu 250 uS
}

void nyalakanLed(int nilaiJarak){
  if(nilaiJarak<10){
    digitalWrite(kuning,LOW);
    digitalWrite(biru,LOW);
    digitalWrite(hijau,LOW);
    digitalWrite(merah,LOW);
  }
  if(nilaiJarak>10 && nilaiJarak<=20){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,LOW);
    digitalWrite(hijau,LOW);
    digitalWrite(merah,LOW);
  }
  if(nilaiJarak>20 && nilaiJarak<=30){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,HIGH);
    digitalWrite(hijau,LOW);
    digitalWrite(merah,LOW);
  }
  if(nilaiJarak>30 && nilaiJarak<=40){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,HIGH);
    digitalWrite(hijau,HIGH);
    digitalWrite(merah,LOW);
  }
  if(nilaiJarak>40 ){
    digitalWrite(kuning,HIGH);
    digitalWrite(biru,HIGH);
    digitalWrite(hijau,HIGH);
    digitalWrite(merah,HIGH);
  }
  
}
