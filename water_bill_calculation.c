//Experiment no_02
#include <stdio.h>

int main()
{
    int wu;
    float rate;
    printf("enter the use of water:");
    scanf("%d", &wu);
    if (wu <= 1000)
    {
        printf("The final cost is:155");
    }
    else
    {
        if (wu > 1000 && wu <= 2000)
        {
            rate = (wu - 1000) * 0.175 + 155;
            printf("The final cost is:%f", rate);
        }
        else
        {
            if (wu > 2000 && wu <= 3000)
            {
                rate = (wu - 2000) * 0.200 + 330;
                printf("The final cost is:%f", rate);
            }
            else
            {
                if (wu > 3000)
                {
                    printf("The final cost:700");
                }
            }
        }
    }
    return 0;
}