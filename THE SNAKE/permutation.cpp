#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


vector<int>v;
map<int,bool>vs;
long long n;
void next()
{
	if(v.size()==n)
	{
		for(int i=0;i<n-1;i++)
		//	cout <<v[i]<<" ";
	    //cout <<v[n-1]<<"\n";
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vs[i])
			continue;
		v.push_back(i);
		cout <<i<<"\n";
		vs[i]=1;
		next();
		vs[i]=0;
		v.pop_back();
	}
}

int main()
{
    cin>>n;
    next();
}


