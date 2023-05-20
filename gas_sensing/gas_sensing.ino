int LED = 26;
#define MQ135_PIN 33
#define MQ2_PIN 32
#define DHTPIN 25
#define DHTTYPE DHT11

#include <DHT.h>
#include <Wire.h>

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  // pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_Aout = analogRead(MQ2_PIN);  /*Analog value read function*/
  Serial.print("MQ2 Gas Sensor: ");  
  Serial.print(sensor_Aout);   /*Read value printed*/
  Serial.print("\t");
  Serial.print("\t");
  if (sensor_Aout > 1800) {    /*if condition with threshold 1800*/
    Serial.println("Gas");  
    digitalWrite (LED, HIGH) ; /*LED set HIGH if Gas detected */
  }
  else {
    Serial.println("No Gas");
    digitalWrite (LED, LOW) ;  /*LED set LOW if NO Gas detected */
  }
  
  int sensor_out = analogRead(MQ135_PIN);  /*Analog value read function*/
  Serial.print("MQ135 Gas Sensor: ");  
  Serial.print(sensor_out);   /*Read value printed*/
  Serial.print("\t");
  Serial.print("\t");
  if (sensor_out > 1800) {    /*if condition with threshold 1800*/
    Serial.println("Gas");  
    digitalWrite (LED, HIGH) ; /*LED set HIGH if Gas detected */
  }
  else {
    Serial.println("No Gas");
    digitalWrite (LED, LOW) ;  /*LED set LOW if NO Gas detected */
  }

  delay(1500);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  delay(1500);

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  Serial.print("\n\n");

  delay(4000);
}
