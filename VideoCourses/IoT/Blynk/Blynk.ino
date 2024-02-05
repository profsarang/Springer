
#define BLYNK_PRINT Serial

// Replace this lines form your Blynk Console.
#define BLYNK_TEMPLATE_ID "TMPL3v-sOk34v"
#define BLYNK_TEMPLATE_NAME "Home"
#define BLYNK_AUTH_TOKEN "Dg4lWXHCo_eYTxyKu83iGnA-gjB8Bf38"

const int V5 = 14;
const int V6 = 12;

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ssid";
char pass[] = "pass";


BLYNK_WRITE(V5)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(V5, LOW);
    Serial.println("LED ON");
  }
  if(value == 0)
  {
     digitalWrite(V5, HIGH);
     Serial.println("LED OFF");
     Blynk.virtualWrite(V5, "LED ON");
  }
}

BLYNK_WRITE(V6)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(V6, LOW);
    Serial.println("LED ON");
    Blynk.virtualWrite(V6, "LED ON");

  }
  if(value == 0)
  {
     digitalWrite(V6, HIGH);
     Serial.println("LED OFF");
     Blynk.virtualWrite(V6, "LED OFF");

  }
}


void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(V5,OUTPUT);
  pinMode(V6,OUTPUT);
}

void loop() {
  Blynk.run();                   
}
