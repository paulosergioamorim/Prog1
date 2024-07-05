#include <stdio.h>

/*
Faça um programa para exibir o índice da turma
com a maior e a menor quantidade de alunos aprovados. O programa deverá exibir
também, para cada turma, a lista dos nomes dos aprovados. O índice da turma é
dado pela sua ordem de leitura, por exemplo, a primeira turma é a turma 1, a
segunda é a turma 2, etc. Um aluno é considerado aprovado, quando sua média é
maior ou igual a 70. O cálculo da média final de um aluno considera todas as suas
notas, exceto a nota mais baixa. Se o aluno só tiver uma nota, então ela será a média
final do aluno. As notas vão de 0 a 100.
• Entrada: um número inteiro n representando a quantidade de turmas a serem analisadas
seguido (na linha seguinte) das informações sobre as turmas. Cada turma será descrita por
um número inteiro a representando o número de alunos da turma seguido (na linha
seguinte) dos alunos da turma (um por linha). As informações de cada aluno serão dadas
em uma linha contendo o “nome” (representado por 2 caracteres) e as notas daquele
aluno. As notas serão dadas entre colchetes e separadas por espaço. Ver formatação nos
exemplos abaixo.
• Saída: para cada turma, o programa deverá imprimir “TURMA:#1” (em que #1 representa o
índice da turma) seguido das primeiras letras dos “nomes” dos alunos aprovados daquela
turma (sendo um em cada linha), ou seja, dos alunos com nota final maior ou igual a 70. Ao
final o programa deverá imprimir uma linha "MAIOR:TURMA #2 MENOR:TURMA #3", em
que #2 e #3 são respectivamente os índices da primeira ocorrência da turma com maior, e
menor, quantidade de alunos aprovados. Ver formato da saída nos exemplos abaixo.*/

double LeNotasECalculaMediaAluno();
int ContaAlunosAprovadosTurma();

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    int melhorTurmaAprovados = 0;
    int melhorTurmaId = 0;
    int piorTurmaAprovados = __INT_MAX__;
    int piorTurmaId = 0;
    for (i = 1; i <= n; i++)
    {
        printf("TURMA:%d\n", i);
        int aprovados = ContaAlunosAprovadosTurma();
        if (aprovados > melhorTurmaAprovados)
        {
            melhorTurmaAprovados = aprovados;
            melhorTurmaId = i;
        }
        if (aprovados < piorTurmaAprovados)
        {
            piorTurmaAprovados = aprovados;
            piorTurmaId = i;
        }
    }

    printf("MAIOR:TURMA %d MENOR:TURMA %d\n", melhorTurmaId, piorTurmaId);

    return 0;
}

double LeNotasECalculaMediaAluno()
{
    int soma = 0;
    int qtdNotas = 0;
    int pior = 101;
    int nota = 0;

    scanf("%*[[]");

    for (qtdNotas; scanf("%d", &nota); qtdNotas++)
    {
        soma += nota;
        if (nota < pior)
            pior = nota;
    }

    scanf("%*[]]%*[\n]");

    if (qtdNotas == 1)
        return pior;

    soma -= pior;
    qtdNotas--;

    return (double)soma / qtdNotas;
}

int ContaAlunosAprovadosTurma()
{
    int aprovados = 0;
    int j = 0;
    scanf("%d%*[\n]", &j);
    for (j; j > 0; j--)
    {
        char c1 = 0;
        char c2 = 0;
        scanf("%c%c", &c1, &c2);
        int media = LeNotasECalculaMediaAluno();
        if (media >= 70)
        {
            printf("%c\n", c1);
            aprovados++;
        }
    }
    return aprovados;
}
