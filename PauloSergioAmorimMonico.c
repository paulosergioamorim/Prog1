#include <stdio.h>
#include <string.h>
#define MAX_WORKDIR_LENGTH 1000

typedef struct
{
    int l;
    int c;
    char **mesh;
} Map;

Map readMap(char *workDir);

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("ERRO: Informe o diretorio com os arquivos de configuracao.");
        return 1;
    }
    Map map = readMap(argv[1]);
    return 0;
}

Map readMap(char *workDir)
{
    FILE *pFile;
    char fileName[] = "mapa.txt";
    char filePath[MAX_WORKDIR_LENGTH + 8] = "";
    strcat(filePath, workDir);
    strcat(filePath, fileName);
    pFile = fopen(filePath, "\r");
}
