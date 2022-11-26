#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct cadastra{
    int codigop,codigof,quantidade;
    char nome[30];
    char fornecedor[30];
    char expessura [16];
    char material [15];
    float preco;
};

struct cadastra cad[MAX];
int quantp=0;

void cadastraProduto(struct cadastra produto){
    cad[quantp]=produto;
    quantp++;
}


struct cadastra leDados(){
    struct cadastra auxiliar;
    srand(time (NULL));
    fflush(stdin);
    printf("Digite a cor do produto: \n");
    scanf("%s",auxiliar.nome);
    auxiliar.codigop = 1 + rand()%100;
    printf("Codigo do produto %d\n",auxiliar.codigop);
    fflush(stdin);
    printf("Quantide de produtos para o estoque\n");
    scanf("%d",&auxiliar.quantidade);
    fflush(stdin);
    printf("Qual a expessura do produto em cm: \n");
    scanf("%s",&auxiliar.expessura);
    fflush(stdin);
     printf("Qual o material do produto: \n");
    scanf("%s",&auxiliar.material);
    fflush(stdin);
    printf("Nome do fornecedor\n");
    scanf("%s",auxiliar.fornecedor);
    auxiliar.codigof = 1 + rand()%100;
    printf("Codigo do fornecedor %s eh %d\n",auxiliar.fornecedor, auxiliar.codigof);
    fflush(stdin);
    printf("Digite o preco do produto\n");
    scanf("%f",&auxiliar.preco);
    fflush(stdin);
    system("CLS");
return auxiliar;
}
void buscar(){
    int i,opica;
    char nome[30];
        do{
            printf("MENU DE BUSCA\n");
            printf("1- Mostrar lista de produtos\n");
            printf("2- Buscar pelo nome produto ou pelo nome do fornecedor\n");;
            printf("3- Sair do menu busca\n");
            printf("Digite o numero da opcao desejada \n");
            scanf("%d",&opica);
            system("CLS");
            switch(opica){
                case 1:
                    printf("Lista de produtos cadastrados\n");
                    for(i=0;i<quantp;i++){
                        printf("Produto %d \n",i+1);
                        printf("+++++++++++++++++++++++\n");
                        printf("Cor do produto:       %s\n",cad[i].nome);
                        printf("Codigo do produto:     %d\n",cad[i].codigop);
                        printf("Quantidade no estoque: %d\n",cad[i].quantidade);
                        printf("Expessura do produto : %s\n",cad[i].expessura);
                        printf("Material  do produto : %s\n",cad[i].material);
                        printf("Nome do fornecedor:    %s\n",cad[i].fornecedor);
                        printf("Codigo do fornecedor:  %d\n",cad[i].codigof);
                        printf("Preço do produto:      %.2f\n",cad[i].preco);
                        printf("+++++++++++++++++++++++\n");
                    }
                    break;
                case 2:
                    printf("Digite o nome do produto ou nome do fornecedor\n");
                    scanf("%s",&nome);
                    for(i=0;i<quantp;i++){
                        if((strcmp (nome, cad[i].nome) == 0) || strcmp (nome, cad[i].fornecedor) == 0) {
                            printf("+++++++++++++++++++++++\n");
                            printf("Cor do produto:       %s\n",cad[i].nome);
                            printf("Codigo do produto:     %d\n",cad[i].codigop);
                            printf("Quantidade no estoque: %d\n",cad[i].quantidade);
                            printf("Expessura do produto : %s\n",cad[i].expessura);
                            printf("Material  do produto : %s\n",cad[i].material);
                            printf("Nome do fornecedor:    %s\n",cad[i].fornecedor);
                            printf("Codigo do fornecedor:  %d\n",cad[i].codigof);
                            printf("Preço do produto:      %.2f\n",cad[i].preco);
                            printf("+++++++++++++++++++++++\n");
                        }
                    }
                    break;
                case 3:
                    break;
            }
        }while(opica!=3);
        system("CLS");
}
void alterar (){
    int i;
    char nome[30];
    fflush(stdin);
    printf("Digite o nome do produto que deseja alterar: ");
    scanf("%s",&nome);
    for(i=0;i<quantp;i++){
        if(strcmp (nome, cad[i].nome) == 0){
            fflush(stdin);
            printf("Digite o nome do produto\n");
            scanf("%s",&cad[i].nome);
            cad[i].codigop = 1 + rand()%10;
            printf("Codigo do produto %d\n",cad[i].codigop);
            fflush(stdin);
            printf("Quantide de produtos para o estoque\n");
            scanf("%d",&cad[i].quantidade);
            fflush(stdin);
            printf("Nome do fornecedor\n");
            scanf("%s",&cad[i].fornecedor);
            cad[i].codigof = 1 + rand()%10;
            printf("Codigo do fornecedor %s eh %d\n",cad[i].fornecedor, cad[i].codigof);
            fflush(stdin);
            printf("Digite o preço do produto\n");
            scanf("%f",&cad[i].preco);
            fflush(stdin);
        }
    }
    system("CLS");
}
void remover () {    			// Função remover
	int i,cont=0;
	int codigo_busc;
	printf("veja numero do produto que você deseja remover\n");
	buscar();                   // Chama a função listar para que seja visto qual codigo relacionado ao produto
	printf("Informe o Codigo do Produto que se Deseja Excluir: "); // Pede o codigo para busca
	scanf("%i",&codigo_busc);
	for(i = 0 ; i < quantp ; i++){

		if (cad[i].codigop == codigo_busc) {  // Compara o codigo relacionado e exclui

			cad[i] = cad[i+1];                // Realoca a Memória

            quantp--;                         // decrementa o indice do vetor para que ocupe o cadastro removido
            cont++;

		}
	}
	if(cont>0){
        printf ("\n\nPRODUTO EXCLUIDO COM SUCESSO !");
        printf ("\nPressione ENTER Para Continuar !");
        setbuf(stdin,NULL);
        getchar ();
        system ("cls");
    }else {
        printf("Esse numero de codigo nao existe\n");
    }
}
int main (){
    int opicao;
    struct cadastra novoProduto;
    do{
        printf("MENU DE OPCAO\n");
        printf("1 - Cadastrar Estoque\n");
        printf("2 - Consultar Estoque\n");
        printf("5 - Finalizar\n");
        printf("Digite o numero da opcao desejada \n");
        scanf("%d",&opicao);
        system("CLS");
        switch(opicao){
            case 1:
                novoProduto=leDados();
                cadastraProduto(novoProduto);
                break;
            case 2:
                buscar();
                break;
            case 3:
                alterar();
                break;
            case 4:
            	remover();
            	break;
            case 5:
                printf("Obrigado!\n");
                break;
            default:
                printf("Opcao invalida!\nTente novamente:\n");
                break;
        }
    }while(opicao!=5);

system("PAUSE");
return 0;
}
