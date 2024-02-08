#include <stdio.h>
#include <locale.h>

/*Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes opções de menu:
    1 – Entrada de dados.
    2 – Lista todas todos os dados na tela.
    3 – Pesquisar um medico pelo nome completo e mostra na tela
    4 – Pesquisar um celular pelo nome completo
    5 – Pesquisar pela data da consulta.
    6 – Altera dados. Pesquisa pelo nome completo.
    7 – Exclui dados. Pesquisa pelo nome completo.
    8 – Saída pelo usuário
Estrutura: medico, celular, data_consulta
A única estrutura de dados do programa deve ser uma variável local na função main(). Portanto a passagem
da estrutura para as funções utiliza ponteiro.
Cada uma das opções do menu é uma função no programa.
OBS: não é necessário aplicar condicionais para que não hajam pessoas com o mesmo nome*/

struct var
    {
    char medico[50];
    char celular[15];
    char data_consulta[11];
    };


RecebeDados(struct var *p)
{   int op;

    do
    {
    printf("\n\nCadastre os dados do médico desejado: \n");
    printf("\nNome: ");
    fflush(stdin);
    gets(p->medico);
    printf("Celular: ");
    gets(p->celular);
    printf("Data da consulta (formato dd/mm/aaaa): ");
    gets(p->data_consulta);


    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "a");
    fwrite(p, sizeof(*p), 1, dadosarquivo);
    fclose(dadosarquivo);

    printf("\nVocê deseja continuar cadastrando novos dados? \n");
    printf("\nNão: digite '1'. \n");
    printf("\nSim: digite qualquer outro número. \n");
    scanf("%d", &op);
    }
    while (op != 1);
}

ImprimeDados(struct var *p)
{   int i, cont = 0;

    for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
    {
        if (p->medico[0] != '*')
    {
        printf("\n\tDados %d: ", i+1);
        printf("\n\tNome: %s", (p) -> medico);
        printf("\n\tCelular: %s", (p) -> celular);
        printf("\n\tData da consulta: %s\n", (p) -> data_consulta);
        printf("\t________________________________________");
        cont++;
    }

    }
    if(cont == 0)
    {
    printf("\n\tNão há dados cadastrados.\n");
    }
}

int ImprimeInfo(struct var *p, int i)
{
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\n\tO arquivo ainda não contém nenhum dado.\n");
        return 0;
        }
    else
        {
        fseek(dadosarquivo, i*sizeof(*p), 0);
        int bytes = fread(p, sizeof(*p), 1, dadosarquivo);
        fclose(dadosarquivo);

        return bytes;
        }
}

int ComparaDados(char *c1, char *c2)
{
    for (int i = 0; c1[i] != '\0' || c2[i] != '\0'; i++)
    {
        if (c1[i] != c2[i])
        {
            return 0;
        }
    }
    return 1;
}

int PesquisaDados(struct var *p)
{
    char procura[50];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\n\tO arquivo ainda não contém nenhum dado.\n");
        return 0;
        }

    printf("\nDigite o nome completo do médico para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\n\tInformações encontradas: " );
            printf("\n\tNome: %s", (p) -> medico);
            printf("\n\tCelular: %s", (p) -> celular);
            printf("\n\tData da consulta: %s\n", (p) -> data_consulta);
            printf("\t________________________________________");
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\n\tNão foi possível encontrar nenhum registro correspondente.\n" );
            }

        fclose(dadosarquivo);
}

int PesquisaCelular(struct var *p)
{
 char procura[50];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\n\tO arquivo ainda não contém nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do médico para buscar o celular: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\n\tInformações encontradas: " );
            printf("\n\tNome: %s", (p) -> medico);
            printf("\n\tCelular: %s", (p) -> celular);
            printf("\n\t________________________________________");
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\n\tNão foi possível encontrar nenhum registro correspondente.\n" );
            }

        fclose(dadosarquivo);
}

int PesquisaData(struct var *p)
{
  char procura[11];
    int bytes, i, cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\n\tO arquivo ainda não contém nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise a data de consulta que deseja encontrar (formato: dd/mm/aaaa): \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->data_consulta))
            {
            printf("\n\tInformações encontradas: " );
            printf("\n\tNome: %s", (p) -> medico);
            printf("\n\tCelular: %s", (p) -> celular);
            printf("\n\tData da consulta: %s\n", (p) -> data_consulta);
            printf("\t________________________________________");
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\n\tNão foi possível encontrar nenhum registro correspondente.\n");
            }

        fclose(dadosarquivo);
}

AlteraDados(struct var *p)
{
    char procura[50];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("\n\tO arquivo ainda não contém nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do médico desejado para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\n\tAltere as seguintes informações: \n");
            printf("\n\tNovo nome: ");
            fflush(stdin);
            gets(p->medico);
            printf("\n\tNovo celular: ");
            gets(p->celular);
            printf("\n\tNova data de consulta (formato dd/mm/aaaa): ");
            gets(p->data_consulta);
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            printf("\n\tAlterado com sucesso.\n\n");
            }
        }
            fclose(dadosarquivo);

        if(cont == 0)
        {
        printf("\n\tNão foi possível encontrar nenhum registro correspondente.\n" );
        }
}

ExcluiDados(struct var *p)
{
    char procura[50];
    int cont = 0;

    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r+");

    if(dadosarquivo == NULL)
        {
        printf("\n\tO arquivo ainda não contém nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do médico desejado para excluir os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            p->medico[0] = '*';
            p->celular[0] = '*';
            p->data_consulta[0] = '*';

            printf("\n\tOs dados foram excluídos com sucesso.\n\n");
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }
            fclose(dadosarquivo);

        if(cont == 0)
        {
        printf("\n\tNão foi possível encontrar nenhum registro correspondente.\n" );
        }
}

main()
{
    setlocale(LC_ALL, "Portuguese");
    char opcao;

    struct var dados;
    struct var *p;

    p = &dados;

   do
    {
    printf("\n\t\tAgenda de funcionários\n\n");
    printf("\t[1] Incluir dados\n");
    printf("\t[2] Listar todos os dados\n");
    printf("\t[3] Pesquisar dados\n");
    printf("\t[4] Pesquisar celular\n");
    printf("\t[5] Pesquisar pela data da consulta\n");
    printf("\t[6] Alterar dados\n");
    printf("\t[7] Excluir dados\n");
    printf("\t[8] Sair\n\n");
    printf("\n\tDigite a opção desejada: ");
    scanf(" %c", &opcao);

        if (opcao == '1')
        {
            RecebeDados(p);
        }
        else
        if(opcao == '2')
        {
            ImprimeDados(p);
        }
        else
        if(opcao == '3')
        {
            PesquisaDados(p);
        }
        else
        if(opcao == '4')
        {
            PesquisaCelular(p);
        }
        else
        if(opcao == '5')
        {
            PesquisaData(p);
        }
        else
        if(opcao == '6')
        {
            AlteraDados(p);
        }
        else
        if(opcao == '7')
        {
            ExcluiDados(p);
        }
        else
        if(opcao == '8')
        {
        printf("\n\tPrograma encerrado.\n");
        exit(0);
        }
        else
        {
            printf("\n\tOpção inválida. Tente novamente!\n");
        }
    }
        while (opcao!= '1' || opcao!= '2' || opcao!= '3');
}
