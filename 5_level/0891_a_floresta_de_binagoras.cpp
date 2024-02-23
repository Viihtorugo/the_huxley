#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

typedef struct tree
{
    lli elem;
    struct tree *left;
    struct tree *right;
} tree;

int str_by_int(string s, int &i)
{
    lli num = 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
        num = num * 10 + ((lli)s[i]) % ((lli)'0');
        i++;
    }

    return num;
}

void print_pre_order(tree *root)
{
    cout << "(";
    if (root != NULL)
    {
        cout << root->elem;
        print_pre_order(root->left);
        print_pre_order(root->right);
    }
    cout << ')';
}

void print_pos_order(tree *root)
{
    if (root != NULL)
    {
        print_pos_order(root->left);
        print_pos_order(root->right);
        cout << root->elem << endl;
    }
}

void binary_tree_by_vector(tree *root, vector<lli> &array)
{
    if (root != NULL)
    {
        binary_tree_by_vector(root->left, array);
        array.push_back(root->elem);
        binary_tree_by_vector(root->right, array);
        return;
    }
    else
    {
        return;
    }
}

bool is_binary_tree(vector<lli> &array)
{
    if (array.size() == 0)
        return false;

    for (lli i = 1; i < array.size(); i++)
        if (array[i] < array[i - 1])
            return false;

    return true;
}

tree *create_tree(string s, int &i, tree *root)
{
    while (i < s.size())
    {
        if (s[i] == '(')
        {
            i++;

            if (s[i] >= '0' && s[i] <= '9')
            {
                lli elem = str_by_int(s, i);
                i++;

                root = (tree *)malloc(sizeof(tree));
                root->elem = elem;
                root->left = NULL;
                root->right = NULL;

                root->left = create_tree(s, i, root->left);
                root->right = create_tree(s, i, root->right);

                return root;
            }
            else if (s[i] == ')')
            {
                return root;
            }
        }

        i++;
    }

    return root;
}

tree *insert(tree *root, lli elem)
{
    if (root == NULL)
    {
        root = (tree *) malloc(sizeof(tree));
        
        root->elem = elem;
        root->left = NULL;
        root->right = NULL;

        return root;
    }
    else
    {
        if (elem < root->elem)
        {
            root->left = insert(root->left, elem);
        }
        else if (elem > root->elem)
        {
            root->right = insert(root->right, elem);
        }

        return root;
    }
}

tree *remove_tree(tree *root, lli elem)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
    {
        if (root->elem == elem)
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else
            {
                if (root->left == NULL || root->right == NULL)
                {
                    tree *aux;

                    if (root->left == NULL)
                    {
                        aux = root->right;
                    }
                    else
                    {
                        aux = root->left;
                    }

                    free(root);
                    return aux;
                }
                else
                {
                    // primeiro para esquerda depois para o ultimo a direita
                    tree *aux = root->right;

                    while (aux->left != NULL)
                        aux = aux->left;

                    root->elem = aux->elem;
                    aux->elem = elem;
                    root->right = remove_tree(root->right, elem);

                    return root;
                }
            }
        }
        else
        {
            if (elem > root->elem)
            {
                root->right = remove_tree(root->right, elem);
            }
            else
            {
                root->left = remove_tree(root->left, elem);
            }
        }

        return root;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);

    tree *root = NULL;

    string s;

    while (cin >> s)
    {
        int i = 0;
        tree *aux_root = NULL;
        vector<lli> array;
        
        aux_root = create_tree(s, i, aux_root);

        binary_tree_by_vector(aux_root, array);

        if (is_binary_tree(array))
        {
            root = insert(root, array[0]);
        }
        else
        {
            root = remove_tree(root, aux_root->elem);
        }

        delete aux_root;
    }

    print_pos_order(root);

    return 0;
}