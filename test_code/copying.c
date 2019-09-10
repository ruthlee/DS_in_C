#include <stdio.h>
/*copy input to output*/
main()
{
    int c;
    printf("%d\n", EOF);
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}
