🍽️ Sistema de Gestão de Pedidos para Restaurante

📌 Sobre o Projeto

Este projeto foi desenvolvido como trabalho prático para a disciplina de Algoritmos, do curso de Análise e Desenvolvimento de Sistemas da FEMA (Fundação Educacional do Município de Assis).

Autoras:

· Rafaela Wolff
· Maria Luiza

O objetivo do trabalho foi implementar um sistema completo para gerenciar as operações de um restaurante, incluindo cadastro de categorias, produtos, ingredientes, clientes, garçons, controle de estoque, pedidos e consumo de ingredientes.

---

🧠 Abordagem Técnica

Conforme solicitado pelo professor, o sistema foi desenvolvido em C++ puro (código de baixo nível), utilizando exclusivamente:

· Estruturas (struct)
· Vetores estáticos (limite de 20 ou 40 registros por tipo)
· Funções modulares
· Menu interativo via console
· Todas as funcionalidades em um único arquivo .cpp

Não foram utilizadas orientação a objetos, ponteiros inteligentes, STL (exceto string e iostream) ou alocação dinâmica, atendendo às restrições do trabalho.

---

🚀 Como Executar o Código

Pré-requisitos

· Compilador C++ (ex: g++, clang++, Dev-C++, Code::Blocks, Visual Studio)
· Terminal / Prompt de comando

Passos

1. Salve o código fonte em um arquivo, por exemplo: restaurante.cpp.
2. Compile o código. Exemplo com g++:
   ```bash
      g++ restaurante.cpp -o restaurante.exe
         ```
         3. Execute o programa:
            ```bash
               ./restaurante.exe   # Linux/Mac
                  restaurante.exe     # Windows
                     ```

                     ⚠️ O programa foi escrito para Windows (uso de conio.h não é padrão e pode não funcionar em outros sistemas. Se estiver no Linux/Mac, remova #include <conio.h> ou substitua por alternativa padrão).

                     ---

                     📋 Funcionalidades

                     1. Cadastros (Menu 1)

                     · Categoria
                     · Produto (com vínculo a categoria)
                     · Ingrediente (com vínculo a produto)
                     · Garçom
                     · Cliente
                     · Consumo de Ingrediente (relaciona produto com ingrediente)
                     · Itens de Pedido (relaciona pedido com produto)

                     2. Exclusão (Menu 2)

                     · Remove produto (busca por código) e reorganiza os vetores de produtos automaticamente.

                     3. Pedidos (Menu 3)

                     · Criar novo pedido (válida cliente e garçom)
                     · Adicionar produto ao pedido (verifica estoque e regra: apenas um produto por pedido)
                     · Finalizar pedido

                     4. Consultas (Menu 4)

                     · Consultar garçom por código
                     · Consultar cliente por código
                     · Consultar um ingrediente (exibe valor total em estoque)
                     · Relatório de ingredientes abaixo do estoque mínimo (com custo de reposição)
                     · Valor total arrecadado com todos os pedidos

                     5. Registros (Menu 5)

                     · Exibe todos os registros inseridos:
                       · Clientes
                         · Garçons
                           · Produtos
                             · Categorias
                               · Ingredientes
                                 · Pedidos
                                   · Itens dos Pedidos
                                     · Consumo de Ingredientes

                                     ---

                                     ⚙️ Regras de Negócio Implementadas

                                     · Códigos únicos e ordenados (inserção ordenada para Categoria, Produto, Garçom, Cliente, Ingrediente).
                                     · Estoque mínimo/máximo para ingredientes.
                                     · Pedido só pode receber um produto (regra 5.3 do enunciado).
                                     · Produto só pode ser adicionado ao pedido se houver estoque suficiente de todos os ingredientes necessários.
                                     · Ao adicionar produto, estoque é baixado automaticamente.
                                     · Exclusão de produto mantém a ordenação e consistência dos dados.

                                     ---

                                     🧪 Limitações Conhecidas

                                     · Tamanho máximo fixo para vetores (20 para fonte, 40 para agregados).
                                     · Não persiste dados entre execuções (tudo em memória).
                                     · Uso de conio.h pode não funcionar em compiladores não Windows.
                                     · Assumimos que o usuário digita dados no formato esperado (pouca validação de tipo).

                                     ---

                                     📁 Estrutura do Código

                                     · Estruturas (struct) para cada entidade.
                                     · Funções de leitura, inclusão (merge ordenado), exclusão, consulta e relatórios.
                                     · main() com menu principal aninhado e switch-case.

                                     ---

                                     🎓 Considerações Finais

                                     Este trabalho atende aos requisitos propostos pelo professor: baixo nível, vetores estáticos, uso exclusivo de estruturas, menu integrado e todas as regras de negócio especificadas. Foi um excelente exercício para fixar lógica de programação, manipulação de vetores e modularização.

                                     ---

                                     📄 Licença

                                     Trabalho acadêmico – livre para uso educacional.