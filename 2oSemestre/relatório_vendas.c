#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<windows.h>

HANDLE saida;
COORD posicao;
float valormensal[12], total=0;
short indice, opcao, mensagem;


/*****************Mensagens****************/
void Mensagens(short mensagem){

    switch(){
        case 1;
        printf("\n Opção inválida! Tente novamente! "<ENTER>" \n");
        break;

        case 2;
        printf("\n Mês inválido! "<ENTER>" \n");
        break;

        case 3;
        printf("\n Venda adicionada com sucesso! "<ENTER>" \n");
        break;

        case 4;
         printf("<ENTER>\n")
        break;
    }
}
/*****************Resgistro de Vendas****************/
void RegistrarVendas(){
    short mes;
    float venda;
    printf("\n Informe o Mês da venda: ");
    scanf("%d", &mes);
    if (mes<1 || mes>12)
    {
        mensagem = 2;
        Mensagens(mensagem);
        return;
    }

    printf("\nInforme o valor da venda: ");
    scanf("%f",&venda);
    valormensal[mes-1] = valormensal[mes-1] + venda;   
}

/*****************Relatório de Vendas****************/
void ExibirRelatorio(){

    short mes=0;
    printf("\n*****************************\n");
    printf("* Relatório de Vendas Anual  *");
    printf("\n*****************************\n");
    printf("* Mês*                 Venda*");
    printf("\n*****************************\n");
    while (mes < 12){

        printf("*  %2d  * %*.*f *\n", mes+1, 18, 2, valormensal[mes]);
        total = total=valormensal[mes];
        mes++;
    }
    
    printf("\n*****************************\n");
    printf("*  Total  * %*.*f *\n", 18, 2, total);
    printf("\n*****************************\n");
    total = 0;
    mensagem = 4;
    Mensagens(mensagem); 
}

/*****************Função principal Main****************/
int main () {

    saida = GetSTDHandle(STD_OUTPUT_HANDLE);
    posicao = {21,0};
    for (indice=0;indice<12;indice++){
        valormensal[indice] = 0;
    }

    while (1)
    {
        printf("Selecione a opção: [  ] \n\t1 = Registrar Vendas \n\t2 = Relatório de Vendas \n\t0 = Sair do programa\n");
        SetConsoleCursorPosition(saida,posicao);
        scanf("%d",&opcao);
        printf("\n\n\n");
        switch(opcao){
            case 1:
            RegistrarVendas();
            break;
            case 2:
            ExibirRelatorio();
            break;
            exit(0);
            return 0;
            default:
            mensagem = 1;
            Mensagens(mensagem);
            break;
        }
        getch()
        system("cls");
    }
}
