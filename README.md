
📘 PruebaEntrevistaCpp
Sistema modular concurrente en C++ con colas seguras, hilos independientes y mensajería estructurada.

---

🚀 Resumen del proyecto

Este proyecto implementa una arquitectura modular concurrente en C++ diseñada para demostrar:

- Procesamiento en paralelo mediante hilos independientes
- Comunicación segura entre módulos usando colas thread‑safe
- Mensajes estructurados con distintos tipos (PING, DATA, STOP…)
- Flujo de datos encadenado entre módulos
- Compilación multiplataforma mediante CMake
- Código limpio, escalable y fácil de extender

Es ideal como demostración técnica para entrevistas, portfolios o como base para sistemas concurrentes reales.

---

🧩 Arquitectura general

`
┌────────────┐      ┌────────────┐      ┌────────────┐
│  Module 1   │ ───► │  Module 2   │ ───► │  (más módulos) │
└────────────┘      └────────────┘      └────────────┘
       │                    │
       ▼                    ▼
  SafeQueue A          SafeQueue B
`

Componentes clave

- ModuleBase  
  Clase abstracta que define la interfaz común de todos los módulos.

- Module1 / Module2  
  Módulos concretos que procesan mensajes y los envían al siguiente módulo.

- Message  
  Estructura que define el contenido y tipo de cada mensaje.

- SafeQueue  
  Cola thread‑safe que garantiza comunicación segura entre hilos.

- main.cpp  
  Orquesta la creación de módulos, hilos y el flujo de mensajes.

---

📁 Estructura del repositorio

`
/
├── CMakeLists.txt
├── include/
│   ├── Message.h
│   ├── ModuleBase.h
│   ├── Module1.h
│   ├── Module2.h
│   ├── SafeQueue.h
│
└── src/
    ├── main.cpp
    ├── ModuleBase.cpp
    ├── Module1.cpp
    ├── Module2.cpp
`

---

⚙️ Compilación

Desde la raíz del proyecto:

`bash
mkdir build
cd build
cmake ..
make
`

---

▶️ Ejecución

`bash
./PruebaEntrevistaCpp
`

---

📨 Ejemplo de salida

`
[Module2] Recibido PING: Ping enviado
[Module2] Procesando DATA: Temperatura: 22.5C
[Module2] Procesando DATA: Humedad: 45%
[Module2] Recibido STOP. Terminando...
`

---

🧠 Decisiones técnicas destacadas

- Uso de C++17 para un código moderno y seguro  
- Arquitectura basada en interfaces para facilitar la extensión  
- Comunicación desacoplada mediante SafeQueue  
- Hilos independientes para cada módulo  
- Sistema de mensajes tipado para evitar errores en tiempo de ejecución  
- CMake para portabilidad y escalabilidad del proyecto  

---

🧪 Cómo extender el proyecto

Añadir un nuevo módulo

1. Crear ModuleX.h y ModuleX.cpp
2. Heredar de ModuleBase
3. Implementar processMessage()
4. Añadirlo en main.cpp
5. CMake lo incluirá automáticamente gracias a:

`
file(GLOB SOURCES "src/*.cpp")
`

Añadir nuevos tipos de mensaje

1. Editar Message.h
2. Añadir nuevos enum class MessageType
3. Implementar su manejo en los módulos

---

📈 Posibles mejoras futuras

- Añadir logging avanzado con timestamps  
- Añadir tests unitarios (Catch2 / GoogleTest)  
- Añadir un módulo de estadísticas  
- Añadir un módulo logger  
- Implementar comunicación bidireccional  
- Añadir un sistema de configuración JSON  

---

🏗️ Cómo compilar correctamente (explicación clara de la estructura)

Este proyecto utiliza una estructura estándar de CMake, donde la raíz del proyecto contiene el código fuente y el archivo CMakeLists.txt, mientras que la carpeta build/ se utiliza únicamente para generar los archivos de compilación.

📌 1. Estructura relevante

`
PruebaEntrevistaCpp/
│
├── CMakeLists.txt      ← raíz del proyecto
├── include/            ← headers
├── src/                ← código fuente
└── build/              ← archivos generados (NO editar aquí)
`

📌 2. ¿Qué significa “compilar desde la raíz”?

Significa:

1. Estar en la carpeta donde está CMakeLists.txt  
2. Crear la carpeta build/  
3. Ejecutar CMake desde dentro de build/, apuntando a la raíz (..)  
4. Compilar con make

📌 3. Comandos exactos

`bash
cd ~/proyectos/PruebaEntrevistaCpp     # Ir a la raíz del proyecto
mkdir -p build                           # Crear carpeta de build (solo la primera vez)
cd build                                 # Entrar en build
cmake ..                                 # Generar archivos de compilación
make                                     # Compilar
`

📌 4. Ejecutar el programa

`bash
./PruebaEntrevistaCpp
`

📌 5. ¿Por qué se usa cmake ..?

El .. significa:

> “Ejecuta CMake usando el CMakeLists.txt que está en la carpeta superior”.

Esto permite mantener la raíz limpia y separar:

- Código fuente  
- Configuración  
- Archivos generados  

---
