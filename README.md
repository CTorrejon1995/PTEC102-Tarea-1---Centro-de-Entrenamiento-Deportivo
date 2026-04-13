# 🏋️ Sistema de Gestión de Rutinas de Entrenamiento Personalizadas

Proyecto desarrollado en C++ que implementa un sistema orientado a objetos para la gestión de ejercicios y generación de rutinas de entrenamiento personalizadas, en el contexto de un centro deportivo.

---

## 📌 Descripción

Este sistema permite administrar ejercicios de distintos tipos (fuerza y cardiovasculares) y generar rutinas personalizadas para clientes, considerando restricciones como el nivel de intensidad y la no repetición de ejercicios en semanas consecutivas.

El diseño está basado en principios de **Programación Orientada a Objetos (POO)**, incorporando conceptos como:
- Encapsulamiento
- Herencia
- Polimorfismo
- Gestión dinámica de memoria con punteros

---

## 🎯 Funcionalidades principales

- ✅ Crear ejercicios
- ✅ Modificar ejercicios
- ✅ Eliminar ejercicios
- ✅ Buscar y consultar ejercicios
- ✅ Filtrar ejercicios por nivel de intensidad
- ✅ Generar rutinas personalizadas
- ✅ Evitar repetición de ejercicios en semanas consecutivas
- ✅ Gestión dinámica de colecciones mediante vectores y punteros

---

## 🧱 Estructura del proyecto

El sistema está compuesto por las siguientes clases principales:

### 🔹 `Ejercicio` (Clase base)
Contiene atributos generales como:
- Código identificador
- Nombre
- Tipo
- Nivel de intensidad
- Tiempo estimado
- Descripción
- Última semana de uso

#### Clases derivadas:
- `Ejercicio_Fuerza`
- `Ejercicio_Cardiovascular`

➡️ Se aplica **herencia y polimorfismo** para manejar distintos tipos de ejercicios de forma uniforme.

---

### 🔹 `Coleccion`
Actúa como una **base de datos de ejercicios**.

Funciones destacadas:
- Almacenamiento dinámico (`vector<Ejercicio*>`)
- Eliminación segura de elementos (`delete`)
- Filtrado por nivel de intensidad
- Selección de ejercicios por índice

---

### 🔹 `Rutina`
Representa una rutina de entrenamiento personalizada.

Contiene:
- Lista de ejercicios (`vector<Ejercicio*>`)
- Cliente asociado
- Tiempo total de la rutina

---

### 🔹 `Coleccion_rutina`
Encargada de almacenar todas las rutinas creadas durante la ejecución del programa.

---

### 🔹 `Orquestador`
Clase central del sistema (núcleo del programa).

Responsabilidades:
- Controlar el flujo del programa
- Gestionar interacción con el usuario
- Coordinar la creación y uso de objetos
- Administrar las colecciones

Métodos clave:
- `menu_principal()`
- `pedir_intensidad()`
- `ejercicios_disponibles(...)`
- `coordinador()`

---

## ⚙️ Tecnologías utilizadas

- Lenguaje: **C++**
- Paradigma: **Programación Orientada a Objetos**
- Estructuras:
  - `vector`
  - Punteros (`*`)
- Gestión manual de memoria (`new` / `delete`)

---

## 🧠 Conceptos aplicados

- ✔ Abstracción de problemas reales
- ✔ Modelamiento mediante clases
- ✔ Herencia (Ejercicio → clases derivadas)
- ✔ Polimorfismo (uso de métodos virtuales)
- ✔ Encapsulamiento (atributos privados + getters/setters)
- ✔ Manejo de memoria dinámica
- ✔ Prevención de punteros colgantes mediante copia de objetos

---

## 🚀 Cómo ejecutar el proyecto

1. Clonar el repositorio:

```bash
git clone https://github.com/CTorrejon1995/PTEC102-Tarea-1---Centro-de-Entrenamiento-Deportivo.git
