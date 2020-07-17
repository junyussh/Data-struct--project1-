//
// Created by USER on 7/4/2020.
//

#ifndef PROJECT___C___DATA_STRUCT_TREE_H
#define PROJECT___C___DATA_STRUCT_TREE_H

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

enum Color{red ,black};

struct Node{
    Node* parent;
    Node* left;
    Node *right;
    int key;
    Color color;
    Node(int n=0)
    {
        parent = nullptr;
        left = nullptr;
        right=nullptr;
        key=n;
        color=red;
    }

};

class Bitree{
public:
    Bitree();
    void Preorder_traversal();
    void Inorder_traversal();
    void Postorder_traversal();
    void LevelOrder_traversal();
    Node* successor(Node*);
    Node* predecessor(Node* );

    virtual  Node*  search(Node* );
    virtual  void  Insert(Node* );
    virtual  void  Delete(Node* );

protected:
    Node* head;
    vector<Node* > Preorder;
    vector<Node* > Inorder;
    vector<Node* > Postorder;
    void reset_data();

private:
    void preorder_traversal(Node* );
    void inorder_traversal(Node* );
    void postorder_traversal(Node* );

};
///////////////////////////////////////////////////////////////////////////////////////
class Bistree: public Bitree{
public:
    Bistree();
    Node* search(Node*) override;
    virtual Node* search(int );
    Node* max();
    Node* min();
    void Insert(Node* ) override;
    void Delete(Node* ) override;
};



//////////////////////////////////////////////////////

class Birbtree: public Bistree
{
public:
    Birbtree();
    void Insert(Node *) override;
    void Delete(Node* ) override;

protected:
    void LeftRotation(Node* );
    void RightRotation(Node* );
    void InsertFix(Node* );
    void DeleteFix(Node* );

private:
    bool fake_guard= false;
};

#endif //PROJECT___C___DATA_STRUCT_TREE_H