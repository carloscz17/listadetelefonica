//caso não consiga rodar por seu vsc, rode em https://www.onlinegdb.com/
#include <iostream>

using namespace std;


int cont_tam = 0;
struct agenda 
{
    string nome;
    string telefone;
    agenda * prox;
    agenda * ant;
};

void inicio(agenda *&head) 
{
    head = NULL;
}
void inserir_inicio(agenda *&head, string nome, string telefone) 
{
    agenda * novo = new agenda;
    novo->nome = nome;
    novo->telefone = telefone;
    novo->ant = NULL;
    novo->prox = NULL;

    if(head == NULL)
    {
        head = novo;
    }
    else
    {
        novo->prox = head;
        head->ant = novo;
        head = novo;

    }
}
int tamanho (agenda *head) 
{
    agenda *aux = head;
    while(aux != NULL)
    {
        cont_tam ++;
        aux = aux->prox;
    }
    return cont_tam;

}
void inserir_pos (agenda *&head, string nome, string telefone, int pos) 
{
    agenda *novo = new agenda;
    novo->nome = nome;
    novo->telefone = telefone;
    novo->ant = NULL;
    novo->prox = NULL;

    if(head == NULL && pos == 0)
    {
        head = novo;

    }
    else if(pos == 0)
    {
        head->ant = novo;
        novo->prox = head;
        head = novo;

    }

    else
    {
        int cont = 1;
        agenda *perc = head->prox;
        while (cont != pos)
        {
            cont ++;
            perc = perc->prox;
        }
        perc->ant->prox = novo;
        novo->ant = perc->ant;
        novo->prox = perc;
        perc->ant = novo;
    }
}
void inserir_fim(agenda *&head, string nome, string telefone)
{
    agenda *novo = new agenda;
    novo->nome = nome;
    novo->telefone = telefone;
    novo->ant = NULL;
    novo->prox = NULL;

    if(head == NULL)
    {
        head = novo;
    }
    else
    {
        agenda *aux = head;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }

}
void delet_ini(agenda *&head) 
{
    if(head == NULL)
    {
        cout<<"Lista NULA";

    }
    else if(head->prox == NULL)
    {
        delete head;
        head = NULL;
        cout<<"2 IF AQUI";
    }
    else
    {
        head = head->prox;
        delete head->ant;
        head->ant = NULL;
        cout<<"ELSE AQUI";
        printf("\n");
    }
}
void delet_fim(agenda *&head) 
{
    agenda *aux = head;

    if(head == NULL)
    {
        cout<<"Não foi possível excluir o contato\n";
    }
    else if(head->prox == NULL)
    {
        delete head;
        head = NULL;
        cout<<"Lista vazia";
    }
    else
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
    aux->ant->prox = NULL;
    delete aux;
}
void remover_pos(agenda *&head, int pos) 
{

    if(head->prox == NULL)
    {
        delete head;
        head = NULL;
        cout<<"Contato deletado com sucesso!";
    }
    else if (pos == 0)
    {
        head = head->prox;
        delete head->ant;
        head->ant = NULL;
        cout<<"Contato deletado com sucesso!";
    }
    else
    {
        int cont = 0;
        agenda *perc = head;
        while (cont != pos)
        {
            cont++;
            perc = perc->prox;
        }
        agenda *aux = perc->prox;
        aux->ant = perc -> ant;
        perc->ant->prox = aux;
        delete perc;
        cout<<"Contato deletado com sucesso!";
    }

}
void remover_repetidos(agenda *& head)  
{
    agenda *perc = head;
    while(perc != NULL)
    {
        agenda *aux = perc->prox;
        while(aux != NULL)
        {
            if(perc->telefone == aux->telefone)
            {
                if(perc->ant != NULL)
                {
                    aux->ant->ant = perc->ant;
                    perc->ant->prox = aux->ant;
                    head = perc->ant;
                    delete perc;
                    break;
                }

                head = perc->prox;
                delete perc;
                head->ant = NULL;
                break;


            }
            aux = aux->prox;
        }
        perc = perc->prox;
    }
}

