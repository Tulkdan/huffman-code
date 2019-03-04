#ifndef HEADER
#define HEADER

struct Leaf {
  char letra;
  int qtd;
  struct Leaf *next, *rear;
  struct Leaf *right, *left;
};

struct Dictionary {
  char letra;
  char repr[10];
  struct Dictionary *next, *rear;
};

typedef struct Leaf* node;
typedef struct Dictionary* DICT;

// List functions
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
void show_tree(node tree, char repr[], DICT* dict);
int is_leaf(node tree);

// Dictionary functions
DICT create_node_dict(char letra, char repr[]);
void insert_into_dictionary(DICT* dict, DICT new);
void show_dictionary(DICT dict);
void write_in_file(DICT dict);
void read_bin_file();
DICT read_dict_from_file(FILE* file);

#endif