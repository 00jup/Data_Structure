#include <stdio.h>
#include <stdlib.h>
typedef struct _bTreeNode
{
    int data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;
typedef int BSTData;

BTreeNode *MakeBTreeNode(void)
{
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt)
{
    return bt->right;
}
BTreeNode *GetRootNode(BTreeNode *bt)
{
    return bt;
}
void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->left = sub;
}
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
    main->right = sub;
}
BTreeNode *RotateLL(BTreeNode *bst)
{
    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);
    return cNode;
}

BTreeNode *RotateRR(BTreeNode *bst)
{
    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);
    return cNode;
}
BTreeNode *RotateRL(BTreeNode *bst)
{
    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeLeftSubTree(pNode, RotateRR(cNode));
    return RotateLL(pNode);
}
BTreeNode *RotateLR(BTreeNode *bst)
{
    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}
int GetHeightDiff(BTreeNode *bst)
{
    int lsh;
    int rsh;

    if (bst == NULL)
        return 0;

    lsh = GetHeightDiff(GetLeftSubTree(bst));
    rsh = GetHeightDiff(GetRightSubTree(bst));

    return lsh - rsh;
}

BTreeNode *Rebalance(BTreeNode **pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);

    if (hDiff > 1)
    {
        if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    if (hDiff < -1)
    {
        if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
}

BTreeNode *BSTInsert(BTreeNode **pRoot, BSTData data)
{
    BTreeNode *pNode = NULL;
    BTreeNode *cNode = *pRoot;
    BTreeNode *nNode = NULL;

    while (cNode != NULL)
    {
        if (data == GetData(cNode))
            return NULL;

        pNode = cNode;

        if (GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTreeNode();
    SetData(nNode, data);

    if (pNode != NULL)
    {
        if (data < GetData(pNode))
            ChangeLeftSubTree(pNode, nNode);
        else
            ChangeRightSubTree(pNode, nNode);
    }
    else
        *pRoot = nNode;

    return nNode;
}
void preorder(BTreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(void)
{
    BTreeNode *root = NULL;

    root = BSTInsert(root, 10);
    root = BSTInsert(root, 20);
    root = BSTInsert(root, 30);
    root = BSTInsert(root, 40);
    root = BSTInsert(root, 50);
    root = BSTInsert(root, 29);

    printf("preorder: \n");
    preorder(root);

    return 0;
}