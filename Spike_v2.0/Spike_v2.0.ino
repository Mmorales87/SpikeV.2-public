
#define BLYNK_USE_DIRECT_CONNECT

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <Thread.>


/*#define LEDb 27
  #define LEDa 32
  #define LEDr 33
*/


int tiempo;



boolean plant = false;
boolean defuse = false;

char auth[] = "kLJQCdpyFcGEL5L0qumnPcxaswMMXaIa";


void setup()
{
  // Debug console
  Serial.begin(9600);

  Serial.println("Waiting for connections...");

  Blynk.setDeviceName("Spike_Controller");

  Blynk.begin(auth);


  //Parte nueva para comprobar si funciona
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(27, OUTPUT);

  tiempo = millis();

}



BLYNK_WRITE(V1) {   //Boton azul plantar bomba

  if (param.asInt() == 1) {
    plant = true;
    for (int i = 0; i < 24; i++) {

      digitalWrite(32, HIGH);
      delay(500);
      digitalWrite(32, LOW);
      delay(500);
    }

    for (int i = 0; i < 19; i++) {

      digitalWrite(32, HIGH);
      delay(250);
      digitalWrite(32, LOW);
      delay(250);
    }

    for (int i = 0; i < 29; i++) {

      digitalWrite(32, HIGH);
      delay(125);
      digitalWrite(32, LOW);
      delay(125);
    }

    for (int i = 0; i < 19; i++) {

      digitalWrite(32, HIGH);
      delay(50);
      digitalWrite(32, LOW);
      delay(50);
      digitalWrite(32, HIGH);
      delay(100);
      digitalWrite(32, LOW);
    }
    plant = false;
  }
}






BLYNK_WRITE(V2) {   //Boton rojo desactivar bomba

  if (param.asInt() == 1) {
    defuse = true;
    for (int j = 0; j < 14; j++) {

      digitalWrite(33, HIGH);
      delay(500);
      digitalWrite(33, LOW);
      delay(500);
    }
  }
}


BLYNK_WRITE(V3) {   //Boton blanco encender luz blanca fija
  if (param.asInt() == 1) {
    digitalWrite(27, HIGH);
  } else {
    digitalWrite(27, LOW);
  }
}


void loop()
{
  Blynk.run();
}
