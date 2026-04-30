📖 Descripción del Proyecto
Este repositorio contiene el diseño, la simulación y la implementación física de un sistema de Control Predictivo Basado en Modelo (MPC) para la dirección lateral de un vehículo autónomo a escala. El "cerebro" matemático fue diseñado y simulado en Simulink/MATLAB, exportado autómaticamente como código C++ mediante MATLAB Coder
, e integrado en un microcontrolador ESP32 para ejecutarse en tiempo real
.
El vehículo es capaz de seguir trayectorias complejas precalculadas (como una figura en forma de "mariposa" de 14,988 waypoints) resolviendo problemas de optimización matricial en bucles fijos de 100 milisegundos
.
⚙️ Metodología y Modelo Físico
El control predictivo asume una velocidad longitudinal constante hacia adelante y ajusta la dinámica lateral utilizando un modelo cinemático de bicicleta. Las constantes físicas fundamentales medidas y utilizadas en el código son:
Distancia entre ejes (L): 0.18 metros
.
Odometría (Velocidad y Posición): Calculada en vivo leyendo las señales de un encoder magnético montado en las llantas traseras. A través de pruebas físicas, calibramos la constante en 0.0002079 metros por pulso
.
🧠 Diseño del Controlador (MPC)
El controlador evalúa el costo de sus acciones basándose en el estado actual (Y y ángulo Yaw) frente a una referencia de trayectoria móvil.
Pesos de la Función de Costo:
Prioridad Máxima (W 
y
​
 =1): Mantener el error de la posición lateral lo más cercano a cero posible.
Prioridad Menor (W 
yaw
​
 =0.1): El ángulo de orientación (Yaw). Se permite que el vehículo oscile su ángulo de trompa libremente si eso minimiza el error lateral más rápidamente.
Restricciones de Hardware y Confort:
El cálculo matemático restringe estrictamente la variable Steeringanglerad (Ángulo de volante) entre −π/6 y π/6 radianes (±30 
∘
 ) para no forzar la mecánica del servo
.
La tasa de giro está limitada a ±π/12 radianes por segundo para evitar volantazos bruscos y asegurar la estabilidad.
🗂️ La Trayectoria de la Mariposa
Se generó un entorno de simulación espacial utilizando la herramienta Driving Scenario Designer de MATLAB.
La trayectoria exportada consta de una matriz de 14,988 filas con la estructura: {Tiempo en segundos, Posición Y, Ángulo Yaw}
.
Debido al inmenso tamaño de este arreglo (~180 KB), la matriz fue declarada usando el tipo const float para obligar al microcontrolador a almacenarla directamente en la memoria Flash (4MB), evitando un colapso en la memoria RAM del ESP32
.
El vehículo tarda poco más de 2 minutos (150 segundos) en trazar la figura completa
.
🛠️ Hardware Utilizado
Microcontrolador principal: Tarjeta ESP32 de 32 bits, seleccionada por su alta capacidad de procesamiento matemático capaz de resolver el objeto de optimización matricial mpc.step()
.
Actuador de Dirección: Micro Servomotor SG90 operando a una frecuencia de 50Hz, mapeado con pulsos de entre 500 y 2400 µs y ajustado con retroalimentación negativa
.
Tracción Trasera: Motorreductor de corriente continua JGA25-370 de 12V y 60 RPM con Encoder Integrado de efecto Hall
.
Controlador de Potencia: Módulo Puente H L298N (Conectado a los pines IN3 y IN4 para sentido de giro y recibiendo un PWM constante en ENB)
