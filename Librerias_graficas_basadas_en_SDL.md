# Librerias Graficas #

## Descripcion ##

Librerias para crear un framework grafico basado en SDL orientado a objetos y amigable al usuario.

## Requerimientos ##

  * **Libsdl2** (_SDL 2_)
  * **SDL Images 2**  (_SDL 2_):
> > Requiere el paquete libsdl2-image-2.0-0 para usarlo
> > Requiere el paquete libsdl2-image-dev para compilarlo
  * **SDL TTF** (_SDL 2_):
> > Requiere el paquete libsdl2-ttf-2.0-0 para correrlo
> > Requiere el paquete libsdl2-ttf-dev para compilarlo

## Archivos ##

  * _surface.h_ :
  * _sprite.h_ :
  * _animated\_sprite.h_ :
  * _window.h_ :
  * _text\_drawer.h_:
  * _text\_box.h_:
  * _secret\_text\_box.h_:
  * _button.h_:
> > Funciona simplemente como un boton que al ser clickeado se activa y al clickearse en otro lado se desactiva. Esto funciona segun el evento pasado, por lo que se puede restringir la zona donde se le pasa el evento o no.
  * _screen\_zone.h_: