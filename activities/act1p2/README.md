# Act. 1.2 - Implementación de la técnica de programación "Programación dinámica" y "algoritmos avaros"
## Autor
Jeshua Nava Avila
## Fechas
Fecha de última modificación: 29/08/2022

## Curso
Nombre y Grupo: Análisis y diseño de algoritmos avanzados (Gpo 601).
Profesor: Gildardo Sánchez Ante.

## Notas
### Casos Prueba
Cada coma significa una línea en el archivo de texto. Lo hago así aquí para que se leíble.
### Denominaciones
En cada denominación, es obligatorio incluir uno, porque sin este, no se podría devolver cambio exacto en algunos casos. Aparte, toda moneda popular en el mercado cuenta con esta unidad en sus denominaciones.

### 1
**[5, 20, 10, 5, 2, 1, 57, 100]**
Esta prueba, tiene *denominaciones normales y representa un caso promedio*, porque de ahí en fuera nada es especial. El cambio que se debe de volver es 43, y este número no tiene nada en particular.

### 2
**[4, 12, 25, 1, 5, 20, 36]**
Este caso *tiene las denominaciones de las monedas sin ningún orden*, de ahí en fuera, esta prueba es considerada normal.

### 3
**[5, 1, 3, 5, 6, 9, 10, 100]**
En esta situación, *las denominaciones son número múltiplo de 3 (y 1), una denominación que no se maneja en las monedas populares del mercado en la actualidad*. Este caso, sirve para demostrar la exactitud de los algoritmos.

### 4
**[1, 2, 15, 20]**
Este es uno de los casos para demostrar que pasaría *si nada más tenemos una moneda en nuestra denominación, y si ese no es uno*. En cada prueba anterior, el uno ha sido agregado a proposito, para que siempre se pueda devolver un cambio exacto.