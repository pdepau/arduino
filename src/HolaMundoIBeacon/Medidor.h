// -*- mode: c++ -*-

#ifndef MEDIDOR_H_INCLUIDO
#define MEDIDOR_H_INCLUIDO

// --------------------------------------------------------------
//
// Medidor.h
// 17/10/2021
// Pau Blanes Climent
// Clase encargada de realizar medidas del sensor de CO2
//
// --------------------------------------------------------------

// ------------------------------------------------------
// ------------------------------------------------------
class Medidor {

  // .....................................................
  // .....................................................
private:
int sensorData [11];
void Serial1InParser(void)
{
    int i = 0;
    for (int i =0; i<11; i++) {
       while(!Serial1.available()) { }
       sensorData[i] = Serial1.parseInt();
    }
}
public:

  // .....................................................
  // constructor
  // .....................................................
  Medidor(  ) {
  } // ()

  // .....................................................
  // .....................................................
  void iniciarMedidor() {
	// las cosas que no se puedan hacer en el constructor, if any
  } // ()

  // .....................................................
  // Mediante serial1 recogemos los datos que nos proporciona el sensor para guardar el co2 
  // .....................................................
  int medirCO2() {
	Serial1.print('\r'); // Inicia una lectura del sensor. Ahora hay que espera a que nos envíe algo de vuelta!
    Serial.println("Lectura del sensor iniciada...esperando...");
    Serial1InParser();
    int co2 = 0;
    for (int i=0; i<11; i++) {
      Serial.println(sensorData[i]);
      // en la segunda posicion siempre esta el co2
      if(i == 1){
        co2 = sensorData[i];
      }
    }
    return co2;
  } // ()

  // .....................................................
  // Mediante serial1 recogemos los datos que nos proporciona el sensor para guardar la temperatura
  // .....................................................
  int medirTemperatura() {
  Serial1.print('\r'); // Inicia una lectura del sensor. Ahora hay que espera a que nos envíe algo de vuelta!
    Serial.println("Lectura del sensor iniciada...esperando...");
    Serial1InParser();
    int temperatura = 0;
    for (int i=0; i<11; i++) {
      Serial.println(sensorData[i]);
      // en la tercera posicion siempre esta la temperatura
      if(i == 2){
        temperatura = sensorData[i];
      }
    }
    return temperatura;
  } // ()
	
}; // class

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
#endif
