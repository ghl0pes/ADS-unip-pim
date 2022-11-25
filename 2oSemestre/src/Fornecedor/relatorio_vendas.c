#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

float valormensal[12], total=0;
short indice, opcao, mensagem;

/*********Mensagens e função Mensagem***************/
void Mensagens(short mensagem)
{

    switch (){
        case 1:
            printf("\n Opção Inválida! Tente Novamente. <ENTER> \n");
        break;

        case 2:
            printf("\n Mês Inválido. <ENTER> \n");
        break;

        case 3:
            printf("\n Venda adicionada com sucesso! <ENTER> \n");
        break;

        case 4:
            printf("\n<ENTER>\n");
        break;
    }
    
    if(mensagem == 1)
        

    if(mensagem == 2)
        

    if(mensagem == 1)
        
}

/*********Função Registro de Vendas***************/
void RegistrarVendas()
{
    short mes;
    float venda;

    printf("\n Informe o mês da Venda: ");
    scanf("%d", &mes);

    if (mes <1 || mes >12){
        mensagem = 2;
        Mensagens(mensagem);
        return;
    }
    printf("\n Informe o vlor da Venda: ");
    scanf("%f",&venda);
    valormensal[mes-1] = valormensal[mes-1] + venda;
}

/*********Função Relatório de Vendas***************/
void ExibirRelatorio()
{
    short mes=0;
    printf("\n*********************************\n");
    printf("\n*********************************\n");
    printf("    *Relatório de Vendas Anual    *\n");
    printf("\n*********************************\n");
    printf("    * Mês *                 Venda *\n");
    printf("\n*********************************\n");
    while (mes < 12)
    {
        printf("    * %2d *  *%*.*f\n", mes+1, 18, 2, valormensal[mes]);
        total = total + valormensal[mes];
        mes++;
    }
    
    printf("\n*********************************\n");
    printf("    * Total*  *%*.*f\n",18, 2, total);
    printf("\n*********************************\n");
    total = 0;
    mensagem = 4;
    Mensagens(mensagem);
}


/*********Função Main***************/
int main (){
    for(indice=0; indice<12; indice++)
        valormensal[indice] = 0;
    while (1)
    {
        printf("Selecione a opção \n\t1 = Registrar Vendas \n\t2 = Relatório de Vendas \n\t0 = Sair do Programa \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: 
            RegistrarVendas();
            break; 
            case 2: 
            ExibirRelatorio();
            break; 
            case 0: 
            exit(0);
            default: 
            mensagem = 1;
            Mensagens(mensagem);
            break;
        }
        getch();
        system("cls");
    }  
}