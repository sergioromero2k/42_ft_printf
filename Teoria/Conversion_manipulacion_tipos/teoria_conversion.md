## Conversión y Manipulación de Tipos Numéricos
---
Cuando implementas algo tipo `ft_printf`, no puedes usar `printf` internamente, así que debes:
* Convertir números a cadenas manualmente.
* Entender cómo representar números en distintas bases (**decimal**, **hexadecimal**, etc.).
* Saber cómo manejar el signo, los tipos y los límites.

### 1. Tipos numéricos principales
#### A. Decimales con signo → `%d`, `%i`
Representan números enteros con signo `(int)`, es decir, pueden ser **positivos** o **negativos**.
```c
int n = -42;
printf("%d", n);  // salida: -42
```
Lo que pasa internamente

* Si el número es negativo → imprime primero '-'.
* Convierte la parte positiva (42) en caracteres ('4', '2').
* Une el signo con los dígitos.

#### B. Enteros sin signo → `%u`
Representan valores solo positivos (unsigned int).
El rango va de `0` a `4294967295` (si son 32 bits).
##### Ejemplo
```c
unsigned int n = 4294967295;
printf("%u", n); // salida: 4294967295
```
**Importante**: Si imprimes un número negativo con `%u`, lo interpreta como su representación binaria sin signo **(overflow visual**).

