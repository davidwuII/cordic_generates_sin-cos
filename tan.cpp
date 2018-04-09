#include <iostream>
#include <math.h>

using namespace std;

void my_atan5(double A);
double S_C[2];

int main()
{	
	cout << "enter a number between 0 and 90: \n";
	int	x;
	cin >> x;	
	while(x < 0 || x > 90){
		cout << "enter a number between 0 and 90: " << endl;
		cin >> x;
	}
	my_atan5(x);

	cout << "cos: " << S_C[0] << endl;
	cout << "sin: " << S_C[1] << endl;
	system("pause");
	return 0;
}


void my_atan5(double A)
{
	/*const double tangent[] = { 1.0,	0.4142,	0.1989,	0.09849,0.04913,
								0.02455,	0.01227,	0.00614,	0.003068,
								0.001534,	7.6699054e-4,3.834952e-4
	};*/
	double angle[] = {	45,		26.565,	14.036,		7.125,	3.5763,
								1.7899,	0.8952,	0.4476,		0.22381,	0.1119,
								0.0559,	0.028,	0.01399		// 12 time
	};

	double x = 1;
	double y = 0;
	double k = 0.60723;//0.63664;
	int i = 0;
	double x_new, y_new;
	//double angle=45;
	for (i = 0; i < 12; i++)
	{
		angle[i] = (angle[i] / 45)*pow(2, 20);
	}
	A = (A / 45)*pow(2, 20);

	for (i = 0; i < 12; i++)
	{
		if (A > 0)
		{
			x_new = (x - y * (1 / pow(2, i)));
			y_new = (y + x * (1 / pow(2, i)));
			x = x_new;
			y = y_new;
			A -= angle[i];
		}
		else
		{
			x_new = (x + y * (1 / pow(2, i)));
			y_new = (y - x * (1 / pow(2, i)));
			x = x_new;
			y = y_new;
			A += angle[i];
		}
		//angle /= 2;
	}

	S_C[0] = x * k;
	S_C[1] = y * k;
}

