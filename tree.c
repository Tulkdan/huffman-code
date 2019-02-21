#include <stdio.h>
#include <stdlib.h>
#include "head.h"

node leaf_to_tree(node first, node second) {
  node root = (node) malloc(sizeof(struct Leaf));
  root->soma = soma_nos(first, second);
  root->left = *first;
  root->right = *second;
  root->letra = NULL;
  root->next = NULL;
  return root;
}

int soma_leaf(node n1, node n2) {
  return (n1->qtd + n2->qtd);
}
