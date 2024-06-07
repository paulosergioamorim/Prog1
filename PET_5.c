#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
    char nome;
    char tipo;
    int nivel;
    int vidaAtual;
    int vidaMaxima;
    int ataque;
    int defesa;
    int velocidade;
} Pokemon;

typedef struct
{
    Pokemon diogo;
    Pokemon adversario;
    int numDeAdversarios;
    int numDeBatalha;
    /*
    acopla o pokemon de diogo, do adversario e informacoes que podem ser uteis, como qtdDeAdversarios
    */
} Ginasio;

float calculaVantagem(Pokemon atacante, Pokemon defensor);
/*
Retorna o valor de vantagem que é 0.5(desvantagem), 1.5(vantagem) ou 1.0(duelo equilibrado)
*/

int calculaDano(Pokemon atacante, Pokemon defensor);
/*
Dentro da funcao, recebe o valor da vantagem e utiliza a formula dada para calcular a quantidade de dano na vida do oponente
obs: utilizar floor para arrendondar com mais precisao
*/
int estaVivo(Pokemon p);
/*
Verifica se o pokemon esta vivo
retorna 1 caso verdadeiro
retorna 0 caso falso
*/

int menorNivel(Pokemon atacante, Pokemon defensor);
/*
Verifica se o atacante tem menor nivel que o defensor
retorna 1 caso verdadeiro
retorna 0 caso falso
*/

Pokemon subirDeNivel(Pokemon p);
/*
Sobe o nivel do pokemon e atualiza seus status
retorna p atualizado
obs: utilizar floor para arrendondar com mais precisao
*/
Ginasio batalhar(Pokemon atacante, Pokemon defensor, Ginasio ginasio);
/*
funcao que recebe o pokemon atacante, defensor e o ginasio.
Aqui que a batalha eh efetuada
a batalha continua ateh que alguem morra
no final, atribua defensor e atacante ao ginasio
retorna ginasio atualizado
obs1: o pokemon de maior velocidade ataca primeiro
*/
Pokemon lePokemon();
/*
Declara pokemon
Efetua a leitura do pokemon
retorna pokemon
*/
void imprimePokemon(Pokemon p);
/*
Imprime todas as informacoes do pokemon p
*/
Ginasio inicializaGinasio();
/*
Declara ginasio
Faz a leitura do pokemon de diogo, numDeAdversarios e inicializa as outras variaveis
retorna ginasio
*/
Ginasio RealizaBatalha(Ginasio ginasio);
/*
Recebe o ginasio inicializado e efetua as batalhas ate que diogo venca ou perca
retorna ginasio atualizado
*/
void FinalizaBatalha(Ginasio ginasio);
/*
Imprime todas as informacoes da batalhas, especificadas no enunciado e casos de teste
*/
int main()
{
    Ginasio ginasio = inicializaGinasio();
    ginasio = RealizaBatalha(ginasio);
    FinalizaBatalha(ginasio);
    return 0;
}

float calculaVantagem(Pokemon atacante, Pokemon defensor)
{
    switch (atacante.tipo)
    {
    case 'W':
        switch (defensor.tipo)
        {
        case 'F':
        case 'R':
        case 'G':
            return 1.5;
        case 'E':
        case 'P':
            return 0.5;
        default:
            return 1;
        }
    case 'F':
        switch (defensor.tipo)
        {
        case 'P':
            return 1.5;
        case 'W':
        case 'G':
        case 'R':
            return 0.5;
        default:
            return 1;
        }
    case 'P':
        switch (defensor.tipo)
        {
        case 'W':
        case 'G':
        case 'R':
            return 1.5;
        case 'F':
            return 0.5;
        default:
            return 1;
        }
    case 'G':
        switch (defensor.tipo)
        {
        case 'F':
        case 'E':
        case 'R':
            return 1.5;
        case 'W':
        case 'P':
            return 0.5;
        default:
            return 1;
        }
    case 'E':
        switch (defensor.tipo)
        {
        case 'W':
            return 1.5;
        case 'G':
            return 0.5;
        default:
            return 1;
        }
    case 'R':
        switch (defensor.tipo)
        {
        case 'F':
            return 1.5;
        case 'W':
        case 'P':
        case 'G':
            return 0.5;
        default:
            return 1;
        }
    }
}

