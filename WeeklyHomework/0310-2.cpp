#include <iostream>
using namespace std;

int main()
{
	int N,a,b,sum;
	cin>>N;
	int primenum[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	for(int i=0;i<N;i++)
	{
		cin>>a>>b;
		sum=0;
		for(int j=a;j<=b;j++)
		{
			if(j%2) sum+=j;
		}
		for(int j=0;j<25;j++)
		{
			if((primenum[j]>a&&primenum[j]<b)||primenum[j]==a||primenum[j]==b)
			{
				sum-=primenum[j];
			}
		}
		cout<<sum<<endl;
	}
}
