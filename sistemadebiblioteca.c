#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estructura para representar un libro
struct libros {
    char titulo[100];
    char autor[100];
    int codigo;
    char estado[20]; // "Disponible" o "Prestado"
};

// Estructura para representar un nodo en la lista enlazada
struct Nodo {
    struct libros libro;
    struct Nodo *siguiente;
};

// Función para mostrar el menú principal
void mostrar_menu() {
    printf("\n--- Sistema de Biblioteca ---\n");
    printf("1. Agregar libros\n");
    printf("2. Modificar estado de un libro\n");
    printf("3. Buscar libro por título\n");
    printf("4. Buscar libro por autor\n");
    printf("5. Listar libros alfabéticamente\n");
    printf("6. Mostrar libros por autor\n");
    printf("7. Libros prestados activos\n");
    printf("8. Mostrar todos los libros\n");
    printf("9. Guardar lista en un archivo 'datos_libros.txt'\n");
    printf("10. Salir\n");
}

// Función para agregar un libro a la lista enlazada
void agregar_libro(struct Nodo **cabeza, struct libros nuevo_libro) {
    struct Nodo *nuevo_nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo_nodo->libro = nuevo_libro;
    nuevo_nodo->siguiente = *cabeza;
    *cabeza = nuevo_nodo;
}

// Función para truncar texto con "..." si es necesario
void truncar_con_ellipsis(const char *original, char *destino, size_t max_visible_chars) {
    size_t visible = 0;
    const char *p = original;
    char *d = destino;

    while (*p && visible < max_visible_chars) {
        if ((*p & 0xC0) != 0x80) {  // No es byte de continuación UTF-8
            visible++;
        }
        *d++ = *p++;
    }

    if (*p) {
        // Si se truncó, agregamos "..."
        if (max_visible_chars >= 4) {
            d -= 4;  // Retrocede para reemplazar los últimos 4 con "..."
            strcpy(d, "...");
        } else {
            *d = '\0';
        }
    } else {
        *d = '\0';  // Finaliza si no fue truncado
    }
}

//Cargar Libro
struct libros cargar_libro() {
    struct libros nuevo_libro;
    char buffer[100];
    //Cargar un nuevo libro
    printf("Ingrese el título del libro: ");
    fgets(nuevo_libro.titulo, sizeof(nuevo_libro.titulo), stdin);
    nuevo_libro.titulo[strcspn(nuevo_libro.titulo, "\n")] = 0;
    printf("Ingrese el autor del libro: ");
    fgets(nuevo_libro.autor, sizeof(nuevo_libro.autor), stdin);
    nuevo_libro.autor[strcspn(nuevo_libro.autor, "\n")] = 0;
    printf("Ingrese el código del libro: ");
    fgets(buffer, sizeof(buffer), stdin);
    nuevo_libro.codigo = atoi(buffer);
    printf("Ingrese el estado del libro (Disponible/Prestado): ");
    fgets(nuevo_libro.estado, sizeof(nuevo_libro.estado), stdin);
    nuevo_libro.estado[strcspn(nuevo_libro.estado, "\n")] = 0;
    return nuevo_libro;
}

// Función para mostrar todos los libros en la lista enlazada
void mostrar_libros(struct Nodo *cabeza) {
    setlocale(LC_ALL, "");  // Para soportar UTF-8 en consola
    struct Nodo *actual = cabeza;
    char titulo_truncado[64];
    char autor_truncado[64];
    printf("\n+--------------------------------+--------------------------------+------------+------------+\n");
    printf("| %-30s | %-30s | %-10s | %-10s |\n", "Titulo", "Autor", "Codigo", "Estado");
    printf("+--------------------------------+--------------------------------+------------+------------+\n");

    while (actual != NULL) {
        truncar_con_ellipsis(actual->libro.titulo, titulo_truncado, 30);
        truncar_con_ellipsis(actual->libro.autor, autor_truncado, 30);
        printf("| %-30s | %-30s | %-10d | %-10s |\n",
               actual->libro.titulo, actual->libro.autor,
               actual->libro.codigo, actual->libro.estado);
        actual = actual->siguiente;
    }

    printf("+--------------------------------+--------------------------------+------------+------------+\n");
}

void modificar_estado_libro(struct Nodo *cabeza, int codigo, const char *nuevo_estado) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        if (actual->libro.codigo == codigo) {
            strncpy(actual->libro.estado, nuevo_estado, sizeof(actual->libro.estado) - 1);
            actual->libro.estado[sizeof(actual->libro.estado) - 1] = '\0'; // Asegurar terminación
            printf("Estado del libro con código %d modificado a '%s'.\n", codigo, nuevo_estado);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Libro con código %d no encontrado.\n", codigo);
}

//Buscar título de un libro
void buscar_titulo_libro(struct Nodo *cabeza, const char *titulo) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        if (strcmp(actual->libro.titulo, titulo) == 0) {
            printf("Libro encontrado: Título: %s, Autor: %s, Código: %d, Estado: %s\n",
                   actual->libro.titulo, actual->libro.autor,
                   actual->libro.codigo, actual->libro.estado);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Libro con título '%s' no encontrado.\n", titulo);
}

//Buscar autor de un libro
void buscar_autor_libro(struct Nodo *cabeza, const char *autor) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        if (strcmp(actual->libro.autor, autor) == 0) {
            printf("Libro encontrado: Título: %s, Autor: %s, Código: %d, Estado: %s\n",
                   actual->libro.titulo, actual->libro.autor,
                   actual->libro.codigo, actual->libro.estado);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Libro con autor '%s' no encontrado.\n", autor);
}

void mostrar_lista_prestados(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    int encontrado = 0;
    printf("\n+--------------------------------+--------------------------------+------------+------------+\n");
    printf("| %-30s | %-30s | %-10s | %-10s |\n", "Título", "Autor", "Código", "Estado");
    printf("+--------------------------------+--------------------------------+------------+------------+\n");

    while (actual != NULL) {
        if (strcmp(actual->libro.estado, "Prestado") == 0 || strcmp(actual->libro.estado, "prestado") == 0) {
            printf("| %-30s | %-30s | %-10d | %-10s |\n",
                   actual->libro.titulo, actual->libro.autor,
                   actual->libro.codigo, actual->libro.estado);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        printf("| No hay libros prestados.                                                                 |\n");
    }
    printf("+--------------------------------+--------------------------------+------------+------------+\n");
}

//agregar lista de prestamo
void agregar_a_prestamos(struct Nodo **prestamos, struct libros libro) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->libro = libro;
    nuevo->siguiente = *prestamos;
    *prestamos = nuevo;
}

int main() {
    struct Nodo *cabeza = NULL;
    int opcion, condicion_fin_menu = 1, condicion_fin_cargar_libro = 1; 
    char titulo[100], autor[100], estado[20];

   while(condicion_fin_menu == 1) {
        int condicion_fin_lista_prestados = 1;
        //Menú principal
        mostrar_menu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar el buffer
        switch(opcion) {
            case 1:
                // Cargar libros
                while(condicion_fin_cargar_libro == 1){
                    struct libros nuevo_libro = cargar_libro();
                    agregar_libro(&cabeza, nuevo_libro);
                    printf("¿Desea ingresar otro libro? (1: Sí, 0: No): ");
                    scanf("%d", &condicion_fin_cargar_libro);
                    getchar();  // Limpiar el buffer
                }
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
                
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                mostrar_libros(cabeza);
                break;
            case 9:
                
                break;
            case 10:
                
                return 0;
            default:
                
                return 1;
        }
        if(condicion_fin_lista_prestados == 0) {
            continue;
        }
    }

    return 0;
}
