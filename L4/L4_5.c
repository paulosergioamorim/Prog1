#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} tPonto;

tPonto create_point(float x, float y);
tPonto read_point();
float get_distance(tPonto pA, tPonto pB);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);

    tPonto previousPoint = create_point(0, 0);
    for (i = 0; i < n; i++) {
        tPonto currentPoint = read_point();
        if (i == 0)
            printf("-\n");
        else
            printf("%.2f\n", get_distance(previousPoint, currentPoint));
        previousPoint = currentPoint;
    }
}

tPonto create_point(float x, float y)
{
    tPonto point = {x, y};
    return point;
}

tPonto read_point()
{
    float x = 0;
    float y = 0;
    scanf("%f %f", &x, &y);
    return create_point(x, y);
}

float get_distance(tPonto pA, tPonto pB)
{
    return sqrt(pow(pA.x - pB.x, 2) + pow(pA.y - pB.y, 2));
}
