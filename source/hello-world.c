#include <nds.h>
#include <stdio.h>
#include "hello-world.h"

#include <dir.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    consoleDemoInit();
    printf("Hello World\n");

    while(1) {
        swiWaitForVBlank();
        scanKeys();
        int pressed = keysDown();
        if(pressed & KEY_START) break;
    }

    /*
     * struct stat st;
    char filename[MAXPATHLEN]; // always guaranteed to be enough to hold a filename
    DIR_ITER* dir;

    dir = diropen ("/");

    if (dir == NULL)
    {
        iprintf ("Unable to open the directory.\n");
    }
    else
    {
        while (dirnext(dir, filename, &st) == 0)
        {
            // st.st_mode & S_IFDIR indicates a directory
            iprintf ("%s: %s\n", (st.st_mode & S_IFDIR ? " DIR" : "FILE"), filename);
        }
    }
     */
    return 0;
}







