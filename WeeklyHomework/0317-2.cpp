#include<iostream>

int GCDchecker(int a,int b);

int main()
{
	int n;
	std::cin>>n;
	
	for(int i=0;i<n;i++)
	{
		int num;
		std::cin>>num;
		
		int snum=1;
		for(int j=2;j<num;j++)
		{
			if(GCDchecker(num,j)==1)
			{
				snum+=1;
			}
		}
		std::cout<<snum<<std::endl;
	}
}

int GCDchecker(int a,int b)
{
	int r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
