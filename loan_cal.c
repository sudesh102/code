#include <stdio.h>
#include <math.h>
int main()
{
    float loan_amt, intrest_rate, period, monthly_i_rate, emi, month_intrest, pay_amt, intrest = 0;
    printf("Enter the principle loan amount:");
    scanf("%f", &loan_amt);
    printf("Enter the interest rate per year:");
    scanf("%f", &intrest_rate);
    printf("Enter the repayment period:");
    scanf("%f", &period);
    int temp=loan_amt;
    monthly_i_rate = (intrest_rate) / 1200;
    emi = (loan_amt * (intrest_rate / 100) / 12) / (1 - pow(1 + (intrest_rate / 100) / 12, -period * 12));
    //emi = (loan_amt * monthly_i_rate * pow(1 + monthly_i_rate, period)) / pow(1 + monthly_i_rate, period)- 1;
    for (int i = 1; loan_amt >1; i++)
    {
        month_intrest = (loan_amt *intrest_rate)/1200 ;
        pay_amt = emi - month_intrest;
        printf(" Month=%d ", i);
        printf(" Interest=%f ", month_intrest);
        printf(" EMI=%f ", emi);
        printf(" Payable amount with interest:%f ", pay_amt);
        printf(" Closing balance=%f", loan_amt - pay_amt);
        printf("\n");
        intrest = intrest + month_intrest;
        loan_amt = loan_amt - pay_amt;
    }
    printf("Total intrest:%f",intrest);
    printf("\nFinal payable amount:%f",temp+intrest);
    return 0;
}