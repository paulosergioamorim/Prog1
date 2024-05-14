#include <stdio.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
} tPonto;

typedef struct
{
    tPonto pi;
    tPonto pf;
} tReta;

tPonto create_point(int x, int y);
tReta create_line(tPonto pi, tPonto pf);
tPonto read_point();
tReta read_line();
void print_line(tReta r);
tPonto get_start_point(tReta r);
tPonto get_end_point(tReta r);
tReta move(tReta r, tPonto pi, tPonto pf);
float length_of_line(tReta r);
int get_x(tPonto p);
int get_y(tPonto p);
float get_distance(tPonto pA, tPonto pB);

int main(int argc, char const *argv[])
{
    int i = 0;
    scanf("%d", &i);

    for (i; i > 0; i--)
    {
        tPonto point = read_point();
        tReta line = read_line();
        tPonto pi = get_start_point(line);
        tPonto pf = get_end_point(line);

        float distancePi = get_distance(pi, point);
        float distancePf = get_distance(pf, point);

        if (distancePi == distancePf)
            printf("EQUIDISTANTE\n");
        else if (distancePi < distancePf)
            printf("INICIO\n");
        else
            printf("FIM\n");
    }

    return 0;
}

tPonto create_point(int x, int y)
{
    tPonto point = {x, y};
    return point;
}

tReta create_line(tPonto pi, tPonto pf)
{
    tReta line = {pi, pf};
    return line;
}

tPonto read_point()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    return create_point(x, y);
}

tReta read_line()
{
    tPonto pi = read_point();
    tPonto pf = read_point();
    return create_line(pi, pf);
}

void print_line(tReta r)
{
    tPonto pi = get_start_point(r);
    tPonto pf = get_end_point(r);
    printf("[(%d,%d):(%d,%d)]", pi.x, pi.y, pf.x, pf.y);
}

tPonto get_start_point(tReta r)
{
    return r.pi;
}

tPonto get_end_point(tReta r)
{
    return r.pf;
}

tReta move(tReta r, tPonto pi, tPonto pf)
{
    r.pi = pi;
    r.pf = pf;
    return r;
}

float length_of_line(tReta r)
{
    tPonto pi = get_start_point(r);
    tPonto pf = get_end_point(r);
    return get_distance(pi, pf);
}

float get_distance(tPonto pA, tPonto pB)
{
    int xA = get_x(pA);
    int xB = get_x(pB);
    int yA = get_y(pA);
    int yB = get_y(pB);
    return sqrt(pow(xA - xB, 2) + pow(yA - yB, 2));
}

int get_x(tPonto p)
{
    return p.x;
}

int get_y(tPonto p)
{
    return p.y;
}
