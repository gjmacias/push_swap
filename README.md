# push_swap - gmacias-
Push_swap es un proyecto de algoritmia simple, tienes que ordenar datos. Tienes a tu disposición un conjunto de valores desordenados guardados en un stack, tienes dos stacks y un conjunto de instrucciones para manipularlos. En este proyecto deberás utilizar el minimo de instrucciones posible.
### Indice
* [Que es push_swap?](#que-es-push_swap)
* [Que utilizamos?](#que-utilizamos)
* [EL ALGORITMO](#el-algoritmo)
* [Como funciona?](#como-funciona)

### Que es push_swap?
push_swap es un proyecto de [42][1] sobre algoritmia simple, donde debes ordenar datos numéricos de menor a mayor. Con el único inconveniente de tener dos stacks y una serie de movimientos permitidos para ordenarlos:

| Operaciones | Explicación |
| :--- | :--- |
| sa | swap a - intercambia los dos primeros elementos encima del stack a. |
| sb | swap b - intercambia los dos primeros elementos encima del stack b. |
| ss | swap a y swap b a la vez. |
| pa | push a -  toma el primer elemento del stack b y lo pone encima del stack a. |
| pb | push b -  toma el primer elemento del stack a y lo pone encima del stack b. |
| ra | rotate a - desplaza hacia arriba todos los elementos del stack a una posición, el primer elemento se convierte en el último. |
| rb | rotate b - desplaza hacia arriba todos los elementos del stack b una posición, el primer elemento se convierte en el último. |
| rr | ra y rb a la vez. |
| rra | reverse rotate a - desplaza hacia abajo todos los elementos del stack a una posición, el último elemento se convierte en el primero. |
| rrb | reverse rotate b - desplaza hacia abajo todos los elementos del stack b una posición, el último elemento se convierte en el primero. |
| rrr | rra y rrb a la vez. |

Muestro por aqui los movimientos máximos permitidos por cantidad de numeros:

- 3 numeros: 	**Max 3 movimientos**
- 5 numeros: 	**Max 12 movimientos**
- 100 numeros:	**Menos de 700**; ⭐⭐⭐⭐⭐ |  701 a 900; ⭐⭐⭐⭐ |  901 a 1100; ⭐⭐⭐ |  1101 a 1300; ⭐⭐ |  1301 a 1500; ⭐ |
- 500 numeros:	**Menos de 5500**; ⭐⭐⭐⭐⭐ |  5501 a 7000; ⭐⭐⭐⭐ |  7001 a 8500; ⭐⭐⭐ |  8501 a 10000; ⭐⭐ |  10001 a 11500; ⭐ |

 Y aquí mostramos unos ejemplos de su funcionamiento:

![push_swap_pequeño](https://github.com/gjmacias/push_swap/assets/98602276/5c82a898-c2d2-4535-9c58-7ff46e9b7f4f)

![push_swap](https://github.com/gjmacias/push_swap/assets/98602276/7f41980b-3722-4b0f-b3b1-5b774b34134f)

### Que utilizamos?
En nuestro **push_swap** tenemos solo las siguentes funciones de librerias externas autorizadas:

| Función  | Descripción														 	|
|-------|-----------------------------------------------------------------------------------|
| malloc | Solicitar un bloque de memoria del tamaño suministrado como parámetro.     											|
| free | Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 									|
| write | Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.							|
| exit | Finaliza inmediatamente el programa liberando la memoria dinamica asignada        |

### EL ALGORITMO
Este algoritmo no tiene nobre como tal, si tubiera un nombre seria; *Shortest Move Sort*. Por que busca el movimiento más corto posible en cada caso y lo ejecuta, para ello debe cumplir
estas condiciones:  

El numero elegido del Stack A debe ser menor al número top del Stack B y Mayor al Numero del fondo del Stack B. Ejemplo:

| Stack A  | Stack B		|
|----------|--------------------|
| 6 | 7		|
| ... | ...	|
| ... | 5     |

Por que nos interesa? Por que es el movimiento más rápido para pasar los valores de manera ordenada desde el stack A al stack B. No buscamos un número en concreto, buscamos el número que necesite menos movimientos.
Para eso creamos un mapa de movimientos donde rotamos todos los números del Stack B por cada número del Stack A para comprobar cuanto hay que rotar A y cuanto hay que rotar B para que:

1. Cumpla la primera condición.
2. Consuma los minimos movimientos necesarios para enviarlos al Stack B de manera ordenada.

**Ejemplo práctico**:

| Stack A  | Stack B		|
|----------|--------------------|
| 5 | 1		|
| 4 | 3		|
| 2 | 6     |

| Movimientos para cumplir condición 1  | Stack B + 0		| Stack B + 1		| Stack B + 2		| Stack B + 3		|
|---------------------------------------|-----------------------|-----------------------|-----------------------|-----------------------|
| Stack A + 0 rotación hacia arriba	| No cumple		| No cumple		| **Cumple, 0 + 2 = 2**	| No cumple		|
| Stack A + 1 rotación hacia arriba	| No cumple		| No cumple		| Cumple, 1 + 2 = 3	| No cumple		|
| Stack A + 2 rotación hacia arriba	| No cumple		| Cumple, 2 + 1 = 3	| No cumple		| No cumple		|
| Stack A + 3 rotación hacia arriba	| No cumple		| No cumple		| Cumple, 3 + 2 = 5	| No cumple		|

En este pequeño y básico ejemplo, vemos el mapa de movimientos y cual consume los minimos, que seria rotar dos veces el stack B y añadir el numero en su lugar correspondiente. Ahora no se ve tan necesario, pero con
una cantidad elevada de números marca la diferencia.

Esa es la base, ahora falta optimizarlo, el primer paso es que las rotaciones pueden ser tanto por arriba o por abajo, Para ello, cuando la condición se cumple, comprobamos tanto del Stack A como del Stack B si es mas rápido rotando hacia arriba o hacia abajo:

**Ejemplo práctico**:

| Stack A  |
|----------|
| 25 |
| 42 |
| 200 |
| **6**|
| 73 |

Imaginemos que opción óptima es el 6; si vamos por arriba serán 3 movimientos pero, si vamos por abajo (numeros del stack; *5* - movimientos hacia arriba; *3*) vemos que serian 2.

Como hemos visto importa el sentido de los movimientos, y esto nos ayudará a elegir mejor los movimientos para hacer, pero todavia se puede optimizar mucho más:

Una vez encontramos una opción que cumpla la condición 1, guardamos cuantos movimientos hacia arriba y hacia abajo se harian tanto en el Stack A como en el Stack B:

**Ejemplo práctico**:

|Movimientos  	| Stack A (300 numeros) | Stack B (100 numeros)		|
|--------------|------------------------|------------------------------|
| Hacia arriba | 192 movimientos	| 5 movimientos			|
| Hacia abajo | 300 - 192 = 108 mov.	| 100 - 5 = 95 mov.	|

Aqui se pueden solapar movimientos ya que si los dos van hacia arriba o hacia abajo, se pueden hacer a la vez y ahorrar muchos movimientos, asi que aqui hay 4 posibilidades:

- Stack A arriba y Stack B arriba: *Solapan* - 192 y 5 = **192 movimientos**
- Stack A abajo y Stack B abajo: *Solapan* - 108 y 95 = **108 movimientos**
- Stack A arriba y Stack B abajo: 192 + 95 = **287 movimientos**
- Stack A abajo y Stack B arriba: 108 y 5 = **109 movimientos**

En este caso la mejor opcion seria solapar movimientos rotativos hacia abajo y luego el stack que falte por rotar rote solo.

**CON TODO ESTO YA ESTAS LISTO PARA CREAR TU ALGORITMO(casi):**

Debes de ver cuando se cumple la condición 1.  
En cada uno de los nodos que se cumpla deberás ver que unión de movimientos es el más eficaz.
Una vez hecho esto en cada posibilidad, deberas ejecutar la que utilize menos movimientos.
Cuando este todo en el Stack B, solo te queda ordenarlo en el stack A.



Me he saltado la explicación de que hacer en caso de encontrarte con el numero más pequeño, el más grande o lo de ordenar los tres últimos numeros ya que sé que serás capaz de averiguarlo sin mi ayuda, te deseo suerte!
### Como funciona?

Para compilar el programa seguimos los siguientes pasos:

	git clone https://github.com/gjmacias/push_swap
	cd push_swap
	make
Luego ejecutamos el programa pasandole de parametro la ubicacion junto al listado de numeros que deseas ordenar:

	./push_swap 3 6 23 3645 12 ...

Una vez enviado, te mostrará por pantalla los movimientos que el algoritmo hace para tomarle los minimos movimientos posibles, ¡Eso sería todo!

# Quizás pueda interesarte!

### - Para ver mi progresion en 42 🌠
[AQUÍ](https://github.com/gjmacias/42BCN)

### - Mi perfil de 42 👾
[AQUÍ](https://profile.intra.42.fr/users/gmacias-)

### - Mis proyectos personales 🧐
[AQUÍ🗒️](https://github.com/gjmacias/autoproyectos)

# Contacto 📥

◦ Email: gmacias-@student.42barcelona.com

[1]: https://www.42barcelona.com/ "42 BCN"
