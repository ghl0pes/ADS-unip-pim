#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
int main()
{
    int cod, qtde, parcela;
    int p112=20, p145=25, p876=34, p547=17, p912=46, p334=48; //declaração dos produtos com seus valores de compra
    float valor, dvd;
    char pagamento;
    char nome[50], cpf[20], telefone[20]; //informações pessoais do cliente
    char rua[30], bairro[30], cep[15]; //endereço para entrega

    produtos: printf("---------------------------------------------------\n");
    printf("\nprodutos disponiveis: \n");
    printf("cod. 00112 = R$20,00\ncod. 00145 = R$25,00\ncod. 00876 = R$34,00");
    printf ("\ncod. 00547 = R$17,00\ncod. 00912 = R$46,00\ncod. 00334 = R$48,00\n");
    printf("\n---------------------------------------------------\n");
    printf("***INFORME O CODIGO DO PRODUTO QUE DESEJA:***\n               ***SEM OS %d***\n",0);
    printf("---------------------------------------------------\n");
    scanf("%d",&cod);
    quantidade: printf("\n---------------------------------------------------\n");
    printf("        ESCOLHA A QUANTIDADE:\n");
    printf("---------------------------------------------------\n");
    scanf("%d",&qtde);

    if(qtde>=1)
    {
        switch(cod)
        {
            case 112: valor = p112*qtde;
                    printf("-- o valor da sua compra e de R$%.2f --\n",valor);
                    break;

            case 145: valor = p145*qtde;
                    printf("-- o valor da sua compra e de R$%.2f --\n",valor);
                    break;

            case 876: valor = p876*qtde;
                    printf("-- o valor da sua compra e de R$%.2f --\n",valor);
                    break;          

            case 547: valor = p547*qtde;
                    printf("-- o valor da sua compra e de R$%.2f --\n",valor);
                    break;

            case 912: valor = p912*qtde;
                    printf("-- o valor da sua compra e de R$%.2f --\n",valor);
                    break;  

            case 334: valor = p334*qtde;
                    printf("-- o valor da sua compra e de R$%.2f --\n",valor);
                    break;      

            default: printf("\n\n***PRODUTO INVALIDO***");
                    printf("\ntente novamente sem %d no comeco\n ou tente um valor valido\n",0); 
                    Sleep(650); 
                    goto produtos;
        }   
    }
    else
    {
        printf("escolha uma quantidade superior a ZERO\n");
        Sleep(357);
        goto quantidade;
    }
    
    fflush(stdin);

    printf("\n***PARA CONTINUAR COM A COMPRA PREENCHA OS CAMPOS***\n\n");
    printf("digite seu nome: \n");
    fgets(nome, 50, stdin);
    printf("\ndigite seu CPF: \n");
    fgets(cpf, 20, stdin);
    printf("digite seu telefone: \n");
    fgets(telefone, 20, stdin);

    fflush(stdin);

    printf("\n\n***PREENCHA AS INFORMACOES PARA ENTREGA:***\n");
    printf("digite sua rua com numero: \n");
    fgets(rua, 30, stdin);
    printf("digite seu bairro: \n");
    fgets(bairro, 30, stdin);
    printf("digite seu CEP: \n");
    fgets(cep, 15, stdin);

    fflush(stdin);

    printf("\n***SELECIONE A FOMRA DE PAGAMENTO***");
    printf("\nDIGITE -c- PARA CARTAO OU -b- PARA BOLETO\n");
    scanf("%c",&pagamento);

        if(pagamento == 'c' || pagamento == 'C')
        {
        parcelamented: printf("escolha o numero de parcelas: \n");
        printf("1x\n2x\n3x\n4x\n5x\n");
        scanf("%d",&parcela);
        switch(parcela)
                {
                case 1: dvd = valor/1;
                        printf("\n1x de R$%.2f",dvd);break;
                case 2: dvd = valor/2;
                        printf("\n2x de R$%.2f",dvd);break;
                case 3: dvd = valor/3;
                        printf("\n3x de R$%.2f",dvd);break;      
                case 4: dvd = valor/4;
                        printf("\n4x de R$%.2f",dvd);break;                 
                case 5: dvd = valor/5;
                        printf("\n5x de R$%.2f",dvd);break;
                default: printf("*** ESCOLHA UM PARCELAMENTO ENTRE 1 E 5\n");
                        Sleep(357);
                        goto parcelamented;
                }
        }
        else if(pagamento =='b' || pagamento == 'B')
        {
                printf("\nO total do seu boleto e de R$%.2f\n",valor*0.95);
                printf("***VOCE GANHOU 5%% DE DESCONTO***");
        }

        printf("\n\n\n***EMITINDO RELATORIO DA COMPRA***\n");
        Sleep(750);

        printf("NOME: %s\n",nome);
        printf("CPF: %s\n",cpf);
        printf("TELEFONE: %s\n",telefone);
        printf("ENDERECO: Rua %sBairro %sCEP: %s",rua,bairro,cep);
        if(pagamento == 'c' || pagamento == 'C')
                printf("\nPAGAMENTO: %dx de R$%.2f\n\n\n",parcela,dvd);
        else if(pagamento =='b' || pagamento == 'B')
        {
                printf("\nPAGAMENTO: R$%.2f no boleto com 5%% de desconto",valor);
                printf("\n***VALOR TOTAL DE R$%.2f***\n\n\n",valor*0.95);
        }


} 