
#include <iostream>
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

void leituraCategoria (struct Categoria c[],int&contcat) {
   int i=0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "Categoria " << i+1 << ": ";
        cout <<"Codigo: ";
        cin >>c[i].codigo;
        if (c[i].codigo > 0) {
            cout <<"Descricao: ";
            cin >> c[i].descricao;
        }
        else saida=0;
    }
   contcat = i-1;
}

void leituraProduto (struct Produto p[],int &contpro) {
   int i=0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout <<"Produtos: " << i+1 << ": ";
        cout<<"Codigo:";
        cin >>p[i].codigo;
        if (p[i].codigo > 0) {
            cout <<"Preco unitario ";
            cin >> p[i].preco_unitario;
        }
        else saida=0;
    }
    contpro = i-1;
}

void leituraIngrediente (struct Ingredientes ing[],int &conting) {
   int i=0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
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
            cin>> ing[i].estoque.maximo;
            cout<<"Preco Unitario: ";
            cin >> ing[i].preco_unitario;
        }
        else saida=0;
    }
    conting = i-1;
}




int main() {

}
