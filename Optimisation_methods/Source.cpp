#include <iostream>
using namespace std;
double function(double x)
{
	double result=0; 
	result=(1/(atan(cos(4-2*x))+1)); 
	return result;
}
void EP_approx(long double alpha_low,long double alpha_high,long double accuracy)
{
	double EP_division, x1, x2,a_res,b_res,x1_res,x2_res,f_result,counter=0,f_x; 
	EP_division=(b-a)/3;
	x1=a+EP_division; 
	x2=b-EP_division; 
	a_res=function(a); 
	b_res=function(b); 
	x1_res=function(x1); 
	x2_res=function(x2); 
	while(abs(b-a)>=accuracy)
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
	EP_approx(-1,1,0.00001);
	system("PAUSE");
	return 0;
}