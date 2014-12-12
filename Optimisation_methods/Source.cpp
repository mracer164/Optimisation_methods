#include <iostream>
#include <math.h>
#include <string>
using namespace std;
long double c_der_x,c_der_y,c_x,c_y;
long double accuracy = 0.0000001;
long double function(double x, double y)
{
	long double result=0; 
	result=pow(sin(x-0.5),2)-pow(sin(y-0.2),2); 
	return result;
}
long double dx_derriv(long double x)
{
	return sin(2 * x - 1);
}
long double dy_derriv(long double y)
{
	return -sin(2 * y - 0.4);
}
long double FindMin(long double a, long double b)
{
	return ((a) < (b) ? (a) : (b));
}

long double FindMax(long double a, long double b)
{
	return ((a) > (b) ? (a) : (b));
}

long double EP_function(double alpha)
{
	long double alpha_x=c_x+c_der_x*alpha;
	long double alpha_y=c_y+c_der_y*alpha;
	long double result=0;
	result=function(alpha_x,alpha_y); 
	return result;
}
long double GS(long double a, long double b, long double epsilon)
{
	if (a > b) return GS(b, a, epsilon);

	long double p = (sqrt(5) - 1) / 2;
	long double L = b - p * (b - a);
	long double R = a + p * (b - a);
	long double buffer;

	while (abs(b - a) > epsilon && (!(abs((abs(b - a) - epsilon)) < epsilon)))
	{
		if (EP_function(L) < EP_function(R))
		{
			b = R;
			R = L;
			L = b - p * (b - a);
		}
		else
		{
			a = L;
			L = R;
			R = a + p * (b - a);
		}
		if (L > R)
		{
			buffer = L;
			L = R;
			R = buffer;
		}
	}
	return (a + b) / 2;
}
long double alpha_intervals(long double  der_x, long double der_y, long double x_max, long double x_min, long double y_max, long double y_min, long double x, long double y)
{
	long double alpha_x1,alpha_x2,alpha_y1,alpha_y2,result;
	alpha_x1 = (x_max-x)/der_x;
	alpha_x2 = (x_min-x)/der_x;
	alpha_y1 = (y_max-y)/der_y;
	alpha_y2 = (y_min-y)/der_y;
	c_x=x;
	c_y=y;
	c_der_x=der_x;
	c_der_y=der_y;
	
	
			if(der_x != 0 && der_y != 0)
			{
				result = GS(FindMin(FindMax(alpha_x1, alpha_x2), FindMax(alpha_y1, alpha_y2)),FindMax(FindMin(alpha_x1, alpha_x2), FindMin(alpha_y1, alpha_y2)),accuracy);
			}
			else if(der_x != 0)
			{
				result = GS(FindMax(alpha_x1, alpha_x2),FindMin(alpha_x1, alpha_x2),accuracy);
			}
			else if(der_y != 0)
			{
				result = GS(FindMax(alpha_y1, alpha_y2),FindMin(alpha_y1, alpha_y2),accuracy);
			}
			else result = 0;
	return result;
}
void Steepest_descent(long double init_val_x,long double init_val_y,long double x_min,long double x_max,long double y_min, long double y_max,long double accuracy)
{
	long double alpha,x1,x2,y1,y2,f_result_1,f_result_2,der_x,der_y,distance;
	x1=init_val_x;
	y1=init_val_y;
	x2=init_val_x;
	y2=init_val_y;
	distance=1+accuracy;
	alpha=0;
	while(distance > accuracy)
	{
		x1=x2;
		y1=y2;
		der_x=dx_derriv(x1);
		der_y=dy_derriv(y1);
		der_x=-der_x;
		der_y=-der_y;
		alpha=alpha_intervals(der_x,der_y,1,-1,1,-1,x2,y2);
		x2=x2+alpha*der_x;
		y2=y2+alpha*der_y;
		distance=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

		
	}
	cout << "Xmin=[" << x2 << "," << y2 << "]" << endl;


}
int main()
{
	long double init_val_x=0.5;
	long double init_val_y=0.5;
	Steepest_descent(init_val_x,init_val_y,-1,1,-1,1,accuracy);
	system("PAUSE");
	return 0;
}