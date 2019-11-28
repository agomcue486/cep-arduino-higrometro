int lecturaDeLaConexionSerie;      // variable para leer los bytes de entrada
// variables humedad
const int sensorHigrometro = A0; // pin conexion
float humedad = 0; // variable almacenar lectura

void setup() {
  // inicializamos la comunicacion serie
  Serial.begin(9600);
}

void loop() {
  // leemos el sensor
  int lectura = analogRead(sensorHigrometro); // Valor entre 0 y 1023


  if (Serial.available() > 0) {
    // lectura del byte mas antiguo del buffer serial
    lecturaDeLaConexionSerie = Serial.read();
    
    // si el byte es H  envia dato de humedad
    if (lecturaDeLaConexionSerie == 'H') {

      if (lectura < 1024.0 / 3.0) {
        Serial.println("Humedad baja: hay que regar.");
      }
      else if (lectura < 2 .0/ 3.0 * 1024.0) {
        Serial.println("Humedad correcta.");
      }
      else {
        Serial.println("Humedad alta: por favor, no riegue.");
      }
    }
  }

  // Espera de un segundo.
  delay(1000);
}

