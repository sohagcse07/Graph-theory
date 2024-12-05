//In the name of ALLAH

// Insallah one day success will be your

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
 
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define U upper_bound
#define L lower_bound
#define all(a) (a).begin(),(a).end()
#define mid(l,r) ((r+l)/2)

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
 
#define mem(a,b) memset(a, b, sizeof(a) )
#define gcd(a,b) __gcd(a,b)
#define sqr(a) ((a) * (a))

const int mx = 1e5+135;

vector<vector<int>> adj[mx];

ll dist[mx];

int traincnt[mx];


void dijkstra ( int s , int n ){

	for ( int i=1; i<=n; i++ ) dist[i] = infLL;



	dist[s] = 0;

	priority_queue <pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;


	pq.push ( { 0 , s });


	while ( !pq.empty() ){

		int u = pq.top().S;

		ll curD = pq.top().F;
		pq.pop();


		if ( dist[u] < curD ) continue;


		for ( auto e:adj[u] ){

			int v = e[0];

			ll w = e[1];

			int type = e[2];


			if ( curD + w  < dist[v] ){

				dist[v] = curD + w;

				traincnt[v] = type;

				pq.push ( {dist[v] , v} );
			}

			else if ( curD + w == dist[v] && traincnt[v] == 1  && type == 0 ){

				traincnt[v] = 0;
			}
		}
	}
}



int32_t main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);


  int n , m , k;

  cin>> n >> m >> k;


  for ( int i=1; i<=m; i++ ){

  	int u , v , w;
  	cin>> u >> v >> w;

  	adj[u].PB ( {v , w , 0 });
  	adj[v].PB ( { u , w , 0 });
  }



  for ( int i=1; i<=k; i++ ){

  	int u , w;
  	cin>> u >> w;

  	adj[1].PB ( { u , w , 1 });
  	adj[u].PB ( { 1 , w ,1 });
  }

  dijkstra ( 1 , n );

  int ans  = 0;

  for ( int i=1; i<=n; i++ ){

  	ans += traincnt[i];
  }


  cout << k - ans << endl;


    return 0;
}


// 1.Understand the problem

// 2.Plan 

// 3.Divide & Conquor  // part by part a problem

// 4. Stuck while coding 

// practice must be