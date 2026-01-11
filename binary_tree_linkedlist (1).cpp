#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

typedef struct TreeNode TreeNode;


TreeNode* createTreeNode(char data)
{
    TreeNode* temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}


int count_leaves(TreeNode* root)
{
    if(root==NULL) return 0;
    else if(root->left == NULL && root->right==NULL)
    {
        return 1;
    }
    else
        return count_leaves(root->left) + count_leaves(root->right);
}

int count_nodes(TreeNode* root)
{
    if(root==NULL) return 0;
    else
        return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void preorder(TreeNode* root)
{
    if(root==NULL)
        return;

    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root)
{
    if(root==NULL)
        return;


    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void postorder(TreeNode* root)
{
    if(root==NULL)
        return;


    postorder(root->left);

    postorder(root->right);

    printf("%c ", root->data);
}

int level(TreeNode* root)
{
    if(root==NULL) return 0;
    else
    {
        int left_level = level(root->left);
        int right_level = level(root->right);

        if(left_level>right_level) return 1 + left_level;
        else return 1 + right_level;
    }
}

int count_vowel(TreeNode* root)
{
    if(root==NULL) return 0;
    else
    {
        int vowel_left_side = count_vowel(root->left);
        int vowel_right_side = count_vowel(root->right);

        if(root->data=='A' || root->data=='E' || root->data=='I' || root->data=='O' || root->data=='U')
            return 1 + vowel_left_side + vowel_right_side;
        else
            return vowel_left_side + vowel_right_side;
    }
}

void mirror_tree(TreeNode* root)
{

}



int main()
{
    TreeNode* a = createTreeNode('A');
    TreeNode* b = createTreeNode('B');
    TreeNode* c = createTreeNode('C');
    TreeNode* d = createTreeNode('D');
    TreeNode* f = createTreeNode('E');
    TreeNode* g = createTreeNode('F');

    a->left = b;
    b->parent = a;

    a->right = c;
    c->parent = a;

    b->left = d;
    d->parent = b;

    c->left = f;
    f->parent = c;

    c->right = g;
    g->parent = c;

    TreeNode *root = a;

    a = b = c = d = f = g = NULL;


    root->right->right->right = createTreeNode('J');
    root->right->right->right->parent = root->right->right;


    printf("Number of Leaves: %d\n", count_leaves(root));
    printf("Number of Nodes: %d\n", count_nodes(root));
    printf("Number of Internal Nodes: %d\n", count_nodes(root) - count_leaves(root));


    printf("Preorder: "); preorder(root); printf("\n");
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    printf("Number of Levels: %d\n", level(root));
    printf("Number of vowels: %d\n", count_vowel(root));

    return 0;
}
