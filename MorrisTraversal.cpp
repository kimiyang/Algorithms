//Morris Traversal
//Pre order, in order and post order
//Wenhua Yang
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderMorrisTraversal(TreeNode * root)
{
    TreeNode * cur = root, *prev = NULL;
    while(cur != NULL)
    {
        if(cur->left == NULL)
        {
            printf("%d ", cur->val);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while(prev->right != NULL && prev->right != cur)
                prev = prev->right;
            if(prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                printf("%d ",cur->val);
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}


void preorderMorrisTravesal(TreeNode *root)
{
    TreeNode *cur = root, *prev = NULL;
    while(cur != NULL)
    {
        if(cur->left == NULL)
        {
            printf("%d ",cur->val);
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while(prev->right != NULL && prev->right != cur)
                prev = prev->right;
            if(prev->right == NULL)
            {
                printf("%d ",cur->val);
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}

////post order
void reverseNode(TreeNode *from, TreeNode *to)
{
    if(from == to)return;
    TreeNode *x = from, *y = to, *z;
    while(true)
    {
        z = y->right;
        y->right = x;
        x = y;
        y = z;
        if(x == to)break;
    }
}
void printReverseNode(TreeNode *from, TreeNode *to)
{
    reverseNode(from, to);
    TreeNode *p = to;
    while (true)
    {
        printf("%d ", p->val);
        if(p == from)break;
        p = p->right;
    }
    reverseNode(to, from);
}
void postorderMorrisTraversal(TreeNode *root)
{
    TreeNode dump(0);
    dump.left = root;
    TreeNode *cur = &dum, *prev = NULL;
    while(cur != NULL)
    {
        if(cur->left == NULL)
        {
            cur = cur->right;
        }
        else
        {
            prev = cur->left;
            while(prev->right != NULL && prev->right != cur)
                prev = prev->right;
            if(prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                printReverseNode(cur->left, prev);
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
}
