#Introdución
------------
En este proyecto se verá la realización del sistema solar con Unity, mediante un Universal Render Pipeline, utilizando Shadergraph. Esto se logrará utilizando las diversas técnicas y enseñanzas obtenidas en clase, así como a su vez intentar técnicas distintas como lo son los efectos visuales. El objetivo es realizar un Sistema Solar con mucha semejanza al real.

Teniendo integrado los siguientes puntos:
- Textura
- Normal Map
- Rim Light
- Efectos extra sobre la Superficie
- Orden de los respectivos planetas
- Visual Efects

-------------
#Desarrollo
-------------
Para la creación de la mayoría de los planetas, se utilizó un Shader Lit que forma parte del universal render pipeline, una vez creado el desarrollo del shader se dividió en cuatro segmentos importantes que lo conformarán mediante el uso de nodos. Que vendrían siendo la main texture, el normal map, la Rim Light y el occlussion junto a Visual Effects.

**Main Texture**
![alt text](direccion de imagen)

**Normal Map**
![alt text](direccion de imagen)

**Rim Light**
![alt text](direccion de imagen)

**Occlussion**
![alt text](direccion de imagen)

**Video Animacion**
[![Watch the video](https://lh3.google.com/u/0/d/1uTzLP9AhY8K0NdlAdWvuZXv_xJ22DgJt=k)](https://drive.google.com/file/d/1uTzLP9AhY8K0NdlAdWvuZXv_xJ22DgJt/view?usp=sharing)

**Obtencion de Texturas**
Para obtener la textura base de los planetas, se visitó el sitio Solar System Scope, donde se pueden encontrar texturas reales en resolución 2K de todos los planetas de forma gratuita.

![alt text](direccion de imagen)

Sin embargo, no contaban con la mayoría de las texturas normales y ninguna de oclusión ambiental, por lo que se utilizó un programa llamado Crazybump con el que pudimos mapear estas texturas fácilmente. 

En este programa primero se introduce la textura original, y luego el programa pide que elijas una imagen para hacer un mapeado de la textura, en este caso se utilizó la primera figura.

![alt text](direccion de imagen)

Una vez seleccionada la figura, se puede pasar a conseguir la textura normal y de oclusión ambiental. Se modifican los sliders para tener una textura más semejante a la de la realidad, y de ahí se exporta directamente en la carpeta de unity, donde se encuentra la textura principal.

![alt text](direccion de imagen)

Para realizar la textura principal, se eligió una de las que se descargaron anteriormente. La textura se indica en un Sample Texture 2D, el cual estará conectado con el color base del shader. A esta textura se le aplican varias cosas. La primera es el efecto de Tiling and Offset, el cual se usa para rotar la textura alrededor de una esfera, para simular la rotación del planeta sobre su propio eje. Se tiene que conectar un nodo de multiplicación del tiempo transcurrido con la velocidad de rotación. La fórmula es un despeje de velocidad: V = D/T  a D = V*T.

Este nodo va conectado con un Vector2, que será el que maneje el eje X. Esto es importante, ya que si no se conecta aquí, la textura comenzará a rotar en direcciones no deseadas, por lo que le indicamos que solo se mueva en el eje X.

![alt text](direccion de imagen)

Para la textura Normal, se realizó un proceso similar, donde se indica la textura en un Sample Texture 2D, y su UV está conectado con el mismo Tiling and Offset de la textura principal, ya que estas texturas tienen que rotar a la misma velocidad y dirección. Sin embargo, es importante asegurarse de que el tipo de textura esté indicado como Normal y no Default como en la principal, para dar un efecto más convincente. Sirve para añadir profundidad al planeta, y que no sea simplemente una esfera plana. El Sample Texture 2D luego pasa a un filtro donde se puede manejar su fuerza utilizando un slider. Después va conectada al nodo Normal (Tangent Space) del fragmento.

![alt text](direccion de imagen)

Un efecto importante para la composición del planeta fue el de un anillo de luz, o Rim Light. Para esto se necesitó utilizar el nodo de Fresnel Effect, el cual necesita un vector3, la dirección de vista, y un Float el cual manejaría la intensidad del anillo. Esto pasa a otro donde se multiplican el efecto anterior con un color HDR, para así poder cambiar el color del anillo fácilmente.  Una vez terminado el efecto, este pasa a conectarse con el nodo de emisión del fragmento.

![alt text](direccion de imagen)
