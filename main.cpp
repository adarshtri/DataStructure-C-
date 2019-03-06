#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
    binarytree *btree = new binarytree();
    btree->insertnode(btree->getroot(),10);
    btree->insertnode(btree->getroot(),5);

    btree->inorder(btree->getroot());
    return 0;
}
