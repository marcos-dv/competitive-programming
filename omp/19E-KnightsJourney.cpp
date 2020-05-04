#include <bits/stdc++.h>
#define push_back pb

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MAXN = 2002;

int arr[MAXN][MAXN], visited[MAXN][MAXN];

int main() {
	int casos;
	cin >> casos;
	int n,m,x,y;
	ii posibles[] = {ii(1,2),ii(1,-2),ii(	-1,2),ii(-1,-2),ii(2,1),ii(2,-1),ii(-2,1),ii(-2,-1)};
	while(casos--){
		cin >> n >> m >> x >> y;
		memset(visited,0, sizeof(visited));
		memset(arr,0,sizeof(arr));
		int maxi = 0;
		queue<ii> q;
		visited[x][y]=true;
		q.emplace(x,y);
		while(!q.empty()){
			ii v = q.front();
			maxi = max(maxi, arr[v.first][v.second]);
			q.pop();
			//	cerr << v.first << " " << v.second << " " << arr[v.first][v.second]<<endl;
			for(const ii p : posibles){
				ii aux = ii(p.first+v.first, p.second+v.second);
				if(0<=aux.first && aux.first < n && 0<= aux.second && aux.second<m && !visited[aux.first][aux.second]){
					visited[aux.first][aux.second]=true;
					q.push(aux);
					arr[aux.first][aux.second] = arr[v.first][v.second] + 1;
				}
			}
		}
		cout << maxi << endl;
		
	}
}
