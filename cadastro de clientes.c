/*-------------------------------------------------------------
* UNIFAL - Universidade Federal de Alfenas.
* BACHARELADO EM CIENCIA DA COMPUTACAO.
* Atividade.: Cadastro de clientes
* Disciplina: AEDs I
* Professor.: Paulo Alexandre Bressan
* Aluno.....: Andre Neves Medeiros
* Data......: 30/10/2020
*-------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[100][20];
    char sobrenome[100][20];
    int celular[100];
    long long int cpf[100];
}registro;

registro bubble_sort(registro cliente, int quantidade_registros)
{
    int i, j, aux;
    char string_aux[100][40];
    long long int auxl;
    for (i=quantidade_registros-1; i > 0; i--)
	{
		for(j=0; j<i; j++)
		{
			if (cliente.celular[j] > cliente.celular[j + 1])
			{
				aux = cliente.celular[j];
				cliente.celular[j] = cliente.celular[j + 1];
				cliente.celular[j + 1] = aux;

                strcpy(string_aux[j], cliente.nome[j]); 
                strcpy(cliente.nome[j], cliente.nome[j+1]);
                strcpy(cliente.nome[j+1], string_aux[j]);

                strcpy(string_aux[j],cliente.sobrenome[j]);
                strcpy(cliente.sobrenome[j], cliente.sobrenome[j+1]);
                strcpy(cliente.sobrenome[j+1], string_aux[j]);
                
                auxl=cliente.cpf[j];
                cliente.cpf[j] = cliente.cpf[j+1];
                cliente.cpf[j+1]=auxl;
			}
		}
	}
    return cliente; 
}

registro selection_sort(registro cliente, int quantidade_registros)
{
    long long int auxl;
    int i, j, aux;
    char auxc1[20], auxc2[20];

    for (i = 1; i < quantidade_registros; i++)
	{
		auxl = cliente.cpf[i];
        strcpy(auxc1,cliente.nome[i]);
        strcpy(auxc2,cliente.sobrenome[i]);
        aux=cliente.celular[i];
		for (j = i - 1; j >= 0 && cliente.cpf[j] > auxl; j--)
		{
			cliente.cpf[j + 1] = cliente.cpf[j];
            strcpy(cliente.nome[j+1], cliente.nome[j]);
            strcpy(cliente.sobrenome[j+1], cliente.sobrenome[j]);
            cliente.celular[j+1]=cliente.celular[j];
		}
		cliente.cpf[j + 1] = auxl;
        strcpy(cliente.nome[j+1], auxc1);
        strcpy(cliente.sobrenome[j+1], auxc2);
        cliente.celular[j+1]=aux;
	}
  

    return cliente;
}

registro inserir_cliente(registro cliente, char newname[40], char newlastname[40], int newnumber, long long int newid, int quantidade_registros, int contador_insercao)
{
    int i;
    i=quantidade_registros+contador_insercao;
    strcpy(cliente.nome[i], newname);
    strcpy(cliente.sobrenome[i], newlastname);
    cliente.celular[i]=newnumber;
    cliente.cpf[i]=newid;

    return cliente;
}


registro remover_cliente(registro cliente, int opcao, int quantidade_registros)
{   
    int i, auxiliar;
    long long int auxiliarl;
    char aux[40];
    
    if(opcao==quantidade_registros-1)
    {
        strcpy(cliente.nome[quantidade_registros-1], "");
        strcpy(cliente.sobrenome[quantidade_registros-1], "");
        cliente.celular[quantidade_registros]=0;
        cliente.cpf[quantidade_registros-1]=0;
    }
   else
   {
       i=opcao;
       while(i<quantidade_registros-1)
        {
            strcpy(aux, cliente.nome[i+1]);
            strcpy(cliente.nome[i], aux);

            strcpy(aux, cliente.sobrenome[i+1]);
            strcpy(cliente.sobrenome[i], aux);

            auxiliar=cliente.celular[i+1];
            cliente.celular[i]=auxiliar;

            auxiliarl=cliente.cpf[i+1];
            cliente.cpf[i]=auxiliarl;
            i++;
        }
   }
    
    strcpy(cliente.nome[quantidade_registros-1], " ");
    strcpy(cliente.sobrenome[quantidade_registros-1], " ");
    cliente.celular[quantidade_registros-1]=0;
    cliente.cpf[quantidade_registros-1]=0;
    return cliente;
}

int busca_celular(registro cliente, int celular, int quantidade_registros)
{
    int i;
    int a;
    a=0;
    for(i=0; i<quantidade_registros; i++)
    {
        if(celular==cliente.celular[i])
        {
            return i;
            break;
        }
        else
        {
            a++;
        }
    }
    i=i+a;
    return i;
}

int busca_cpf(registro cliente, long long int cpf, int quantidade_registros)
{
    int i;
    int a;
    a=0;
    for(i=0; i<quantidade_registros; i++)
    {
        if(cpf==cliente.cpf[i])
        {
            return i;
            break;
        }
        else
        {
            a++;
        }
    }
    i=i+a;
    return i;
}


registro alterar_dados(registro cliente, int alterar, int oque, char string[20], int celular, long long int cpf)
{
    char aux[20];
    int auxi;
    long long int auxl;
    auxi=oque;
    switch(auxi)
    {
    case 1:
        strcpy(aux, string);
        strcpy(cliente.nome[alterar], aux);
        break;
    case 2:
        strcpy(aux, string);
        strcpy(cliente.sobrenome[alterar], aux);
        break;
    case 3:
        cliente.celular[alterar]=celular;
        break;
    case 4:
        cliente.cpf[alterar]=cpf;
        break;
    default:
        break;
    }
    return cliente;
}



int main()
{
    registro cliente;
    FILE *arq, *arq_saida;
    int inutil, opcao_selecionada, quantidade_registros, i, j, contador_insercao;
    char aux[350];
    inutil=0;
    opcao_selecionada=0;
    contador_insercao=0;

    //leitura do arquivo inicial
    arq = fopen ("arquivo de clientes.txt", "r");
    if(arq==NULL)
    {
        printf("Erro: nao foi possivel abrir o arquivo de clientes");
        return (1);
    }
    fscanf(arq, "%d", &quantidade_registros);

    char auxa[10], auxb[12];
    int aux1;
    long long int aux2;
    aux2=0;
    char cpf_procurado[13];
    for(i=0; i<quantidade_registros; i++)
    {
        fscanf(arq, "%s", cliente.nome[i]);
        fscanf(arq, "%s", cliente.sobrenome[i]);

        fscanf(arq, "%s", auxa);
        aux1=atoi(auxa);
        cliente.celular[i]=aux1;

        fscanf(arq, "%s", auxb);
        aux2=atoll(auxb);
        cliente.cpf[i]=aux2;
    }
    
    cliente = bubble_sort(cliente, quantidade_registros); //organizacao bubblesort por celular
    fclose(arq);



    //Interação com o usuário
    selecao:
    printf("---- Menu de opcoes ----\n1 - Inserir cliente\n2 - Remover cliente\n3 - Alterar dados\n4 - Busca por celular\n5 - Busca por CPF\n6 - Mostrar clientes\n7 - Sair\n");
   
    scanf("%d", &opcao_selecionada);
    char newname[40], newlastname[40];
    long long int newid;
    int newnumber, metodo_exclusao;
    char opt[2], string[20], sobrenome[20];
    int opcao, celular, alterar, oque;
    long long int cpf;
        switch(opcao_selecionada)
        {
        case 1:
            printf("Selecionado: Inserir Cliente\n\n");
            printf("Digite o nome: ");
            scanf("%s", &newname);
            printf("\nDigite o sobrenome: ");
            scanf("%s", &newlastname);
            printf("\nDigite o numero de celular: ");
            scanf("%d", &newnumber);
            printf("\nDigite o CPF: ");
            scanf("%lld", &newid);
            //printf("%s %s %s %s", newname, newlastname, newnumber, newid); //verificacao se variaveis estao sendo preenchidas

            cliente=inserir_cliente(cliente, newname, newlastname, newnumber, newid, quantidade_registros, contador_insercao);
            quantidade_registros++;
            printf("\nNovo cliente registrado com sucesso!\n\n");
         
            goto selecao;
            break;
        
        case 2:
            loop2:
            printf("Selecionado: Remover cliente.\n");
            printf("Como deseja encontrar o cliente?\n");
            printf("1 - Selecionar pela lista completa\n2 - Procurar pelo celular\n3 - Procurar pelo CPF\n");   
            scanf("%d", &metodo_exclusao);
            if(metodo_exclusao==1)
            {
                printf("SELECIONE UMA DAS OPCOES\n");
                printf("Opcao   Nome    Sobrenome    Celular    CPF\n");
                for(i=0; i<quantidade_registros; i++)
                {
                    printf("   %d - %s  %s  %d  %lld\n", i, cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                }
                printf("Opcao selecionada:");
            
                scanf("%s", opt);
                opcao=atoi(opt);
                if(opcao>quantidade_registros-1)
                {
                    printf("\nCliente invalido.\n\n");
                    goto loop2;
                }
                cliente=remover_cliente(cliente, opcao, quantidade_registros);
                quantidade_registros--;
            
                printf("\nCliente selecionado removido com sucesso!\n\n");
            }
            if(metodo_exclusao==2)
            {
                printf("Digite o celular do cliente a ser excluido\n");
                scanf("%d", &celular);
                i=busca_celular(cliente, celular, quantidade_registros);
                if(i>quantidade_registros)
                {
                    printf("\nNenhum cliente com o numero de celular correspondente.\n\n");
                    goto selecao;
                }
                confirmacao:
                printf("\n***CONFIRMAR EXCLUSAO DO CLIENTE?***\n%s %s %d %lld\n\n", cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                printf("Digite 1 para confirmar exclusao(permanente) ou 2 para cancelar\n");
                scanf("%d", &j);
                if(j==1)
                {
                    cliente=remover_cliente(cliente, i, quantidade_registros);
                    printf("\nCliente removido com sucesso!\n\n");
                    quantidade_registros--;
                }
                if(j==2)
                {
                    printf("\nExclusao cancelada\n\n");
                    goto selecao;
                    break;
                }
                if(j!=1 && j!=2)
                {
                    printf("\nOpcao selecionada invalida\n");
                    goto confirmacao;
                }
            }
            if(metodo_exclusao==3)
            {
                printf("Digite o CPF do cliente a ser excluido\n");
                scanf("%lld", &cpf);
                i=busca_cpf(cliente, cpf, quantidade_registros);
                if(i>quantidade_registros)
                {
                    printf("\nNenhum cliente com o numero de celular correspondente.\n\n");
                    goto selecao;
                }
                nconfirmacao:
                printf("\n*** CONFIRMAR EXCLUSAO DO CLIENTE? ***\n%s %s %d %lld\n\n", cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                printf("Digite 1 para confirmar exclusao(permanente) ou 2 para cancelar\n");
                scanf("%d", &j);
                if(j==1)
                {
                    cliente=remover_cliente(cliente, i, quantidade_registros);
                    printf("\nCliente removido com sucesso!\n\n");
                    quantidade_registros--;
                    goto selecao;
                }
                if(j==2)
                {
                    printf("\nExclusao cancelada\n\n");
                    goto selecao;
                    break;
                }
                if(j!=1 && j!=2)
                {
                    printf("\nOpcao selecionada invalida\n");
                    goto confirmacao;
                }
                break;
            }
            goto selecao;
            break;

        case 3:
            terceiro:
            printf("Selecionado: Alteracao de dados.\n");
            printf("\nLocalizar cliente por:\n1 - Selecao a partir de lista\n2 - Busca por celular\n3 - Busca por CPF\n");
            scanf("%s", opt);
            opcao=atoi(opt);
            if(opcao==1)
            {
                printf("Opcao   Nome    Sobrenome    Celular    CPF\n");
                for(i=0; i<quantidade_registros; i++)
                {
                    printf("   %d - %s  %s  %d  %lld\n", i, cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                }
                printf("\nSelecione a opcao correspondente ao cliente que deseja alterar dados.\n");
                scanf("%d", &alterar);
                if(alterar>quantidade_registros-1 || alterar<0)
                {
                    printf("\nOPCAO NAO REGISTRADA\n\n");
                    goto terceiro;
                }
                printf("Selecione uma das opcoes:\n1 - Alterar Nome\n2 - Alterar Sobrenome\n3 - Alterar celular\n4 - Alterar CPF\n");
                scanf("%d", &oque);
                celular=0;
                if(oque==1)
                {
                    printf("Digite o novo nome:");
                    scanf("%s", string);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("\nNome alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque==2)
                {
                    printf("Digite o novo sobrenome:");
                    scanf("%s", string);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("\nSobrenome alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque==3)
                {
                    printf("Digite o novo celular:");
                    scanf("%d", &celular);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("\nCelular alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque==4)
                {
                    printf("Digite o novo CPF:");
                    scanf("%lld", &cpf);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("\nCPF alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque != 1 && oque != 2 && oque != 3 && oque != 4 )
                {
                    printf("OPCAO INEXISTENTE.\n\n");
                    goto terceiro;
        
                }
                //printf("%s %s %d %s", string, sobrenome, celular, cpf); //verificacao
                break;
            }
            if(opcao==2) //alterar dados de cliente buscado por celular
            {
                printf("Digite o celular do cliente a ser encontrado:");
                scanf("%d", &celular);
                i=busca_celular(cliente, celular, quantidade_registros);
                if(i>quantidade_registros)
                {
                    printf("\nNenhum cliente com o numero de celular correspondente.\n\n");
                    goto selecao;
                }
                printf("\nINFORMACOES DO CLIENTE:\nNome: %s\nSobrenome: %s\nCelular: %d\nCPF: %lld\n", cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                printf("\nQual dado deseja alterar?\n1 - Alterar Nome\n2 - Alterar Sobrenome\n3 - Alterar celular\n4 - Alterar CPF\n");
                scanf("%d", &oque);
                alterar=i;
                if(oque==1)
                {
                    printf("Digite o novo nome:");
                    scanf("%s", string);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("Nome alterado com sucesso!");
                    goto selecao;
                }
                if(oque==2)
                {
                    printf("Digite o novo sobrenome:");
                    scanf("%s", string);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular,cpf);
                    printf("Sobrenome alterado com sucesso!");
                    goto selecao;
                }
                if(oque==3)
                {
                    printf("Digite o novo celular:");
                    scanf("%d", &celular);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("Celular alterado com sucesso!");
                    goto selecao;
                }
                if(oque==4)
                {
                    printf("Digite o novo CPF:");
                    scanf("%lld", &cpf);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("CPF alterado com sucesso!");
                    goto selecao;
                }
                if(oque != 1 && oque != 2 && oque != 3 && oque != 4 )
                {
                    printf("OPCAO INEXISTENTE.\n");
                    goto terceiro;
                }
                for(i=0; i<quantidade_registros; i++)
                {
                    printf("   %d - %s  %s  %d  %lld\n", i, cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                }
                goto selecao;
                break;
            }
            if(opcao==3)//alteracao a partir de busca por CPF
            {
                printf("Digite o CPF do cliente a ser encontrado:");
                scanf("%lld", &cpf);
                i=busca_cpf(cliente, cpf, quantidade_registros);
                if(i>quantidade_registros)
                {
                    printf("\nNenhum cliente com o documento correspondente.\n\n");
                    goto selecao;
                }
                printf("\nINFORMACOES DO CLIENTE:\nNome: %s\nSobrenome: %s\nCelular: %d\nCPF: %lld\n", cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                printf("\nQual dado deseja alterar?\n1 - Alterar Nome\n2 - Alterar Sobrenome\n3 - Alterar celular\n4 - Alterar CPF\n");
                scanf("%d", &oque);
                alterar=i;
                if(oque==1)
                {
                    printf("Digite o novo nome:");
                    scanf("%s", string);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("Nome alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque==2)
                {
                    printf("Digite o novo sobrenome:");
                    scanf("%s", string);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular,cpf);
                    printf("Sobrenome alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque==3)
                {
                    printf("Digite o novo celular:");
                    scanf("%d", &celular);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("Celular alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque==4)
                {
                    printf("Digite o novo CPF:");
                    scanf("%lld", &cpf);
                    cliente=alterar_dados(cliente, alterar, oque, string, celular, cpf);
                    printf("CPF alterado com sucesso!\n\n");
                    goto selecao;
                }
                if(oque != 1 && oque != 2 && oque != 3 && oque != 4 )
                {
                    printf("OPCAO INEXISTENTE.\n");
                    goto terceiro;
                }
                for(i=0; i<quantidade_registros; i++)
                {
                    printf("   %d - %s  %s  %d  %lld\n", i, cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                }
                goto selecao;
                break;
            }

            
            if(opcao==5)
            {

                goto selecao;
            }
            
            break;
        case 4:
            printf("Selecionado: Busca por celular.\n");
            printf("Digite o celular do cliente a ser encontrado:");
            scanf("%d", &celular);
            cliente=bubble_sort(cliente, quantidade_registros);
            i=busca_celular(cliente, celular, quantidade_registros);
            if(i>quantidade_registros)
            {
                printf("\nCLIENTE NAO ENCONTRADO\n\n");
                goto selecao;
                break;
            }
            printf("\nInformacoes do cliente:\nNome: %s\nSobrenome: %s\nCelular: %d\nCPF: %lld\n\n", cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
            goto selecao;
            break;
            
        case 5:
            printf("Selecionado: Busca por CPF.\n\n");
            printf("Digite o CPF do cliente a ser encontrado:");
            scanf("%lld", &cpf);
            cliente=selection_sort(cliente, quantidade_registros);
            i=busca_cpf(cliente, cpf, quantidade_registros);
            if(i>quantidade_registros)
            {
                printf("\nCLIENTE NAO ENCONTRADO\n\n");
                goto selecao;
                break;
            }
            printf("\nInformacoes do cliente:\nNome: %s\nSobrenome: %s\nCelular: %d\nCPF: %lld\n\n", cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
            goto selecao;
            break;
        case 6:
            printf("Opcao     Nome      Sobrenome     Celular      CPF\n");
                for(i=0; i<quantidade_registros; i++)
                {
                    printf("   %d - %s  %s  %d  %lld\n", i, cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                }
            printf("\n");
            goto selecao;
            break;
        case 7:
            printf("Tem certeza que deseja sair?\nDigite 1 para confirmar ou 0 para voltar para o menu.\n");
            scanf("%d", &i);
            if(i==1)
            {
                arq_saida=fopen("arquivo de clientes.txt", "w");
                fprintf(arq_saida,"%d\n", quantidade_registros);
                for(i=0; i<quantidade_registros; i++)
                {
                    fprintf(arq_saida, "%s %s %d %lld\n", cliente.nome[i], cliente.sobrenome[i], cliente.celular[i], cliente.cpf[i]);
                }
                fclose(arq_saida);
                printf("\n\nNovo arquivo gravado com sucesso!\n\n");
                exit(0);
            }
            else
            {
                printf("Saida nao confirmada\n");
                goto selecao;
            }
            break;
        default:
            printf("\nOpcao selecionada invalida, selecione uma opcao entre as 7 disponiveis\n");
            goto selecao;
            break;
        }
    return 0;
}