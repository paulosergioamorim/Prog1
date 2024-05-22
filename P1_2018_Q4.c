#include <stdio.h>

void print_date(int days, int hours, int minutes);
void print_days(int days);
void print_hours(int hours);
void print_minutes(int minutes);

int main(int argc, char const *argv[])
{
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int add = 0;
    scanf("%d:%d %d", &hours, &minutes, &add);
    minutes += add;
    hours += minutes / 60;
    minutes %= 60;
    days += hours / 24;
    hours %= 24;
    print_date(days, hours, minutes);
    return 0;
}

void print_date(int days, int hours, int minutes)
{
    if (days > 0)
        print_days(days);
    if (hours > 0)
        print_hours(hours);
    if (minutes > 0)
        print_minutes(minutes);
    printf("\n");
}

void print_days(int days)
{
    if (days == 1)
        printf("(1 dia)");
    else
        printf("(%d dias)", days);
}

void print_hours(int hours)
{
    if (hours == 1)
        printf("(1 hora)");
    else
        printf("(%d horas)", hours);
}

void print_minutes(int minutes)
{
    if (minutes == 1)
        printf("(1 minuto)");
    else
        printf("(%d minutos)", minutes);
}
