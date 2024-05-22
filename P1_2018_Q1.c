#include <stdio.h>

void print_point(int x, int y);

int main(int argc, char const *argv[])
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 < x2)
    {
        if (y1 < y2)
        {
            print_point(x1, y2);
            print_point(x1, y1);
            print_point(x2, y1);
            print_point(x2, y2);
        }
        else
        {
            print_point(x1, y1);
            print_point(x1, y2);
            print_point(x2, y2);
            print_point(x2, y1);
        }
    }
    else
    {
        if (y1 < y2)
        {
            print_point(x2, y2);
            print_point(x2, y1);
            print_point(x1, y1);
            print_point(x1, y2);
        }
        else
        {
            print_point(x2, y1);
            print_point(x2, y2);
            print_point(x1, y2);
            print_point(x1, y1);
        }
    }

    printf("\n");

    return 0;
}

void print_point(int x, int y)
{
    printf("(%d,%d)", x, y);
}
