#include <bits/stdc++.h> 
#include <string.h>
using namespace std;
int main()
{
	int T,i;
	int x=0;
	cin>>T;
	string result[10];
	while(x<T)
	{
	int N;
	cin>>N;	

	int vill[N];
	int energy[N];

	for(i=0;i<N;i++)
	{
		cin>>vill[i];
	}
	sort(vill,vill+N,greater<int>() );

	for(i=0;i<N;i++)
	{
		cin>>energy[i];
	}
	sort(energy,energy + N,greater<int>());
	int flag=1;
	for(i=0;i<N;i++)
	{
		if(energy[i]>vill[i])
		{
			continue;
		}
		else
		{
			flag=0;
			break;
		}
	}

	if(flag==1)
		result[x]="WIN\n";
	
	else
		 result[x]="LOSE\n";

	x++;
	}

	for(int j=0;j<=x;j++)
	{
		cout<<result[j];
	}
	
}
