#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIR_MAX_LENGTH 1000
#define MAP_MAX_LINES 40
#define MAP_MAX_COLUMNS 100
#define ENEMIES_MAX_COUNT 100
#define FILE_MAP "mapa.txt"
#define FILE_ENEMY "inimigo.txt"
#define FILE_INPUT "entrada.txt"
#define FILE_INITIALIZATION "./saida/inicializacao.txt"
#define FILE_RESUME "./saida/resumo.txt"
#define FILE_RANKING "./saida/ranking.txt"
#define FILE_STATISTICS "./saida/estatisticas.txt"
#define FILE_HEATMAP "./saida/heatmap.txt"
#define DIRECTION_RIGHT 1
#define DIRECTION_LEFT -1
#define NONE -1
#define BORDER_LEFT 0
#define BORDER_RIGHT 1
#define STATISTICS_PLAYER_MOVE 0
#define STATISTICS_EFFECTIVE_SHOT 1
#define STATISTICS_NON_EFFECTIVE_SHOT 2
#define STATISTICS_ENEMIES_MOVE_DOWN 3

typedef struct Player
{
    int i;
    int j;
} Player;

typedef struct Enemy
{
    int id;
    int row;
    int alive;
    int i;
    int j;
} Enemy;

typedef struct Shot
{
    int i;
    int j;
    int active;
} Shot;

typedef struct EnemyDraw
{
    int animate;
    int currentAnimation;
    char values[3][3][3];
} EnemyDraw;

typedef struct Map
{
    int l;
    int c;
    char values[MAP_MAX_LINES + 2][MAP_MAX_COLUMNS + 2];
} Map;

typedef struct Ranking
{
    int id;
    int row;
    int line;
    int iteration;
} Ranking;

typedef struct Statistics
{
    int playerMoves;
    int effectiveShots;
    int nonEffectiveShots;
    int enemiesMovesDown;
} Statistics;

typedef struct Heatmap
{
    int l;
    int c;
    int values[MAP_MAX_LINES][MAP_MAX_COLUMNS];
} Heatmap;

typedef struct Game
{
    Map map;
    Player player;
    Shot shot;
    Enemy enemies[ENEMIES_MAX_COUNT];
    Ranking rankings[ENEMIES_MAX_COUNT];
    EnemyDraw enemyDraw;
    Heatmap heatmap;
    Statistics statistics;
    int enemiesCount;
    int enemiesDirection;
    int rankingsCount;
    int iteration;
    int points;
} Game;

typedef struct MovePlayerResult
{
    Player player;
    Statistics statistics;
    int touchedBorder;
} MovePlayerResult;

typedef struct
{
    int iteration;
    int id;
    int row;
    int touchedBorder;
} EnemyCollision;

typedef struct MoveEnemiesResult
{
    int enemiesDirection;
    int enemyCollisionsCount;
    EnemyCollision enemyCollisions[ENEMIES_MAX_COUNT];
    Statistics statistics;
} MoveEnemiesResult;

typedef struct ShotResult
{
    Shot shot;
    Statistics statistics;
} ShotResult;

FILE *createFile(char dir[], char fileName[], char modes[]);
void createResumeFile(char dir[]);

Game createGame(char dir[]);
Game playGame(char dir[], Game game);
Game updateGameState(Game game);
int changeEnemiesDirection(int enemiesDirection);
void printGameState(Map map, int points, int iteration);
int isValidAction(char action);

MovePlayerResult movePlayer(Map map, Player player, char action, Statistics statistics);
Player moveToLeft(Player player);
Player moveToRigth(Player player);
Player createPlayer(char dir[]);
int calculatePlayerLimit(Player player);

int createEnemies(char dir[], Enemy enemies[]);
MoveEnemiesResult moveEnemies(Map map, int enemiesCount, Enemy enemies[], int enemiesDirection, int iteration, Statistics statistics);
int moveDownEnemies(Map map, int enemiesCount, Enemy enemies[], int iteration, int enemiesDirection, int enemyCollisionsCount, EnemyCollision enemyCollisions[]);
int isAlive(Enemy enemy);
int someEnemyAlive(int enemiesCount, Enemy enemies[]);
int someEnemyCrossPlayerLimit(int enemiesCount, Enemy enemies[], Player player);
int someEnemyHitted(int enemiesCount, Enemy enemies[], Shot shot);
int calculatePoints(Map map, Enemy enemy);
void killEnemy(Enemy enemies[], int id);
int isEnemyCollidingWithLeftBorder(Enemy enemy, int enemiesDirection);
int isEnemyCollidingWithRightBorder(Map map, Enemy enemy, int enemiesDirection);

