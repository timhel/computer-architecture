#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
    int ival = atoi(argv[1]);
    long lval = atol(argv[1]);
    float fval = (float) ival;
    double dval = (double) lval;
    long *pval = &lval;

    printf("Input: %s\n", argv[1]);
    printf("Int representation:    ");
    show_int(ival);
    printf("             (%d)\n", ival);
    printf("Long representation:   ");
    show_long(lval);
    printf(" (%ld)\n", lval);
    printf("Float representation:  ");
    show_float(fval);
    printf("             (%.1f)\n", fval);
    printf("Double representation: ");
    show_double(dval);
    printf(" (%.1f)\n", dval);
    printf("Address representation:");
    show_pointer(pval);
    printf(" (%p)\n", pval);
}
