#include <stdio.h>

//maior quantidade de itens que pode ser incluido
#define TAM_MAX 100

//Como um "Molde" que define como cada "produto" será
typedef struct Produto {
  int id;
  char nome[50];
  float unitario;
  int qtde;
  float totalItem;
} Produto;

int main() {
  int nItens, i, j, codigoInserido;
  float totalGeral = 0;

  printf("Informe a quantidade de itens que deseja cadastrar: ");
  scanf("%d", &nItens);

//mensagem de erro, caso o usuario informe uma letra ou um numero menor que 1 e maior que 100
  if (nItens <= 0 || nItens > TAM_MAX) {
    printf("Por gentileza, informe apenas numeros entre 1 e %d.\n", TAM_MAX);
    return 1;
  }

//um espaço para guardar todos os produtos
  Produto produtos[TAM_MAX];
  for (i = 0; i < nItens; i++) {
    produtos[i].totalItem = 0;
  }
//detalhes de cada produto | se o número já foi usado antes, pede para tentar outro. No final, calcula o total de cada produto.
  for (i = 0; i < nItens; i++) {
    printf("\nCadastro do item %d:\n", i + 1);

    do {
      printf("ID do cadastro: ");
      scanf("%d", &codigoInserido);

      for (j = 0; j < i; j++) {
        if (produtos[j].id == codigoInserido) {
          printf("ID já cadastrado! Tente outro.\n");
          break;
        }
      }
    } while (j < i);

    produtos[i].id = codigoInserido;

    printf("Nome do produto (sem espaco): ");
    scanf("%s", produtos[i].nome);

    printf("Valor Unitario do produto (ate 5 digitos): ");
    scanf("%f", &produtos[i].unitario);

    printf("Quantidade de produto: ");
    scanf("%d", &produtos[i].qtde);

    produtos[i].totalItem = produtos[i].unitario * produtos[i].qtde;
  }
 
//mostra a lista de todos os produtos e seus detalhes, incluindo o total de cada um.
  //\n\n pula duas linhas
  printf("\n\nLISTA DE ITENS\n");
  printf("CODIGO |NOME                 |QTDE   |UNIT        |TOTAL\n");

//repetidor (o laço começa com i igual a 0 e continua repetindo enquanto i for menor que o nItens. A cada repetição,  i aumenta em 1. É como contar de 0 até um número menor que nItens.)
  for (i = 0; i < nItens; i++) {

//"%05d": % indica um espaço reservado para um valor. 05 significa que o número deve ter 5 dígitos, preenchendo com zeros à esquerda 
//se necessário. d significa que o valor é um número inteiro (decimal).produtos[i].id é o valor que vai ser mostrado nesse espaço 
//reservado, o ID do produto atual.

//"%-20s": % indica um espaço reservado. -20 significa que o texto (string) deve ocupar 20 caracteres e alinhar à esquerda. 
//"s" significa que o valor é uma string (texto). produtos[i].nome é o valor que vai ser mostrado nesse espaço reservado, 
//o nome do produto atual.

//"%3d": % indica um espaço reservado. 3 significa que o número deve ocupar 3 dígitos. "d" significa que o valor é um número inteiro.
//produtos[i].qtde é o valor que vai ser mostrado nesse espaço reservado, a quantidade do produto atual.

//"%5.2f": % indica um espaço reservado. 5.2 significa que o número deve ocupar 5 caracteres no total, com 2 casas decimais. 
//f significa que o valor é um número de ponto flutuante (decimal). produtos[i].unitario e produtos[i].totalItem são os valores 
//que vão ser mostrados nesses espaços reservados, o valor unitário e o total do produto atual.

    printf("%06d  %-20s  %06d  %5.2f       %5.2f\n",
           produtos[i].id, produtos[i].nome, produtos[i].qtde,
           produtos[i].unitario, produtos[i].totalItem);
    totalGeral += produtos[i].totalItem;
  }

  printf("\n                                                   |TOTAL FINAL   \n");
  printf("                                                   |%5.2f\n"  , totalGeral);
  
  return 0;
}
