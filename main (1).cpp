#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <limits>
#include <stack>
using namespace std;
class Vertex
{
public:
    int Data;
    list <pair <int, int> > AdjacencyList;
};
list<Vertex> Graph;
class Edge
{
public:
    int cost,time;
    bool visited;
};
void menu()
{
    cout << "****************************************" << endl;
    cout << "Enter the number of your choice:" << endl;
    cout << "1.Problem 1." << endl;
    cout << "2.Problem 2." << endl;
    cout << "3.Problem 3." << endl;
    cout << "4.Exit." << endl;
}
bool Check(int n)
{
    bool found = false;
    list<Vertex> ::iterator i;
    for (i = Graph.begin(); i != (Graph.end()); i++)
    {
        if ((*i).Data == n)
        {
            found = true;
            break;
        }
    }
    return found;
}
void AddEdge(int u, int v, int weight)
{
    pair<int, int> PairTemp;
    bool flag;
    PairTemp.first = v;
    PairTemp.second = weight;
    flag = Check(u);
    if (flag == false)
    {
        Vertex NewVertex;
        NewVertex.Data = u;
        NewVertex.AdjacencyList.push_back(PairTemp);
        Graph.push_back(NewVertex);
    }
    else
    {
        list<Vertex> ::iterator i;
        for (i = Graph.begin(); i != (Graph.end()); i++)
        {
            if ((*i).Data == u)
            {
                (*i).AdjacencyList.push_back(PairTemp);
            }
        }
    }
    PairTemp.first = u;
    flag = Check(v);
    if (flag == false)
    {
        Vertex NewVertex;
        NewVertex.Data = v;
        NewVertex.AdjacencyList.push_back(PairTemp);
        Graph.push_back(NewVertex);
    }
    else
    {
        list<Vertex> ::iterator i;
        for (i = Graph.begin(); i != (Graph.end()); i++)
        {
            if ((*i).Data == v)
            {
                (*i).AdjacencyList.push_back(PairTemp);
            }
        }
    }
}
void PrintGraph()
{
    list<Vertex> ::iterator i;
    list<pair<int, int> > ::iterator j;
    for (i = Graph.begin(); i != (Graph.end()); i++)
    {
        cout << (*i).Data << "-->";
        for (j = ((*i).AdjacencyList).begin(); j != (((*i).AdjacencyList).end()); j++)
        {
            cout << (*j).first << " (weight= " << (*j).second << ") ";
        }
        cout << endl;
    }
}
void   PeopleAtK(int StartVertex, int k)
{
    Vertex start;
    Vertex top;
    Vertex v;
    vector<int> in;
    queue<Vertex> Q;
    list<Vertex> ::iterator i;
    for (i = Graph.begin(); i != (Graph.end()); i++)
    {
        if ((*i).Data == StartVertex)
        {
            start = *i;
            break;
        }
    }
    Q.push(start);
    in.push_back(start.Data);
    bool f = true;
    int s = k;
    list<pair<int, int> >::iterator j;
    while (k > 0)
    {
        int s = Q.size();
        for (int x = 0; x < s; x++)
        {
            top = Q.front();
            for (j = top.AdjacencyList.begin(); j != top.AdjacencyList.end(); j++)
            {
                int temp = (*j).first;
                for (i = Graph.begin(); i != (Graph.end()); i++)
                {
                    if ((*i).Data == temp)
                    {
                        v = *i;
                        break;
                    }
                }
                for (int u = 0; u < in.size(); u++)
                {
                    if (in.at(u) == v.Data)
                    {
                        f = false;
                        break;
                    }
                }
                if (f == true)
                {
                    Q.push(v);
                    in.push_back(v.Data);
                }
                f = true;
            }
            Q.pop();
        }
        k--;
    }
    cout << "There are" << Q.size() << "people with" << s << "connections away starting from" << StartVertex << endl;
}
void Problem1()
{
    int NumberOfVertices, NumberOfEdges, StartVertex, k, u, v;
    bool flag;
    cout << "please enter number of vertices:" << endl;
    cin >> NumberOfVertices;
    cout << "please enter number of edges: " << endl;
    cin >> NumberOfEdges;
    cout << "please enter edges in the form (u v): ";
    for (int i = 0; i < NumberOfEdges; i++)
    {
        cin >> u >> v;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        AddEdge(u, v, 1);
    }
    cout << "please enter starting vertex:";
    cin >> StartVertex;
    cout << "please enter value k :";
    cin >> k;
    PeopleAtK(StartVertex, k);
    PrintGraph();
}
void Problem2() {
    int N;
    stack <pair <int, int> > visited;
    pair <int, int> x;
    list<pair <int, int> > output;
    x.first = 0; //row
    x.second = 0; //col
    visited.push(x);
    cout << "please enter N: " << endl;
    cin >> N;
    int GraphMat[100][100];
    cout << "please enter values for maze:" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> GraphMat[i][j];
        }
    if (GraphMat[0][0] == 1 || GraphMat[N - 1][N - 1] == 1)
    {
        cout << "There is no path" << endl;
        return;
    }
    pair<int, int> temp = visited.top();
    while (!visited.empty() && (temp.first < N && temp.second < N))
    {
        //cout<<"in\n";
        while (GraphMat[temp.first][temp.second] == 0 && temp.second < N && temp.first < N) // goes right
        {
            temp.second++;
            visited.push(temp);
        }
        if (temp.second < N && temp.first < N)
        {
            visited.pop();
            if(!visited.empty())
                temp = visited.top();
        }
        if (temp.second == N) {
            visited.pop();
if(!visited.empty())
        temp = visited.top();        }
        visited.pop();
        int p=0;
        int t=0;
        if(!visited.empty())
        {
            pair<int, int> parent = visited.top();
             p=parent.first;
             t=temp.first;

        }
        visited.push(temp);
        if( temp.first < N && GraphMat[temp.first+1][temp.second] == 0)
        {if(p>t)
        {
            GraphMat[temp.first][temp.second]=1;
            visited.pop();
            if(!visited.empty())
        temp = visited.top();


        }
            else
            {temp.first++;
            visited.push(temp);}
        }else if( temp.first > 0  && GraphMat[temp.first-1][temp.second] == 0)
        {if(p<t)
        {
            GraphMat[temp.first][temp.second]=1;
            visited.pop();
            if(!visited.empty())
        temp = visited.top();


        }
           else{ temp.first--;
            visited.push(temp);}

        }else{GraphMat[temp.first][temp.second]=1;
        visited.pop();
        if(!visited.empty())
        temp = visited.top();
        }
    }
    if (visited.empty())
    {
        cout << "There is no path"<<endl;
    }
    else
    {
        stack <pair <int, int> > Extra;
        visited.pop();
        cout << "There is a path" << "\n";
        while (!visited.empty())
        {
            Extra.push(visited.top());
            visited.pop();
        }
        while (!Extra.empty())
        {
            cout << "(" << Extra.top().first << "," << Extra.top().second << ")";
            Extra.pop();
        }
        cout << endl;
    }
}
Edge Create_Edge(int time, int cost)
{
    Edge e;
    e.cost=cost;
    e.time=time;
    e.visited=false;
    return e;
}
void Problem3()
{
    int M,V,E,s,d,t,c;
    int src,dest;
    int min_cost,min_time;
    queue <int> temp;
    queue <int> path;
    cout << "Please enter amount M: \n";
    cin >> M;
    cout << "Please enter number of cities: \n";
    cin >> V;
    cout << "Please enter number of routes: \n";
    cin >> E;
    Edge edges[V+1][V+1];
    for(int m=0;m<V+1;m++)
    {
        for(int k=0;k<V+1;k++)
            edges[m][k]=Create_Edge(-1,-1);
    }
    for(int i=0;i<E;i++)
    {
        cout << "Please enter source , destination, time and cost for each route: \n";
        cin >> s >> d >> t >> c;
        edges[s][d].time=t;
        edges[s][d].cost=(M*t)+c;
        edges[d][s].time=t;
        edges[d][s].cost=(M*t)+c;
    }
    cout << "Please enter source city: \n";
    cin >> src;
    cout << "Please enter destination city: \n";
    cin >> dest;
    min_cost=INT_MAX;
    min_time=INT_MAX;
    int temp_src=src;
    int temp_cost=0,temp_time=0;

    int counter=0;
    for(int k=0;k<V+1;k++)
    {
        if(edges[src][k].cost!=-1)
            counter++;
    }
    int j;
    bool flag=false;
    for(int i=0;i<counter;i++)
    {
        temp.push(src);
        for(j=0;j<V+1;j++)
        {
            if(!edges[src][j].visited && edges[src][j].cost!=-1)
            {
                temp.push(j);
                temp_cost+=edges[src][j].cost;
                temp_time+=edges[src][j].time;
                edges[src][j].visited=true;
                edges[j][src].visited=true;
                if(j!=dest)
                {
                    int check=src,ct=0;
                    src=j;
                    for(int m=0;m<V+1;m++)
                    {
                        if(edges[src][m].cost!=-1 && !edges[src][m].visited)
                            ct++;
                    }
                    if(ct>1)
                        edges[check][j].visited=false;
                    j=0;
                    temp_cost+=M;
                    temp_time+=1;
                }
                else
                {
                  src=temp_src;
                  flag=true;
                  break;
                }

            }
        }
        if(j==V+1 && !flag)
               {
                  src=temp_src;
                  j=0;
                  temp_cost=temp_time=0;
                  while(!temp.empty())
                  temp.pop();
               }
        if(temp_cost>0 && temp_time>0 && flag){
        if(temp_cost<min_cost)
                {
                min_cost=temp_cost;
                min_time=temp_time;
                temp_cost=temp_time=0;
                if(!path.empty())
                {
                    while(!path.empty())
                        path.pop();
                }
                while(!temp.empty())
                {
                int x=temp.front();
                path.push(x);
                temp.pop();
                }
            }
        else
        {
            while(!temp.empty())
                temp.pop();
            temp_cost=temp_time=0;
        }
        flag=false;
        }

    }
    if(!path.empty()){
    cout << "The route with minimum cost is ";
    int p=path.front();
    path.pop();
    cout<<p;
    while(!path.empty())
    {
        p=path.front();
        cout<< " -> ";
        cout<< p;
        path.pop();
    }
    cout <<"\n";
    cout<< "Total time " << min_time <<" hours"<<endl;
    cout<< "Total cost = "<<min_cost <<"$" <<endl;
    }
    else
        cout<<"There is no path.\n";
}
int main()
{
    menu();
    int x;
    cin >> x;
    while (x != 4)
    {
        if (x == 1)
            Problem1();
        else if (x == 2)
            Problem2();
        else if (x == 3)
            Problem3();
        menu();
        cin >> x;
    }
}
