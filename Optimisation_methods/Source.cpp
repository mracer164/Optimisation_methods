#include <iostream>
#include <math.h>
using namespace std;
double function(double x, double y)
{
	double result=0; 
	result=pow(sin(x-0.5),2)-pow(sin(y-0.2),2); 
	return result;
}
double dx_derriv(double x)
{
	double result;
	result=2*cos(x-0.5)*sin(x-0.5);
	return result;
}
double dy_derriv(double y)
{
	double result;
	result=-2*cos(y-0.2)*sin(y-0.2);
	return result;
}
double EP_function(double x, double y, double der_x,double der_y,double alpha)
{
	double alpha_x=x-der_x*alpha;
	double alpha_y=y-der_y*alpha;
	double result=0;
	result=pow(sin(alpha_x-0.5),2)-pow(sin(alpha_y-0.2),2); 
	return result;
}
void EP_approx(long double alpha_low,long double alpha_high,long double accuracy)
{
	double EP_division, x1, x2,a_res,b_res,x1_res,x2_res,f_result,counter=0,f_x; 
	EP_division=(alpha_high-alpha_low)/3;
	x1=alpha_low+EP_division; 
	x2=alpha_high-EP_division; 
	a_res=EP_function(alpha_low); 
	b_res=EP_function(alpha_high); 
	x1_res=EP_function(x1); 
	x2_res=EP_function(x2); 
	while(abs(alpha_high-alpha_low)>=accuracy)
	{
		counter++;
		if(x1_res<=x2_res)
		{
			a=x1;
			EP_division=abs(b-a)/3;
			x1=a+EP_division; 
			x2=b-EP_division; 
			x1_res=function(x1); 
			x2_res=function(x2);
		}
		else
		{
			b=x2;
			EP_division=abs(b-a)/3;
			x1=a+EP_division; 
			x2=b-EP_division; 
			x1_res=function(x1); 
			x2_res=function(x2); 
		}
	}
	f_x=(b+a)/2;
	f_result=((function(a)+function(b))/2);
	cout << f_x << " " << counter << " " << f_result << endl;
}
void Steepest_descent(double init_val_x,double init_val_y,double low_x_intvl,double high_x_intvl,double low_y_intvl,double high_y_intvl,double accuracy)
{

}

int main()
{
	double init_val_x=0;
	double init_val_y=0;
	EP_approx(-1,1,0.00001);
	system("PAUSE");
	return 0;
}