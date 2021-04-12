#include "LedControl.h"
#include <DallasTemperature.h>
#include <OneWire.h>

int cero[15] = 
{
  1,1,1,
  1,0,1,
  1,0,1,
  1,0,1,
  1,1,1
};

int uno[15] = 
{
  0,0,1,
  0,0,1,
  0,0,1,
  0,0,1,
  0,0,1
};

int dos[15] = 
{
  1,1,1,
  0,0,1,
  1,1,1,
  1,0,0,
  1,1,1
};

int tres[15] = 
{
  1,1,1,
  0,0,1,
  1,1,1,
  0,0,1,
  1,1,1
};

int cuatro[15] = 
{
  1,0,1,
  1,0,1,
  1,1,1,
  0,0,1,
  0,0,1
};

int cinco[15] = 
{
  1,1,1,
  1,0,0,
  1,1,1,
  0,0,1,
  1,1,1
};

int seis[15] = 
{
  1,1,1,
  1,0,0,
  1,1,1,
  1,0,1,
  1,1,1
};

int siete[15] = 
{
  1,1,1,
  0,0,1,
  0,1,0,
  1,0,0,
  1,0,0
};

int ocho[15] = 
{
  1,1,1,
  1,0,1,
  1,1,1,
  1,0,1,
  1,1,1
};

int nueve[15] = 
{
  1,1,1,
  1,0,1,
  1,1,1,
  0,0,1,
  1,1,1
};

int LetraA[15] = 
{
  1,1,1,
  1,0,1,
  1,1,1,
  1,0,1,
  1,0,1
};

int LetraT[15] = 
{
  1,1,1,
  0,1,0,
  0,1,0,
  0,1,0,
  0,1,0
};

int LetraH[15] = 
{
  1,0,1,
  1,0,1,
  1,1,1,
  1,0,1,
  1,0,1
};

const byte PinSensorTAgua = 3;
int TEMPERATURA_AGUA;

LedControl lc = LedControl(11,13,10,1);
OneWire ourWire(PinSensorTAgua);
DallasTemperature sensors(&ourWire);

void setup() 
{
  lc.shutdown(0, false);
  lc.setIntensity(0, 4);
  lc.clearDisplay(0);

  sensors.begin();

  //Serial.begin(9600);
}

void loop() 
{
  sensors.requestTemperatures();
  TEMPERATURA_AGUA = sensors.getTempCByIndex(0);

  //Serial.println(TEMPERATURA_AGUA);
    
  String numero1;
  String numero2;
  

  if (TEMPERATURA_AGUA < 10)
  {
    numero1 = "0";
    numero2 = String(TEMPERATURA_AGUA);
  }
  else
  {
    String valorCadena = String(TEMPERATURA_AGUA);

    numero1 = valorCadena.substring(0,1);
    numero2 = valorCadena.substring(1);
  }

  saberNumero(numero1.toInt(), 1, 1);
  saberNumero(numero2.toInt(), 1, 5);
  delay(500);
}

void mostrar(int numero[15], int comienzo_fila, int comienzo_columna)
{
  int numeroDatos = 0;
  
  for (int tamanio = 0; tamanio < 5; tamanio++)
  {
    for (int vuelta = 0; vuelta < 3; vuelta++)
    {
      lc.setLed(0,comienzo_fila + tamanio,comienzo_columna + vuelta, numero[numeroDatos]);
      numeroDatos++;
    }
  }
}

void saberNumero(int numero, int comienzo_fila, int comienzo_columna)
{
  switch (numero) 
  {
    case 0:
      mostrar(cero,comienzo_fila,comienzo_columna);
      break;
    case 1:
      mostrar(uno,comienzo_fila,comienzo_columna);
      break;
    case 2:
      mostrar(dos,comienzo_fila,comienzo_columna);
      break;
    case 3:
      mostrar(tres,comienzo_fila,comienzo_columna);
      break;
    case 4:
      mostrar(cuatro,comienzo_fila,comienzo_columna);
      break;
    case 5:
      mostrar(cinco,comienzo_fila,comienzo_columna);
      break;
    case 6:
      mostrar(seis,comienzo_fila,comienzo_columna);
      break;
    case 7:
      mostrar(siete,comienzo_fila,comienzo_columna);
      break;
  
    case 8:
      mostrar(ocho,comienzo_fila,comienzo_columna);
      break;
  
    case 9:
      mostrar(nueve,comienzo_fila,comienzo_columna);
      break;
      
    default:
      break;
  }
}
