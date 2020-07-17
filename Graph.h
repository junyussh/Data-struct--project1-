//
// Created by USER on 6/25/2020.
//

#ifndef TEST_GRAPH_GRAPHBASIC_H
#define TEST_GRAPH_GRAPHBASIC_H


#include<iostream>
#include<vector>
#include<deque>

using namespace std ;

struct List_node{
    double Edge_weight;
    int connect_node;
    List_node(int connect_node_input=0, double Edge_weight_input=0.0)
    {
        Edge_weight=Edge_weight_input;
        connect_node=connect_node_input;
    }
};


template<typename T=int>
class UndirectedGraph{

public :
    //----- debug function -----//
    void print_adjacency();
    void print_distance();
    void print_predecessor();

    //-----basic ctor dtor and set function of graph -----//
    UndirectedGraph();
    UndirectedGraph(vector< vector<int> >& input, T* inputdata);//ctor by matrix
    ~UndirectedGraph();
    void set(vector< vector<int> >& input , T* inputdata);//set by matrix

    //---- basic function of graph-----//
    void DFS(int start_number=0);
    void BFS(int start_number=0);
    vector<int> Shortest_path(int start_number, int target_number);

private:
    //-----data of basic graphic-----//
    void transfer_matrix_to_list();
    vector< vector<int> > adjacency_matrix;
    vector< vector<List_node> > adjacency_list;
    T* data;

    //----- mechanism  of dfs  -----//
    vector< vector<int> > dfs_order;
    void dfs_visited(int start_number, int node_number,bool* visited);

    //----- mechanism of bfs -----//
    vector< vector<int> > bfs_order;
    vector< vector<int> > shortest_distance;
    vector< vector<int> > bfs_predecessor;
};

/////////////    basic ctor and output (below)     ////////////////

template<typename T>
UndirectedGraph<T>::UndirectedGraph()
{
    data= nullptr;
}

template<typename  T>
UndirectedGraph<T>::UndirectedGraph(vector< vector<int> > &input, T *inputdata)
{
    //----- copy input  to matrix and build list-----//
    adjacency_matrix=input;
    transfer_matrix_to_list();

    //----- adjacency_list.size() equal to adjacency_matrix.size() -----//
    //----- which means number of node in Graph -----//
    //----- allocate the space which record data used in graph algorithm-----//
    for (int i = 0; i <adjacency_list.size() ; ++i)
    {
        dfs_order.push_back( vector<int>() );
        bfs_order.push_back( vector<int>() );
        bfs_predecessor.push_back( vector<int>() );
        for (int j = 0; j <adjacency_list.size() ; ++j)
        {
            bfs_predecessor.at(i).push_back(-1);
        }
        shortest_distance.push_back( vector<int>() );
        for (int j = 0; j <adjacency_list.size() ; ++j)
        {
            shortest_distance.at(i).push_back(-1);
        }
    }

    //----- copy input to data -----//
    data = new T[adjacency_list.size()];
    for(int i=0;i<adjacency_list.size();++i)
    {
        data[i]=inputdata[i];
    }
}

template<typename T>
UndirectedGraph<T>::~UndirectedGraph()
{
    if(data!= nullptr)
        delete data;
}

template<typename T>
void UndirectedGraph<T>::set(vector<vector<int> > &input, T *inputdata)
{
    adjacency_matrix=input;
    transfer_matrix_to_list();

    for (int i = 0; i <adjacency_list.size() ; ++i)
    {
        dfs_order.push_back( vector<int>() );
        bfs_order.push_back( vector<int>() );
        bfs_predecessor.push_back(vector<int>() );
        for (int j = 0; j <adjacency_list.size() ; ++j)
        {
            bfs_predecessor.at(i).push_back(-1);
        }
        shortest_distance.push_back( vector<int>() );
        for (int j = 0; j <adjacency_list.size() ; ++j)
        {
            shortest_distance.at(i).push_back(-1);
        }
    }

    data = new T[adjacency_list.size()];
    for(int i=0;i<adjacency_list.size();++i)
    {
        data[i]=inputdata[i];
    }
}

template<typename T>
void  UndirectedGraph<T>::transfer_matrix_to_list()
{
    for(int i=0;i<adjacency_matrix.size();++i)
    {
        adjacency_list.push_back( vector<List_node>() );
        for(int j=0;j<adjacency_matrix.at(i).size();++j)
        {
            if(adjacency_matrix.at(i).at(j)>0)
            {
                adjacency_list.at(i).push_back(List_node(j,adjacency_matrix.at(i).at(j)));
            }
        }
    }
}

template<typename  T>
void UndirectedGraph<T>::print_adjacency()
{

    cout<<"adjacency list: "<<endl;
    for(int i=0;i<adjacency_list.size();++i)
    {
        cout<<i+1<<" : ";
        for(int j=0;j<adjacency_list.at(i).size();++j)
        {
            cout<<adjacency_list.at(i).at(j).connect_node
                <<"("<<adjacency_list.at(i).at(j).Edge_weight<<") ";
        }
        cout<<endl;
    }

}

