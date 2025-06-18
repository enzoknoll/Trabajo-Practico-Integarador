# Trabajo Práctico Integrador

**Materia:** Programación 1  
**Trabajo:** Trabajo Práctico Integrador

## Integrantes

| Nombre y Apellido            | Rol  |
|-----------------------------|------|
| Knoll, Enzo José Javier     | Dev  |
| Saavedra, Lautaro Alejandro | Dev  |
| Quintana, Leonardo Ezequiel | Dev  |

---

## Instrucciones para Compilar y Ejecutar el Programa en C

### Requisitos Previos

#### Para Windows:

1. Instalar [TDM-GCC](https://jmeubank.github.io/tdm-gcc/) o [MinGW](https://www.mingw-w64.org/downloads/#mingw-w64-builds).
   - Durante la instalación, asegurate de agregar el compilador al `PATH`.
2. Alternativamente, podés usar Code::Blocks (incluye un compilador) o Dev-C++.

#### Para Linux (Ubuntu, Debian, Fedora, etc.)

1. Abrí la terminal y escribí el siguiente comando según tu sistema:

**Ubuntu/Debian:**
```bash
sudo apt update && sudo apt install build-essential -y
```

**Fedora:**
```bash
sudo dnf install gcc
```

---

## Pasos para Compilar y Ejecutar

1. Crear un archivo de código fuente:
   - Abrí un editor de texto.
   - Pegá todo el código fuente del programa.
   - Guardalo como: `biblioteca.c`

2. Abrir la terminal o consola:

**En Windows:**
```bash
cd ruta\a\la\carpeta\donde\esta\biblioteca.c
```

**En Linux:**
```bash
cd ~/ruta/a/la/carpeta
```

3. Compilar el programa:

**Windows (TDM-GCC o MinGW):**
```bash
gcc biblioteca.c -o biblioteca.exe
```

**Linux:**
```bash
gcc biblioteca.c -o biblioteca
```

4. Ejecutar el programa:

**Windows:**
```bash
biblioteca.exe
```

**Linux:**
```bash
./biblioteca
```

---

## ⚠️ Importante

- El programa utiliza un archivo llamado `libros.txt` para cargar datos.  
  Asegurate de que esté en la misma carpeta que el ejecutable.

- La opción **9** del menú guarda los datos en `datos_libros.txt`.

- Para salir del programa, elegí la opción **10** o presioná `Ctrl + C`.
