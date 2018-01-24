#include<iostream>
#include<cmath>
#include<vector>

class Matrix
{
public:
	Matrix() : NRows(0), NColumns(0) {}	
			//constructor w/ no parameters
	Matrix(int R, int C, double x=0) : NRows(R), NColumns(C), A(R*C, x) {}
			//constructor w/ parameters for number of rows, columns and the option to
			//enter an initialising double value x, for every entry
	Matrix &operator=(double x)
		{
			for (int i=0;i<NRows*NColumns;i++) A[i]=x;
			return *this;
		}
	double operator()(int i, int j) const
	{	
		return A[j*NRows+i];
	}
	double &operator()(int i, int j)
	{
		return A[j*NRows+i];
	}
	int Rows() const {return NRows;}
	int Columns() const {return NColumns;}
	int SizeMatrix() const {return NRows*NColumns;} 
private:
	int NRows, NColumns;
	std::vector<double> A;
};

int main()
{
	
	return 0;
}
