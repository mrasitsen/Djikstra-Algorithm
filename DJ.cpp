#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

//djikstra algoritmasi, input olarak matrix alir

#define vertices 9

using namespace std;


class myComparator 
{ 
public: 
    bool operator() (const pair<int,int>& p1, const pair<int,int>& p2) 
    { 
        return p1.first > p2.first; 
    } 
}; 

//operator overloading ogren

// int operator<(const pair<int,int> &X,const pair<int,int> &Y){
// 	return X.first>Y.first;
// }

void Djikstra(vector< vector<int> > &V, int src){

	priority_queue < pair<int,int>, vector<pair<int,int> >, myComparator> pq; //queue
	//, 
	pair<int,int> pr; //pair
	pair<int,int> xx;
	bool flag[vertices];
	int dist[vertices];
	for (int i = 0; i < vertices; ++i)
	{
		flag[i] = 0;
		dist[i] = 999;
	}

	dist[src] = 0;

	pr.first = V[src][src]; //her daim 0
	pr.second = src; //head(ilk seferde kendisine loop yapacak)
	

	pq.push(pr);

	while(!pq.empty()){
		pr = pq.top();
		pq.pop();
		src = pr.second;
		// cout<<" source: "<<src<<"\n";
		if(!flag[src]){
			for (int i = 0; i < vertices; ++i)
			{
				if(V[src][i] != 0 && dist[i] > V[src][i] + pr.first){
					dist[i] = V[src][i] + pr.first;
					xx.first = dist[i];
					xx.second = i;
					// cout<<"pushed inside queue: pair<"<<xx.first<<","
					// 	<<xx.second<<">\n";
					pq.push(xx);
				}
			}

		// for (int i = 0; i < vertices; ++i)
		// {
		// 	cout<<i<<" --> "<<dist[i]<<"\n";
		// }

		flag[src] = 1;
		}
	}
	cout<<"------------final-------------\n";
	for (int i = 0; i < vertices; ++i)
	{
		cout<<i<<" --> "<<dist[i]<<"\n";
	}
}
		
int main(){

	 vector<vector<int> > vect{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
		                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
		                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
		                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
		                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
		                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
		                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
		                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
		                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	Djikstra(vect, 0);

	return 0;
}