Map createMap(char dir[]);
Map cleanMap(Map map);
Map drawMatrix(Map map, int i, int j, int width, int height, char values[width][height]);
Map drawPlayer(Map map, Player player);
Map drawPlayerLimit(Map map, Player player);
Map drawEnemies(Map map, int enemiesCount, Enemy enemies[], EnemyDraw enemyDraw);
Map drawShot(Map map, Shot shot);
int isLeftBorder(int j);
int isRightBorder(Map map, int j);
int isHorizontalBorder(Map map, int i);
int isVerticalBorder(Map map, int j);
int isBorder(Map map, int i, int j);
int isCorner(Map map, int i, int j);
int isTouchingLeftBorder(int j);
int isTouchingRightBorder(Map map, int j);
void printMap(Map map);

ShotResult moveShot(Shot shot, Statistics statistics);
ShotResult shootShot(Shot shot, Player player, Statistics statistics);
Shot disableShot(Shot shot);
int isActive(Shot shot);

EnemyDraw createEnemyDraw(char dir[]);
EnemyDraw advanceAnimation(EnemyDraw enemyDraw);

int addEnemyRanking(int rankingsCount, Ranking rankings[], Map map, Enemy enemy, Shot shot, int iteration);
void sortRankings(int rankingsCount, Ranking rankings[]);

Statistics createStatistics();
Statistics addStatistic(Statistics statistics, int event);

Heatmap createHeatmap(Map map);
Heatmap markHeatmap(Heatmap heatmap, int i, int j, int amountI, int amountJ);
Heatmap markPlayer(Heatmap heatmap, Player player);
Heatmap markShot(Heatmap heatmap, Shot shot);

void saveInitialization(char dir[], Map map, Player player);
void savePlayerCollisionResume(char dir[], int iteration, Player player, int event);
void saveEnemyHittedResume(char dir[], int iteration, Enemy enemy, Shot shot);
void saveEnemyCollisionResume(char dir[], EnemyCollision collision);
void saveRankings(char dir[], int rankingsCount, Ranking rankings[]);
void saveStatistics(char dir[], Statistics statistics);
void saveHeatmap(char dir[], Heatmap heatmap);

int main(int argc, char const *argv[])
{
    char dir[DIR_MAX_LENGTH];
    if (argc < 2)
    {
        printf("ERRO: Informe o diretorio com os arquivos de configuracao.");
        return 1;
    }
    strcpy(dir, argv[1]);
    createResumeFile(dir);
    Game game = createGame(dir);
    saveInitialization(dir, game.map, game.player);
    game = playGame(dir, game);
    sortRankings(game.rankingsCount, game.rankings);
    saveRankings(dir, game.rankingsCount, game.rankings);
    saveStatistics(dir, game.statistics);
    saveHeatmap(dir, game.heatmap);
    return 0;
}

FILE *createFile(char dir[], char fileName[], char modes[])
{
    FILE *pFile;
    char filePath[DIR_MAX_LENGTH + strlen(fileName) + 1];
    sprintf(filePath, "%s/%s", dir, fileName);
    pFile = fopen(filePath, modes);
    if (!pFile)
    {
        printf("ERRO! Não foi possivel ler o arquivo %s", filePath);
        exit(1);
    }
    return pFile;
}

Map createMap(char dir[])
{
    Map map;
    FILE *pFile = createFile(dir, FILE_MAP, "r");
    fscanf(pFile, "%d %d", &map.c, &map.l);
    map.l += 2;
    map.c += 2;
    fclose(pFile);
    return map;
}

Map cleanMap(Map map)
{
    for (int i = 0; i < map.l; i++)
        for (int j = 0; j < map.c; j++)
        {
            if (isCorner(map, i, j))
                map.values[i][j] = '+';
            else if (isHorizontalBorder(map, i))
                map.values[i][j] = '-';
            else if (isVerticalBorder(map, j))
                map.values[i][j] = '|';
            else
                map.values[i][j] = ' ';
        }
    return map;
}

