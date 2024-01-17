#include <stdio.h>
#define IB 0.03
#define ST 10.36
#define STT 0.025
#define SD 0.002
#define RC 0.004
int main()
{
    float sp, bp, ib, st, stt, sd, rc;
    printf("Enter the buying price:");
    scanf("%f", &bp);
    printf("Enter the selling price:");
    scanf("%f", &sp);
    ib = ((sp + bp) * IB) / 100;
    st = (ib * ST) / 100;
    stt = (sp * STT) / 100;
    sd = ((sp + bp + ib + st + stt) * SD) / 100;
    rc = (sd * RC) / 100;
    float profit = (sp - bp) - (st + stt + sd + rc + ib);
    printf("The total is:%f", profit);
    return 0;
}