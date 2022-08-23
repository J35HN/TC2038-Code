# Act. 1.1 - Implementación de la técnica de programacion "divide y vencerás"
## Autor
Jeshua Nava Avila | A01639282
Fecha de última modificación: 22/08/2022.

## Curso
Nombre y Grupo: Análisis y diseño de algoritmos avanzados (Gpo 601).
Profesor: Gildardo Sánchez Ante.

## Nota
Escribo esta nota por como **YO** debo de correr el archivo en ambiente Windows, y me genera inquietud.
* En Command Line debo de correr el archivo con la sintaxis "*main < prueba1.txt*". 
* A diferencia como lo marca en las instrucciones "*./main < prueba1.txt*".
Lo más problable es que en Linux tenga esta segunda sintaxis, pero por si acaso no lo corre,
quizá valga la pena intentar de la primera forma.

## Casos Prueba
### 1
**[ 10 ]**
Este caso de prueba lo escogo por ser un caso particular. No queremos que corra todo el algoritmo completo 
cuando *no es necesario tener que ordenar el único elemento de la lista*.

### 2
**[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]**
En este caso ya se cuenta con una *lista ordenada pero en reversa*. El algoritmo debe de invertir esta lista.

### 3
**[0, 1, 0, 0, -1, -1, -1, 1, 1, 1, -1, 1, 0, 0, -1, 0]**
Este caso se utiliza por tener *varios elementos repetidos*, con un poco de desorden.
El algoritmo debe ser capaz de ordenar esta lista.

### 4
**[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]**
Para el útlimo caso, la *lista ya se encuentra ordenada* con el criterio de mayor a menor.
El algoritmo debería de regresar la misma lista.