Player createPlayer(char dir[])
{
    Player player;
    FILE *pFile = createFile(dir, FILE_MAP, "r");
    fscanf(pFile, "%*[^\n]%*c");
    fscanf(pFile, "(%d %d)", &player.j, &player.i);
    fclose(pFile);
    return player;
}

int createEnemies(char dir[], Enemy enemies[])
{
    FILE *pFile = createFile(dir, FILE_MAP, "r");
    fscanf(pFile, "%*[^\n]%*c%*[^\n]%*c");
    int enemiesCount = 0;
    char c = 0;
    Enemy enemy;
    enemy.id = 1;
    enemy.row = 1;
    enemy.alive = 1;
    while (!feof(pFile))
    {
        /*
        Lê o primeiro caracter. Se for '(', significa que a primeira fileira existe.
        Caso o contrário ('\n'), pula uma fileira. Caso a fileira exista (na primeira
        leitura), lê no formato '%d %d)', pois o primeiro '(' já foi consumido. Caso o
        contrário, lê no formato '(%d %d)'
         */
        fscanf(pFile, "%c", &c);
        if (c == '\n')
        {
            enemy.row++;
            enemy.id = 1;
        }
        if (fscanf(pFile, (enemiesCount == 0 && c == '(') ? "%d %d)" : "(%d %d)", &enemy.j, &enemy.i) == 2)
        {
            enemies[enemiesCount] = enemy;
            enemiesCount++;
            enemy.id++;
        }
    }
    fclose(pFile);
    return enemiesCount;
}

EnemyDraw createEnemyDraw(char dir[])
{
    EnemyDraw enemyDraw;
    enemyDraw.currentAnimation = 0;
    FILE *pFile = createFile(dir, FILE_ENEMY, "r");
    fscanf(pFile, "%d%*c", &enemyDraw.animate);
    for (int k = 0; k < 3; k++)
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                fscanf(pFile, "%c", &enemyDraw.values[k][i][j]);
                if (j == 2)
                    fscanf(pFile, "%*c");
            }
    fclose(pFile);
    return enemyDraw;
}

Game createGame(char dir[])
{
    Game game;
    game.map = createMap(dir);
    game.player = createPlayer(dir);
    game.enemyDraw = createEnemyDraw(dir);
    game.enemiesCount = createEnemies(dir, game.enemies);
    game.heatmap = createHeatmap(game.map);
    game.statistics = createStatistics();
    game.rankingsCount = 0;
    game.points = 0;
    game.enemiesDirection = DIRECTION_RIGHT;
    game = updateGameState(game);
    return game;
}

int isAlive(Enemy enemy)
{
    return enemy.alive;
}

int someEnemyAlive(int enemiesCount, Enemy enemies[])
{
    for (int i = 0; i < enemiesCount; i++)
        if (isAlive(enemies[i]))
            return 1;
    return 0;
}

int someEnemyCrossPlayerLimit(int enemiesCount, Enemy enemies[], Player player)
{
    for (int i = 0; i < enemiesCount; i++)
    {
        Enemy enemy = enemies[i];
        if (!isAlive(enemy))
            continue;
        if (enemy.i == calculatePlayerLimit(player))
            return 1;
    }
    return 0;
}

int someEnemyHitted(int enemiesCount, Enemy enemies[], Shot shot)
{
    if (!isActive(shot))
        return NONE;
    for (int id = 0; id < enemiesCount; id++)
    {
        Enemy enemy = enemies[id];
        if (!isAlive(enemy))
            continue;
        for (int i = enemy.i - 1; i <= enemy.i + 1; i++)
            for (int j = enemy.j - 1; j <= enemy.j + 1; j++)
                if (i == shot.i && j == shot.j)
                    return id;
    }
    return NONE;
}

int calculatePoints(Map map, Enemy enemy)
{
    return (map.l - enemy.i - 2) * enemy.j;
}

int isLeftBorder(int j)
{
    return j == 0;
}

int isRightBorder(Map map, int j)
{
    return j == map.c - 1;
}

int isHorizontalBorder(Map map, int i)
{
    return i == 0 || i == map.l - 1;
}

int isVerticalBorder(Map map, int j)
{
    return isLeftBorder(j) || isRightBorder(map, j);
}

int isBorder(Map map, int i, int j)
{
    return isHorizontalBorder(map, i) || isVerticalBorder(map, j);
}

int isCorner(Map map, int i, int j)
{
    return isHorizontalBorder(map, i) && isVerticalBorder(map, j);
}

