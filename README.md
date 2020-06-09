# IndicadorHorizonte
Este repositorio contiene todos los códigos y librerías necesarias para el desarrollo del proyecto de diseño 1

Las librerias encontradas en este codigo son las siguientes:
-U8GLIB: Librería utilizada para el uso de la pantalla LCD Nokia 5110
-U8GLIB_PCD8544: Librería utilizada para la escritura en el controlador interno PCD8544 en la pantalla LCD. 
-Adafruit_Sensor: Librería utilizada para el uso de sensores Adafruit en general.
-Adafruit_BNO055: Librería utilizada para el uso exclusivo del IMU: Adafruit BNO055.
-AccelerometerAngle: Librería utilizada para el cálculo de los ángulos del acelerometro.
-GyroscopeAngle: Librería utilizada para el cálculo de los ángulos del giroscopio.
-AngleFilter: Librería utilizada para calcular el filtro de compensación para ambos ángulos.
-Pixels: Librería utilizada para la conversión de los ángulos en rectas en coordenadas cartesianas (en lineas)
-PrintLine: Librería utilizada para la suma de ambas rectas y la obtencion de los valores cartesianos que se imprimiran en la pantalla LCD


Cada libreria posee dos archivos:
- Codigo.cpp: Vienen definidos los metodos y sus respectivas funciones
- Codigo.h: Se definen las clases y sus atributos asi como los constructores

El codigo principal en donde se corre el programa es llamado:
- IndicadorHorizonte.ino
