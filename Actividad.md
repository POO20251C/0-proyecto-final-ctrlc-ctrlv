# Práctica en parejas de Programación Orientada a Objetos en C++  
## Caso de Estudio: Tienda de Mascotas Virtuales Evolutivas

### Introducción

¡Bienvenidos a **PixelPets**, la primera tienda en línea de mascotas virtuales adoptables y evolutivas!

En PixelPets, los usuarios pueden adoptar criaturas digitales únicas que crecen, cambian y se desarrollan con el tiempo. Cada mascota tiene una personalidad diferente, puede aprender trucos, interactuar con otras mascotas y necesita cuidados constantes. La tienda permite gestionar las mascotas de los usuarios, registrar nuevas mascotas, almacenar su evolución y registrar qué habilidades han aprendido.

Tu reto como programador es construir un sistema que simule la lógica principal de esta tienda virtual, siguiendo principios de la **Programación Orientada a Objetos**.

---

## Objetivos

- Analizar un caso de estudio para identificar **clases**, **atributos**, **relaciones** y **responsabilidades**.
- Diseñar un diagrama de clases UML con al menos.
- Implementar en C++ el código que implemente el diseño creado en UML, usando:
  - Contenedores `vector` y `map`.
  - Apuntadores para relacionar objetos entre clases en caso de ser necesario.
  - Encapsulamiento y funciones para interactuar con los datos.

---

## Requisitos del caso

### Contexto

Cada usuario registrado en PixelPets puede adoptar múltiples mascotas virtuales. Las mascotas tienen un nombre, un nivel de energía, un estado de salud (sano, regular, enfermo y muy enfermo) una edad y un estado emocional (Registra al menos 3 estados emocionales). También pueden aprender habilidades específicas, como bailar, buscar objetos, o incluso comunicarse con emojis. Estas habilidades se desbloquean con experiencia ganada.

Además, la tienda ofrece objetos digitales (registra por lo menos 8, ejemplos pueden ser snacks, juguetes, pociones) que los usuarios pueden usar para mejorar la salud, o estado emocional de sus mascotas. Cada objeto tiene un tipo y un efecto especial.

La plataforma también lleva registro de los cuidados realizados a cada mascota (por ejemplo: Cuantas veces fue alimentada, estados de salud que ha tenido, qué objeto se le dio, etc.). 

Los usuarios pueden consultar un historial de actividades (cuidados) de una mascota.

---

## Actividades

### 1. **Análisis del caso**
- Identifica al menos **6 clases** necesarias para modelar este sistema.  
- Define los **atributos**, **métodos** y **relaciones** de cada clase.  
- Determina qué clases se relacionan entre sí (asociación y agregación) y cómo ¿quién tiene unun contenedor de qué?.  
- Determina en qué casos necesitarías **apuntadores a objetos** para permitir la interacción entre clases.

### 2. **Diseño UML**
- Dibuja el **diagrama de clases UML** del sistema, representando:
  - Clases con sus atributos y métodos.
  - Relaciones entre clases (asociaciones y agregaciones).
  - El dibujo puedes hacerlo en una app o a mano, pero debe respetar toda la sintaxis de UML.

### 3. **Implementación en C++**
- Implementa las clases diseñadas.
- Usa un contenedor asociativo como `map` para relacionar usuarios con sus mascotas.
- Usa un contendor secuencial como `vector` para guardar habilidades, historial de cuidados u objetos.
- Usa **apuntadores** entre clases donde sea necesario (por ejemplo, una mascotas que pasan a otras funciones y queremos que se conserven los cambios que tuvo).
- Crea un menú por consola que permita:
  - Registrar nuevos usuarios.
  - Adoptar nuevas mascotas.
  - Brindar objetos a las mascotas.
  - Enseñar habilidades a las mascotas.
  - Aumentar experiencia de una mascota (manual o aleatorio)
  - Consultar el historial de una mascota.

---

## Reglas

- El diagrama UML debe tener coherencia con el código que lo implementa
- Cada clase debe tener un archivo .h y un archivo .cpp
- Todo debe manejarse mediante clases básicas, relaciones con apuntadores, vectores y mapas.
- Implementa la lógica de manera que cada clase sea responsable solo de su propia información (buen diseño de responsabilidades).
- Crea al menos 3 usuarios y 5 mascotas diferentes para probar tu sistema.

---

## Entregables

1. Archivo con el **diagrama UML** (puede ser una foto o PDF).
2. Archivos `.cpp` y `.h` de la implementación.
3. Archivo README con:
   - Instrucciones de compilación.
   - Breve explicación del diseño.

---

## Consejos

- Puedes hacer una clase para manejar el sistema general, como un "Controlador" o "Plataforma".
- Piensa cómo harías para que las mascotas "evolucionen" (puede ser solo aumentando edad o energía por ahora).
- Usa funciones auxiliares para que el `main()` no se vuelva demasiado largo.

---

## Bonus (opcional)

Si terminas antes del tiempo límite, intenta agregar una función que **guarde en un archivo de texto** el historial de una mascota o los usuarios registrados.

---

Recuerda que la actividad puede realizarse en parejas, encuentra alguien te que complemente y multipliquen sus conocimientos
