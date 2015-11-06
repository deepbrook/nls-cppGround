
#include <iostream>
#include<cstdlib>
using namespace std;

struct tree_item {
    int value;
    int balance;
    tree_item *left;
    tree_item *right;
    tree_item *parent;
};

void balanceLeft(tree_item *nc,tree_item *c, tree_item *p, tree_item **root){
    //Still needs balance adjustment
    if(p != NULL){
        if(c->right == nc){
            //cout << "LR";
            //LR Case

           /* c->right = nc->left; //
            p->left = nc->right;
            nc->left = c;
            nc->right = p;
             if(p->parent != NULL){ //point p's parent to nc
                if(p->parent->left == p){
                    p->parent->left = nc;
                }
                else{
                    p->parent->right = nc;
                }
                if(p->parent == *root){
                    *root = nc;
                }
            }
            c->parent = nc;
            p->parent = nc;
            p->balance = 0;
            c->balance = 0;
    */
        }
        else{
            //cout << "LL";
            //LL Case
            p->left = c->right;
            c->left = nc;
            c->right = p;

            if(p->parent != NULL){ //point p's parent to c
                if(p->parent->left == p){
                    p->parent->left = c;
                }
                else{
                    p->parent->right = c;
                }
                if(p->parent == *root){
                    *root = c;
                }
            }
            c->parent = p->parent; //make p's parent to c's parent
            p->parent = c; //make c the parent of p
            nc->parent = c;

            p->balance = 0;
            c->balance = 0;

        }

    }
}

void balanceRight(tree_item *nc,tree_item *c, tree_item *p, tree_item **root){
    if(p != NULL){
        if(c->left == nc){
            //cout << "RL\n";
            //RL Case
            p->right = nc->left;
            c->left = nc->right;
            nc->left = p;
            nc->right = c;

             if(p->parent != NULL){ //point p's parent to nc
                if(p->parent->left == p){
                    p->parent->left = nc;
                }
                else{
                    p->parent->right = nc;
                }
                if(p == *root){
                    *root = nc;}
            }

            c->parent = nc;
            p->parent = nc;
            p->balance = 0;
            c->balance = 0;


        }
        else{
            //cout << "RR\n";
            //RR Case
            p->right = c->left;
            c->left = p;
          //  cout << nc << " "<< c << " " << p << " "<< *root << "\n";
            if(p->parent != NULL){ //point p's parent to c
                if(p->parent->left == p){
                    p->parent->left = c;
                }
                else{
                    p->parent->right = c;
                }



            }
            if(p == *root){
                *root = c;}
            c->parent = p->parent; //make p's parent to c's parent
            p->parent = c; //make c the parent of p
            nc->parent = c;
            p->balance = 0;
            c->balance = 0;

        }
    }
}

int countBranchItems(tree_item *branch){
    int counter = 1;

        if(branch->left != NULL){
            //counter++;
            counter += countBranchItems(branch->left);
        }

        if(branch->right != NULL){
            //counter++;
            counter += countBranchItems(branch->right);
        }
        return counter;
    }


int findBalance(tree_item *root){
    int c_l = 0;
    int c_r = 0;
    if (root == NULL){
        return 0;
    }

    if(root->left != NULL){
        c_l = 1 + findBalance(root->left);
    }

    if(root->right != NULL){
       c_r = 1 + findBalance(root->right);
    }

    return c_l < c_r ? c_r : c_l;

}

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
                else if (value < child->value && child->left != NULL)
                {
                    child = child->left;

                }
                else if(value > child->value && child->right != NULL)
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

    void insert(int value){

        if (has(value) == false) //if the item is not part of the tree yet, do
        {
            tree_item *newChild = new tree_item();
            newChild->value = value;
            newChild->left = NULL;
            newChild->right = NULL;
            newChild->parent = NULL;
            newChild->balance = 0;

            if (root==NULL){
                root = newChild;
                return;
            }
            else{
                for(tree_item *child = root;;){

                    if(value < child->value)
                    { //LOOK LEFT
                        if(child->left != NULL)
                        { //update gp, p, and child and move on
                            child = child->left;
                        }
                        else
                        { //insert newChild here if its null
                            newChild->parent = child;
                            child->left = newChild;
                            //cout << "Balance of " << child->parent << " is "<< findBalance(child->parent) << "\n";
                            if(child->parent != NULL ){
                                if(findBalance(child->parent) >= 2){
                                    balanceRight(newChild, child, child->parent, &root);
                                }
                                else if(findBalance(child->parent) <= -2){
                                    balanceLeft(newChild, child, child->parent, &root);
                                }
                            }
                            break;
                        }

                    }
                    else{ //LOOK RIGHT
                        if(child->right != NULL){ //update gp, p, and child and move on
                            child = child->right;
                        }
                        else{ //if its null, insert newChild here
                            newChild->parent = child;
                            child->right = newChild;
                            //cout << value <<"\n";
                            //BALANCING

                            for(tree_item *p = child->parent; p != NULL; newChild = child, child= p, p = p->parent){
                              //  cout << "Balance of " << child->parent<< " is "<< findBalance(child->parent) << "\n";
                                if(findBalance(p->right) - findBalance(p->left) >= 2){
                                    balanceRight(newChild, child, child->parent, &root);
                                }
                                else if(findBalance(p->right) - findBalance(p->left)  <= -2){
                                    balanceLeft(newChild, child, child->parent, &root);
                                }
                            }
                            break;
                        }

                    }

                }//End FOR Loop

            }// End ELSE
        }//End IF

    }//end tmp()

};




void printTree(tree_item *root)//sports.bwin.com/de/sports#eventId=&leagueIds=35&page=0&sportId=11
{
    if (root == NULL){
        return;
    }
    if(root->left){
    cout << "v"<< root->value << "->v"<< root->left->value << ";\n";
    }
    if(root->right){
    cout << "v"<<root->value << "->v"<< root->right->value << ";\n";
    }

    printTree(root->left);
    printTree(root->right);
    return;
}



int main()
{
    tree *t = new tree();

#if 1
    for (int i = 0; i<100; i++){

             t->insert(i);

    };
    int sum = 0;
    for (int i = 0; i<100; i++){
            sum += t->has(i);

    };
    cout <<"digraph {";
    printTree(t->root);
    cout << "}";
#endif
    delete t;
}
