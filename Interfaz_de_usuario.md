# Interfaz de usuario #

## Librerias utilizadas ##

  * **Librerias graficas basadas en SDL**:
> > _https://code.google.com/p/v-c-s/wiki/Librerias_graficas_basadas_en_SDL_
  * **Librerias de sonido basadas en SDL**
> > _https://code.google.com/p/v-c-s/wiki/Librerias_de_sonido_basadas_en_SDL_
## SDL vs GTK ##

Es importante hacer notar el porque de la elección de desarrollar enteramente la interfaz en SDL y no en GTK.
La principal razón es que GTK ~~es una mierda~~ no provee un soporte flexible para el desarrollo de juegos, esta mas orientado a interfaces de usuario estáticas. Por el otro lado, son muy difícilmente combinables, por lo que no es viable utilizar GTK como frame principal.