int isTouchingLeftBorder(int j)
{
    return isLeftBorder(j - 2);
}

int isTouchingRightBorder(Map map, int j)
{
    return isRightBorder(map, j + 2);
}

int isValidAction(char action)
{
    return action == 'a' || action == 'd' || action == 's' || action == ' ';
}

void killEnemy(Enemy enemies[], int id)
{
    enemies[id].alive = 0;
}

Shot disableShot(Shot shot)
{
    shot.active = 0;
    return shot;
}

void saveInitialization(char dir[], Map map, Player player)
{
    FILE *pFile = createFile(dir, FILE_INITIALIZATION, "w+");
    for (int i = 0; i < map.l; i++)
        for (int j = 0; j < map.c; j++)
        {
            fprintf(pFile, "%c", map.values[i][j]);
            if (j == map.c - 1)
                fprintf(pFile, "\n");
        }
    fprintf(pFile, "A posicao central do jogador iniciara em (%d %d).", player.j, player.i);
    fclose(pFile);
}

int calculatePlayerLimit(Player player)
{
    return player.i - 2;
}

Map drawMatrix(Map map, int i, int j, int width, int height, char values[width][height])
{
    /*
    Desenha no mapa um desenho 3x3 com a posição central (i, j)
     */
    for (int a = i - 1; a <= i + 1; a++)
        for (int b = j - 1; b <= j + 1; b++)
            map.values[a][b] = values[a - (i - 1)][b - (j - 1)];
    return map;
}

Map drawPlayer(Map map, Player player)
{
    char playerDraw[3][3] = {{'M', ' ', 'M'}, {'M', 'M', 'M'}, {'M', 'M', 'M'}};
    map = drawMatrix(map, player.i, player.j, 3, 3, playerDraw);
    return map;
}

Map drawPlayerLimit(Map map, Player player)
{
    int i = calculatePlayerLimit(player);
    map.values[i][0] = '-';
    map.values[i][map.c - 1] = '-';
    return map;
}

EnemyDraw advanceAnimation(EnemyDraw enemyDraw)
{
    if (!enemyDraw.animate)
        return enemyDraw;
    enemyDraw.currentAnimation++;
    if (enemyDraw.currentAnimation == 3)
        enemyDraw.currentAnimation = 0;
    return enemyDraw;
}

Map drawEnemies(Map map, int enemiesCount, Enemy enemies[], EnemyDraw enemyDraw)
{
    for (int i = 0; i < enemiesCount; i++)
    {
        Enemy enemy = enemies[i];
        if (!isAlive(enemy))
            continue;
        map = drawMatrix(map, enemy.i, enemy.j, 3, 3, enemyDraw.values[enemyDraw.currentAnimation]);
    }
    return map;
}

Map drawShot(Map map, Shot shot)
{
    if (!isActive(shot))
        return map;
    map.values[shot.i][shot.j] = 'o';
    return map;
}

Game playGame(char dir[], Game game)
{
    FILE *pFile = createFile(dir, FILE_INPUT, "r");
    char action = 0;
    int hittedEnemyId = NONE;
    for (game.iteration = 0; !feof(pFile); game.iteration++)
    {
        printGameState(game.map, game.points, game.iteration);
        if (!someEnemyAlive(game.enemiesCount, game.enemies))
        {
            printf("Parabéns, você ganhou!\n");
            return game;
        }
        if (someEnemyCrossPlayerLimit(game.enemiesCount, game.enemies, game.player))
        {
            printf("Você perdeu, tente novamente!\n");
            return game;
        }
        if ((hittedEnemyId = someEnemyHitted(game.enemiesCount, game.enemies, game.shot)) != NONE)
        {
            Enemy hittedEnemy = game.enemies[hittedEnemyId];
            game.points += calculatePoints(game.map, hittedEnemy);
            saveEnemyHittedResume(dir, game.iteration, hittedEnemy, game.shot);
            game.rankingsCount = addEnemyRanking(game.rankingsCount, game.rankings, game.map, hittedEnemy, game.shot, game.iteration);
            killEnemy(game.enemies, hittedEnemyId);
            game.shot = disableShot(game.shot);
        }
        do
            fscanf(pFile, "%c", &action);
        while (action == '\n');
        MoveEnemiesResult moveEnemiesResult = moveEnemies(game.map, game.enemiesCount, game.enemies, game.enemiesDirection, game.iteration, game.statistics);
        for (int i = 0; i < moveEnemiesResult.enemyCollisionsCount; i++)
        {
            EnemyCollision collision = moveEnemiesResult.enemyCollisions[i];
            saveEnemyCollisionResume(dir, collision);
        }
        game.enemiesDirection = moveEnemiesResult.enemiesDirection;
        game.statistics = moveEnemiesResult.statistics;
        ShotResult moveShotResult = moveShot(game.shot, game.statistics);
        game.shot = moveShotResult.shot;
        game.statistics = moveShotResult.statistics;
        if (isValidAction(action))
        {
            if (action == ' ')
            {
                ShotResult shootShotResult = shootShot(game.shot, game.player, game.statistics);
                game.shot = shootShotResult.shot;
                game.statistics = shootShotResult.statistics;
            }
            if (action != 's')
            {
                MovePlayerResult movePlayerResult = movePlayer(game.map, game.player, action, game.statistics);
                game.player = movePlayerResult.player;
                game.statistics = movePlayerResult.statistics;
                savePlayerCollisionResume(dir, game.iteration, game.player, movePlayerResult.touchedBorder);
            }
        }
        game = updateGameState(game);
    }
    fclose(pFile);
}

