#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N,score[100][100],sum[100],ans[100];
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>score[i][0];
		sum[i]=0;
		ans[i]=0;
		for(int j=0;j<score[i][0];j++)
		{
			cin>>score[i][j+1];
			sum[i]+=score[i][j+1];
		}
		for(int j=0;j<score[i][0];j++)
		{
			if(score[i][j+1]*score[i][0]>sum[i])
			{
				ans[i]+=1;
			}
		}
		ans[i]*=100;
		cout<<fixed<<setprecision(3)<<float(ans[i])/score[i][0]<<"%"<<endl;
	}
}