template<typename T>
void UndirectedGraph<T>::print_distance()
{
    for (int i = 0; i < shortest_distance.size(); ++i)
    {
        cout<< "shortest path from "<<i+1<<" : ";
        for (int j = 0; j <shortest_distance.at(i).size() ; ++j)
        {
            cout<<shortest_distance.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
}

template<typename T>
void UndirectedGraph<T>::print_predecessor()
{
    for (int i = 0; i < bfs_predecessor.size(); ++i)
    {
        cout<< "Prodecessor in BFS start with  "<<i+1<<" : ";
        for (int j = 0; j <bfs_predecessor.at(i).size() ; ++j)
        {
            cout<<bfs_predecessor.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
}

/////////////    basic ctor and output  (above)    ////////////////

/////////////    basic graph function (below)      ////////////////


//dfs function/
template<typename T>
void UndirectedGraph<T>::DFS(int start_number)
{
    if(adjacency_list.empty())
    {
        cout<<"Graph has not implentment!"<<endl;
        return ;
    }
    else if(!dfs_order.at(start_number).empty())
    {
        //cout<<"this node already DFS!!"<<endl;
        cout<<"DFS order start with "<<start_number+1 <<" : " <<endl;
        for (int i = 0; i <dfs_order.at(start_number).size() ; ++i)
        {
            cout<<"Node "<<dfs_order.at(start_number).at(i)+1<<" : "<<data[dfs_order.at(start_number).at(i)]<<endl;
        }
        cout<<endl;
        return ;
    }

    bool visited[adjacency_list.size()];
    for (int i = 0; i <adjacency_list.size() ; ++i)
    {
        visited[i]= false;
    }

    cout<<"DFS order start with "<<start_number+1 <<" : " <<endl;
    dfs_visited(start_number,start_number,visited);
    return;
}

template<typename T>
void UndirectedGraph<T>::dfs_visited(int start_number ,int node_number,bool* visited)
{
    if(visited[node_number])
        return ;

    cout<<"Node "<<node_number+1<<" : "<<data[node_number]<<endl;
    visited[node_number]= true;
    dfs_order[start_number].push_back(node_number);
    for(int i = 0; i <adjacency_list.at(node_number).size() ; ++i)
    {
        if(!visited[adjacency_list.at(node_number).at(i).connect_node])
        {
            dfs_visited(start_number,adjacency_list.at(node_number).at(i).connect_node,visited);
        }
    }
    return;
}


//--bfs function//
template<typename  T>
void UndirectedGraph<T>::BFS(int start_number)
{
    //----- -----//
    if(adjacency_list.empty())
    {
        cout<<"Graph has not implentment!"<<endl;
        return ;
    }
    else if(!bfs_order.at(start_number).empty())
    {
        cout<<"this node already BFS!!"<<endl;
        cout<<"BFS order start with "<<start_number+1 <<" : " <<endl;
        for (int i = 0; i < bfs_order.at(start_number).size(); ++i)
        {
            cout<<"Node "<<bfs_order.at(start_number).at(i)+1<<" : "<<data[bfs_order.at(start_number).at(i)]<<endl;
        }
        return;
    }

    //-----  -----//
    bool visited[adjacency_list.size()];
    for(int i=0;i<adjacency_list.size();++i)
    {
        visited[i]= false;
    }

    //----- -----//
    deque<int > q;
    q.push_back(start_number);
    visited[start_number]=true;

    //----- -----//
    //int distance=0;
    shortest_distance.at(start_number).at(start_number)=0;

    cout<<"BFS start with "<<start_number+1<<" : "<<endl;
    //----- -----//
    while (!q.empty())
    {
        cout<<"Node "<<q.front()+1<<" : "<<data[q.front()]<<endl;
        bfs_order.at(start_number).push_back(q.front());
        //----- judge front node's connect node visited or not-----//
        for (int i = 0; i <adjacency_list.at(q.front()).size() ; ++i)
        {
            if(!visited[adjacency_list.at(q.front()).at(i).connect_node])
            {
                visited[adjacency_list.at(q.front()).at(i).connect_node]= true;
                bfs_predecessor.at(start_number).at(adjacency_list.at(q.front()).at(i).connect_node)=q.front();
                shortest_distance.at(start_number).at(adjacency_list.at(q.front()).at(i).connect_node)
                        =1+shortest_distance.at(start_number).at(bfs_predecessor.at(start_number).at(adjacency_list.at(q.front()).at(i).connect_node));
                q.push_back(adjacency_list.at(q.front()).at(i).connect_node);
            }
        }
        q.pop_front();
    }
    return;
}

template<typename T>
vector<int> UndirectedGraph<T>::Shortest_path(int start_number, int target_number)
{
    if(bfs_predecessor.at(start_number).empty())
    {
        BFS(start_number);
    }

    vector<int> temp_path;
    int father=bfs_predecessor.at(start_number).at(target_number);
    int current=target_number;


    while(father!=-1)
    {
        temp_path.push_back(current);
        int temp=father;
        father=bfs_predecessor.at(start_number).at(father);
        current=temp;
    }
    temp_path.push_back(current);

    cout<<"Shortest path between "<<start_number<<" and "<<target_number<<" is : ";
    for(int i=temp_path.size()-1;i>=0;--i)
        cout<<temp_path.at(i)<<" -> ";
    cout<<endl;

    return temp_path;
}

#endif //TEST_GRAPH_GRAPHBASIC_H