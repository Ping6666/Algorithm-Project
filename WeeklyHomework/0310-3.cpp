#include <iostream>
using namespace std;

int main()
{
	int num,N,i=0;
	int primenum[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int primecount[25]={0};
	cin>>num;
	N=num;
	while(num!=1)
	{
		if(num%primenum[i]==0)
		{
			num/=primenum[i];
			primecount[i]+=1;
		}
		else
		{
			i+=1;
		}
	}
	cout<<N<<"=";
	for(int j=0;j<25;j++)
	{
		if(j==0)
		{
			if(primecount[j]==1)
			{
				cout<<primenum[j];
			}
			else if(primecount[j]>1)
			{
				cout<<primenum[j]<<"^"<<primecount[j];
			}
		}
		else
		{
			if(primecount[j]==1)
			{
				cout<<"*"<<primenum[j];
			}
			else if(primecount[j]>1)
			{
				cout<<"*"<<primenum[j]<<"^"<<primecount[j];
			}
		}
	}
	cout<<endl;
}
