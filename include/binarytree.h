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

    protected:

    private:
        Node *root;
};

#endif // BINARYTREE_H
