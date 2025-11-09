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

#### C. Hexadecimales → `%x,` `%X,` `
* `%x` → **minúsculas** (a-f)
* `%X` → **mayúsculas** (A-F)
* `%p` → **direcciones de memoria** (`void *`), convertidas a hexadecimal precedido por 0x
* 
##### Ejemplo básico
```c
unsigned int n = 255;
printf("%x", n); // salida: ff
printf("%X", n); // salida: FF
```

##### Ejemplo con puntero
```c
void *ptr = (void *)0x7ffeefbff618;
printf("%p", ptr); // salida: 0x7ffeefbff618
```

##### Conversión interna
* Divide el número entre 16.
* Usa el resto como índice en la tabla "`0123456789abcdef`".
* Repite hasta que el número llegue a 0.

#### 3. Conversión numérica (lo que implementas tú)
Si estás haciendo tu propio `printf`, vas a necesitar funciones tipo:
```c
char *ft_itoa(int n);                 // convierte int → string
char *ft_utoa(unsigned int n);        // unsigned int → string
char *ft_xtoa(unsigned long n, int mayus);  // base 16 → string
```
Estas funciones **usan recursión o divisiones sucesivas** para obtener los dígitos.
#### 4. Casos de uso comunes
| Tipo | Ejemplo de uso                | Qué imprime    |
| ---- | ----------------------------- | -------------- |
| `%d` | `ft_printf("%d", -42)`        | `-42`          |
| `%i` | `ft_printf("%i", 100)`        | `100`          |
| `%u` | `ft_printf("%u", -1)`         | `4294967295`   |
| `%x` | `ft_printf("%x", 3735928559)` | `deadbeef`     |
| `%X` | `ft_printf("%X", 3735928559)` | `DEADBEEF`     |
| `%p` | `ft_printf("%p", ptr)`        | `0x7ffe123abc` |
