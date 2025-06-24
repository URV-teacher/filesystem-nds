#include <nds.h>
#include "hello-world.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fat.h>
#include <dirent.h>
#include <unistd.h>

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

    consoleDemoInit();

    // Inicializar libfat
    if (!fatInitDefault()) {
        printf("No se pudo inicializar libfat\n");
        while (1) swiWaitForVBlank();
        return 1;
    }


    FILE* test = fopen("/test.txt", "r");
    if (!test) {
        printf("No se pudo abrir el archivo\n");
    } else {
        printf("Leyendo test.txt...\n");

        char buffer[256];
        while (fgets(buffer, sizeof(buffer), test)) {
            printf("%s", buffer);
        }
        fclose(test);
    }

    // Open file for writing
    test = fopen("/out.txt", "w");
    if (!test) {
        printf("No se pudo abrir el archivo para escribir\n");
    } else {
        printf("Escribiendo en out.txt...\n");

        // Usar fwrite en lugar de fprintf
        const char *text1 = "Hola, este es un test en DeSmuME.\n";
        const char *text2 = "Probando escritura en archivo.\n";

        if (fwrite(text1, 1, strlen(text1), test) != strlen(text1)) {
            printf("Error al escribir en el archivo\n");
        }

        if (fwrite(text2, 1, strlen(text2), test) != strlen(text2)) {
            printf("Error al escribir en el archivo\n");
        }

        fclose(test);
        printf("Escritura completada.\n");
    }

    // Bucle infinito para mantener la pantalla encendida
    //while (1) swiWaitForVBlank();

    exit(0);
}








