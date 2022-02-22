#include <stdlib.h>
#include <string.h>
#include "Tree.h"

void CreatTree(Tree *pt) /*creating a tree means initializing its values*/
{
    pt->size = 0;
    pt->root = NULL;
}

int TreeEmpty(Tree *pt)
{
    return !(pt->root);
}

int TreeFull(Tree *pt)
{
    return 0; /*the tree will never be full except the stack-overflow of the memory*/
}

int TreeSize(Tree *pt)
{
    return pt->size;
}
int TreeDepthAux(PtrTreeNode *ppn) /*this function takes a pointer to the pointer of the first node in the tree(or subtree)*/
{                                  /*this function is not allowable to the user only to be called in TreeDepth*/
    if (!*ppn)                     /*base case of the recursion(the pointer of the first node in the subtree points to NULL)*/
        return 0;
    int a = TreeDepthAux(&(*ppn)->left);  /*getting the depth of the left subtree*/
    int b = TreeDepthAux(&(*ppn)->right); /*getting the depth of the right subtree*/
    return (a > b) ? (a + 1) : (b + 1);   /*return the biggest depth*/
}
int TreeDepth(Tree *pt)
{
    return TreeDepthAux(&pt->root); /*pass the pointer of the pointer of the first node in the tree*/
}

void InOrderTreeAux(PtrTreeNode *ppn, void (*pf)(TreeEntry)) /*this function takes a pointer to the pointer of the first node in the tree(or subtree) and the pointer of the functoin that will visit the entries*/
{                                                            /*this function is not allowable to the user only to be called in InOrderTree*/
    if (*ppn)                                                /*base case of the recursion(the pointer of the first node in the subtree points to NULL)*/
    {                                                        /*LVR*/
        InOrderTreeAux(&(*ppn)->left, pf);                   /*apply the function over the left subtree(L)*/
        (*pf)((*ppn)->entry);                                /*after applying the function over the left subtree(L) apply it over the root node(V)*/
        InOrderTreeAux(&(*ppn)->right, pf);                  /*apply the function over the right subtree(R)*/
    }
}

void InOrderTree(Tree *pt, void (*pf)(TreeEntry))
{
    InOrderTreeAux(&(pt->root), pf); /*pass the pointer of the pointer of the first node in the tree and the pointer of the function*/
}

void ClearTreeAux(PtrTreeNode *ppn) /*this function takes a pointer to the pointer of the first node in the tree(or subtree)*/
{                                   /*this function is not allowable to the user only to be called in ClearTree*/
    if (*ppn)                       /*base case of the recursion(the pointer of the first node in the subtree points to NULL)*/
    {
        ClearTreeAux(&(*ppn)->left);  /*clear the whole left subtree*/
        ClearTreeAux(&(*ppn)->right); /*clear the whole right subtree*/
        free(*ppn);                   /*free the root node of the subtree*/
        *ppn = NULL;
    }
}

void ClearTree(Tree *pt)
{
    ClearTreeAux(&pt->root); /*pass the pointer of the pointer of the first node in the tree and the pointer of the function*/
    pt->size = 0;            /*initialise the size of the tree*/
}

void InsertTreeAux(PtrTreeNode *ppn, TreeEntry *pe) /*this function takes a pointer to the pointer of the first node in the tree(or subtree) and the pointer to the inseted element*/
{                                                   /*this function is not allowable to the user only to be called in InsertTree*/
    if (!*ppn)                                      /*base case of the recursion(the pointer of the first node in the subtree points to NULL) this node will be the parent of the new node*/
    {
        /*create a node and assign the values*/
        *ppn = (PtrTreeNode)malloc(sizeof(TreeNode));
        (*ppn)->entry = *pe;
        (*ppn)->left = NULL;
        (*ppn)->right = NULL;
    }
    else if (LT(pe->key, (*ppn)->entry.key))
        InsertTreeAux(&(*ppn)->left, pe); /*go to the left subtree*/
    else
        InsertTreeAux(&(*ppn)->right, pe); /*go to the right subtree*/
}

void InsertTree(Tree *pt, TreeEntry *pe)
{

    InsertTreeAux(&(pt->root), pe); /*pass the pointer of the pointer of the first node in the tree and the pointer of the function*/
    pt->size++;                     /*increment the size*/
}

void InsertTreeIter(Tree *pt, TreeEntry *pe)
{
    TreeNode *pn, *prev, *pcrnt;

    /*create a node and assign the values*/
    pn = (TreeNode *)malloc(sizeof(TreeNode));
    pn->entry = *pe;
    pn->left = NULL;
    pn->right = NULL;

    /*first node(root)*/
    if (!pt->root)
        pt->root = pn;
    else
    {
        pcrnt = pt->root; /*start from the root node till finding the right place*/
        while (pcrnt)     /*reach the NULL place(the place of inserting)*/
        {
            prev = pcrnt;
            if (LT(pe->key, pcrnt->entry.key))
                pcrnt = pcrnt->left;
            else
                pcrnt = pcrnt->right;
        }
        if (LT(pe->key, prev->entry.key))
            prev->left = pn; /*insert in the left*/
        else
            prev->right = pn; /*insert in the right*/
    }
    pt->size++; /*increment the size*/
}

int FindItemTree(Tree *pt, TreeEntry *pe, KeyType k)
{
    int found = 0;
    TreeNode *pn = pt->root;
    while (pn && !(found = EQ(k, pn->entry.key))) /*the process will continue till finding the wanted node or reaching the end of the tree*/
    {
        if (LT(k, pn->entry.key))
            pn = pn->left;
        else
            pn = pn->right;
    }
    if (found)
        *pe = pn->entry; /*takeing the value*/
    return found;
}

void DeletNodeTreeAux(PtrTreeNode *ppn) /*this function takes a pointer to the pointer of the first node in the tree(or subtree)*/
{                                       /*this function is not allowable to the user only to be called in DeletItemTree*/
    TreeNode *q = *ppn, *r;
    if (!(*ppn)->left) /*no left subtree*/
        *ppn = (*ppn)->right;
    else if (!(*ppn)->right) /*no left subtree*/
        *ppn = (*ppn)->left;
    else /*has left and right subtrees*/
    {
        q = (*ppn)->left;
        if (!q->right) /*the left subtree has no right subtree*/
        {
            (*ppn)->entry = q->entry;
            (*ppn)->left = q->left;
        }
        else
        {
            do /*reaching the most right node in the left subtree to take the place of the deleted node (it is biggest node in the left subtree and smaller than the smallest node in the right subtree)*/
            {
                r = q;
                q = q->right;
            } while (q->right);
            (*ppn)->entry = q->entry;
            r->right = q->left;
        }
    }
    free(q); /*clear the node*/
}

int DeletItemTree(Tree *pt, TreeEntry *pe, KeyType k)
{
    int found = 0;
    TreeNode *q = pt->root, *r = NULL;
    while (q && !(found = EQ(k, q->entry.key))) /*try to find the wanted node*/
    {
        r = q;
        if (LT(k, q->entry.key))
            q = q->left;
        else
            q = q->right;
    }
    if (found)
    {
        *pe = r->entry; /*takeing the value*/
        if (!r)         /*case of deleting the root*/
            DeletNodeTreeAux(&pt->root);
        else if (LT(k, r->entry.key)) /*case of deleting the root of the left subtree*/
            DeletNodeTreeAux(&r->left);
        else /*case of deleting the root of the right subtree*/
            DeletNodeTreeAux(&r->right);
    }
    pt->size--; /*decrimint the size*/
    return found;
}
