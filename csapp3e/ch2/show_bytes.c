#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_long(long x)
{
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x)
{
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_string(char *x)
{
    show_bytes((byte_pointer) x, strlen(x) + 1);
}

int main(int argc, char *argv[])
{
    char *str = argv[1];
    int ival = atoi(str);
    long lval = atol(str);
    float fval = (float) ival;
    double dval = (double) lval;
    long *pval = &lval;

    printf("Input string: %s\n", str);
    printf("String representation:                 ");
    show_string(str); 
    printf("\n");
    printf("Int atoi(string)  representation:      ");
    show_int(ival);
    printf("             (%d)\n", ival);
    printf("Long atol(string) representation:      ");
    show_long(lval);
    printf(" (%ld)\n", lval);
    printf("Float (cast from int) representation:  ");
    show_float(fval);
    printf("             (%.1f)\n", fval);
    printf("Double (cast from long) representation:");
    show_double(dval);
    printf(" (%.1f)\n", dval);
    printf("Address (of long) representation:      ");
    show_pointer(pval);
    printf(" (%p)\n", pval);
}
