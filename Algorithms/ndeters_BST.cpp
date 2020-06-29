// collaborated With Alonso Garcia
#include <sstream>
#include <iostream>
//#include <vectors>
#include <array>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node *parent;
};
// Binarry search Finding the value in the trees
class BinarySearchTree{
    Node *root;
    Node* Search(int toFind){
        Node *x = root;
        while (x != NULL){
            if (x->val == toFind){
                return x;
            }
            else if (x->val < toFind){
                x = x->right;
            }
            else x = x->left;
        }
        if (x == NULL) {
            return NULL;
        }
        return x;
    }
    // Node of successor Node
    // Successor Node is coupled seeing if it must go right or left for lines 35-60
    // New function succss
    Node* Successor(Node *x) {
        if (x->right != NULL) {
            return Minimum(x->right);
        }
        Node *y = x->parent;
        while (y != NULL && x == y->right) {
            x = y;
            y = y->parent;
        }return y;
        
    }//New func find the minimum
    Node* Minimum(Node *x) {
        while (x->left != NULL) {
            x = x->left;
        }
        return x;
        
    }//New Function find the maximum
    Node* Maximum(Node *x) {
        
        while (x->right != NULL) {
            x = x->right;}
        return x;
        }
    
    
    // New function of Transplant to see if the parent node has to replaced somewhere else
    // Making the
    void Transplant(Node *u, Node *v) {
        if (u->parent == NULL){
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else u->parent->right = v;
        if (v != NULL) {
            v->parent = u->parent;
        }
    }
    
public:
    // calls to the search tree results that will
    BinarySearchTree() {
        root = NULL;
    }
    
    virtual ~BinarySearchTree() {
        while (root != NULL) {
            Delete(root->val);
            }}
    
    Node* getRoot() {
    return root;
        
    }
    // Page 464 inserted the tree
    // building the tree with the values in the nodes
    void Insert(int toInsert) {
        Node *z = new Node;
        z->parent = NULL;
        z->val = toInsert;
        z->left = NULL;
        z->right = NULL;
        
        Node *y = NULL;
        Node *x = root;
        while (x != NULL) {
            y = x;
            if (toInsert < x->val) {
                x = x->left;
            }
            else {
                x = x->right;
            }
        }
        
        z->parent = y;
        
        if (y == NULL) {
            root = z;}
        else if (z->val < y->val) {
            y->left = z;}
        else y->right = z;
        }
    // making a trash like heap to delete that has been translated
    void Delete(int toDelete) {
        
        Node *z = Search(toDelete);
        if (z == NULL) return;
        if (z->left == NULL) {
            Transplant(z, z->right);
        }
        else if (z->right == NULL) {
            Transplant(z, z->left);
        }
        else {
            Node *y = Minimum(z->right);
            if (y->parent != z) {
                Transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            Transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        
    }
    // Posts for the check
    void InOrder(Node *x) {
        
        if (x == NULL) return;
        
        InOrder(x->left);
        cout << x->val << endl;
        InOrder(x->right);
        
    }
    
    void PreOrder(Node *x) {
        
        if (x == NULL) return;
        
        cout << x->val << endl;
        PreOrder(x->left);
        PreOrder(x->right);
        
    }
    
    void PostOrder(Node *x) {
        
        if (x==NULL) return;
        
        PostOrder(x->left);
        PostOrder(x->right);
        cout << x->val << endl;
        
    }
    
};

int main() {
    // Made a pyrammid of death for the Binary search tree
    BinarySearchTree Tree;
    
    char line[100];
    // Checks for the line into
    while (cin.getline(line,100) ) {
        string str(line);
        if ( str.size()==0 ) continue;
        if ( str[0]=='e' ) return 0;
        
        if ( str.substr(0,3) == "oin" ) {
            Tree.InOrder(Tree.getRoot());
        }
        else {
            if ( str.substr(0,4) == "opre" ) {
                Tree.PreOrder(Tree.getRoot());
            }
            else {
                if (str.substr(0,5) == "opost") {
                    Tree.PostOrder(Tree.getRoot());
                }
                else {
                    int key;
                    stringstream convert_stm(str.substr(1, str.size()-1));
                    if ( !(convert_stm>>key) ) key = -1;
                    
                    if (str.substr(0,1) == "i") Tree.Insert(key);
                    else if (str.substr(0,1) == "d") Tree.Delete(key);
                }}}}
    return 0;
}
