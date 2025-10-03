#include<iostream>
using namespace std;
struct Node{
    int key;
    Node* leftchild;
    Node* rightchild;
    Node* parent;
    char color='0';
    Node(int key,Node* leftchild=nullptr,Node* rightchild=nullptr, Node* parent=nullptr,char color) : 
        key(key), leftchild(leftchild), rightchild(rightchild), parent(parent), color(color) {}
};

class rbt{
    public:
        Node* root;

        //constructors

        rbt();
        rbt(Node* root);

        //Member functions
        void printrbt(Node* node, const string& prefix, bool isLeft=false);
        void insert(int key);
        void rrvio(Node* node1, Node* node2);
        void del(int key);
        Node* find(int key);
};