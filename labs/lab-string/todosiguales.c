#include <stdio.h>
#include "String.h"

int main(int argc, char *argv[]) {
    (void)argc;

    if (argv[1] == NULL) {
        printf("1\n");
        return 0;
    }

    int todos_iguales = 1;
    
    for (char **arg = argv + 2; *arg != NULL; arg++) {
        if (!AreEqual(argv[1], *arg)) {
            todos_iguales = 0;
            break;
        }
    }

    printf("%d\n", todos_iguales);
    return 0;
}
