#ifndef HEADER
#define HEADER

struct Leaf {
  char letra;
  int qtd;
  struct Leaf *next, *rear;
  struct Leaf *right, *left;
};

typedef struct Leaf* node;

node create_node(char letra);
void insert_into_list(node* dict, char letra);
void mostrar(node dict);
FILE* abrir_arquivo(char *arquivo);
node min_in_dict(node* dict);
void insert_final(node* dict, node new);
int count_elements(node dict);

// Tree functions
node leaf_to_tree(node first, node second);
int soma_leaf(node n1, node n2);
void create_tree(node* dict);
void show_tree(node tree);
int is_leaf(node tree);

#endif