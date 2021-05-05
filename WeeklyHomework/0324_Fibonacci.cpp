#include <iostream>

int main()
{
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
	{
		int F;
		std::cin>>F;
		if(F==1 || F==2)
		{
			std::cout<<"1"<<std::endl;
		}
		else
		{
			int a=1,b=1;
			int c=0;
			while(F>2)
			{
				c=a+b;
				a=b;
				b=c;
				F-=1;
			}
			std::cout<<c<<std::endl;
		}
	}
} 
