#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>

using namespace std; 

struct point
{
	long long h;
	long long child;
	long long code;

};

bool sorth(point A, point B)
{
    return A.h>B.h;
}

struct edge
{
	long long v;
	long long w;
};

void createEdge(long long a, long long b, long long c, vector<vector<edge> >&graph)
{
	edge temp;

	temp.v = b-1;
	temp.w = c;//value of edge

    graph[a-1].push_back(temp);

	temp.v = a-1;
	temp.w = c;

    graph[b-1].push_back(temp);
}


long long DFS( vector<vector<edge> > &graph, long long node, long long dis, long long &maxNode, long long &maxD, vector<long long>&visit, vector<point>&Point, long long h)
{
	visit[node] = 1 ;
    // vector<long long> temp(2,0);

    if( dis > maxD )
    {
        maxNode = node ;
        maxD = dis ;
    }

    h = 0;

    if(graph[node].size() != 0)
    {
	    for(long long i = 0; i < graph[node].size(); i++)
	    {
	    	if(visit[graph[node][i].v] == 0)
	    	{
	    		h = DFS(graph , graph[node][i].v, dis+graph[node][i].w, maxNode, maxD, visit, Point, h) + graph[node][i].w;
	    		if(h >= Point[node].h)
	    		{
	    			if(Point[node].h != 0)
	    			{
	    				Point[Point[node].child].h = Point[node].h;
	    			}
	    			Point[node].h = h;
	    			Point[node].child = graph[node][i].v;
	    		}
	    		else
	    		{
	    			Point[graph[node][i].v].h = h;
	    		}
	    	}
	    }
	}
    if(Point[node].child != -1)
    {
    	Point[Point[node].child].h = 0;
    }
    return Point[node].h;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long maxD = -1;
	long long maxNode = -1 ;
	long long n;//cities
	long long u;
	long long v;
	long long d;//value
	long long h = 0;

	cin >> n;

	vector<long long> visit(n,0);//走過的點
	vector<long long> ans;

    vector<vector<edge> >graph(n);//store edges
    vector<point> Point;
    vector<point> Point2;

    for(long long i = 0; i < n-1; i++)
    {
    	cin >> u;
    	cin >> v;
    	cin >> d;//1,2,3 -> 0,1,2
    	createEdge( u, v, d, graph);
    }

    point temp;
    for (long long i = 0; i < n; i++)
    {
    	temp.code = i;
    	temp.h = 0;
    	temp.child = -1;
    	Point.push_back(temp);
    }

    Point2.assign(Point.begin(),Point.end());

    DFS(graph , 0, 0, maxNode, maxD, visit, Point2, h);

    maxD = -1;
    visit.clear();
    visit.assign(n,0);

    long long root = maxNode;
    DFS( graph , root, 0, maxNode, maxD, visit, Point, h);

    sort(Point.begin(), Point.end(), sorth);

    ans.push_back(0);//k=1
    for(long long i = 0; i < n-1; i++)
    {
    	ans.push_back(Point[i].h + ans[ans.size()-1]);
    }

	for(long long i = 0; i < ans.size(); i++)
    {
    	printf("%lld ", ans[i]);//debug
    }

    return 0;

}