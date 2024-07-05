#include <stdio.h>

typedef struct
{
    int h;
    int m;
    int s;
} time;

time read_time();
int compare(time tA, time tB);
int sum(time t);

int main(int argc, char const *argv[])
{
    time tA = read_time();
    time tB = read_time();

    switch (compare(tA, tB))
    {
    case -1:
        printf("RESP:%d", sum(tB) / 10 % 10);
        break;
    case 0:
        printf("IGUAIS");
        break;
    case 1:
        printf("RESP:%d", sum(tA) / 10 % 10);
        break;
    }

    return 0;
}

time read_time()
{
    time time = {0, 0, 0};
    int h = 0;
    int m = 0;
    int s = 0;
    scanf("%d %d %d", &h, &m, &s);
    time.h = h;
    time.m = m;
    time.s = s;

    return time;
}

int compare(time tA, time tB)
{
    if (tA.h > tB.h)
        return 1;
    if (tA.h == tB.h)
    {
        if (tA.m > tB.m)
            return 1;
        if (tA.m == tB.m)
        {
            if (tA.s > tB.s)
                return 1;
            if (tA.s == tB.s)
                return 0;
            return -1;
        }
        return -1;
    }
    return -1;
}

int sum(time t)
{
    return t.h + t.m + t.s;
}
