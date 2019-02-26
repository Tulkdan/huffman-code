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
  root->rear = NULL;
  return root;
}

int soma_leaf(node n1, node n2) {
  return (n1->qtd + n2->qtd);
}

void show_tree(node tree) {
  // TODO: add new representation for the letter
  if (is_leaf(tree)) {
    printf("%c - %d\n", tree->letra, tree->qtd);
  }
  if (tree->left != NULL) {
    show_tree(tree->left);
  }
  if (tree->right != NULL)
    show_tree(tree->right);
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