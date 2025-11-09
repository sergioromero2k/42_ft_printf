## Control de flujo y Parsing
---
Tu función `ft_printf` recibe una cadena como:
```c
ft_printf("Hola %s, tu número es %d", "Ana", 42);
```
Tu trabajo es recorrer esa cadena, carácter por carácter, y cuando encuentres un '%', interpretar el siguiente carácter como un especificador de formato (como s, d, x, etc.).

#### 2. Iteración y búsqueda
Usas un **bucle** para ir leyendo la cadena:
```c
int i = 0;
while (format[i])
{
    if (format[i] == '%')
        // aquí analizas el siguiente carácter
    else
        // imprimes el carácter normal
    i++;
}
```
#### 3. Detección del especificador (%)
Cuando detectas un `'%',` miras el carácter siguiente `format[i + 1]`.
Ese carácter te dice qué tipo de dato imprimir.

Ejemplo con **if/else if**:
```c
if (format[i + 1] == 'c')
    print_char(va_arg(args, int), counter);
else if (format[i + 1] == 's')
    print_string(va_arg(args, char *), counter);
else if (format[i + 1] == 'd' || format[i + 1] == 'i')
    print_number(va_arg(args, int), counter);
else if (format[i + 1] == 'u')
    print_unsigned(va_arg(args, unsigned int), counter);
else if (format[i + 1] == 'x')
    print_hex(va_arg(args, unsigned int), 0, counter);
else if (format[i + 1] == 'X')
    print_hex(va_arg(args, unsigned int), 1, counter);
else if (format[i + 1] == 'p')
    print_pointer(va_arg(args, void *), counter);
else if (format[i + 1] == '%')
    print_char('%', counter);
```

Luego avanzas **i += 2** para saltarte el % y su especificador.