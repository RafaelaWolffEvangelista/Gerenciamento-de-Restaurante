
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
        cout <<"\TProdutos: " << i+1 << ": ";
        cout<<"\nCodigo:";
        cin >>pro[i].codigo;
        if (pro[i].codigo > 0) {
            cout<<"\nDescricao:";
            cin >>pro[i].descricao;
            cout <<"\nPreco unitario ";
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

void leituraGarcom (struct Garcom gar[], int &contgar) {
    int i=0;
    for (int saida=1; i<5 && saida!=0; i++) {
        cout<<"\t---Informacoes dos Garcoes---"<<endl;
        cout<<"Codigo: "<<endl;
        cin>>gar[i].codigo;
        if (gar[i].codigo>0) {
            cout<<"Nome: "<<endl;
            cin>>gar[i].nome;
        }
        else saida=0;
    }
    contgar=i-1;
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
void mostrar_produto (struct Produto proA[], struct Categoria catA[], int contproA ) {
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i=0;i<contproA;i++) {
        cout << "\nCodigo: " << proA[i].codigo;
        cout << "\nDescricao: " << proA[i].descricao;
        cout << "\n Codigo Categoria: " << catA[i].codigo;
        cout << "\n Valor Unitario: " << proA[i].preco_unitario;

    }
}

void inclusao_ingrediente (struct Ingrediente ingS[], int contingS, struct Ingrediente ingT[], int contingT, struct Ingrediente ingA[], int &contingA, struct Produto proA[]) {
    int i=0, j=0, k=0,p=0;
    for (;i<contingS && j<contingT;k++) {
        if (ingS[i].codigo<ingT[j].codigo) {
            ingA[k].codigo=ingS[i].codigo;
            ingA[k].descricao=ingS[i].descricao;
            ingA[k].quant_estoque=ingS[i].quant_estoque;
            ingA[k].estoque_minimo=ingS[i].estoque_minimo;
            ingA[k].estoque_maximo=ingS[i].estoque_maximo;
            ingA[k].preco_unitario=proA[p].preco_unitario;
            i++;
        }
        else {
            ingA[k].codigo=ingT[j].codigo;
            ingA[k].descricao=ingT[j].descricao;
            ingA[k].quant_estoque=ingT[j].quant_estoque;
            ingA[k].estoque_minimo=ingT[j].estoque_minimo;
            ingA[k].estoque_maximo=ingT[j].estoque_maximo;
            ingA[k].preco_unitario=proA[p].preco_unitario;
            j++;
        }
    }
    while (i < contingS) {
        ingA[k].codigo=ingS[i].codigo;
        ingA[k].descricao=ingS[i].descricao;
        ingA[k].quant_estoque=ingS[i].quant_estoque;
        ingA[k].estoque_minimo=ingS[i].estoque_minimo;
        ingA[k].estoque_maximo=ingS[i].estoque_maximo;
        ingA[k].preco_unitario=proA[p].preco_unitario;
        i++;
        k++;
    }
    while (j < contingT) {
        ingA[k].codigo=ingT[j].codigo;
        ingA[k].descricao=ingT[j].descricao;
        ingA[k].quant_estoque=ingT[j].quant_estoque;
        ingA[k].estoque_minimo=ingT[j].estoque_minimo;
        ingA[k].estoque_maximo=ingT[j].estoque_maximo;
        ingA[k].preco_unitario=proA[p].preco_unitario;
        j++;
        k++;
    }
    contingA=k;
}
void mostrar_ingrediente (struct Ingrediente ingA[], struct Produto proA[], int contingA) {
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i=0;i<contingA;i++) {
        cout << "\n Codigo: "<< ingA[i].codigo;
        cout << "\n Descricao: " << ingA[i].descricao;
        cout << "\n Quantidade Estoque: " << ingA[i].quant_estoque;
        cout << "\n Quantidade Minimo: " << ingA[i].estoque_minimo;
        cout << "\n Quantidade Maximo: " << ingA[i].estoque_maximo;
        cout << "\n Preco Unitario: " << proA[i].preco_unitario;
    }
}

void inclusao_garcom(struct Garcom garS[],int contgarS,struct Garcom garT[],int contgarT,struct Garcom garA[],int &contgarA) {
    int i=0, j=0, k=0;
    for (;i<contgarS && j<contgarT;k++) {
        if (garS[i].codigo<garT[j].codigo) {
            garA[k].codigo=garS[i].codigo;
            garA[k].nome=garS[i].nome;
            i++;
        }
        else{
            garA[k].codigo=garT[j].codigo;
            garA[k].nome=garT[j].nome;
            j++;
        }
    }

    while (i<contgarS) {
        garA[k].codigo=garS[i].codigo;
        garA[k].nome=garS[i].nome;
        i++;
        k++;
    }

    while (j<contgarT) {
        garA[k].codigo=garT[j].codigo;
        garA[k].nome=garT[j].nome;
        j++;
        k++;
    }
    contgarA=k;
}

void mostrar_garcom(struct Garcom garA[], int contgarA) {
    cout << "\n\nLista dos Registros dos Garcoes Atualizada" << endl;
    for (int i=0;i<contgarA;i++) {
        cout << "\nCodigo: " << garA[i].codigo;
        cout << "\nNome: " << garA[i].nome;
    }
}


int main() {
  struct Categoria catS[20], catT[20], catA[40];
  struct Produto proS[20], proT[20], proA[40];
  struct Ingrediente ingS[20], ingT[20], ingA[40];
  struct Garcom garS[20], garT[20], garA[20];

    int contcatS,contcatT,contcatA,
        contproS,contproT,contproA,
        contingS,contingT,contingA,
        contgarS,contgarT,contgarA;

    cout<<"\n---Leitura de Categoria S---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraCategoria(catS,contcatS);

    cout<<"\n---Leitura de Categoria T---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraCategoria(catT,contcatT);

    inclusao_categoria(catS, contcatS, catT, contcatT, catA,contcatA);
    mostrar_categoria(catA, contcatA);

    cout<<"\n---Leitura de Produtos S---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraProduto(proS,contproS);

    cout<<"\n---Leitura de Produtos T---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraProduto(proT,contproT);

    inclusao_produto(catA, proS, contproS, proT, contproT, proA,contproA);
    mostrar_produto(proA, catA, contproA);

    cout<<"\n---Leitura Ingrediente S---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraIngrediente(ingS,contingS);

    cout<<"\n---Leitura Ingrediente T---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraIngrediente(ingT,contingT);

    inclusao_ingrediente(ingS, contingS, ingT,contingT, ingA,contingA, proA);
    mostrar_ingrediente(ingA,proA,contingA);

    cout<<"\n---Leitura dos Garcoes S---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraGarcom(garS, contgarS);

    cout<<"\n---Leitura do Garcoes T---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraGarcom(garT, contgarT);

    inclusao_garcom(garS,contgarS, garT, contgarT, garA,contgarA);
    mostrar_garcom(garA, contgarA);


    return 0;
}