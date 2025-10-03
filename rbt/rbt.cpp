#include "rbt.h"

rbt::rbt(){
    this->root = nullptr;
}

rbt::rbt(Node* root){
    this->root = root;
}
void rbt::printrbt(Node* node, const string& prefix, bool isLeft=false){
            if (node != nullptr) {
                cout << prefix;
                cout << (isLeft ? "|--" : "|__");
                cout << node->key << endl;

                // Recurse on children, passing the correct node
                printrbt(node->leftchild,  prefix + (isLeft ? "|  " : "   "), true);
                printrbt(node->rightchild, prefix + (isLeft ? "|  " : "   "), false);
            }
}

void rbt::insert(int k){
    Node* curr = root;
    Node* prev;
    if(root==nullptr){ 
        root = new Node(k,nullptr,nullptr,nullptr,'B');
        return;
    }
    while(true){
        prev = curr;
        if(curr->key>k){
            curr = curr->leftchild;
            if(curr == nullptr){
                prev->leftchild = new Node(k,nullptr,nullptr,prev,'R');
                if(prev->color=='R') rrvio(prev,prev->leftchild);
                return;
            }
        }
        else{
            curr = curr->rightchild;
            if(curr == nullptr){
                prev->rightchild = new Node(k,nullptr,nullptr,prev,'R');
                if(prev->color=='R') rrvio(prev,prev->rightchild);
                return;
            }
        }        
    }
}

void rbt::rrvio(Node* par,Node* n){
    if(!(par->color=='R'&&n->color=='R')) return;
    else{
        Node* gpar = par->parent; 
        Node* uncl = (gpar->leftchild==par) ? gpar->rightchild : gpar->leftchild;
        if(uncl!=nullptr && uncl->color=='R'){
            uncl->color = 'B';
            gpar->color = 'R';
            par->color = 'B';
            if((gpar->parent)->color=='R'){
                rrvio(gpar->parent,gpar);
            }
            else return;
        }
        else{
            if(gpar->rightchild==par){
                if(par->leftchild==n){
                    Node* tmp = n->rightchild;
                    gpar->rightchild=n; n->parent = gpar;
                    par->leftchild=tmp; tmp->parent=par;
                    n->rightchild=par; par->parent=n;
                    rrvio(n,par);
                }
                else{
                    //rotate(gpar,par) and reverse the colors
                    gpar->color='R'; par->color='B';
                    Node* tmp = par->leftchild;
                    Node* gp_par = gpar->parent;
                    if(gp_par->rightchild==gpar) gp_par->rightchild=par;
                    else gp_par->leftchild=par;
                    par->parent = gp_par;
                    gpar->rightchild = tmp; tmp->parent=gpar;
                    par->leftchild = gpar; gpar->parent = par;
                    return; 
                }
            }
            else{
                if(par->rightchild==n){
                    Node* tmp = n->leftchild;
                    gpar->leftchild = n; n->parent = gpar;
                    par->rightchild = tmp;tmp->parent = par;
                    n->leftchild = par; par->parent = n;
                    rrvio(n,par);
                }
                else{
                    gpar->color='R'; par->color='B';
                    Node* tmp = par->rightchild;
                    Node* gp_par = gpar->parent;
                    if(gp_par->leftchild==gpar) gp_par->leftchild=par;
                    else gp_par->rightchild=par;
                    par->parent = gp_par;
                    gpar->leftchild = tmp; tmp->parent=gpar;
                    par->rightchild = gpar; gpar->parent = par;
                    return;
                }
            }
        }
    }
}