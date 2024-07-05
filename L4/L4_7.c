#include <stdio.h>

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

void imprime_quadrante(tReta reta);
int get_quadrante(tPonto ponto);
int get_x(tPonto ponto);
int get_y(tPonto ponto);
tPonto get_pi(tReta reta);
tPonto get_pf(tReta reta);
tReta cria_reta(tPonto pi, tPonto pf);
tPonto cria_ponto(int x, int y);
tPonto le_ponto();
tReta le_reta();

int main(int argc, char const *argv[])
{
    int i = 0;
    scanf("%d", &i);

    for (i; i > 0; i--) {
        tReta reta = le_reta();
        imprime_quadrante(reta);
    }

    return 0;
}

void imprime_quadrante(tReta reta)
{
    tPonto pi = get_pi(reta);
    tPonto pf = get_pf(reta);
    int quadrantePi = get_quadrante(pi);
    int quadrantePf = get_quadrante(pf);

    if (quadrantePi == quadrantePf && quadrantePi != 0 && quadrantePf != 0)
        printf("MESMO\n");
    else
        printf("DIFERENTE\n");
}

int get_quadrante(tPonto ponto)
{
    int x = get_x(ponto);
    int y = get_y(ponto);

    if (x == 0 || y == 0)
        return 0;
    if (x >= 0 && y >= 0)
        return 1;
    if (x > 0 && y < 0)
        return 4;
    if (x < 0 && y < 0)
        return 3;
    return 2;
}

tPonto get_pi(tReta reta)
{
    return reta.pi;
}

tPonto get_pf(tReta reta)
{
    return reta.pf;
}

tReta cria_reta(tPonto pi, tPonto pf)
{
    tReta reta = {pi, pf};
    return reta;
}

tPonto cria_ponto(int x, int y)
{
    tPonto ponto = {x, y};
    return ponto;
}

tPonto le_ponto()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    return cria_ponto(x, y);
}

tReta le_reta()
{
    tPonto pi = le_ponto();
    tPonto pf = le_ponto();
    return cria_reta(pi, pf);
}

int get_x(tPonto ponto)
{
    return ponto.x;
}

int get_y(tPonto ponto)
{
    return ponto.y;
}