#include <stdio.h>
#include <locale.h>

/*Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes op��es de menu:
    1 � Entrada de dados.
    2 � Lista todas todos os dados na tela.
    3 � Pesquisar um medico pelo nome completo e mostra na tela
    4 � Pesquisar um celular pelo nome completo
    5 � Pesquisar pela data da consulta.
    6 � Altera dados. Pesquisa pelo nome completo.
    7 � Exclui dados. Pesquisa pelo nome completo.
    8 � Sa�da pelo usu�rio
Estrutura: medico, celular, data_consulta
A �nica estrutura de dados do programa deve ser uma vari�vel local na fun��o main(). Portanto a passagem
da estrutura para as fun��es utiliza ponteiro.
Cada uma das op��es do menu � uma fun��o no programa.
OBS: n�o � necess�rio aplicar condicionais para que n�o hajam pessoas com o mesmo nome*/

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
    printf("\n\nCadastre os dados do m�dico desejado: \n");
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

    printf("\nVoc� deseja continuar cadastrando novos dados? \n");
    printf("\nN�o: digite '1'. \n");
    printf("\nSim: digite qualquer outro n�mero. \n");
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
    printf("\n\tN�o h� dados cadastrados.\n");
    }
}

int ImprimeInfo(struct var *p, int i)
{
    FILE *dadosarquivo;
    dadosarquivo = fopen("arquivodesafio.txt", "r");

    if(dadosarquivo == NULL)
        {
        printf("\n\tO arquivo ainda n�o cont�m nenhum dado.\n");
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
        printf("\n\tO arquivo ainda n�o cont�m nenhum dado.\n");
        return 0;
        }

    printf("\nDigite o nome completo do m�dico para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\n\tInforma��es encontradas: " );
            printf("\n\tNome: %s", (p) -> medico);
            printf("\n\tCelular: %s", (p) -> celular);
            printf("\n\tData da consulta: %s\n", (p) -> data_consulta);
            printf("\t________________________________________");
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\n\tN�o foi poss�vel encontrar nenhum registro correspondente.\n" );
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
        printf("\n\tO arquivo ainda n�o cont�m nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do m�dico para buscar o celular: \n");
    fflush(stdin);
    gets(procura);

        for (i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\n\tInforma��es encontradas: " );
            printf("\n\tNome: %s", (p) -> medico);
            printf("\n\tCelular: %s", (p) -> celular);
            printf("\n\t________________________________________");
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\n\tN�o foi poss�vel encontrar nenhum registro correspondente.\n" );
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
        printf("\n\tO arquivo ainda n�o cont�m nenhum dado.\n");
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
            printf("\n\tInforma��es encontradas: " );
            printf("\n\tNome: %s", (p) -> medico);
            printf("\n\tCelular: %s", (p) -> celular);
            printf("\n\tData da consulta: %s\n", (p) -> data_consulta);
            printf("\t________________________________________");
             cont++;
            }
        }

        if(cont == 0)
            {
            printf("\n\tN�o foi poss�vel encontrar nenhum registro correspondente.\n");
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
        printf("\n\tO arquivo ainda n�o cont�m nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do m�dico desejado para buscar os dados: \n");
    fflush(stdin);
    gets(procura);

        for (int i = 0; (ImprimeInfo(p, i)) != 0; i++)
        {
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fread(p, sizeof(*p), 1, dadosarquivo);

            if(ComparaDados(procura, p->medico))
            {
            printf("\n\tAltere as seguintes informa��es: \n");
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
        printf("\n\tN�o foi poss�vel encontrar nenhum registro correspondente.\n" );
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
        printf("\n\tO arquivo ainda n�o cont�m nenhum dado.\n");
        return 0;
        }

    printf("\nPesquise o nome completo do m�dico desejado para excluir os dados: \n");
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

            printf("\n\tOs dados foram exclu�dos com sucesso.\n\n");
            cont++;
            fseek(dadosarquivo, i*sizeof(*p), 0);
            fwrite(p, sizeof(*p), 1, dadosarquivo);
            }
        }
            fclose(dadosarquivo);

        if(cont == 0)
        {
        printf("\n\tN�o foi poss�vel encontrar nenhum registro correspondente.\n" );
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
    printf("\n\t\tAgenda de funcion�rios\n\n");
    printf("\t[1] Incluir dados\n");
    printf("\t[2] Listar todos os dados\n");
    printf("\t[3] Pesquisar dados\n");
    printf("\t[4] Pesquisar celular\n");
    printf("\t[5] Pesquisar pela data da consulta\n");
    printf("\t[6] Alterar dados\n");
    printf("\t[7] Excluir dados\n");
    printf("\t[8] Sair\n\n");
    printf("\n\tDigite a op��o desejada: ");
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
            printf("\n\tOp��o inv�lida. Tente novamente!\n");
        }
    }
        while (opcao!= '1' || opcao!= '2' || opcao!= '3');
}
