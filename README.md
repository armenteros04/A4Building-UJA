<img src="https://eps.ujaen.es/sites/centro_eps/files/styles/news_photo_tablet/public/uploads/node_noticia/2020-03/unnamed.png?itok=gtl_-LKj" width="200" height="150" />

# A4 Building
## Proyecto final de Informática gráfica y visualización
### Realizado por Antonio Armenteros y Jacobo Pancorbo

En nuestro proyecto final de prácticas hemos querido representar el edificio A4 de manera en la cual puedes interactuar con objetos de la escena y moverse libremente alrededor del edificio. 
[Pulsando en este enlace](https://youtu.be/TeK37ZUuyUg) se puede ver un video con todos los detalles y características del proyecto.



### **Generación de cámaras, proyecciones y viewports**

  Hemos creado una cámara que es un dron, con la cual puedes moverte de forma totalmente libre por la escena pudiendo
  tener infinitas proyecciones y posibilidades de ver cualquier detalle. La proyección utilizada ha sido la proyección perspectiva,
  con la intención de darle un mayor grado de realismo a la escena que el que podría haber sido conseguido con la paralela.

### **Movimientos de la cámara**

La cámara tiene varios movimientos.
En un primer lugar se da la libertad de mover el punto donde está situada la cámara p0, hacia delante o hacia detrás, cada vez que se mueve hacia delante o hacia detrás tanto con el punto de visión p0 como el punto al que mira la cámara se incrementan en su distancia, dando así la sensación de moverse a lo largo del espacio.
Por otra parte, la cámara tiene la libertad de mover el punto de visión libremente hacia arriba y hacia abajo, hacia derecha e izquierda. Esto se ha conseguido utilizando la ecuación paramétrica de la esfera.

<img src="https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiOpK3HlTJHMhLkMtBmDmFbWbmMKWWYX8iUy9xRbAUCwjFdlBXnJNat9PBO7U1PkB1osMDgnWlMot6amA-OYe1F4l1WCoj2i2_syn-RKEqs3-KyUgAFQlgx7r3W3XZaw4Sbd87g40SLxqcm/s1600/esfera.png" >

Se ha llevado el control de dos ángulos alfa y beta para controlar arriba o abajo y izquierda o derecha respectivamente.
Se puede acceder a todos los puntos dentro del radio de la esfera para posteriormente moverse hacia ellos, así es como se garantiza el efecto de libertad de movimiento por toda la escena.

### **Modelado de objetos**

El proyecto consta de objetos modelados mediante mallas de triangulos que son un cono truncando con dos pasantes enfrentados, y un cilindro.
Además, también cuenta con primitivas de OpenGL como glutSolidCube(1.0);
Lo cual origina un cubo sólido de tamaño 1 que al aplicar transformaciones geométricas hemos conseguido crear sillas, mesas, una pizarra y un tablón de anuncios.

### **Modelado del grafo de escena**

<img src="https://media.discordapp.net/attachments/1339681933994623102/1339681947542360074/image.png?ex=67af9b8a&is=67ae4a0a&hm=c0b4bd5dc223eee993c8a078abeb1aeac83c8f301396095abb383ce3627dcc17&=&format=webp&quality=lossless" width="650">

El grafo de escena que vamos a representar es una persona con gorra bailando.
Las transformaciones que puede hacer son mover los brazos haciendo una rotación, al igual que la cabeza. Respecto a las piernas puede agacharse simulando hacer una sentadilla con un ángulo de 45 grados.

<img src="https://media.discordapp.net/attachments/1339681933994623102/1339682700168134736/image.png?ex=67af9c3d&is=67ae4abd&hm=d8ab8148c4f1bf638650e2c3b679bbf49c94d0a38cb1b391b4619e4c58ece1f7&=&format=webp&quality=lossless" width="400">

### **Selección e interacción con el grafo de escena**

El proceso de selección se ha aplicado principalmente a abrir y cerrar las puertas del aula anteriormente presentadas.
Para implementar el proceso de selección de elementos se ha utilizado un proceso de selección por buffer de color. 
Para empezar el color de las puertas es ligeramente diferente, la diferencia es inapreciable, pero con ella conseguimos que cuando se selecciona una de ellas se puedan diferenciar, permitiendo hacer la rotación sobre la puerta correspondiente abriendo y cerrando.
Para seleccionarla se utiliza el ratón, la tecla izquierda concretamente, y una vez seleccionada se atiende al propio desplazamiento del ratón para abrirla o cerrarla, simulando lo que podría ser agarrar una puerta para abrirla. El propio hecho de arrastrar el ratón con el botón izquierdo pulsado aplica una rotación sobre la puerta dando la impresión de que se abre o se cierra.

[Ver video de selección e interacción](https://drive.google.com/file/d/1iENZPVU87htEFo1iqeiqzLt0kvxttMTk/view)

### **Animación de la escena**

Hemos usado la función glutIdleFunc() para animar parte de la escena de manera automática haciendo que la persona representada en el grafo de escena esté bailando.

[Ver video de la animación de la escena](https://drive.google.com/file/d/1JalA0PMtCAUhMTkad2DeheSLDqwC3LSy/view)

### **Aplicación de materiales, luces y texturas**

En nuestro proyecto hemos ubicado un foco de luz de forma que apunta directamente a las escaleras del edificio.
También, hemos incluido varias texturas que las hemos implementado mediante un quad escogiendo 4 vértices de la cara de un cubo y aplicando sobre esas coordenadas la textura.

### **Manual de usuario**
* Tecla e → Activar y desactivar ejes
* Tecla w → Avanzar hacia delante
* Tecla s → Avanzar hacia atrás
* Tecla i → Mirar hacia arriba
* Tecla k → Mirar hacia abajo
* Tecla l → Mirar hacia la derecha
* Tecla j → Mirar hacia la izquierda
* Tecla a → Activar la animación
* Mecanismo para abrir puerta: Para seleccionar la puerta y abrirla, el mecanismo consiste en seleccionar el cubo que simula la puerta con el botón izquierdo del ratón mantenido y desplazar el ratón para abrirla o cerrarla manteniendo pulsado durante la interacción.