int calculaDano(Pokemon atacante, Pokemon defensor)
{
    float adv = calculaVantagem(atacante, defensor);
    int nivel = atacante.nivel;
    int ataque = atacante.ataque;
    int defesa = defensor.defesa;
    return floor((((0.4 * nivel + 2) * floor((float)ataque / defesa)) + 2) * adv);
}

int estaVivo(Pokemon p)
{
    return p.vidaAtual > 0;
}

int menorNivel(Pokemon atacante, Pokemon defensor)
{
    return atacante.nivel < defensor.nivel;
}

Pokemon subirDeNivel(Pokemon p)
{
    p.nivel++;
    p.ataque = floor(p.ataque * 1.1);
    p.defesa = floor(p.defesa * 1.1);
    p.velocidade = floor(p.velocidade * 1.1);
    p.vidaMaxima = floor(p.vidaMaxima * 1.1);
    p.vidaAtual = p.vidaMaxima;
    return p;
}

Ginasio batalhar(Pokemon atacante, Pokemon defensor, Ginasio ginasio)
{
    int danoAtacante = calculaDano(atacante, defensor);
    int danoDefensor = calculaDano(defensor, atacante);
    while (1)
    {
        defensor.vidaAtual -= danoAtacante;
        if (!estaVivo(defensor))
            break;
        atacante.vidaAtual -= danoDefensor;
        if (!estaVivo(atacante))
            break;
    }
    if (atacante.nome == ginasio.diogo.nome)
    {
        ginasio.diogo = atacante;
        ginasio.adversario = defensor;
    }
    else
    {
        ginasio.diogo = defensor;
        ginasio.adversario = atacante;
    }
    if (estaVivo(ginasio.diogo) && menorNivel(ginasio.diogo, ginasio.adversario))
        ginasio.diogo = subirDeNivel(ginasio.diogo);

    return ginasio;
}

Pokemon lePokemon()
{
    char nome = 0;
    char tipo = 0;
    int nivel = 0;
    int vidaMaxima = 0;
    int ataque = 0;
    int defesa = 0;
    int velocidade = 0;
    scanf("%c\n%c\n%d\n%d\n%d\n%d\n%d\n", &nome, &tipo, &nivel, &vidaMaxima, &ataque, &defesa, &velocidade);
    Pokemon pokemon = {nome, tipo, nivel, vidaMaxima, vidaMaxima, ataque, defesa, velocidade};
    return pokemon;
}

void imprimePokemon(Pokemon p)
{
    printf("Nome: %c\nTipo: %c\nNivel: %d\nVidaMax: %d \nVidaAtual: %d\nAtaque: %d\nDefesa: %d\nVelocidade: %d", p.nome, p.tipo, p.nivel, p.vidaMaxima, p.vidaAtual, p.ataque, p.defesa, p.velocidade);
}

Ginasio inicializaGinasio()
{
    int numDeAdversarios = 0;
    scanf("%d\n", &numDeAdversarios);
    Pokemon diogo = lePokemon();
    Ginasio ginasio;
    ginasio.diogo = diogo;
    ginasio.numDeAdversarios = numDeAdversarios;
    ginasio.numDeBatalha = 0;
    return ginasio;
}

Ginasio RealizaBatalha(Ginasio ginasio)
{
    while (ginasio.numDeAdversarios >= ginasio.numDeBatalha && estaVivo(ginasio.diogo))
    {
        ginasio.adversario = lePokemon();
        ginasio.numDeBatalha++;
        if (ginasio.diogo.velocidade > ginasio.adversario.velocidade)
            ginasio = batalhar(ginasio.diogo, ginasio.adversario, ginasio);
        else
            ginasio = batalhar(ginasio.adversario, ginasio.diogo, ginasio);
    }
    return ginasio;
}

void FinalizaBatalha(Ginasio ginasio)
{
    if (estaVivo(ginasio.diogo))
    {
        printf("Diogo venceu todas as %d batalhas!\nPokemon de Diogo:\n", ginasio.numDeAdversarios);
        imprimePokemon(ginasio.diogo);
        printf("\n");
    }
    else
    {
        printf("Diogo perdeu na %d batalha!\nUltimo Pokemon adversario:\n", ginasio.numDeBatalha);
        imprimePokemon(ginasio.adversario);
        printf("\n");
    }
}
