
#include <iostream>
#include<cstdlib>
using namespace std;

struct tree_item {
    int value;
    tree_item *left;
    tree_item *right;
};

struct tree {
    tree_item *root;

    bool has(int value)
    {
        if (root == NULL)
        {
            return false;
        }
        else
        {
            for (tree_item *child = root;;)
            {
                if(child->value == value)
                {
                    return true;
                }
                else if (child->value < value && child->left != NULL)
                {
                    child = child->left;

                }
                else if(child->right > NULL && child->left != NULL)
                {
                    child = child->right;

                }
                else
                {
                    return false;
                }
            };
        }

    };

    void insert(int value)
    {
        if (has(value) == false) //if the item is not part of the tree yet, do
        {
            tree_item *newChild = new tree_item();
            newChild->value = value;
            newChild->left = NULL;
            newChild->right = NULL;

            tree_item *p;

            if(root == NULL){ //if the to be added value is same as the item, replace
                root = newChild;
            }
            else
            {
                for (tree_item *child = root;;)
                {

                    if (child->value < value) //if the value to be added is less than this items value, move it left
                    {
                        if (child->left == NULL) //
                        {
                            child->left = newChild;
                            break;
                        }
                        else
                        {
                            p = child; //save the current child as parent for future ref;
                            child = child->left; //update child to next item & keep looking.

                        };

                    }
                    else //else if the value to be added is greater than this items value, move it right
                    {
                        if(child->right == NULL)
                        {
                            child->right = newChild;
                            break;
                        }
                        else
                        {
                            p = child; //save the current child as parent for future ref;
                            child = child->right; //update child to next item & keep looking.
                        };

                    };
                };
            };
        };
    };



};
#if 0
int main()
{
    tree *t = new tree();
    t->insert(55);


    for (int i = 0; i<500000; i++){

             t->insert(i);

    };
    int sum = 0;
    for (int i = 0; i<500000; i++){
            sum += t->has(i);

    };
    cout << sum;

    delete t;
}
#endif
