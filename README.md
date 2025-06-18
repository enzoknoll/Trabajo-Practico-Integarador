# Trabajo-Practico-Integrador
Programación 1: Trabajo Práctico Integrador

Integrantes:
+------------------------------+-----+
| Nombre y Apellido            | Rol |
| Knoll, Enzo José Javier      | dev |
| Saavedra, Lautaro Alejandro  | dev |
| Quintana, Leonardo Ezequiel  | dev |
+------------------------------+-----+

INSTRUCCIONES PARA COMPILAR Y EJECUTAR EL PROGRAMA DE SISTEMA DE BIBLIOTECA EN C

==================================================
REQUISITOS PREVIOS
==================================================

PARA WINDOWS:
1. Instalar TDM-GCC (https://jmeubank.github.io/tdm-gcc/) o MinGW (http://www.mingw.org/).
   - Durante la instalación, asegurate de agregar el compilador al PATH.
2. Alternativamente, podés usar Code::Blocks (incluye un compilador) o Dev-C++.

PARA LINUX (Ubuntu, Debian, Fedora, etc.):
1. Abrí la terminal y escribí:
   Ubuntu/Debian:
   sudo apt update && sudo apt install build-essential -y

   Fedora:
   sudo dnf install gcc

==================================================
PASOS PARA COMPILAR Y EJECUTAR
==================================================

1. Crear un archivo de código fuente:
   - Abrí un editor de texto.
   - Pegá todo el código fuente del programa.
   - Guardalo como: biblioteca.c

2. Abrir la terminal o consola:
   En Windows:
   - Presioná Win + R, escribí cmd y presioná Enter.
   - Navegá con: cd Desktop (o la carpeta donde esté el archivo).

   En Linux:
   - Abrí la terminal.
   - Navegá con: cd ~/Escritorio (o la carpeta correspondiente).

3. Compilar el programa:
   En Windows (MinGW o TDM-GCC):
   gcc biblioteca.c -o biblioteca.exe

   En Linux:
   gcc biblioteca.c -o biblioteca

4. Ejecutar el programa:
   En Windows:
   biblioteca.exe

   En Linux:
   ./biblioteca

==================================================
IMPORTANTE
==================================================

- El programa usa un archivo llamado libros.txt para cargar datos.
  Asegurate de que esté en la misma carpeta que el ejecutable.

- Al usar la opción 9 del menú, el programa guarda en datos_libros.txt.

- Para cerrar el programa, elegí la opción 10 o presioná Ctrl + C.

==================================================
