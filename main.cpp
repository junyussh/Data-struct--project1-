#include<iostream>
#include "Tree.h"
#include "Graph.h"

using namespace std;

int main()
{
    Birbtree tree;
    Node *A = new Node(36), *B = new Node(16), *C = new Node(41), *D = new Node(4), *E = new Node(22), *F = new Node(39),*G = new Node(48),
         *H = new Node(3),*I = new Node(9),*J = new Node(19),*K = new Node(27),*L = new Node(45),*M = new Node(52), *N = new Node(1), *O = new Node(7),
         *P = new Node(10),*Q = new Node(24),*R = new Node(51),*S = new Node(55);
    tree.Insert(A); tree.Insert(B); tree.Insert(C); tree.Insert(D);
    tree.Insert(E); tree.Insert(F); tree.Insert(G); tree.Insert(H);
    tree.Insert(I); tree.Insert(J); tree.Insert(K); tree.Insert(L);
    tree.Insert(M); tree.Insert(N); tree.Insert(O); tree.Insert(P);
    tree.Insert(Q); tree.Insert(R); tree.Insert(S);  

    tree.Inorder_traversal();
    tree.LevelOrder_traversal();

    tree.Delete(S);
    tree.LevelOrder_traversal();
    //tree.Delete(&R);tree.LevelOrder_traversal();
    //tree.Delete(&Q);tree.LevelOrder_traversal();
    //tree.Delete(&P);tree.LevelOrder_traversal();
    //tree.Delete(&O);tree.LevelOrder_traversal();
    //tree.Delete(&N);tree.LevelOrder_traversal();
    //tree.Delete(&M);tree.LevelOrder_traversal();



    /*
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
    */

    return 0;
}