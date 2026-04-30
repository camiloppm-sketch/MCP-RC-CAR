%% 1. DEFINIR VELOCIDAD Y DINÁMICA DEL VEHÍCULO
Vx = 0.15; % Velocidad física alcanzable por tu motorreductor (m/s)

% TUS PARÁMETROS FÍSICOS ACTUALIZADOS
m = 0.748;  % ¡ACTUALIZADO! Masa real de tu auto en kg (748 gramos)
Iz = 0.007; % Estimación del momento de inercia ajustado a la nueva masa
lf = 0.09;  % Distancia del centro de gravedad al eje delantero en metros (9 cm)
lr = 0.09;  % Distancia del centro de gravedad al eje trasero en metros (9 cm)
Cf = 50;    % Estimación: Rigidez de las llantas delanteras (N/rad)
Cr = 50;    % Estimación: Rigidez de las llantas traseras (N/rad)

%% 2. CREAR MATRICES DE ESPACIO DE ESTADOS (Modelo de Bicicleta)
% Al cambiar 'm' a 0.748, el sistema ahora modela la resistencia real al giro
A = [-(2*Cf+2*Cr)/m/Vx, 0, -Vx-(2*Cf*lf-2*Cr*lr)/m/Vx, 0;
     0, 0, 1, 0;
     -(2*Cf*lf-2*Cr*lr)/Iz/Vx, 0, -(2*Cf*lf^2+2*Cr*lr^2)/Iz/Vx, 0;
     1, Vx, 0, 0];
     
B = [2*Cf/m; 0; 2*Cf*lf/Iz; 0];
C = [0 0 0 1; 0 1 0 0];
D = 0;

% Crear la planta
vehicle = ss(A,B,C,D);

%% 3. CARGAR LA REFERENCIA DE "MI MARIPOSA"
% Llamamos a la función recién exportada con los 0.15 m/s
[allData, scenario, sensor] = mi_mariposa();

% Extraemos los datos
t = [allData.Time]';
ap = [allData.ActorPoses];
yawRef = [ap.Yaw]';
posRef = vertcat(ap.Position);

% Creamos la variable reference para el bloque MPC
reference = [t posRef(:,2) deg2rad(yawRef)];