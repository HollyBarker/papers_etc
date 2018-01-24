#include<iostream>
#include<fstream>
#include<random>
#include<string>
#include<vector>

// generates random numbers from a normal distribution and writes to file
int main()
{
	std::default_random_engine randnos;
	std::normal_distribution<double> dist(0.025,0.00025);
	std::ofstream random_normal_numbers;
	random_normal_numbers.open("random_normal_numbers.txt");
	
	for (int i=0;i<1000;++i)
	{
		double number=dist(randnos);
		random_normal_numbers<< number<< std::endl;
	}
	random_normal_numbers.close();
	return 0;
}
