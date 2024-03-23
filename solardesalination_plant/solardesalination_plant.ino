#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 3
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
// Constants
#define DHTPIN 2       // What pin we're connected to
#define DHTTYPE DHT22  // DHT 22 (AM2302)
  
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

// Variables
float hum;  // Stores humidity value
float temp;// Stores temperature value
float Celsius = 0;
float Fahrenheit = 0;
const int trigPin1 = 4;
const int echoPin1 = 5;

const int trigPin2 = 6;
const int echoPin2 = 7;

const int relay = 9;//FOR TURN ON MOTORS


int h=14;// height of the tank
double m1, m2;

float duration1, distance1;
float duration2, distance2;

void setup() {

    Serial.begin(9600);
    sensors.begin();
    dht.begin();
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(11, INPUT);//LOWER LEVEL 
  pinMode(12, INPUT);//UPPER LEVEL
  pinMode(10, INPUT);//THIS PIN FOR STORE RELAY VALUE
  pinMode(8, OUTPUT);// ERROR LED
  
  
}

void ultrasonic() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  m1 = distance1*100/200;
  Serial.println(" precentage1 : ");
  Serial.print( m1);
  Serial.println("%");
  delay(1000);

   digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  
  
  

  m2 = distance2*100/200;
  Serial.println(" precentage2 : ");
  Serial.print( m2);
  Serial.println("%");
  delay(1000);

  
}

void humidity(){
    // Wait a few seconds between measurements
    delay(2000);

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    hum = dht.readHumidity();    // Read humidity value
    temp = dht.readTemperature();  // Read temperature value

    // Check if any reads failed and exit early (to try again).
    if (isnan(hum) || isnan(temp)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.println(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");

 }
  void tempsen() {
  sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  Serial.print(Celsius);
  Serial.println(" C  ");
  Serial.print(Fahrenheit);
  Serial.println(" F");

  delay(1000);
}
 void loop(){
  ultrasonic();
  humidity();
  tempsen();

  if(relay == HIGH){
    Serial.println("Motor is turn on");
    digitalWrite(14,HIGH);
    }
     int ul = digitalRead(11); 
  int ll = digitalRead(12);
  
  if (digitalRead(10) == LOW && ul == LOW && ll == LOW) {

    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);
    
    Serial.println("motor on");
    Serial.println("loop1");
    delay(5);

  }
