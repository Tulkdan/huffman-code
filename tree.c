#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

node leaf_to_tree(node first, node second) {
  node root = (node) malloc(sizeof(struct Leaf));
  root->left = first;
  root->right = second;
  root->qtd = soma_leaf(first, second);
  root->letra = NULL;
  root->next = NULL;
  root->rear = NULL;
  return root;
}

int soma_leaf(node n1, node n2) {
  return (n1->qtd + n2->qtd);
}

void show_tree(node tree, char repr[], DICT* dict) {
  if (is_leaf(tree)) {
    DICT nodeAux = create_node_dict(tree->letra, repr);
    insert_into_dictionary(dict, nodeAux);
    // printf("%c - %d - %s\n", tree->letra, tree->qtd, repr);
    return;
  }
  if (tree->left != NULL) {
    char aux[10];
    strcpy(aux, repr);
    show_tree(tree->left, strcat(repr, "0"), dict);
    strcpy(repr, aux);
  }
  if (tree->right != NULL) {
    char aux[10];
    strcpy(aux, repr);
    show_tree(tree->right, strcat(repr, "1"), dict);
    strcpy(repr, aux);
  }
}

void create_tree(node* dict) {
  node aux = *dict;
  while(aux->next != NULL) {
    node min1 = min_in_dict(&aux);
    node min2 = min_in_dict(&aux);
    node newNode = leaf_to_tree(min1, min2);
    insert_final(&aux, newNode);
  }
  *dict = aux;
}

int is_leaf(node tree) {
  return (tree->left == NULL && tree->right == NULL);
}
