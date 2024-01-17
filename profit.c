// Experiment no_01

#include <stdio.h>

int main()
{
    int no_share;
    float bp, sp, net_buying_price, net_selling_price, turn_over, buying_brokarage, selling_brokarage, total_brokarage, service_tax, security_tran_tax, stamp_duty, regulatory_charge, profit;
    printf("\nEnter total number of share:");
    scanf("%d", &no_share);
    printf("\nEnter the buying price:");
    scanf("%f", &bp);
    printf("\nEnter the selling price:");
    scanf("%f", &sp);
    net_buying_price = no_share * bp;
    net_selling_price = no_share * sp;
    turn_over = net_buying_price + net_selling_price;
    buying_brokarage = (net_buying_price * 0.03) / 100;
    selling_brokarage = (net_selling_price * 0.03) / 100;
    total_brokarage = buying_brokarage + selling_brokarage;
    service_tax = (total_brokarage * 10.36) / 100;
    security_tran_tax = (selling_brokarage * 0.025) / 100;
    stamp_duty = (turn_over * 0.002) / 100;
    regulatory_charge = (turn_over * 0.004) / 100;
    profit = (sp + bp) - (total_brokarage + service_tax + security_tran_tax + stamp_duty + regulatory_charge);
    printf("\nThe total profit:%f", profit);
    return 0;
}