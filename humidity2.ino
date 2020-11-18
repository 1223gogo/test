#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){
    Serial.begin(9600);
    dht.begin();
    Serial.println("Start DHT");
  }

void loop(){
    delay(2000);
    float temperature = dht.readTemperature(); //readTemperature() default가 celcius, not force mode
    float humidity = dht.readHumidity();
    float heat = dht.computeHeatIndex(temperature,humidity,false);
    Serial.print("Temperature : ");
    Serial.print(temperature);
    Serial.print(" *C Humidity : ");
    Serial.print(humidity);
    Serial.print(" % Heat Index : ");
    Serial.print(heat);
    Serial.println(" *C");

}