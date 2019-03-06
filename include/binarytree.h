#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstddef>
#include<iostream>
using namespace std;

class Node{

    private:
        int data;
        Node *lchild;
        Node *rchild;

    public:

        Node(){
            this->data = 0;
            this->lchild = NULL;
            this->rchild = NULL;
        }

        Node(int x){
            this->data = x;
            this->lchild = NULL;
            this->rchild = NULL;
        }

        int getdata(){
            return this->data;
        }

        Node * getlchild(){
            return this->lchild;
        }

        Node * getrchild(){
            return this->rchild;
        }

        void setlchild(Node *lchild){
            this->lchild = lchild;
        }

        void setrchild(Node *rchild){
            this->rchild = rchild;
        }

};

class binarytree
{
    public:
        binarytree();
        virtual ~binarytree();

        Node * getroot(){
            return this->root;
        }

        Node* insertnode(Node* node, int value){

            if(node == nullptr || node->getdata() == value){

                Node *newnode = new Node(value);

                if(node == this->root){
                    this->root = newnode;
                }

                return newnode;
            }

            if(node->getdata() > value)
                node->setlchild(insertnode(node->getlchild(),value));

            else
                node->setrchild(insertnode(node->getrchild(),value));

            return node;
        }

        void inorder(Node *root){

            if(root == nullptr)
                return;

            inorder(root->getlchild());
            cout<<root->getdata()<<endl;
            inorder(root->getrchild());
        }

        void preorder(Node *root){

            if(root == nullptr)
                return;

            cout<<root->getdata()<<endl;
            preorder(root->getlchild());
            preorder(root->getrchild());
        }

        inline void postorder(Node *root);
        inline bool iscontinous(Node *root);
        inline bool isMirrorWithoutData(Node *roota, Node *rootb);
        inline bool isfoldable(Node *root);

    protected:

    private:
        Node *root;
};

void binarytree::postorder(Node *root){

    if(root == nullptr)
        return;
    postorder(root->getlchild());
    postorder(root->getrchild());
    cout<<root->getdata()<<endl;
}

bool binarytree::iscontinous(Node *root){

    if (root == nullptr)
        return true;

    if (root->getlchild() == nullptr && root->getlchild() == nullptr)
        return true;


    if(root->getlchild() == nullptr){
        if (abs(root->getdata() - root->getrchild()->getdata()) == 1 && iscontinous(root->getrchild()))
            return true;
        return false;
    }

    if(root->getrchild() == nullptr){
        if (abs(root->getdata() - root->getlchild()->getdata()) == 1 && iscontinous(root->getlchild()))
            return true;
        return false;
    }

    return abs(root->getdata() - root->getrchild()->getdata()) ==1 &&
           abs(root->getdata() - root->getlchild()->getdata()) ==1 &&
           iscontinous(root->getrchild()) &&
           iscontinous(root->getlchild());

}

bool binarytree::isMirrorWithoutData(Node *a, Node *b){

    if (a == nullptr && b == nullptr)
        return true;

    if (a == nullptr || b == nullptr)
        return false;

    return isMirrorWithoutData(a->getlchild(), b->getrchild()) &&
           isMirrorWithoutData(a->getrchild(), b->getlchild());

}


#endif // BINARYTREE_H
