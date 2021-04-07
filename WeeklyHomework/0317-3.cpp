#include<iostream>

int main()
{
	int n=1;
	std::cin>>n;
	while(n!=0)
	{
		int age[2000];
		for(int i=0;i<n;i++)
		{
			std::cin>>age[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(age[i]<age[j])
				{
					int num=age[i];
					age[i]=age[j];
					age[j]=num;
				}
			}
		}
		for(int i=0;i<n-1;i++)
		{
			std::cout<<age[i]<<" ";
		}
		std::cout<<age[n-1]<<std::endl;
		std::cin>>n;
	}
}
