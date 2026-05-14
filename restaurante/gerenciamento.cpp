
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
void leituraCategoria (struct Categoria c[]) {
    for (int i = 0; i < 3; i++) {
        cout << "Categoria " << i+1 << ": ";
        cout <<"Codigo: ";
        cin >>c[i].codigo;
        cout <<"Descricao: ";
        cin >> c[i].descricao;
    }
}

void leituraProduto (struct Produto p[]) {
    for (int i = 0; i < 3; i++) {
        cout <<"Produtos: " << i+1 << ": ";
        cout<<"Codigo:";
        cin >>p[i].codigo;
        cout <<"Preco unitario ";
        cin >> p[i].preco_unitario;
    }
}

void leituraIngreduentente (struct Ingredientes ing[]) {
    for (int i = 0; i < 3; i++) {
        cout <<"Ingredientes: " << i+1 << ": ";
        cout<<"Codigo: ";
        cin >> ing[i].codigo;
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
}




int main() {

}
