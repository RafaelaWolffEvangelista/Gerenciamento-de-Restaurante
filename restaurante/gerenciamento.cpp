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
                acheiDuplicado = true;
                cout << "O codigo deve ser MAIOR que o anterior (" << cat[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            if (codigoDigitado <= 0) {
                saida = 0;
                break;
            }
            for (int checa = 0; checa < i; checa++) {
                if (cat[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "Esse codigo ja existe. Tente outro!\n\n";
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

void lecturaProduto (struct Produto pro[], int &contpro) {
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
                cout << "O codigo deve ser MAIOR que o anterior (" << pro[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            for (int checa = 0; checa < i; checa++) {
                if (pro[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "Esse codigo de produto ja existe. Tente outro!\n\n";
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
                cout << "O codigo deve ser MAIOR que o anterior (" << ing[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            for (int checa = 0; checa < i; checa++) {
                if (ing[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "Esse codigo de ingrediente ja existe. Tente outro!\n\n";
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
                cout << "O codigo deve ser MAIOR que o anterior (" << gar[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            for (int checa = 0; checa < i; checa++) {
                if (gar[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "Esse codigo de garcom ja existe. Tente outro!\n\n";
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

void leituraCliente (struct Cliente cli[], int &contcli) {
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "\n\t--- Cliente " << i+1 << " ---" << endl;
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

            if (i > 0 && codigoDigitado <= cli[i-1].codigo) {
                acheiDuplicado = true;
                cout << "O codigo deve ser MAIOR que o anterior (" << cli[i-1].codigo << ") para manter a fila ordenada!\n\n";
            }

            for (int checa = 0; checa < i; checa++) {
                if (cli[checa].codigo == codigoDigitado) {
                    acheiDuplicado = true;
                    cout << "Esse codigo de garcom ja existe. Tente outro!\n\n";
                }
            }

        } while (acheiDuplicado == true);

        if (saida == 0) break;

        cli[i].codigo = codigoDigitado;
        cout << "Nome: ";
        cin >> cli[i].nome;
        cout << "Telefone: ";
        cin >> cli[i].telefone;
    }
    contcli = i;
}

void leituraConsumoIngrediente(struct Consumo_Ingrediente cons[], int &contcons) {
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "\n\t--- Consumo Ingrediente " << i+1 << " ---" << endl;
        int codigoProdutoDigitado;

        cout << "Codigo do Produto: ";
        cin >> codigoProdutoDigitado;

        if (codigoProdutoDigitado <= 0) {
            saida = 0;
            break;
        }

        cons[i].codigo_produto = codigoProdutoDigitado;
        cout << "Codigo do Ingrediente: ";
        cin >> cons[i].codigo_ingrediente;
        cout << "Quantidade Necessaria: ";
        cin >> cons[i].quant_necessaria;
    }
    contcons = i;
}

void leituraItensPedidos(struct Itens_Pedidos itens[], int &contitens) {
    int i = 0;
    for (int saida = 1; i < 5 && saida != 0; i++) {
        cout << "\n\t--- Item do Pedido " << i+1 << " ---" << endl;
        int codigoPedidoDigitado;

        cout << "Codigo do Pedido: ";
        cin >> codigoPedidoDigitado;

        if (codigoPedidoDigitado <= 0) {
            saida = 0;
            break;
        }

        itens[i].codigo_pedido = codigoPedidoDigitado;
        cout << "Codigo do Produto: ";
        cin >> itens[i].codigo_produto;
        cout << "Quantidade: ";
        cin >> itens[i].qunatidade;
    }
    contitens = i;
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
    for (int i=0;i<contcatA;i++) {
    cout << "\n\nLista de Categoria Atualizada" << endl;
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
    for (int i=0;i<contproA;i++) {
    cout << "\n\nLista de Produtos Atualizada" << endl;
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
    for (int i=0;i<contingA;i++) {
    cout << "\n\nLista de Ingredientes Atualizada" << endl;
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
    for (int i=0;i<contgarA;i++) {
    cout << "\n\nLista de Garcoes Atualizada" << endl;
        cout << "\nCodigo: " << garA[i].codigo;
        cout << "\nNome: " << garA[i].nome;
    }
}

void inclusao_cliente(struct Cliente cliS[], int contcliS, struct Cliente cliT[], int contcliT, struct Cliente cliA[], int &contcliA) {
    int i = 0, j = 0, k = 0;

    while (i < contcliS && j < contcliT) {
        if (cliS[i].codigo < cliT[j].codigo) {
            cliA[k].codigo = cliS[i].codigo;
            cliA[k].nome = cliS[i].nome;
            cliA[k].telefone = cliS[i].telefone;
            i++;
            k++;
        }
        else if (cliT[j].codigo < cliS[i].codigo) {
            cliA[k].codigo = cliT[j].codigo;
            cliA[k].nome = cliT[j].nome;
            cliA[k].telefone = cliT[j].telefone;
            j++;
            k++;
        }
        else {
            cliA[k].codigo = cliS[i].codigo;
            cliA[k].nome = cliS[i].nome;
            cliA[k].telefone = cliS[i].telefone;
            i++;
            j++;
            k++;
        }
    }

    while (i < contcliS) {
        cliA[k].codigo = cliS[i].codigo;
        cliA[k].nome = cliS[i].nome;
        cliA[k].telefone = cliS[i].telefone;
        i++;
        k++;
    }

    while (j < contcliT) {
        cliA[k].codigo = cliT[j].codigo;
        cliA[k].nome = cliT[j].nome;
        cliA[k].telefone = cliT[j].telefone;
        j++;
        k++;
    }
    contcliA = k;
}

void mostrar_cliente(struct Cliente cliA[], int contcliA) {
    for (int i=0;i<contcliA;i++) {
        cout << "\n\nLista de Clientes Atualizada" << endl;
        cout << "\nCodigo: " << cliA[i].codigo;
        cout << "\nNome: " << cliA[i].nome;
        cout << "\nTelefone: " << cliA[i].telefone;
    }
}

void inclusao_consumo_ingrediente(struct Consumo_Ingrediente consS[], int contconsS, struct Consumo_Ingrediente consT[], int contconsT, struct Consumo_Ingrediente consA[], int &contconsA) {
    int i = 0, j = 0, k = 0;

    while (i < contconsS && j < contconsT) {
        if (consS[i].codigo_produto < consT[j].codigo_produto) {
            consA[k] = consS[i];
            i++;
            k++;
        } else if (consT[j].codigo_produto < consS[i].codigo_produto) {
            consA[k] = consT[j];
            j++;
            k++;
        } else {
            consA[k] = consS[i];
            i++;
            j++;
            k++;
        }
    }
    while (i < contconsS) {
        consA[k] = consS[i];
        i++;
        k++;
    }
    while (j < contconsT) {
        consA[k] = consT[j];
        j++;
        k++;
    }
    contconsA = k;
}

void inclusao_itens_pedidos(struct Itens_Pedidos itensS[], int contitensS, struct Itens_Pedidos itensT[], int contitensT, struct Itens_Pedidos itensA[], int &contitensA) {
    int i = 0, j = 0, k = 0;

    while (i < contitensS && j < contitensT) {
        if (itensS[i].codigo_pedido < itensT[j].codigo_pedido) {
            itensA[k] = itensS[i];
            i++;
            k++;
        } else if (itensT[j].codigo_pedido < itensS[i].codigo_pedido) {
            itensA[k] = itensT[j];
            j++;
            k++;
        } else {
            itensA[k] = itensS[i];
            i++;
            j++;
            k++;
        }
    }
    while (i < contitensS) {
        itensA[k] = itensS[i];
        i++;
        k++;
    }
    while (j < contitensT) {
        itensA[k] = itensT[j];
        j++;
        k++;
    }
    contitensA = k;
}

void exclusao_produto(struct Categoria catA[], struct Produto proS[], int contproS, struct Produto proT[], int contproT, struct Produto proA[], int &contproA, int &codExclusao) {
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

void criar_pedido(struct Pedidos pedA[], int &contpedA, struct Cliente cliA[], int contcliA, struct Garcom garA[], int contgarA, int &pedidoAtual) {
    int codPed, codCli, codGar;
    string dataPed;
    bool achouCli = false, achouGar = false;

    cout << "\nDigite o codigo do novo pedido: ";
    cin >> codPed;

    for (int i = 0; i < contpedA; i++) {
        if (pedA[i].codigo == codPed) {
            cout << "Esse codigo de pedido ja existe!\n";
            return;
        }
    }

    cout << "Digite o codigo do cliente: ";
    cin >> codCli;

    for (int i = 0; i < contcliA; i++) {
        if (cliA[i].codigo == codCli) {
            cout << "Cliente encontrado: " << cliA[i].nome << endl;
            achouCli = true;
            break;
        }
    }

    if (achouCli==false) {
        cout << "Cliente nao cadastrado!\n";
        return;
    }

    cout << "Digite o codigo do garcom: ";
    cin >> codGar;

    for (int i = 0; i < contgarA; i++) {
        if (garA[i].codigo == codGar) {
            cout << "Garcom encontrado: " << garA[i].nome << endl;
            achouGar = true;
            break;
        }
    }

    if (achouGar==false) {
        cout << "Garcom nao cadastrado!\n";
        return;
    }

    cout << "Digite a data (DD/MM/AAAA): ";
    cin >> dataPed;

    pedA[contpedA].codigo = codPed;
    pedA[contpedA].codigo_cliente = codCli;
    pedA[contpedA].codigo_garcom = codGar;
    pedA[contpedA].data = dataPed;

    pedidoAtual = codPed;
    contpedA++;
    cout << "Pedido criado. Agora adicione um produto!\n";
}

void adicionar_produto_pedido(struct Itens_Pedidos itensA[], int &contitensA, struct Produto proA[], int contproA, struct Consumo_Ingrediente consA[], int contconsA, struct Ingrediente ingA[], int contingA, int pedidoAtual) {

    if (pedidoAtual == -1) {
        cout << "Nenhum pedido esta ativo no momento. Crie um pedido primeiro!\n";
        return;
    }

    for (int i = 0; i < contitensA; i++) {
        if (itensA[i].codigo_pedido == pedidoAtual) {
            cout << "Conforme regra 5.3, este pedido ja possui um produto adicionado!\n";
            return;
        }
    }

    int codPro, quantPro;
    cout << "\nDigite o codigo do produto: ";
    cin >> codPro;

    int indPro = -1;
    for (int i = 0; i < contproA; i++) {
        if (proA[i].codigo == codPro) {
            indPro = i;
            break;
        }
    }

    if (indPro == -1) {
        cout << "Produto nao cadastrado!\n";
        return;
    }

    cout << "Produto: " << proA[indPro].descricao << " | Preco Unitario: " << proA[indPro].preco_unitario << endl;
    cout << "Digite a quantidade: ";
    cin >> quantPro;

    for (int i = 0; i < contconsA; i++) {
        if (consA[i].codigo_produto == codPro) {
            int codIng = consA[i].codigo_ingrediente;
            int totalNecessario = consA[i].quant_necessaria * quantPro;
            int indIng = -1;

            for (int j = 0; j < contingA; j++) {
                if (ingA[j].codigo == codIng) {
                    indIng = j;
                    break;
                }
            }

            if (indIng == -1 || ingA[indIng].quant_estoque < totalNecessario) {
                cout << "Inclusao nao permitida. Estoque insuficiente ou ingrediente nao encontrado!\n";
                return;
            }

            cout << "Ingrediente: " << ingA[indIng].descricao << " | Necessario: " << totalNecessario << "\n";
        }
    }

    for (int i = 0; i < contconsA; i++) {
        if (consA[i].codigo_produto == codPro) {
            int codIng = consA[i].codigo_ingrediente;
            int totalNecessario = consA[i].quant_necessaria * quantPro;

            for (int j = 0; j < contingA; j++) {
                if (ingA[j].codigo == codIng) {
                    ingA[j].quant_estoque -= totalNecessario;
                    break;
                }
            }
        }
    }

    itensA[contitensA].codigo_pedido = pedidoAtual;
    itensA[contitensA].codigo_produto = codPro;
    itensA[contitensA].qunatidade = quantPro;
    contitensA++;

    cout << "Produto adicionado com sucesso ao pedido!\n";
}

void consultar_ingrediente(struct Ingrediente ingA[], int contingA) {
    int codIng;
    bool achouIng = false;

    cout << "\nDigite o codigo do ingrediente para consulta: ";
    cin >> codIng;

    for (int i = 0; i < contingA; i++) {
        if (ingA[i].codigo == codIng) {
            cout << "\n--- DADOS DO INGREDIENTE ---" << endl;
            cout << "Codigo: " << ingA[i].codigo << endl;
            cout << "Descricao: " << ingA[i].descricao << endl;
            cout << "Quantidade em Estoque: " << ingA[i].quant_estoque << endl;
            cout << "Estoque Minimo: " << ingA[i].estoque_minimo << endl;
            cout << "Estoque Maximo: " << ingA[i].estoque_maximo << endl;
            cout << "Preco Unitario: " << ingA[i].preco_unitario << endl;
            cout << "Valor Total em Estoque: " << (ingA[i].quant_estoque * ingA[i].preco_unitario) << endl;
            achouIng = true;
            break;
        }
    }

    if (achouIng==false) {
        cout << "Ingrediente nao encontrado!\n";
    }
}

void relatorio_estoque_minimo(struct Ingrediente ingA[], int contingA) {
    float totalGeralReposicao = 0;
    bool estoqueBaixo = false;

    cout << "\n--- Ingredientes abaixo do estoque minimo ---" << endl;

    for (int i = 0; i < contingA; i++) {
        if (ingA[i].quant_estoque < ingA[i].estoque_minimo) {
            estoqueBaixo = true;
            int quantComprar = ingA[i].estoque_maximo - ingA[i].quant_estoque;
            float valorCompra = quantComprar * ingA[i].preco_unitario;
            totalGeralReposicao += valorCompra;

            cout << "\nCodigo: " << ingA[i].codigo << endl;
            cout << "Descricao: " << ingA[i].descricao << endl;
            cout << "Quantidade em estoque: " << ingA[i].quant_estoque << endl;
            cout << "Estoque maximo: " << ingA[i].estoque_maximo << endl;
            cout << "Quantidade a ser comprada: " << quantComprar << endl;
            cout << "Valor da compra: " << valorCompra << endl;
            cout << "------------------------------------------" << endl;
        }
    }

    if (estoqueBaixo==false) {
        cout << "Nenhum ingrediente esta abaixo do estoque minimo.\n";
    } else {
        cout << "\nValor total a ser gasto na reposicao: " << totalGeralReposicao << endl;
    }
}

void calcular_arrecadacao_pedidos(struct Itens_Pedidos itensA[], int contitensA, struct Produto proA[], int contproA) {
    float totalArrecadado = 0;

    for (int i = 0; i < contitensA; i++) {
        int codPro = itensA[i].codigo_produto;
        float precoUn = 0;

        for (int j = 0; j < contproA; j++) {
            if (proA[j].codigo == codPro) {
                precoUn = proA[j].preco_unitario;
                break;
            }
        }

        totalArrecadado += (itensA[i].qunatidade * precoUn);
    }

    cout << "VALOR TOTAL ARRECADADO COM TODOS OS PEDIDOS: " << totalArrecadado << endl;
}

void mostrar_pedidos(struct Pedidos pedA[], int contpedA) {
    for (int i = 0; i < contpedA; i++) {
        cout << "\nPedido Codigo: " << pedA[i].codigo << endl;
        cout << "Codigo Cliente: " << pedA[i].codigo_cliente << endl;
        cout << "Codigo Garcom: " << pedA[i].codigo_garcom << endl;
        cout << "Data: " << pedA[i].data << endl;

    }
}

void mostrar_itens_pedidos(struct Itens_Pedidos itensA[], int contitensA) {
    for (int i = 0; i < contitensA; i++) {
        cout << "\nPedido Codigo: " << itensA[i].codigo_pedido << endl;
        cout << "Codigo Produto: " << itensA[i].codigo_produto << endl;
        cout << "Quantidade: " << itensA[i].qunatidade << endl;
    }
}

void mostrar_consumo_ingredientes(struct Consumo_Ingrediente consA[], int contconsA) {
    for (int i = 0; i < contconsA; i++) {
        cout << "\nCodigo Produto: " << consA[i].codigo_produto << endl;
        cout << "Codigo Ingrediente: " << consA[i].codigo_ingrediente << endl;
        cout << "Quantidade Necessaria: " << consA[i].quant_necessaria << endl;
    }
}

int main() {
  struct Categoria catS[20], catT[20], catA[40];
  struct Produto proS[20], proT[20], proA[40];
  struct Ingrediente ingS[20], ingT[20], ingA[40];
  struct Garcom garS[20], garT[20], garA[20];
  struct Cliente cliS[20],cliT[20], cliA[40];

  struct Consumo_Ingrediente consS[20], consT[20], consA[40];
  struct Itens_Pedidos itensS[20], itensT[20], itensA[40];
  struct Pedidos pedA[40];

  int contcatS=0,contcatT=0,contcatA=0,
      contproS=0,contproT=0,contproA=0,
      contingS=0,contingT=0,contingA=0,
      contgarS=0,contgarT=0,contgarA=0,
      contcliS=0,contcliT=0,contcliA=0,
      contconsS=0,contconsT=0,contconsA=0,
      contitensS=0,contitensT=0,contitensA=0,
      contpedA=0;

    int codLeitura=1,codExclusao=0,codCliente,codGarcom;
    int pedidoAtual = -1;

    int escolha_principal, escolha_cadastro,
    escolha_pedido, escolha_cosulta;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1 - Cadastro\n";
        cout << "2 - Exclusao\n";
        cout << "3 - Novo Pedido\n";
        cout << "4 - Consultas\n";
        cout << "5 - Registros\n";
        cout << "0 - Sair\n";
        cin >> escolha_principal;

        switch (escolha_principal) {

            case 1:
              cout << "\n==== MENU CADASTRO ====\n";
              cout << "1 - Nova Categoria\n";
              cout << "2 - Novo Produto\n";
              cout << "3 - Novo Ingrediente\n";
              cout << "4 - Novo Garcom\n";
              cout << "5 - Novo Cliente\n";
              cout << "6 - Novo Consumo de Ingrediente\n";
              cout << "7 - Novo Item do Pedido\n";
              cout << "0 - Voltar\n";
              cin >> escolha_cadastro;

                switch (escolha_cadastro) {

                    case 1:
                        cout<<"\n---Leitura de Categoria S---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraCategoria(catS,contcatS);

                        cout<<"\n---Leitura de Categoria T---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraCategoria(catT,contcatT);

                        inclusao_categoria(catS, contcatS, catT, contcatT, catA,contcatA);
                        break;

                    case 2:
                        cout<<"\n---Leitura de Produtos S---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        lecturaProduto(proS,contproS);

                        cout<<"\n---Leitura de Produtos T---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        lecturaProduto(proT,contproT);

                        inclusao_produto(catA, proS, contproS, proT, contproT, proA,contproA);

                        break;

                    case 3:
                        cout<<"\t---Leitura Ingrediente S---"<<endl;
                        cout<<"\nPara sair de leitura digite 0"<<endl;
                        leituraIngrediente(ingS,contingS);

                        cout<<"\t---Leitura Ingrediente T---"<<endl;
                        cout<<"\nPara sair de leitura digite 0"<<endl;
                        leituraIngrediente(ingT,contingT);

                        inclusao_ingrediente(ingS, contingS, ingT,contingT, ingA,contingA, proA);

                        break;

                    case 4:
                        cout<<"\n---Leitura dos Garcoes S---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraGarcom(garS, contgarS);

                        cout<<"\n---Leitura do Garcoes T---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraGarcom(garT, contgarT);

                        inclusao_garcom(garS,contgarS, garT, contgarT, garA,contgarA);
                        break;

                    case 5:
                        cout<<"\n---Leitura dos Clientes S---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraCliente(cliS, contcliS);

                        cout<<"\n---Leitura do Clientes T---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraCliente(cliT, contcliT);

                        inclusao_cliente(cliS,contcliS, cliT, contcliT, cliA,contcliA);
                        break;

                    case 6:
                        cout<<"\n---Leitura do Consumo S---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraConsumoIngrediente(consS, contconsS);

                        cout<<"\n---Leitura do Consumo T---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraConsumoIngrediente(consT, contconsT);

                        inclusao_consumo_ingrediente(consS, contconsS, consT, contconsT, consA, contconsA);
                        break;

                    case 7:
                        cout<<"\n---Leitura dos Itens S---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraItensPedidos(itensS, contitensS);

                        cout<<"\n---Leitura dos Itens T---"<<endl;
                        cout<<"Para sair de leitura digite 0"<<endl;
                        leituraItensPedidos(itensT, contitensT);

                        inclusao_itens_pedidos(itensS, contitensS, itensT, contitensT, itensA, contitensA);
                        break;

                    case 0:
                        break;
                }
                break;

            case 2:
                codLeitura = 1;
                do{
                    if (codLeitura==1) {
                        cout << "\nInforme o Codigo de Registro do Produto a ser Excluido: ";
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
                }  while (codLeitura!=0);
                break;

            case 3:
                do {
                    cout << "\n=== PEDIDOS ===\n";
                    cout << "1 - Criar Pedido\n";
                    cout << "2 - Adicionar Produto ao Pedido\n";
                    cout << "3 - Finalizar Pedido\n";
                    cout << "0 - Voltar\n";
                    cin >> escolha_pedido;

                    switch(escolha_pedido) {
                        case 1:
                            criar_pedido(pedA, contpedA, cliA, contcliA, garA, contgarA, pedidoAtual);
                            break;
                        case 2:
                            adicionar_produto_pedido(itensA, contitensA, proA, contproA, consA, contconsA, ingA, contingA, pedidoAtual);
                            break;
                        case 3:
                            if (pedidoAtual != -1) {
                                cout << "Pedido " << pedidoAtual << " finalizado com sucesso!\n";
                                pedidoAtual = -1;
                            } else {
                                cout << "Nao ha nenhum pedido ativo para finalizar.\n";
                            }
                            break;
                        case 0:
                            break;
                    }
                } while (escolha_pedido != 0);
                break;

            case 4:
                do {
                    cout << "\n=== CONSULTAS ===\n";
                    cout << "1 - Funcionarios (Garcons)\n";
                    cout << "2 - Clientes\n";
                    cout << "3 - Determinado Ingrediente\n";
                    cout << "4 - Ingredientes Abaixo do Minimo\n";
                    cout << "5 - Valor Total Arrecadado\n";
                    cout << "0 - Voltar\n";
                    cin >> escolha_cosulta;

                    switch(escolha_cosulta) {
                        case 1: {
                            int i;
                            bool achouGarcom = false;
                            cout<<"Codigo do Garcom: "<<endl;
                            cin>>codGarcom;

                            for ( i = 0; i < contgarA; i++) {
                                if (codGarcom==garA[i].codigo) {
                                    cout<< "Nome: "<<garA[i].nome<<endl;
                                    achouGarcom = true;
                                    break;
                                }
                            }
                            if(achouGarcom==false) {
                                cout<<"Codigo incorreto"<<endl;
                            }
                            break;
                        }
                        case 2: {
                            int i;
                            bool achouCliente = false;
                            cout<<"Codigo do Cliente: "<<endl;
                            cin>>codCliente;

                            for ( i = 0; i < contcliA; i++) {
                                if (codCliente==cliA[i].codigo) {
                                    cout<< "Nome: "<<cliA[i].nome<<endl;
                                    achouCliente = true;
                                    break;
                                }
                            }
                            if(achouCliente==false) {
                                cout<<"Codigo incorreto"<<endl;
                            }
                            break;
                        }
                        case 3:
                            consultar_ingrediente(ingA, contingA);
                            break;
                        case 4:
                            relatorio_estoque_minimo(ingA, contingA);
                            break;
                        case 5:
                            calcular_arrecadacao_pedidos(itensA, contitensA, proA, contproA);
                            break;
                        case 0:
                            break;
                    }
                } while (escolha_cosulta != 0);
                break;

            case 5:
                cout << "==== MENU REGISTROS ====\n" << endl;
                cout << "1 - Clientes\n" << endl;
                cout << "2 - Garcom\n" << endl;
                cout << "3 - Produtos\n" << endl;
                cout << "4 - Categoria\n" << endl;
                cout << "5 - Ingredientes\n" << endl;
                cout << "6 - Pedidos\n" << endl;
                cout << "7 - Itens dos Pedidos\n" << endl;
                cout << "8 - Consumo de Ingredientes\n" << endl;
                cout << "0 - sair\n" << endl;
                cin >> escolha_cosulta;

                switch (escolha_cosulta) {
                    case 1:
                        if (contcliA >= 1) {
                            mostrar_cliente(cliA, contcliA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 2:
                        if (contgarA >= 1) {
                            mostrar_garcom(garA, contgarA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 3:
                        if (contproA >= 1) {
                            mostrar_produto(proA, catA, contproA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 4:
                        if (contcatA >= 1) {
                            mostrar_categoria(catA, contcatA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 5:
                        if (contingA >= 1) {
                            mostrar_ingrediente(ingA, proA, contingA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 6:
                        if (contpedA >= 1) {
                            mostrar_pedidos(pedA, contpedA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 7:
                        if (contitensA >= 1) {
                            mostrar_itens_pedidos(itensA, contitensA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 8:
                        if (contconsA >= 1) {
                            mostrar_consumo_ingredientes(consA, contconsA);
                        } else {
                            cout<<"Registro se encontra vazio\n"<<endl;
                        }
                        break;

                    case 0:
                        break;
                }
                break;

            case 0:
                break;

            default:
                cout << "Opcao invalida";
        }
    } while(escolha_principal != 0);

    return 0;
}