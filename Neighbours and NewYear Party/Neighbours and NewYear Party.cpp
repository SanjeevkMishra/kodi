#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t,n,i,j,k,bax,y;
	int* a;
	cin>>t;
	for(i=0;i<t;i++)
  {
		cin>>n;
		int flag=0;
		int z=0;
		a = (int*)calloc(n,sizeof(int));
		for(j=0;j<n;j++)
    {
			cin>>a[j];
		}
		int *max=std::max_element(a, a + n);
		bax = *max;
		for(j=0;j<n-2;j++)
    {
			for(k=j+2;k<n;k++)
      {
			    if((a[j]+a[k]>=bax)&&(a[k]>=z)&&(a[k]!=0)&&(a[j]!=0)){
				    bax=a[j]+a[k];
					z=a[k];y=a[j];
					flag=1;
				}
			}
		}
		if(flag==1)
		  cout<<z<<y<<endl;
		else
		  cout<<bax<<endl;
	}
	
}
