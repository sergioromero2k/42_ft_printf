## Funciones variádicas
---
### 1. ¿Qué son las funciones variádicas?
En C, **una función variádica** es una función que puede recibir **un número de variable argumentos**.
Ejemplo clásico
```c
printf("Hola %s, tienes %d años", nombre, edad);
```

### 2. Librería necesaria
Para manejar argumentos variables, se incluye:
```c
#include <stdarg.h>
```
Esta librería define **4 macros clave:**
| Macro      | Función        | Explicación                                        |
| ---------- | -------------- | -------------------------------------------------- |
| `va_list`  | Declaración    | Define una variable que almacenará los argumentos. |
| `va_start` | Inicialización | Indica dónde comienzan los argumentos variables.   |
| `va_arg`   | Lectura        | Permite obtener cada argumento (uno por uno).      |
| `va_end`   | Finalización   | Limpia la lista (por buenas prácticas).            |

### 3. Estructura básico de una función variádica
```c
tipo_retorno nombre_funcion(tipo fijo, ...) {
    va_list lista;
    va_start(lista, fijo);

    // uso de va_arg para extraer valores

    va_end(lista);
}
```
La función **debe tener al menos un parámetro fijo,** porque `var_start` necesita saber **dónde empiezan los argumentos variables.**



