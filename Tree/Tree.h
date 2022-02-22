#ifndef TREE_H
#define TREE_H

//#define STR
#ifdef STR

/*comparing strings*/
#define EQ(a, b) (!strcmp((a), (b)))
#define LT(a, b) (strcmp((a), (b)) < 0)
#define LE(a, b) (strcmp((a), (b)) <= 0)
#define GT(a, b) (strcmp((a), (b)) > 0)
#define GE(a, b) (strcmp((a), (b)) >= 0)

#else

/*comparing numbers*/
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LE(a, b) ((a) <= (b))
#define GT(a, b) ((a) > (b))
#define GE(a, b) ((a) >= (b))

#endif

typedef int Data;
typedef char *Name;
typedef int KeyType;

typedef struct element /*this data type of the element*/
{
    KeyType key;
    Data data;
    Name name;
} Element;

typedef Element TreeEntry; /*this data type of the entries of the tree and can be defined as what ever you want*/

typedef struct treenode /*this data type of the tree node in the linked-binary-tree*/
{
    TreeEntry entry; /*each node consists of entry, pointer to the right subtree(node) and pointer to the left subtree(node)*/
    struct treenode *right;
    struct treenode *left;
} TreeNode;

typedef TreeNode *PtrTreeNode; /*data type of the pointer of the node*/

typedef struct tree /*this data type of the tree itself*/
{
    TreeNode *root; /*this is a pointer to the root node of the tree*/
    int size;       /*this is size field*/
} Tree;

void CreatTree(Tree *);                          /*this function takes the pointer of the tree*/
void ClearTree(Tree *);                          /*this function takes the pointer of the tree*/
int TreeEmpty(Tree *);                           /*this function takes the pointer of the tree*/
int TreeFull(Tree *);                            /*this function takes the pointer of the tree*/
int TreeSize(Tree *);                            /*this function takes the pointer of the tree*/
int TreeDepth(Tree *);                           /*this function takes the pointer of the tree*/
void InsertTree(Tree *, TreeEntry *);            /*this function takes the pointer of the tree and the pointer of the inserted element*/
void InsertTreeIter(Tree *, TreeEntry *);        /*this function takes the pointer of the tree and the pointer of the inserted element*/
int FindItemTree(Tree *, TreeEntry *, KeyType);  /*this function takes the pointer of the tree, the pointer of the variable that will be filled with the element and the key of the wanted element*/
int DeletItemTree(Tree *, TreeEntry *, KeyType); /*this function takes the pointer of the tree, the pointer of the variable that will be filled with the element and the key of the wanted element*/
void InOrderTree(Tree *, void (*)(TreeEntry));   /*this function takes the pointer of the tree and the pointer of the functoin that will visit the entries*/

#endif