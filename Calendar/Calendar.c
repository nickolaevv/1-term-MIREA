#include <stdio.h>
#include <stdlib.h>
int main()
{
  int  day, month, year;
  int a, b, c, d;
  printf ("Enter the day\n");
  scanf  ("%d",&day);
  printf  ("Enter the month\n");
  scanf  ("%d",&month);
  printf ("Enter the year\n");
  scanf  ("%d",&year);
  a =(14 - month) / 12;
  b = year - a;
  c = month + 12 * a - 2;
  d = 7000 + (day + b + b / 4 - b / 100 + b / 400 + (31 * c) / 12);
  d = d % 7;
  switch(d)
    {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 0:
            printf("Sunday\n");
            break;
    }


    return 0;
}
