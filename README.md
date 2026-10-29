# Organização de Preços de um Supermercado

## 1. Objetivo

Desenvolver uma aplicação em linguagem C que organize os preços
de produtos de um supermercado utilizando os algoritmos
Bubble Sort e Quick Sort.

## 2. Situação-problema

Em um supermercado, organizar os preços dos produtos facilita
a comparação de valores e ajuda os consumidores a identificar
os produtos mais baratos e os mais caros.

Para resolver esse problema, a aplicação utiliza algoritmos
de ordenação que organizam os produtos do menor para o maior
preço.

## 3. Tecnologias utilizadas

- Linguagem C
- Biblioteca stdio.h
- Biblioteca string.h
- Compilador GCC

## 4. Funcionamento da aplicação

O programa possui dez produtos com preços fictícios.

Primeiramente, exibe os produtos na ordem original.
Em seguida, cria cópias dos mesmos dados e executa o Bubble
Sort e o Quick Sort separadamente.

Ao final, apresenta os resultados dos dois algoritmos,
permitindo comparar as listas ordenadas.

## 5. Explicação dos algoritmos

### Bubble Sort

O Bubble Sort compara elementos vizinhos e troca suas
posições quando estão fora da ordem desejada.

Durante cada passagem, os maiores preços vão sendo
deslocados para o final da lista.

Sua complexidade média e de pior caso é O(n²).
No melhor caso, com a otimização utilizada no programa,
a complexidade é O(n).

### Quick Sort

O Quick Sort escolhe um elemento chamado pivô e reorganiza
a lista, colocando os preços menores de um lado e os maiores
do outro.

Depois, aplica o mesmo procedimento recursivamente às
partes da lista.

Sua complexidade média é O(n log n), enquanto seu pior caso
é O(n²).

## 6. Como executar

Salve o código-fonte no arquivo main.c.

Se possuir o GCC instalado, abra o terminal na pasta do
projeto e execute:

```bash
gcc main.c -o supermercado
```

No Linux ou macOS, execute:

```bash
./supermercado
```

No Windows, execute:

```bash
supermercado.exe
```

Também é possível utilizar um compilador online de C.

## 7. Conclusão

A aplicação demonstra como os algoritmos Bubble Sort e
Quick Sort podem resolver um problema cotidiano.

Os dois algoritmos produzem a mesma ordenação, mas possuem
características de desempenho diferentes. O Quick Sort
geralmente é mais eficiente para conjuntos grandes de dados.
