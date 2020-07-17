#include<iostream>
#include "Tree.h"
#include "Graph.h"

using namespace std;

int main()
{
    Birbtree tree;
    Node A(36), B(16), C(41), D(4), E(22), F(39),G(48),
         H(3),I(9),J(19),K(27),L(45),M(52), N(1), O(7),
         P(10),Q(24),R(51),S(55);
    tree.Insert(&A); tree.Insert(&B); tree.Insert(&C); tree.Insert(&D);
    tree.Insert(&E); tree.Insert(&F); tree.Insert(&G); tree.Insert(&H);
    tree.Insert(&I); tree.Insert(&J); tree.Insert(&K); tree.Insert(&L);
    tree.Insert(&M); tree.Insert(&N); tree.Insert(&O); tree.Insert(&P);
    tree.Insert(&Q); tree.Insert(&R); tree.Insert(&S);  

    tree.Inorder_traversal();
    tree.LevelOrder_traversal();


    double input_data[10]={2.2,5.6,7.5,9.1,3.4,6.4,8.8,1.3,12.7,14.6};
    int arr[10][10]={
            {0,1,1,0,0,0,0,0,0,0},
            {1,0,0,1,1,0,0,0,0,0},
            {1,0,0,0,0,1,1,0,0,0},
            {0,1,0,0,0,0,0,1,0,0},
            {0,1,0,0,0,0,0,1,0,0},
            {0,0,1,0,0,0,0,0,1,0},
            {0,0,1,0,0,0,0,0,1,0},
            {0,0,0,1,1,0,0,0,0,1},
            {0,0,0,0,0,1,1,0,0,1},
            {0,0,0,0,0,0,0,1,1,0}
    };

    vector< vector<int> > input_vector;
    for(int i=0;i<10;++i)
    {
        input_vector.push_back(vector<int>());
        for(int j=0;j<10;++j)
        {
            input_vector.at(i).push_back(arr[i][j]);
        }
    }

    UndirectedGraph<double> gg(input_vector,input_data);

    gg.print_adjacency();
    for(int i=0;i<input_vector.size();++i)
    {
        gg.BFS(i);
        gg.DFS(i);
    }

    return 0;
}