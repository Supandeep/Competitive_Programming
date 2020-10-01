/*
    author : Supandeep Singh
    codechef handle @supandeep
    codeforces handle @_Shinigami
*/
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl '\n'
#define M 1000000007
//#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define omset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(NULL);ios_base::sync_with_stdio(false);cout.tie(NULL);

using namespace std;
//using namespace __gnu_pbds;

void matMul(ll a[3][3] , ll b[3][3]) {
    ll res[3][3];

    for(int i=0 ; i<3 ; i++) {
        for(int j=0 ; j<3 ; j++) {
            res[i][j] = 0;
            for(int k=0 ; k<3 ; k++) {
                res[i][j] = ((ll)res[i][j] + ((ll)(a[i][k]*b[k][j])) % M) % M;
            }
        }
    }

    for(int i=0 ; i<3 ; i++) {
        for(int j=0 ; j<3 ; j++) {
            a[i][j] = res[i][j];
        }
    }

}

int matPow(ll mat[3][3] , ll n) {
    //if(n == 0)
       // return 0;
    if(n == 1)
        return mat[0][0] + mat[0][2];

    matPow(mat , n/2);
    ll m[3][3] = {{1 , 1 , 1} , {1 , 0 , 0} , {0 , 0 , 1}};
    matMul(mat , mat);

    if(n % 2 != 0) {
        matMul(mat , m);
    }

    return (int)(((ll)(mat[0][0]%M + mat[0][2]%M)) % M);
}

int main() {

    fastio
    /*
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    */
    ll t;
    cin>>t;

    while(t--) {

        ll n , m;
        cin>>n>>m;
        //n++ , m++;
        //cout<<"huha"<<endl;
        ll mat[3][3] = {{1 , 1 , 1} , {1 , 0 , 0} , {0 , 0 , 1}};
        ll Sn = -1 , Sm = -1;
        //int ans;
        if(n <= 2)
            Sn = n-1;
        if(m <= 2)
            Sm = m;
        if(n == 0)
            Sn = 0;
        if(Sn == -1 && Sm == -1) {
            Sn = matPow(mat , n-2);
            ll mat[3][3] = {{1 , 1 , 1} , {1 , 0 , 0} , {0 , 0 , 1}};
            Sm = matPow(mat , m-1);
        } else if(Sn == -1) {
            Sn = matPow(mat , n-2);
        } else if(Sm == -1) {
            Sm = matPow(mat , m-1);
        }
        //cout<<"Sm : "<<Sm<<"  Sn : "<<Sn<<endl;
        cout<<(Sm%M - Sn%M + M)%M<<endl;

    }
    return 0;
}