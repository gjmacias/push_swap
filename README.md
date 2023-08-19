# push_swap - gmacias-
Push_swap es un proyecto de algoritmia simple, tienes que ordenar datos. Tienes a tu disposición un conjunto de valores desordenados guardados en un stack, tienes dos stacks y un conjunto de instrucciones para manipularlos. En este proyecto deberás utilizar el minimo de instrucciones posible.
### Indice
* [Que es push_swap?](#que-es-push_swap)
* [Que utilizamos?](#que-utilizamos)
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

![](https://github.com/gjmacias/push_swap/bl/push_swap.gif)

### Que utilizamos?
En nuestro **push_swap** tenemos solo las siguentes funciones de librerias externas autorizadas:

| Función  | Descripción														 			|
|-------|-----------------------------------------------------------------------------------|
| malloc | Solicitar un bloque de memoria del tamaño suministrado como parámetro.     													|
| free | Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 											|
| write | Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.								|
| open |  Abre el archivo del sistema seleccionado.													|
| close |  Cierra el archivo del sistema seleccionado.               											|
| read |  Lee el contenido del archivo del sistema seleccionado.               									|
| exit | Finaliza inmediatamente el programa liberando la memoria dinamica asignada        |

### Como funciona?

Para compilar el programa seguimos los siguientes pasos:

	git clone https://github.com/gjmacias/push_swap
	cd push_swap
	make
Luego ejecutamos el programa pasandole de parametro la ubicacion :

	./push_swap 

¡Y eso seria todo!¡Estas liso para jugar!

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
