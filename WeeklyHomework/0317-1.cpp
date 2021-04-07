#include<iostream>

int main()
{
	long long int clnum;
	while(std::cin>>clnum)
	{
		std::cout<<3*((clnum+1)*(clnum+1)/2-3)<<std::endl;
	}
}
