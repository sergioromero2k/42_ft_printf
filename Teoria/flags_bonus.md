### TABLA RESUMEN DE FLAGS, ANCHO Y PRECISIÓN EN printf
---
#### FLAGS PRINCIPALES (- 0 # + ' ')
| Flag          | Significado                                                                | Tipos donde aplica | Ejemplo | Resultado |          |   |            |   |
| ------------- | -------------------------------------------------------------------------- | ------------------ | ------- | --------- | -------- | - | ---------- | - |
| `-`           | Alinear a la izquierda                                                     | Todos              | `"      | %-10d     | " → 42`  | ` | 42         | ` |
| `0`           | Relleno con ceros a la izquierda (si no hay `-` ni precisión para enteros) | Numéricos          | `"      | %010d     | " → 42`  | ` | 0000000042 | ` |
| ` ` (espacio) | Coloca un espacio si el número es positivo                                 | Enteros            | `"      | % d       | " → 42`  | ` | 42         | ` |
| `+`           | Fuerza el signo (+ o -)                                                    | Enteros            | `"      | %+d       | " → 42`  | ` | +42        | ` |
| `#`           | Formato alternativo                                                        | `o`, `x`, `X`, `f` | `"      | %#x       | " → 255` | ` | 0xff       | ` |

#### ANCHO MÍNIMO (width)
| Elemento        | Significado                  | Ejemplo | Resultado |            |   |         |   |
| --------------- | ---------------------------- | ------- | --------- | ---------- | - | ------- | - |
| `N` (número)    | Campo mínimo de N caracteres | `"      | %10s      | " → "hey"` | ` | hey     | ` |
| Combina con `-` | Alinear izquierda            | `"      | %-10s     | " → "hey"` | ` | hey     | ` |
| Combina con `0` | Rellenar con ceros           | `"      | %07d      | " → 42`    | ` | 0000042 | ` |

#### PRECISIÓN (.N) 
| Tipo                                   | Efecto                | Ejemplo | Resultado |             |   |       |   |
| -------------------------------------- | --------------------- | ------- | --------- | ----------- | - | ----- | - |
| Enteros (`d`, `i`, `u`, `x`, `X`, `o`) | Mínimo de dígitos     | `"      | %.5d      | " → 42`     | ` | 00042 | ` |
| Cadenas (`s`)                          | Máximo de caracteres  | `"      | %.3s      | " → "Hola"` | ` | Hol   | ` |
| Flotantes (`f`)                        | Nº de decimales       | `"      | %.2f      | " → 3.1416` | ` | 3.14  | ` |
| Enteros + precisión                    | Desactiva el flag `0` | `"      | %010.5d   | " → 42`     | ` | 00042 | ` |

#### TABLA DE PRIORIDAD ENTRE FLAGS
| Combinación                 | Gana             | Explicación                          |
| --------------------------- | ---------------- | ------------------------------------ |
| `+` vs ` `                  | `+`              | Si pones ambos, el espacio se ignora |
| `-` vs `0`                  | `-`              | Alineación izquierda anula ceros     |
| `0` vs precisión en enteros | Precisión        | Si hay `.N`, se ignora `0`           |
| `#`                         | Siempre funciona | Si el número ≠ 0                     |

#### EJEMPLOS ÚTILES COMBINADOS
| Especificador | Explicación                      | Resultado    |
| ------------- | -------------------------------- | ------------ |
| `%08d`        | 8 caracteres, rellenar con ceros | `00000042`   |
| `%-8d`        | 8 caracteres, izquierda          | `42______`   |
| `%+8d`        | Reserva 8, muestra signo         | `_____+42`   |
| `% 8d`        | Igual que arriba sin `+`         | `______42`   |
| `%#.5x`       | Hex con `0x` + precisión         | `0x000ff`    |
| `%-10.3s`     | 10 de ancho, máx 3 chars         | `Hol_______` |
