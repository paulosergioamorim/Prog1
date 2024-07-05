#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int idMelhorDelegacaoMasculino = 0;
    int somaMelhorDelegacaoMasculino = 0;
    int idMelhorDelegacaoFeminino = 0;
    int somaMelhorDelegacaoFeminino = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        int somaMasculino = 0;
        int somaFeminino = 0;
        int idMelhorAtletaMasculino = 10;
        int primeiraMelhorNotaAnteriorMasculino = 0;
        int segundaMelhorNotaAnteriorMasculino = 0;
        int terceiraMelhorNotaAnteriorMasculino = 0;
        int idMelhorAtletaFeminino = 10;
        int primeiraMelhorNotaAnteriorFeminino = 0;
        int segundaMelhorNotaAnteriorFeminino = 0;
        int terceiraMelhorNotaAnteriorFeminino = 0;
        int idPiorAtletaMasculino = 0;
        int primeiraPiorNotaAnteriorMasculino = 10;
        int segundaPiorNotaAnteriorMasculino = 10;
        int terceiraPiorNotaAnteriorMasculino = 10;
        int idPiorAtletaFeminino = 0;
        int primeiraPiorNotaAnteriorFeminino = 10;
        int segundaPiorNotaAnteriorFeminino = 10;
        int terceiraPiorNotaAnteriorFeminino = 10;

        while (1)
        {
            int id = 0;
            char sexo = '\0';
            int p1 = 0;
            int p2 = 0;
            int p3 = 0;

            scanf("%d ", &id);

            if (id == -1)
                break;

            scanf("%c %d %d %d%*c", &sexo, &p1, &p2, &p3);

            int primeiraNota = 0;
            int segundaNota = 0;
            int terceiraNota = 10;

            if (p1 > primeiraNota)
                primeiraNota = p1;
            if (p2 > primeiraNota)
                primeiraNota = p2;
            if (p3 > primeiraNota)
                primeiraNota = p3;
            if (p1 < terceiraNota)
                terceiraNota = p1;
            if (p2 < terceiraNota)
                terceiraNota = p2;
            if (p3 < terceiraNota)
                terceiraNota = p3;
            if ((primeiraNota == p1 && terceiraNota == p3) || (terceiraNota == p1 && primeiraNota == p3))
                segundaNota = p2;
            if ((primeiraNota == p1 && terceiraNota == p2) || (terceiraNota == p1 && primeiraNota == p2))
                segundaNota = p3;
            if ((primeiraNota == p2 && terceiraNota == p3) || (terceiraNota == p2 && primeiraNota == p3))
                segundaNota = p1;

            if (sexo == 'M')
                somaMasculino += primeiraNota;
            else
                somaFeminino += primeiraNota;

            if (sexo == 'M')
            {
                if (primeiraNota > primeiraMelhorNotaAnteriorMasculino)
                {
                    idMelhorAtletaMasculino = id;
                    primeiraMelhorNotaAnteriorMasculino = primeiraNota;
                    segundaMelhorNotaAnteriorMasculino = segundaNota;
                    terceiraMelhorNotaAnteriorMasculino = terceiraNota;
                }
                else if (primeiraNota == primeiraMelhorNotaAnteriorMasculino)
                {
                    if (segundaNota > segundaMelhorNotaAnteriorMasculino)
                    {
                        idMelhorAtletaMasculino = id;
                        segundaMelhorNotaAnteriorMasculino = segundaNota;
                        terceiraMelhorNotaAnteriorMasculino = terceiraNota;
                    }
                    else if (segundaNota == segundaMelhorNotaAnteriorMasculino)
                    {
                        if (terceiraNota > terceiraMelhorNotaAnteriorMasculino)
                        {
                            idMelhorAtletaMasculino = id;
                            terceiraMelhorNotaAnteriorMasculino = terceiraNota;
                        }
                        else if (terceiraNota == terceiraMelhorNotaAnteriorMasculino && id < idMelhorAtletaMasculino)
                            idMelhorAtletaMasculino = id;
                    }
                }
                if (primeiraNota < primeiraPiorNotaAnteriorMasculino)
                {
                    idPiorAtletaMasculino = id;
                    primeiraPiorNotaAnteriorMasculino = primeiraNota;
                    segundaPiorNotaAnteriorMasculino = segundaNota;
                    terceiraPiorNotaAnteriorMasculino = terceiraNota;
                }
                else if (primeiraNota == primeiraPiorNotaAnteriorMasculino)
                {
                    if (segundaNota < segundaPiorNotaAnteriorMasculino)
                    {
                        idPiorAtletaMasculino = id;
                        segundaPiorNotaAnteriorMasculino = segundaNota;
                        terceiraPiorNotaAnteriorMasculino = terceiraNota;
                    }
                    else if (segundaNota == segundaPiorNotaAnteriorMasculino)
                    {
                        if (terceiraNota < terceiraPiorNotaAnteriorMasculino)
                        {
                            idPiorAtletaMasculino = id;
                            terceiraPiorNotaAnteriorMasculino = terceiraNota;
                        }
                        else if (terceiraNota == terceiraPiorNotaAnteriorMasculino && id > idPiorAtletaMasculino)
                            idPiorAtletaMasculino = id;
                    }
                }
            }
            else
            {
                if (primeiraNota > primeiraMelhorNotaAnteriorFeminino)
                {
                    idMelhorAtletaFeminino = id;
                    primeiraMelhorNotaAnteriorFeminino = primeiraNota;
                    segundaMelhorNotaAnteriorFeminino = segundaNota;
                    terceiraMelhorNotaAnteriorFeminino = terceiraNota;
                }
                else if (primeiraNota == primeiraMelhorNotaAnteriorFeminino)
                {
                    if (segundaNota > segundaMelhorNotaAnteriorFeminino)
                    {
                        idMelhorAtletaFeminino = id;
                        segundaMelhorNotaAnteriorFeminino = segundaNota;
                        terceiraMelhorNotaAnteriorFeminino = terceiraNota;
                    }
                    else if (segundaNota == segundaMelhorNotaAnteriorFeminino)
                    {
                        if (terceiraNota > terceiraMelhorNotaAnteriorFeminino)
                        {
                            idMelhorAtletaFeminino = id;
                            terceiraMelhorNotaAnteriorFeminino = terceiraNota;
                        }
                        else if (terceiraNota == terceiraMelhorNotaAnteriorFeminino && id < idMelhorAtletaFeminino)
                            idMelhorAtletaFeminino = id;
                    }
                }
                if (primeiraNota < primeiraPiorNotaAnteriorFeminino)
                {
                    idPiorAtletaFeminino = id;
                    primeiraPiorNotaAnteriorFeminino = primeiraNota;
                    segundaPiorNotaAnteriorFeminino = segundaNota;
                    terceiraPiorNotaAnteriorFeminino = terceiraNota;
                }
                else if (primeiraNota == primeiraPiorNotaAnteriorFeminino)
                {
                    if (segundaNota < segundaPiorNotaAnteriorFeminino)
                    {
                        idPiorAtletaFeminino = id;
                        segundaPiorNotaAnteriorFeminino = segundaNota;
                        terceiraPiorNotaAnteriorFeminino = terceiraNota;
                    }
                    else if (segundaNota == segundaPiorNotaAnteriorFeminino)
                    {
                        if (terceiraNota < terceiraPiorNotaAnteriorFeminino)
                        {
                            idPiorAtletaFeminino = id;
                            terceiraPiorNotaAnteriorFeminino = terceiraNota;
                        }
                        else if (terceiraNota == terceiraPiorNotaAnteriorFeminino && id > idPiorAtletaFeminino)
                            idPiorAtletaFeminino = id;
                    }
                }
            }
        }

        printf("MELHORES ATLETAS DA DELEGACAO %d\nMASCULINO: %d FEMININO: %d\nPIORES ATLETAS DA DELEGACAO %d\nMASCULINO: %d FEMININO: %d\n\n",
               i,
               idMelhorAtletaMasculino,
               idMelhorAtletaFeminino,
               i,
               idPiorAtletaMasculino,
               idPiorAtletaFeminino);

        if (somaMasculino > somaMelhorDelegacaoMasculino)
        {
            idMelhorDelegacaoMasculino = i;
            somaMelhorDelegacaoMasculino = somaMasculino;
        }
        else if (somaMasculino == somaMelhorDelegacaoMasculino && i < idMelhorDelegacaoMasculino)
        {
            idMelhorDelegacaoMasculino = i;
            somaMelhorDelegacaoMasculino = somaMasculino;
        }
        if (somaFeminino > somaMelhorDelegacaoFeminino)
        {
            idMelhorDelegacaoFeminino = i;
            somaMelhorDelegacaoFeminino = somaFeminino;
        }
        else if (somaFeminino == somaMelhorDelegacaoFeminino && i < idMelhorDelegacaoFeminino)
        {
            idMelhorDelegacaoFeminino = i;
            somaMelhorDelegacaoFeminino = somaFeminino;
        }
    }

    printf("DELEGACAO CAMPEA:\nMASCULINO: %d FEMININO: %d", idMelhorDelegacaoMasculino, idMelhorDelegacaoFeminino);

    return 0;
}
