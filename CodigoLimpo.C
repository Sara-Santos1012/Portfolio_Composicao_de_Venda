#include <stdio.h>

#define TAM_MAX 100

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

  if (nItens <= 0 || nItens > TAM_MAX) {
    printf("Por gentileza, informe apenas numeros entre 1 e %d.\n", TAM_MAX);
    return 1;
  }

  Produto produtos[TAM_MAX];
  for (i = 0; i < nItens; i++) {
    produtos[i].totalItem = 0;
  }

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

  printf("\n\nLISTA DE ITENS\n");
  printf("CODIGO |NOME                 |QTDE   |UNIT        |TOTAL\n");
  for (i = 0; i < nItens; i++) {
    printf("%06d  %-20s  %06d  %5.2f       %5.2f\n",
           produtos[i].id, produtos[i].nome, produtos[i].qtde,
           produtos[i].unitario, produtos[i].totalItem);
    totalGeral += produtos[i].totalItem;
  }

  printf("\n                                                   |TOTAL FINAL   \n");
  printf("                                                   |%5.2f\n"  , totalGeral);
  
  return 0;
}

  // 5. Calcular e imprimir total geral
  printf("\n                                           TOTAL FINAL   %5.2f\n", totalGeral);

  return 0;
}