void buscar_contato(agenda *head, string nome)
{
    agenda *perc = head;
    bool valida = false;
    while(perc!=NULL)
    {
        if(nome == perc->nome)
        {
            valida = true;
            cout<<"Nome ["<<perc->nome <<"] \t "<< "Numero [" <<perc->telefone<<"] \n";
        }
        perc = perc->prox;
    }
    if(valida == false)
    {
        cout<<"O nome não foi encontrado!";
    }
}
int imprimir_total(agenda *head)
{
    agenda *perc = head;
    int cont = 0;
    if(head == NULL)
    {
        return cont;
    }
    while(perc != NULL)
    {
        cont++;
        perc = perc->prox;
    }
    return cont;
}
void imprimir(agenda *head) 
{
    if(head == NULL)
    {
        cout<<"Contato inexistentes!";
    }
    else
    {
        agenda * aux = head;
        while(aux!=NULL)
        {
            cout<<"Nome ["<<aux->nome <<"] \t "<< "Numero [" <<aux->telefone<<"] \n";
            aux = aux->prox;
        }
    }
}

int main()
{

    agenda *head;
    inicio(head);
    int op = 0, retorno = -1;
    char letra;
    string nome, esco, telefone;



    do 
    {
        do 
        {
            cout<<"\n===============MENU===============\n=[1] Adicionar um contato no início da lista;\n=[2] Adicionar contato no final da lista;\n=[3] Adicionar em uma posição desejada;\n=[4] Remover o primeiro contato inserido;\n=[5] Remover o último contato inserido;\n=[6] Remover contato de uma posição desejada;\n=[7] Buscar um contato\n=[8] Listar os contatos;\n=[9] Sair\n===============MENU===============\n-Qual a sua escolha? ";
            retorno = scanf("%d", &op);
            do 
            {
                letra = getchar();
            }
            while(letra != '\n');
            
        }
        while(retorno == 0);
        if(op == 1)
        {
            cout<<"Nome: ";
            cin>>nome;
            cout<<"Telefone: ";
            cin>>telefone;
            inserir_inicio(head, nome, telefone);
            cout<<"\nContato salvo com Sucesso!";

        }
        else if(op == 2)
        {
            cout<<"Nome: ";
            cin>>nome;
            cout<<"Telefone: ";
            cin>>telefone;
            inserir_fim(head, nome, telefone);
            cout<<"\nContato salvo com Sucesso!";

        }
        else if(op == 3)
        {
            cout<<"Nome: ";
            cin>>nome;
            cout<<"Telefone: ";
            cin>>telefone;
            int posi = -1;
            cout<<"Informe a posição da lista: ";
            cin>>posi;
            while(posi > tamanho(head) || posi < 0)
            {
                cout<<"Posição inválida, informe uma posição diferente: ";
                cin>>posi;
            }
            cout<<"\nContato salvo com sucesso!";
            inserir_pos(head, nome, telefone, posi);

        }

        else
        {

            if(op == 4)
            {
                delet_ini(head);
            }
            else if(op == 5)
            {
                delet_fim(head);
            }
            else if(op == 6)
            {
                int posi = 0;
                cout<<"Informe a posição da lista: ";
                cin>>posi;
                while(posi > tamanho(head) || posi < 0)
                {
                    cout<<"Posição inválida, informe uma posição diferente: ";
                    cin>>posi;
                }
                remover_pos(head, posi);
            }
            else if(op == 7)
            {
                string nome = " ";
                cout<<"Digite o nome do contato que deseja encontrar: ";
                cin>>nome;
                buscar_contato(head, nome);
            }
            else if(op == 8)
            {
                imprimir(head);
            }
        }

    }

    while(op != 9);
    printf("\n");
    remover_repetidos(head);
    imprimir(head);
    cout<<"Número total de contatos: "<<imprimir_total(head)<<"\n";
}