#include <stdio.h>

/*count blanks, tabs, and newlines and copy input to its output, replacing each string of one or more blanks by a single blank*/
main()
{
    int b, t, nl, c;
    b = 0;
    t = 0;
    nl = 0;
    while ((c = getchar()) != EOF);
        if (c == '\n')
            ++nl;
    printf("%s %d\n", "Number of line breaks:", nl);
}
