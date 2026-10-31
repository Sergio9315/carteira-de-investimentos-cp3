# CP3 — Carteira de Investimentos
Projeto desenvolvido em linguagem C.
No CP3, o projeto foi ampliado em relação ao CP2, mantendo a proposta original de cadastro e acompanhamento dos ativos e acrescentando recursos de análise, ordenação, simulação e relatório.

## Repositório do projeto no GitHub

Clique no link abaixo para acessar o código-fonte do projeto:

[https://github.com/Sergio9315/carteira-de-investimentos-cp3.git]

## Apresentação do projeto
O sistema permite cadastrar e acompanhar uma carteira de investimentos.
Os dados são armazenados no arquivo data/carteira.txt e carregados quando o programa é iniciado.

## Integrantes do grupo

Sérgio Apolinário — RGM: 47722681

Nickolas da Silva Coquejo Santiago — RGM: 74847620

Daniel da Silva Mendes — RGM: 048737534

Gustavo do Carmo Germano — RGM: 47880287

Jhonatan Henrique da Cruz Carneiro — RGM: 37734075

## Funcionalidades do CP3

1. Cadastrar ativo: nome, categoria, quantidade, preço de compra e preço atual.

2. Listar ativos com rentabilidade, lucro ou prejuízo e classificação.

3. Calcular o valor atual total da carteira.

4. Calcular a rentabilidade geral em porcentagem.

5. Ordenar os ativos utilizando o algoritmo Bubble Sort, da maior para a menor rentabilidade, exibindo a lista ordenada.

6. Simular, de forma educativa, o rendimento de três alternativas durante 12 meses.

7. Emitir relatório final com os resultados da carteira.

8. Salvar os dados e sair do programa.

## Estrutura do projeto

CP3/
├── src/
│   ├── main.c
│   ├── funcoes.c
│   └── modulo.c
├── include/
│   ├── funcoes.h
│   └── modulo.h
├── data/
│   └── carteira.txt
└── README.md

## Como compilar e executar o projeto

1. Windows (MSYS2 UCRT64)

## Abra o terminal MSYS2 UCRT64 na pasta principal CP3 e execute o comando:

-**gcc -Wall -Wextra -std=c11 -Iinclude src/main.c src/funcoes.c src/modulo.c -o programa.exe**

## Para executar o programa 

./programa.exe

2. Linux

Abra o terminal na pasta principal CP3 e execute o comando:

gcc -Wall -Wextra -std=c11 -Iinclude src/main.c src/funcoes.c src/modulo.c -o programa

Para executar o programa:

./programa

## Formato do arquivo de dados

* Cada linha do arquivo data/carteira.txt representa um ativo no formato:

* nome;categoria;quantidade;precoCompra;precoAtual;

- Os campos são separados por ponto e vírgula (;) para facilitar a organização, a identificação e a leitura das informações armazenadas nos arquivos do programa, permitindo que cada dado seja interpretado corretamente. 

- Os números decimais são gravados utilizando ponto (.) como separador decimal, seguindo o padrão da linguagem C. Isso garante que o programa consiga armazenar e interpretar corretamente valores financeiros durante a leitura e gravação dos arquivos.

- Não utilize ponto e vírgula (;) no nome ou na categoria dos ativos, pois esse caractere é utilizado como separador das informações no arquivo de armazenamento. Seu uso nesses campos pode causar erros na leitura e interpretação dos dados pelo programa.

## Fórmulas utilizadas

- Valor atual de cada ativo = quantidade × preço atual.

- Valor total da carteira = soma do valor atual de todos os ativos.

- Rentabilidade individual (%) = ((preço atual − preço de compra) / preço de compra) × 100.

- Lucro ou prejuízo = (preço atual − preço de compra) × quantidade.

- Rentabilidade geral (%) = ((valor atual total − valor investido total) / valor investido total) × 100.

### Conteúdos de programação utilizados

-*Struct (estrutura):* permite agrupar diferentes informações relacionadas em um único tipo de dado. No projeto, é utilizada para organizar os dados de cada investimento, como nome, categoria, quantidade, preço de compra e preço atual.

-*Vetores:* permitem armazenar vários elementos do mesmo tipo em uma única variável. No projeto, são utilizados para armazenar os diferentes investimentos cadastrados na carteira.

- *Funções:* são blocos de código responsáveis por executar tarefas específicas, facilitando a organização e a reutilização do código. No projeto, cada função realiza uma atividade, como cadastrar, listar, calcular rentabilidade, ordenar e salvar os investimentos.

- *Parâmetros:* são informações enviadas para uma função para que ela possa executar determinada tarefa. Por exemplo, uma função pode receber o vetor de investimentos e a quantidade de ativos cadastrados para realizar uma operação.

- *Retorno:* é o resultado que uma função pode devolver após executar uma tarefa. No projeto, é utilizado para retornar valores calculados, como o valor total da carteira e a rentabilidade.

- *Estruturas condicionais (if/else):* permitem executar diferentes comandos de acordo com uma condição. São utilizadas nas verificações e classificações dos investimentos.

- *Seleção (switch/case):* permite escolher qual operação será executada conforme a opção selecionada pelo usuário no menu principal.

- *Laços de repetição (for e do/while):* permitem repetir comandos. O `for` é utilizado para percorrer os investimentos e realizar operações, enquanto o `do/while` mantém o menu em execução até que o usuário escolha sair.

- *Arquivos de texto:* permitem armazenar informações de forma permanente. No projeto, são utilizados para salvar e carregar os dados dos investimentos.

- *Bubble Sort:* é um algoritmo de ordenação que compara elementos vizinhos e troca suas posições quando necessário. No projeto, é utilizado para ordenar os investimentos conforme sua rentabilidade.

## Simulador educativo
O simulador utiliza o valor atual total da carteira como valor inicial e compara três taxas mensais hipotéticas durante 12 meses:

- Poupança: 0,50% ao mês.

- Tesouro Selic: 0,80% ao mês.

- CDB: 0,90% ao mês.

O cálculo é repetido mês a mês, demonstrando o conceito de juros compostos.

As taxas são fixas e exclusivamente didáticas. Não representam taxas atuais de mercado, previsão de rendimento ou recomendação de investimento.

## Observação

O projeto tem finalidade acadêmica e educativa. Os resultados dependem dos dados informados pelo usuário e das taxas hipotéticas utilizadas no simulador.
