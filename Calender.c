#include<stdio.h>
#include<stdlib.h>
int first_week_day(int year);
int main()
{
    system("color 0F");
    int year,mon,i,daymonth,weekday=0,startday;
    printf("Enter the year :");
    scanf("%d",&year);
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0 && year%100!=0) || (year%400==0)){
        monthDay[1]=29;
    }
    startday= first_week_day(year);
    for(mon=0;mon<12;mon++){
        printf("\n-------------------------------------%s------------------------------------------\n",months[mon]);
        printf("\n Sun  Mon  Tue  Wed  Thr  Fri  Sat\n");
        for(weekday=0;weekday<startday;weekday++){
            printf("     ");
        }
        daymonth = monthDay[mon];
        for(i=1;i<=daymonth;i++){
            printf("%5d",i);
            if(++weekday >6){
                printf("\n");
                weekday=0;
            }
        startday=weekday;
       }
   }
    return 0;
}
int first_week_day(int year){
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}
