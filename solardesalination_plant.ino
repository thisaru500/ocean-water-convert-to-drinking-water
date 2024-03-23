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