MoveEnemiesResult moveEnemies(Map map, int enemiesCount, Enemy enemies[], int enemiesDirection, int iteration, Statistics statistics)
{
    MoveEnemiesResult result;
    result.enemiesDirection = enemiesDirection;
    result.statistics = statistics;
    result.enemyCollisionsCount = 0;
    for (int i = 0; i < enemiesCount; i++)
    {
        Enemy enemy = enemies[i];
        if (!isAlive(enemy))
            continue;
        /*
        Verifica se um inimigo está colidindo com a parede esquerda ou direita.
        Caso esteja, move todos os inimigos para baixo e adiciona essa estatística.
         */
        if (!isEnemyCollidingWithLeftBorder(enemy, enemiesDirection) &&
            !isEnemyCollidingWithRightBorder(map, enemy, enemiesDirection))
            continue;
        result.enemyCollisionsCount = moveDownEnemies(map, enemiesCount, enemies, iteration, enemiesDirection, result.enemyCollisionsCount, result.enemyCollisions);
        result.statistics = addStatistic(result.statistics, STATISTICS_ENEMIES_MOVE_DOWN);
        result.enemiesDirection = changeEnemiesDirection(result.enemiesDirection);
        return result;
    }
    for (int i = 0; i < enemiesCount; i++)
    {
        if (!isAlive(enemies[i]))
            continue;
        enemies[i].j += enemiesDirection;
    }
    return result;
}

int moveDownEnemies(Map map, int enemiesCount, Enemy enemies[], int iteration, int enemiesDirection, int enemyCollisionsCount, EnemyCollision enemyCollisions[])
{
    for (int i = 0; i < enemiesCount; i++)
    {
        Enemy enemy = enemies[i];
        if (!isAlive(enemy))
            continue;
        enemy.i++;
        enemies[i] = enemy;
        /*
        Verifica se o inimigo está colidindo com a parede esquerda ou direita.
        Caso esteja, salva a colisão com base em qual parede colidiu
         */
        if (!isEnemyCollidingWithLeftBorder(enemy, enemiesDirection) &&
            !isEnemyCollidingWithRightBorder(map, enemy, enemiesDirection))
            continue;
        EnemyCollision collision;
        collision.iteration = iteration;
        collision.touchedBorder = enemiesDirection == DIRECTION_RIGHT
                                      ? BORDER_RIGHT
                                      : BORDER_LEFT;
        collision.id = enemy.id;
        collision.row = enemy.row;
        enemyCollisions[enemyCollisionsCount] = collision;
        enemyCollisionsCount++;
    }
    return enemyCollisionsCount;
}

ShotResult moveShot(Shot shot, Statistics statistics)
{
    ShotResult result;
    result.shot = shot;
    result.statistics = statistics;
    if (!isActive(shot))
        return result;
    shot.i--;
    result.shot = shot;
    if (shot.i == 0)
    {
        result.shot = disableShot(result.shot);
        result.statistics = addStatistic(result.statistics, STATISTICS_NON_EFFECTIVE_SHOT);
    }
    return result;
}

