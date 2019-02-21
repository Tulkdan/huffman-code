#include <stdio.h>
#include <stdlib.h>
#include "head.h"

node leaf_to_tree(node first, node second) {
  node root = (node) malloc(sizeof(struct Leaf));
  root->left = first;
  root->right = second;
  root->qtd = soma_leaf(first, second);
  root->letra = NULL;
  root->next = NULL;
  return root;
}

int soma_leaf(node n1, node n2) {
  return (n1->qtd + n2->qtd);
}

node create_tree(node* dict) {
  node aux = *dict;
  while(aux->next != NULL) {
    node min1 = min_in_dict(&aux);
    node min2 = min_in_dict(&aux);
    node newNode = leaf_to_tree(min1, min2);
    node inicio = aux;
    insert_final(&aux, newNode);
    printf("%c\n", inicio->letra);
    aux = inicio;
  }
}
