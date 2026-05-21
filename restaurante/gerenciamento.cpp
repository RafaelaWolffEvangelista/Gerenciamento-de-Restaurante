
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

void inclusao_categoria(struct Categoria cats[],int contcats,struct Categoria catt[],int contcatt, struct Categoria cata[],int &contcata) {
int i=0,j=0,k=0;
  for (;i<contcats && j<contcatt;k++) {
      if (cats[i].codigo<catt[j].codigo) {
          cata[k].codigo=cats[i].codigo;
          cata[k].descricao= cats[i].descricao;
          i++;
      }
      else {
          cata[k].codigo=catt[j].codigo;
          cata[k].descricao= catt[j].descricao;
          j++;
      }
  }
    while (i < contcats) {
        cata[k].codigo = cats[i].codigo;
        cata[k].descricao= cats[i].descricao;
        i++;
        k++;
    }
    while (j < contcatt) {
        cata[k].codigo = catt[j].codigo;
        cata[k].descricao= catt[j].descricao;
        j++;
        k++;
    }
contcata = k;
}

void mostrar_categoria(struct Categoria cata[],int contcata) {
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i=0;i<contcata;i++) {
        cout << "\nCodigo: " << cata[i].codigo;
        cout << "\nDescricao: " << cata[i].descricao;
    }
}

void inclusao_produto(struct Categoria cata[],struct Produto pros[],int contpros,struct Produto prot[],int contprot,struct Produto proa[],int &contproa) {
  int i=0, j=0, k=0, c=0;
   for (;i<contpros && j<contprot;k++) {
       if (pros[i].codigo<prot[j].codigo) {
           proa[k].codigo=pros[i].codigo;
           proa[k].descricao=pros[i].descricao;
           proa[k].codigo_categoria=cata[c].codigo;
           proa[k].preco_unitario=pros[i].preco_unitario;
           i++;
       }
       else {
           proa[k].codigo=prot[j].codigo;
           proa[k].descricao=prot[j].descricao;
           proa[k].codigo_categoria=cata[c].codigo;
           proa[k].preco_unitario=prot[j].preco_unitario;
           j++;
       }
   }

    while (i<contpros) {
        proa[k].codigo=pros[i].codigo;
        proa[k].descricao=pros[i].descricao;
        proa[k].codigo_categoria=cata[c].codigo;
        proa[k].preco_unitario=pros[i].preco_unitario;
        i++;
        k++;
    }

    while (j<contprot) {
        proa[k].codigo=prot[j].codigo;
        proa[k].descricao=prot[j].descricao;
        proa[k].codigo_categoria=cata[c].codigo;
        proa[k].preco_unitario=prot[j].preco_unitario;
        j++;
        k++;
    }
    contproa=k;
}

int main() {
  struct Categoria cats[20], catt[20], cata[40];
  struct Produto pros[20], prot[20], proa[40];
  struct Ingrediente ings[20], ingt[20], inga[40];
  int contcats,contcatt,contcata,
      contpros,contprot,contproa,
      contings,contingt,continga;
    cout<<"Leitura de Categoria S"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraCategoria(cats,contcats);
    cout<<"Leitura de Categoria T"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraCategoria(catt,contcatt);
    inclusao_categoria(cats, contcats, catt, contcatt, cata,contcata);
    mostrar_categoria(cata, contcata);
    cout<<"Leitura de Produtos S"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraProduto(pros,contpros);
    cout<<"Leitura de Produtos T"<<endl;
    cout<<"para sair de leitura digite 0"<<endl;
    leituraProduto(prot,contprot);
   inclusao_produto(cata, pros, contpros, prot, contprot, proa,contproa);

    return 0;
}
