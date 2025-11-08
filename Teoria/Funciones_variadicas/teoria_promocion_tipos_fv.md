## Promoción de tipos
---
Cuando usas una función con **argumentos variables** (como `printf`, o en tu caso `mostrar_datos`), el compilador no sabe los tipos exactos de los argumentos que vienen después del último parámetro fijo.
Por eso, el estándar de C aplica **"promoción de tipos"** (default argument promotions) para los tipos pequeños.

#### Regla importante
Cuando pasas valores a una función con ...:
* `char`, `short` → se promueven a `int`
* `float` → se promueve a `double`

Entonces, en tu código:
```c
char tipo = va_arg(args, int);
```

* Tú esperas leer un `char`, pero el valor que realmente se pasó en la pila o registro fue un int, porque `'i'`, `'c'`, `'s'` son literales de tipo `int`. Por eso, debes pedirlo como int al usar `va_arg`, y luego convertirlo a `char`.

Si intentaras hacer esto:
```c
char tipo = va_arg(args, char);
```
* El comportamiento sería indefinido **(UB, undefined behavior)**, porque `va_arg` buscaría solo 1 byte, pero el valor real ocupa 4 bytes (en la mayoría de arquitecturas).

### 1. Tipos que cambian
Cuando pasas argumentos a una función con `...` (como `printf`, `mostrar_datos`, etc.), el compilador **aplica promociones automáticas** a ciertos tipos pequeños.
Esto es lo que se llama **“default argument promotions”**.

| Tipo original pasado | Tipo que realmente llega a la función          |
| -------------------- | ---------------------------------------------- |
| `char`               | `int`                                          |
| `unsigned char`      | `int` o `unsigned int` (dependiendo del rango) |
| `short`              | `int`                                          |
| `unsigned short`     | `int` o `unsigned int`                         |
| `float`              | `double`                                       |


### 2. Tipos que no cambian
Estos** no se promocionan**, así que los pides tal cual los pasas:
| Tipo pasado                        | Tipo que usas en `va_arg`  |
| ---------------------------------- | -------------------------- |
| `int`                              | `int`                      |
| `double`                           | `double`                   |
| `long`                             | `long`                     |
| `char *` (cadena o puntero)        | `char *`                   |
| `int *`, `float *`, etc.           | igual que el tipo original |
| `struct X` (si lo pasas por valor) | `struct X`                 |

#### Ejemplos prácticos
```c
va_arg(args, int);      // para char, short, int
va_arg(args, double);   // para float o double
va_arg(args, long);     // para long
va_arg(args, char *);   // para cadenas (punteros a char)
va_arg(args, int *);    // para punteros a enteros
va_arg(args, struct Persona);  // si pasas un struct por valor
```