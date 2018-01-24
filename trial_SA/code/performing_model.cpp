
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<random>
#include<list>

using namespace std; 

//class Matrix
//{
//public:
	// Matrix(int r, int c)
	// {
	// rows=r; columns=c;
	// }
	// double operator[] (int i, int j)
	// {
	// return data[(i-1)*(c)+(c)]
	// }
	// void Set(int i, int j)
	// { 
	// data[(i-1)
	// }
//private:
// int rows, columns;
// vector<double> data (rows*columns);
//};

//function prototypes
double rand_no(double mean,double var);
double func1(double x,double y,double z,double a,double b,double c,int t);
double func2(double x,double y,double c,double d, int t);
vector<double> importdata(const char* FileName);

int main()
{
	vector<const char*> files={"xdata.txt", "ydata.txt", "zdata.txt", "adata.txt", "bdata.txt", "cdata.txt", "ddata.txt"};
	vector<double>x=importdata(files[0]);
	vector<double>y=importdata(files[1]);
	vector<double>z=importdata(files[2]);
	vector<double>a=importdata(files[3]);
	vector<double>b=importdata(files[4]);
	vector<double>c=importdata(files[5]);
	vector<double>d=importdata(files[6]);

	vector<double> f1values, f2values;
	ofstream f1data;
	ofstream f2data;
	f1data.open("f1data.txt");
	f2data.open("f2data.txt");
	if (!f1data){cout<<"f1data.txt not found."<<endl; return 1;}
	if (!f2data){cout<<"f2data.txt not found."<<endl; return 1;}
	for (int i=0;i<x.size();i++)
	{
		for (int t=1;t<=3;t++)
		{
			double f1=func1(x[i],y[i],z[i],a[i],b[i],c[i],t);
			f1values.push_back(f1);
			f1data.width(15); f1data<<f1;
			double f2=func2(x[i],y[i],c[i],d[i],t);
			f2values.push_back(f2);
			f2data.width(15); f2data<<f2;
		} 
		f1data<<'\n';
		f2data<<'\n';
	}
	f1data.close();
	f2data.close();
	return 0;
}

//define the functions used

double rand_no(double mean,double var)
{
	default_random_engine randnos;
	normal_distribution<double> dist(mean,var);
	double number=dist(randnos);
	return number;
}

double func1(double x,double y,double z,double a,double b,double c,int t)
{
	double f1=a*x+b*y+c*z*(t-1)+rand_no(0.025,0.00025);
	return f1;
}

double func2(double x,double y,double c,double d,int t)
{
	double f2=c*x*t+d*y*y+rand_no(0.025,0.00025);
	return f2;
}

vector<double> importdata(const char* FileName)
{
	double datapoint;
	vector<double> data;
	ifstream dataFile;
	dataFile.open(FileName);
	if (!dataFile) cout<<"Error reading data file"<<endl;
	while (dataFile >> datapoint)
	{
		data.push_back(datapoint);
	}
	return data;
}


