#include <iostream>

int main()
{
	int N;
	std::cin>>N;
	for(int i=0;i<N;i++)
	{
		int num;
		int seq[1000];
		int test=0;
		std::cin>>num;
		for(int j=0;j<num;j++)
		{
			std::cin>>seq[j];
		}
		for(int a=0;a<num;a++)
		{
			for(int b=a+1;b<num;b++)
			{
				for(int c=0;c<num;c++)
				{
					if(c==a||c==b)
					{
						continue;
					}
					else
					{
						if(seq[c]==seq[a]+seq[b])
						{
							test=1;
							break;
						}
					}
				}
				if(test)
				{
					break;
				}
			}
			if(test)
			{
				break;
			}
		}
		if(test)
		{
			std::cout<<"false"<<std::endl;
		}
		else
		{
			std::cout<<"true"<<std::endl;
		}
	}
}
