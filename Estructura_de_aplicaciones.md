# Estructura de aplicaciones #

## Descripcion ##

Resumen sobre como se organizan las aplicaciones en aplicaciones mas pequeñas.

## ? ##

Las aplicaciones (Cliente y Editor) se componen por una aplicacion que a su vez contiene otras "mini aplicaciones". Cada una de estas "mini aplicaciones" maneja una parte en particular del programa y no se relacionan entre si, de manera de lograr una mayor independencia entre las partes.
Cada "mini aplicacion" deriva de la clase App, y debe implementar los 5 metodos mediante los cuales se ejecutan.