ShotResult shootShot(Shot shot, Player player, Statistics statistics)
{
    ShotResult result;
    result.shot = shot;
    result.statistics = statistics;
    if (isActive(shot))
        return result;
    shot.active = 1;
    shot.i = calculatePlayerLimit(player);
    shot.j = player.j;
    result.shot = shot;
    result.statistics = addStatistic(result.statistics, STATISTICS_EFFECTIVE_SHOT);
    return result;
}

MovePlayerResult movePlayer(Map map, Player player, char action, Statistics statistics)
{
    MovePlayerResult result;
    result.player = player;
    result.statistics = statistics;
    result.touchedBorder = NONE;
    if (action == 'a')
    {
        if (isTouchingLeftBorder(player.j))
        {
            result.touchedBorder = BORDER_LEFT;
            return result;
        }
        result.statistics = addStatistic(result.statistics, STATISTICS_PLAYER_MOVE);
        result.player = moveToLeft(result.player);
    }
    else if (action == 'd')
    {
        if (isTouchingRightBorder(map, player.j))
        {
            result.touchedBorder = BORDER_RIGHT;
            return result;
        }
        result.statistics = addStatistic(result.statistics, STATISTICS_PLAYER_MOVE);
        result.player = moveToRigth(result.player);
    }
    return result;
}

Player moveToLeft(Player player)
{
    player.j--;
    return player;
}

Player moveToRigth(Player player)
{
    player.j++;
    return player;
}

void printGameState(Map map, int points, int iteration)
{
    printf("Pontos: %d | Iteracoes: %d\n", points, iteration);
    printMap(map);
}

Game updateGameState(Game game)
{
    game.map = cleanMap(game.map);
    game.map = drawPlayer(game.map, game.player);
    game.heatmap = markPlayer(game.heatmap, game.player);
    game.map = drawPlayerLimit(game.map, game.player);
    game.map = drawEnemies(game.map, game.enemiesCount, game.enemies, game.enemyDraw);
    game.map = drawShot(game.map, game.shot);
    game.heatmap = markShot(game.heatmap, game.shot);
    game.enemyDraw = advanceAnimation(game.enemyDraw);
    return game;
}

void printMap(Map map)
{
    for (int i = 0; i < map.l; i++)
        for (int j = 0; j < map.c; j++)
        {
            printf("%c", map.values[i][j]);
            if (j == map.c - 1)
                printf("\n");
        }
}

void savePlayerCollisionResume(char dir[], int iteration, Player player, int touchedBorder)
{
    FILE *pFile = createFile(dir, FILE_RESUME, "a+");
    if (touchedBorder == NONE)
        return;
    fprintf(pFile, "[%d] Jogador colidiu na lateral %s.\n", iteration + 1, touchedBorder == BORDER_LEFT ? "esquerda" : "direita");
    fclose(pFile);
}

void saveEnemyHittedResume(char dir[], int iteration, Enemy enemy, Shot shot)
{
    FILE *pFile = createFile(dir, FILE_RESUME, "a+");
    fprintf(pFile, "[%d] Inimigo de indice %d da fileira %d foi atingido na posicao (%d %d).\n", iteration, enemy.id, enemy.row, shot.j, shot.i);
    fclose(pFile);
}

void saveEnemyCollisionResume(char dir[], EnemyCollision collision)
{
    FILE *pFile = createFile(dir, FILE_RESUME, "a+");
    fprintf(pFile, "[%d] Inimigo de indice %d da fileira %d colidiu na lateral %s.\n", collision.iteration, collision.id, collision.row, collision.touchedBorder == BORDER_LEFT ? "esquerda" : "direita");
    fclose(pFile);
}

int addEnemyRanking(int rankingsCount, Ranking rankings[], Map map, Enemy enemy, Shot shot, int iteration)
{
    Ranking ranking;
    ranking.id = enemy.id;
    ranking.row = enemy.row;
    ranking.line = map.l - shot.i - 1;
    ranking.iteration = iteration;
    rankings[rankingsCount] = ranking;
    rankingsCount++;
    return rankingsCount;
}

void saveRankings(char dir[], int rankingsCount, Ranking rankings[])
{
    FILE *pFile = createFile(dir, FILE_RANKING, "w+");
    fprintf(pFile, "indice,fileira,linha,iteracao\n");
    for (int i = 0; i < rankingsCount; i++)
    {
        Ranking ranking = rankings[i];
        fprintf(pFile, "%d,%d,%d,%d\n", ranking.id, ranking.row, ranking.line, ranking.iteration);
    }
    fclose(pFile);
}

