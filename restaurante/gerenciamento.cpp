
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

void leituraCategoria (struct Categoria cat[], int &contcat) {
    int i = 0;

    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "\n\t--- Categoria " << i+1 << " ---" << endl;

        int codigoDigitado;
        bool acheiDuplicado;


        do {
            acheiDuplicado = false;

            cout << "Digite o Codigo: ";
            cin >> codigoDigitado;

            if (i > 0 && codigoDigitado <= cat[i-1].codigo) {
                acheiDuplicado = true; // Forçamos o loop a repetir
                cout << "[AVISO] O codigo deve ser MAIOR que o anterior (" << cat[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            if (codigoDigitado <= 0) {
                saida = 0;
                break;
            }
            for (int checa = 0; checa < i; checa++) {
                if (cat[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "[AVISO] Esse codigo ja existe. Tente outro!\n\n";
                }
            }
        } while (acheiDuplicado == true);

        if (saida == 0) {
            break;
        }

        cat[i].codigo = codigoDigitado;
        cout << "Descricao: ";
        cin >> cat[i].descricao;
    }

    contcat = i;
}

void leituraProduto (struct Produto pro[], int &contpro) {
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "\n\t--- Produto " << i+1 << " ---" << endl;
        int codigoDigitado;
        bool acheiDuplicado;

        do {
            acheiDuplicado = false;
            cout << "Codigo: ";
            cin >> codigoDigitado;

            if (codigoDigitado <= 0) {
                saida = 0;
                break;
            }

            if (i > 0 && codigoDigitado <= pro[i-1].codigo) {
                acheiDuplicado = true;
                cout << "[AVISO] O codigo deve ser MAIOR que o anterior (" << pro[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            for (int checa = 0; checa < i; checa++) {
                if (pro[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "[AVISO] Esse codigo de produto ja existe. Tente outro!\n\n";
                }
            }

        } while (acheiDuplicado == true);

        if (saida == 0) break;

        pro[i].codigo = codigoDigitado;
        cout << "Descricao: ";
        cin >> pro[i].descricao;
        cout << "Preco unitario: ";
        cin >> pro[i].preco_unitario;
    }
    contpro = i;
}

void leituraIngrediente (struct Ingrediente ing[], int &conting) {
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "\n\t--- Ingrediente " << i+1 << " ---" << endl;
        int codigoDigitado;
        bool acheiDuplicado;

        do {
            acheiDuplicado = false;
            cout << "Codigo: ";
            cin >> codigoDigitado;

            if (codigoDigitado <= 0) {
                saida = 0;
                break;
            }

            if (i > 0 && codigoDigitado <= ing[i-1].codigo) {
                acheiDuplicado = true;
                cout << "[AVISO] O codigo deve ser MAIOR que o anterior (" << ing[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            for (int checa = 0; checa < i; checa++) {
                if (ing[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "[AVISO] Esse codigo de ingrediente ja existe. Tente outro!\n\n";
                }
            }

        } while (acheiDuplicado == true);

        if (saida == 0) break;

        ing[i].codigo = codigoDigitado;
        cout << "Descricao: ";
        cin >> ing[i].descricao;
        cout << "Quantidade Estoque: ";
        cin >> ing[i].quant_estoque;
        cout << "Estoque Minimo: ";
        cin >> ing[i].estoque_minimo;
        cout << "Estoque Maximo: ";
        cin >> ing[i].estoque_maximo;
        cout << "Preco Unitario: ";
        cin >> ing[i].preco_unitario;
    }
    conting = i;
}

void leituraGarcom (struct Garcom gar[], int &contgar) {
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "\n\t--- Garcom " << i+1 << " ---" << endl;
        int codigoDigitado;
        bool acheiDuplicado;

        do {
            acheiDuplicado = false;
            cout << "Codigo: ";
            cin >> codigoDigitado;

            if (codigoDigitado <= 0) {
                saida = 0;
                break;
            }

            if (i > 0 && codigoDigitado <= gar[i-1].codigo) {
                acheiDuplicado = true;
                cout << "[AVISO] O codigo deve ser MAIOR que o anterior (" << gar[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            for (int checa = 0; checa < i; checa++) {
                if (gar[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "[AVISO] Esse codigo de garcom ja existe. Tente outro!\n\n";
                }
            }

        } while (acheiDuplicado == true);

        if (saida == 0) break;

        gar[i].codigo = codigoDigitado;
        cout << "Nome: ";
        cin >> gar[i].nome;
    }
    contgar = i;
}

void inclusao_categoria(struct Categoria catS[], int contcatS, struct Categoria catT[], int contcatT, struct Categoria catA[], int &contcatA) {
    int i = 0, j = 0, k = 0;

    while (i < contcatS && j < contcatT) {
        if (catS[i].codigo < catT[j].codigo) {
            catA[k].codigo = catS[i].codigo;
            catA[k].descricao = catS[i].descricao;
            i++;
            k++;
        }
        else if (catT[j].codigo < catS[i].codigo) {
            catA[k].codigo = catT[j].codigo;
            catA[k].descricao = catT[j].descricao;
            j++;
            k++;
        }
        else {
            catA[k].codigo = catS[i].codigo;
            catA[k].descricao = catS[i].descricao;

            i++;
            j++;
            k++;
        }
    }

    while (i < contcatS) {
        catA[k].codigo = catS[i].codigo;
        catA[k].descricao = catS[i].descricao;
        i++;
        k++;
    }

    while (j < contcatT) {
        catA[k].codigo = catT[j].codigo;
        catA[k].descricao = catT[j].descricao;
        j++;
        k++;
    }

    contcatA = k;
}

void mostrar_categoria(struct Categoria catA[],int contcatA) {
    cout << "\n\nLista dos Registros na Categoria Atualizada" << endl;
    for (int i=0;i<contcatA;i++) {
        cout << "\nCodigo: " << catA[i].codigo;
        cout << "\nDescricao: " << catA[i].descricao;
    }
}

void inclusao_produto(struct Categoria catA[], struct Produto proS[], int contproS, struct Produto proT[], int contproT, struct Produto proA[], int &contproA) {
    int i = 0, j = 0, k = 0, c = 0;

    while (i < contproS && j < contproT) {
        if (proS[i].codigo < proT[j].codigo) {
            proA[k].codigo = proS[i].codigo;
            proA[k].descricao = proS[i].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proS[i].preco_unitario;
            i++;
            k++;
            c++;
        }
        else if (proT[j].codigo < proS[i].codigo) {
            proA[k].codigo = proT[j].codigo;
            proA[k].descricao = proT[j].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proT[j].preco_unitario;
            j++;
            k++;
            c++;
        }
        else {
            proA[k].codigo = proS[i].codigo;
            proA[k].descricao = proS[i].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proS[i].preco_unitario;
            i++;
            j++;
            k++;
            c++;
        }
    }

    while (i < contproS) {
        proA[k].codigo = proS[i].codigo;
        proA[k].descricao = proS[i].descricao;
        proA[k].codigo_categoria = catA[c].codigo;
        proA[k].preco_unitario = proS[i].preco_unitario;
        i++;
        k++;
        c++;
    }

    while (j < contproT) {
        proA[k].codigo = proT[j].codigo;
        proA[k].descricao = proT[j].descricao;
        proA[k].codigo_categoria = catA[c].codigo;
        proA[k].preco_unitario = proT[j].preco_unitario;
        j++;
        k++;
        c++;
    }
    contproA = k;
}

void mostrar_produto (struct Produto proA[], struct Categoria catA[], int contproA ) {
    cout << "\n\nLista de Produtos Atualizada" << endl;
    for (int i=0;i<contproA;i++) {
        cout << "\nCodigo: " << proA[i].codigo<<endl;
        cout << "\nDescricao: " << proA[i].descricao<<endl;
        cout << "\n Codigo Categoria: " << catA[i].codigo<<endl;
        cout << "\n Valor Unitario: " << proA[i].preco_unitario<<endl;

    }
}

void inclusao_ingrediente (struct Ingrediente ingS[], int contingS, struct Ingrediente ingT[], int contingT, struct Ingrediente ingA[], int &contingA, struct Produto proA[]) {
    int i = 0, j = 0, k = 0, p = 0;

    while (i < contingS && j < contingT) {
        if (ingS[i].codigo < ingT[j].codigo) {
            ingA[k].codigo = ingS[i].codigo;
            ingA[k].descricao = ingS[i].descricao;
            ingA[k].quant_estoque = ingS[i].quant_estoque;
            ingA[k].estoque_minimo = ingS[i].estoque_minimo;
            ingA[k].estoque_maximo = ingS[i].estoque_maximo;
            ingA[k].preco_unitario = proA[p].preco_unitario;
            i++;
            k++;
        }
        else if (ingT[j].codigo < ingS[i].codigo) {
            ingA[k].codigo = ingT[j].codigo;
            ingA[k].descricao = ingT[j].descricao;
            ingA[k].quant_estoque = ingT[j].quant_estoque;
            ingA[k].estoque_minimo = ingT[j].estoque_minimo;
            ingA[k].estoque_maximo = ingT[j].estoque_maximo;
            ingA[k].preco_unitario = proA[p].preco_unitario;
            j++;
            k++;
        }
        else {
            ingA[k].codigo = ingS[i].codigo;
            ingA[k].descricao = ingS[i].descricao;
            ingA[k].quant_estoque = ingS[i].quant_estoque;
            ingA[k].estoque_minimo = ingS[i].estoque_minimo;
            ingA[k].estoque_maximo = ingS[i].estoque_maximo;
            ingA[k].preco_unitario = proA[p].preco_unitario;
            i++;
            j++;
            k++;
        }
    }

    while (i < contingS) {
        ingA[k].codigo = ingS[i].codigo;
        ingA[k].descricao = ingS[i].descricao;
        ingA[k].quant_estoque = ingS[i].quant_estoque;
        ingA[k].estoque_minimo = ingS[i].estoque_minimo;
        ingA[k].estoque_maximo = ingS[i].estoque_maximo;
        ingA[k].preco_unitario = proA[p].preco_unitario;
        i++;
        k++;
    }

    while (j < contingT) {
        ingA[k].codigo = ingT[j].codigo;
        ingA[k].descricao = ingT[j].descricao;
        ingA[k].quant_estoque = ingT[j].quant_estoque;
        ingA[k].estoque_minimo = ingT[j].estoque_minimo;
        ingA[k].estoque_maximo = ingT[j].estoque_maximo;
        ingA[k].preco_unitario = proA[p].preco_unitario;
        j++;
        k++;
    }
    contingA = k;
}

void mostrar_ingrediente (struct Ingrediente ingA[], struct Produto proA[], int contingA) {
    cout << "\n\nLista de Ingredientes Atualizada" << endl;
    for (int i=0;i<contingA;i++) {
        cout << "\n Codigo: "<< ingA[i].codigo<<endl;
        cout << "\n Descricao: " << ingA[i].descricao<<endl;
        cout << "\n Quantidade Estoque: " << ingA[i].quant_estoque<<endl;
        cout << "\n Quantidade Minimo: " << ingA[i].estoque_minimo<<endl;
        cout << "\n Quantidade Maximo: " << ingA[i].estoque_maximo<<endl;
        cout << "\n Preco Unitario: " << proA[i].preco_unitario<<endl;
    }
}

void inclusao_garcom(struct Garcom garS[], int contgarS, struct Garcom garT[], int contgarT, struct Garcom garA[], int &contgarA) {
    int i = 0, j = 0, k = 0;

    while (i < contgarS && j < contgarT) {
        if (garS[i].codigo < garT[j].codigo) {
            garA[k].codigo = garS[i].codigo;
            garA[k].nome = garS[i].nome;
            i++;
            k++;
        }
        else if (garT[j].codigo < garS[i].codigo) {
            garA[k].codigo = garT[j].codigo;
            garA[k].nome = garT[j].nome;
            j++;
            k++;
        }
        else {
            garA[k].codigo = garS[i].codigo;
            garA[k].nome = garS[i].nome;
            i++;
            j++;
            k++;
        }
    }

    while (i < contgarS) {
        garA[k].codigo = garS[i].codigo;
        garA[k].nome = garS[i].nome;
        i++;
        k++;
    }

    while (j < contgarT) {
        garA[k].codigo = garT[j].codigo;
        garA[k].nome = garT[j].nome;
        j++;
        k++;
    }
    contgarA = k;
}

void mostrar_garcom(struct Garcom garA[], int contgarA) {
    cout << "\n\nLista dos Registros dos Garcoes Atualizada" << endl;
    for (int i=0;i<contgarA;i++) {
        cout << "\nCodigo: " << garA[i].codigo;
        cout << "\nNome: " << garA[i].nome;
    }
}


void exclusao_produto(struct Categoria catA[], struct Produto proS[], int contproS, struct Produto proT[], int contproT, struct Produto proA[], int &contproA, int codExclusao) {
    int i = 0, j = 0, k = 0, c = 0;

    while (i < contproS && j < contproT) {
        if (proS[i].codigo == codExclusao) {
            i++;
        }
        else if (proT[j].codigo == codExclusao) {
            j++;
        }
        else if (proS[i].codigo < proT[j].codigo) {
            proA[k].codigo = proS[i].codigo;
            proA[k].descricao = proS[i].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proS[i].preco_unitario;
            i++;
            k++;
            c++;
        }
        else if (proT[j].codigo < proS[i].codigo) {
            proA[k].codigo = proT[j].codigo;
            proA[k].descricao = proT[j].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proT[j].preco_unitario;
            j++;
            k++;
            c++;
        }
        else {
            proA[k].codigo = proS[i].codigo;
            proA[k].descricao = proS[i].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proS[i].preco_unitario;
            i++;
            j++;
            k++;
            c++;
        }
    }

    while (i < contproS) {
        if (proS[i].codigo == codExclusao) {
            i++;
        } else {
            proA[k].codigo = proS[i].codigo;
            proA[k].descricao = proS[i].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proS[i].preco_unitario;
            i++;
            k++;
            c++;
        }
    }

    while (j < contproT) {
        if (proT[j].codigo == codExclusao) {
            j++;
        } else {
            proA[k].codigo = proT[j].codigo;
            proA[k].descricao = proT[j].descricao;
            proA[k].codigo_categoria = catA[c].codigo;
            proA[k].preco_unitario = proT[j].preco_unitario;
            j++;
            k++;
            c++;
        }
    }

    contproA = k;
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

    int codLeitura=1,codExclusao=-1;

    cout<<"\n---Leitura de Categoria S---"<<endl;
    cout<<"Para sair de leitura digite 0"<<endl;
    leituraCategoria(catS,contcatS);

    cout<<"\n---Leitura de Categoria T---"<<endl;
    cout<<"Para sair de leitura digite 0"<<endl;
    leituraCategoria(catT,contcatT);

    inclusao_categoria(catS, contcatS, catT, contcatT, catA,contcatA);
    mostrar_categoria(catA, contcatA);

    cout<<"\n---Leitura de Produtos S---"<<endl;
    cout<<"Para sair de leitura digite 0"<<endl;
    leituraProduto(proS,contproS);

    cout<<"\n---Leitura de Produtos T---"<<endl;
    cout<<"Para sair de leitura digite 0"<<endl;
    leituraProduto(proT,contproT);

    inclusao_produto(catA, proS, contproS, proT, contproT, proA,contproA);
    mostrar_produto(proA, catA, contproA);

    cout<<"\t---Leitura Ingrediente S---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraIngrediente(ingS,contingS);

    cout<<"\t---Leitura Ingrediente T---"<<endl;
    cout<<"\nPara sair de leitura digite 0"<<endl;
    leituraIngrediente(ingT,contingT);

    inclusao_ingrediente(ingS, contingS, ingT,contingT, ingA,contingA, proA);
    mostrar_ingrediente(ingA,proA,contingA);

    cout<<"\n---Leitura dos Garcoes S---"<<endl;
    cout<<"Para sair de leitura digite 0"<<endl;
    leituraGarcom(garS, contgarS);

    cout<<"\n---Leitura do Garcoes T---"<<endl;
    cout<<"Para sair de leitura digite 0"<<endl;
    leituraGarcom(garT, contgarT);

    inclusao_garcom(garS,contgarS, garT, contgarT, garA,contgarA);
    mostrar_garcom(garA, contgarA);

    cout<<"\nDeseja realizar uma exclusao de um Produto?"<<endl;
    cout<<"Se sim digite 1, senao digite 0"<<endl;
    cin>>codLeitura;
    while (codLeitura==1 && codExclusao!=0) {

        if (codLeitura==1) {
            cout << "\nInforme o Codigo do Registro a ser Excluido: ";
            cin >> codExclusao;
            exclusao_produto(catA,proS, contproS, proT, contproT, proA, contproA, codExclusao);

            contproS = contproA;
            contproT = 0;

            for (int i = 0; i < contproA; i++) {
                proS[i] = proA[i];
            }

            cout << "\nDeseja realizar mais uma exclusao de um Produto?" << endl;
            cout << "Se sim digite 1, senao digite 0: ";
            cin >> codLeitura;
        }
    }

    mostrar_produto(proA, catA, contproA);

    return 0;
}