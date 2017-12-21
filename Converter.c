#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv)
{

    /*
    absolute zero C: = -273.15;
    absolute zero F: = -459.67;
    absolute zero K: = 0;
    */

    float c, f, k;
    double temp;
    char scale;

    if (argc == 1)
        {
            printf("syntax : \n\ttermo t\n or\n\ttermo t c\n where t - temperature, c - scale (C, F, K)");

        }

    else if (argc == 3)
        {
            temp = atof(argv[1]);
            scale = *argv[2];

            if (scale == 'C' || scale == 'c')

                {
                    if (temp < -273.15)
                        {
                            printf("The temperature is less than absolute zero.");
                            return 0;
                        }

                    f = temp * 9 / 5 + 32;
                    k = temp + 273.15;
                    printf("Convert %.2f C:\n%.2f F:\n%.2f K:",temp, f, k);
                }

            else if (scale == 'F' || scale =='f')
                {
                    if (temp < -459.67)
                        {
                            printf("The temperature is less than absolute zero.");
                            return 0;
                        }
                    c = (temp - 32) * 5 / 9;
                    k = c + 273.15;
                    printf( "Convert %.2f F:\n%.2f C:\n%.2f K:",temp, c, k);
                }

            else if (scale == 'K' || scale == 'k')
                {
                    if (temp < 0)
                        {
                            printf("The temperature is less than absolute zero.");
                            return 0;
                        }
                    c = temp - 273.15;
                    f = c * 9 / 5 + 32;
                    printf( "Convert %.2f K:\n%.2f C:\n%.2f F:", temp, c, f);
                }
            else
                printf("Incorrect scale");

        }

    else if (argc==2)
        {
            temp = atof(argv[1]);

            printf("\nConvert %.2f\n", temp);

            if (temp >= -273.15)
                {
                    f = temp * 9 / 5 + 32;
                    k = temp + 273.15;
                    printf("\n%.2f C:\n%.2f F:\n%.2f K:\n",temp, f, k);
                }
            else printf ("\nThe temperature on the scale C: is less than the absolute zero.\n");

            if (temp >= -459.67)
                {
                    c = (temp - 32) * 5 / 9;
                    k = c + 273.15;
                    printf("\n%.2f F:\n%.2f C:\n%.2f K:\n",temp, c, k);
                }
            else printf ("\nThe temperature on the scale F: is less than the absolute zero.\n");
            if (temp >= 0)
                {
                    c = temp - 273.15;
                    f = c * 9 / 5 + 32;
                    printf("\n%.2f K:\n%.2f C:\n%.2f F:\n",temp, c, f);
                }
            else printf ("\nThe temperature on the scale K: is less than the absolute zero.");
        }

    return 0;
}