void sortRankings(int rankingsCount, Ranking rankings[])
{
    for (int i = 0; i < rankingsCount; i++)
        for (int j = i + 1; j < rankingsCount; j++)
            if (rankings[i].line > rankings[j].line || (rankings[i].line == rankings[j].line && rankings[i].iteration > rankings[j].iteration))
            {
                Ranking c = rankings[i];
                rankings[i] = rankings[j];
                rankings[j] = c;
            }
}

Statistics createStatistics()
{
    Statistics statistics = {0, 0, 0, 0};
    return statistics;
}

Statistics addStatistic(Statistics statistics, int event)
{
    switch (event)
    {
    case STATISTICS_PLAYER_MOVE:
        statistics.playerMoves++;
        return statistics;
    case STATISTICS_EFFECTIVE_SHOT:
        statistics.effectiveShots++;
        return statistics;
    case STATISTICS_NON_EFFECTIVE_SHOT:
        statistics.nonEffectiveShots++;
        return statistics;
    case STATISTICS_ENEMIES_MOVE_DOWN:
        statistics.enemiesMovesDown++;
        return statistics;
    default:
        return statistics;
    }
}

void saveStatistics(char dir[], Statistics statistics)
{
    FILE *pFile = createFile(dir, FILE_STATISTICS, "w+");
    fprintf(pFile, "Numero total de movimentos (A ou D): %d;\n", statistics.playerMoves);
    fprintf(pFile, "Numero de tiros efetivos: %d;\n", statistics.effectiveShots);
    fprintf(pFile, "Numero de tiros que nao acertaram: %d;\n", statistics.nonEffectiveShots);
    fprintf(pFile, "Numero de descidas dos inimigos: %d;", statistics.enemiesMovesDown);
    fclose(pFile);
}

int isActive(Shot shot)
{
    return shot.active;
}

Heatmap createHeatmap(Map map)
{
    Heatmap heatmap;
    heatmap.c = map.c - 2;
    heatmap.l = map.l - 2;
    for (int i = 0; i < heatmap.l; i++)
        for (int j = 0; j < heatmap.c; j++)
            heatmap.values[i][j] = 0;
    return heatmap;
}

Heatmap markHeatmap(Heatmap heatmap, int i, int j, int amountI, int amountJ)
{
    /*
    Marca o heatmap com a posição central (i, j) de (i - amountI, j - amountJ)
    até (i + amountJ, j + amountJ)
     */
    for (int a = i - amountI; a <= i + amountI; a++)
        for (int b = j - amountJ; b <= j + amountJ; b++)
            if (heatmap.values[a][b] < 999)
                heatmap.values[a][b]++;
    return heatmap;
}

void saveHeatmap(char dir[], Heatmap heatmap)
{
    FILE *pFile = createFile(dir, FILE_HEATMAP, "w+");
    for (int i = 0; i < heatmap.l; i++)
        for (int j = 0; j < heatmap.c; j++)
        {
            fprintf(pFile, "%3d ", heatmap.values[i][j]);
            if (j == heatmap.c - 1)
                fprintf(pFile, "\n");
        }
    fclose(pFile);
}

void createResumeFile(char dir[])
{
    FILE *pFile = createFile(dir, FILE_RESUME, "w+");
    fclose(pFile);
}

Heatmap markPlayer(Heatmap heatmap, Player player)
{
    heatmap = markHeatmap(heatmap, player.i - 1, player.j - 1, 1, 1);
    return heatmap;
}

Heatmap markShot(Heatmap heatmap, Shot shot)
{
    if (isActive(shot))
        heatmap = markHeatmap(heatmap, shot.i - 1, shot.j - 1, 0, 0);
    return heatmap;
}

int changeEnemiesDirection(int enemiesDirection)
{
    return enemiesDirection == DIRECTION_RIGHT ? DIRECTION_LEFT : DIRECTION_RIGHT;
}

int isEnemyCollidingWithLeftBorder(Enemy enemy, int enemiesDirection)
{
    return enemiesDirection == DIRECTION_LEFT && isTouchingLeftBorder(enemy.j);
}

int isEnemyCollidingWithRightBorder(Map map, Enemy enemy, int enemiesDirection)
{
    return enemiesDirection == DIRECTION_RIGHT && isTouchingRightBorder(map, enemy.j);
}
