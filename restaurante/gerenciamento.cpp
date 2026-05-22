
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Categoria {
    int codigo;
    string descricao;
};

struct Produto {
    int codigo;
    string descricao;
    int codigo_categoria;
    float preco_unitario;
};

struct Ingrediente {
    int codigo;
    string descricao;
    int quant_estoque;
    int estoque_minimo;
    int estoque_maximo;
    float preco_unitario;
};

struct Cliente {
    int codigo;
    string nome;
    int telefone;
};

struct Garcom {
    int codigo;
    string nome;
};

struct Pedidos {
    int codigo;
    int codigo_cliente;
    int codigo_garcom;
    string data;
};

struct Itens_Pedidos {
    int codigo_pedido;
    int codigo_produto;
    int qunatidade;
};

struct Consumo_Ingrediente {
    int codigo_produto;
    int codigo_ingrediente;
    int quant_necessaria;
};

void leituraCategoria (struct Categoria cat[],int&contcat) {
   int i=0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "Categoria " << i+1 << ": ";
        cout <<"Codigo: ";
        cin >>cat[i].codigo;
        if (cat[i].codigo > 0) {
            cout <<"Descricao: ";
            cin >> cat[i].descricao;
        }
        else saida=0;
    }
   contcat = i-1;
}

void leituraProduto (struct Produto pro[],int &contpro) {
   int i=0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout <<"Produtos: " << i+1 << ": ";
        cout<<"Codigo:";
        cin >>pro[i].codigo;
        if (pro[i].codigo > 0) {
            cout <<"Preco unitario ";
            cin >> pro[i].preco_unitario;
        }
        else saida=0;
    }
    contpro = i-1;
}

void leituraIngrediente (struct Ingrediente ing[],int &conting) {
    int i=0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout <<"Ingredientes: " << i+1 << ": ";
        cout<<"Codigo: ";
        cin >> ing[i].codigo;
        if (ing[i].codigo > 0) {
            cout <<"Descricao: ";
            cin >> ing[i].descricao;
            cout<<"Quantidade Estoque: ";
            cin >>ing[i].quant_estoque;
            cout<<"Estoque Minimo: ";
            cin >> ing[i].estoque_minimo;
            cout<<"Estoque Maximo: ";
            cin>> ing[i].estoque_maximo;
            cout<<"Preco Unitario: ";
            cin >> ing[i].preco_unitario;
        }
        else saida=0;
    }
    conting = i-1;
}

void inclusao_categoria(struct Categoria catS[],int contcatS,struct Categoria catT[],int contcatT, struct Categoria catA[],int &contcatA) {
int i=0,j=0,k=0;
  for (;i<contcatS && j<contcatT;k++) {
      if (catS[i].codigo<catT[j].codigo) {
          catA[k].codigo=catS[i].codigo;
          catA[k].descricao= catS[i].descricao;
          i++;
      }
      else {
          catA[k].codigo=catT[j].codigo;
          catA[k].descricao= catT[j].descricao;
          j++;
      }
  }
    while (i < contcatS) {
        catA[k].codigo = catS[i].codigo;
        catA[k].descricao= catS[i].descricao;
        i++;
        k++;
    }
    while (j < contcatT) {
        catA[k].codigo = catT[j].codigo;
        catA[k].descricao= catT[j].descricao;
        j++;
        k++;
    }
contcatA = k;
}

void mostrar_categoria(struct Categoria catA[],int contcatA) {
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i=0;i<contcatA;i++) {
        cout << "\nCodigo: " << catA[i].codigo;
        cout << "\nDescricao: " << catA[i].descricao;
    }
}

void inclusao_produto(struct Categoria catA[],struct Produto proS[],int contproS,struct Produto proT[],int contproT,struct Produto proA[],int &contproA) {
  int i=0, j=0, k=0, c=0;
   for (;i<contproS && j<contproT;k++) {
       if (proS[i].codigo<proT[j].codigo) {
           proA[k].codigo=proS[i].codigo;
           proA[k].descricao=proS[i].descricao;
           proA[k].codigo_categoria=catA[c].codigo;
           proA[k].preco_unitario=proS[i].preco_unitario;
           i++;
       }
       else {
           proA[k].codigo=proT[j].codigo;
           proA[k].descricao=proT[j].descricao;
           proA[k].codigo_categoria=catA[c].codigo;
           proA[k].preco_unitario=proT[j].preco_unitario;
           j++;
       }
   }

    while (i<contproS) {
        proA[k].codigo=proS[i].codigo;
        proA[k].descricao=proS[i].descricao;
        proA[k].codigo_categoria=catA[c].codigo;
        proA[k].preco_unitario=proS[i].preco_unitario;
        i++;
        k++;
    }

    while (j<contproT) {
        proA[k].codigo=proT[j].codigo;
        proA[k].descricao=proT[j].descricao;
        proA[k].codigo_categoria=catA[c].codigo;
        proA[k].preco_unitario=proT[j].preco_unitario;
        j++;
        k++;
    }
    contproA=k;
}

int main() {
  struct Categoria catS[20], catT[20], catA[40];
  struct Produto proS[20], proT[20], proA[40];
  struct Ingrediente ingS[20], ingT[20], ingA[40];
  struct Garcom garS[20], garT[20], garA[20];
  int contcatS,contcatT,contcatA,
      contproS,contproT,contproA,
      contingS,contingT,contingA;
    cout<<"\T---Leitura de Categoria S---"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraCategoria(catS,contcatS);
    cout<<"\T---Leitura de Categoria T---"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraCategoria(catT,contcatT);
    inclusao_categoria(catS, contcatS, catT, contcatT, catA,contcatA);
    mostrar_categoria(catA, contcatA);
    cout<<"\T---Leitura de Produtos S---"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraProduto(proS,contproS);
    cout<<"\T---Leitura de Produtos T---"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraProduto(proT,contproT);
   inclusao_produto(catA, proS, contproS, proT, contproT, proA,contproA);

    //fazer o mostrar de produto, leitura no main de ingrediente,inclusao ingrediente e mostrar ingrediente

    return 0;
}
