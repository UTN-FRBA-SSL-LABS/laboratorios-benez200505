#include <stdio.h>
#include "Conversion.h"

int main(int argc, char *argv[]) {
    (void)argc;
    int suma = 0;
    
    for (char **arg = argv + 1; *arg != NULL; arg++) {
        suma += ToInteger(*arg);
    }
    
    printf("%d\n", suma);
    return 0;
}