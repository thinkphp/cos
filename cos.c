/**
 *  Approximate the function COS with series Taylor.
 *
 *  Can be computed  as follows:
 * 
 *  cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ....(-1)^n*x^(2n)/(2n)!;
 *  
 */

#include <stdio.h>
#include <math.h>

double fact(int n) {

      if(n == 1 || n == 0) return 1;

       else return n * fact(n - 1);   
}

double myPow(double a, double b) {

      int i;

      double p = 1;

      for(i = 1; i <= b; ++i) p *= a;

   return p;
}

double myFabs(double a, double b) {

      if(a > b) return a - b;

           else 

                return b - a;
}


double myCos(float x) {

    int i = 2;

    double EPS = 0.000001;

    double term1 = 1, 

          term2 = term1 - (double) myPow(x, 2) * 1.0/ fact(2);         

          while( myFabs(term1, term2) >= EPS ) {

                 term1 = term2;
    
                 term2 += (double) pow(-1, i) * (double) myPow(x, 2 * i) * 1.0 / fact(2 * i);
              
                 i++;
          }        

       
    return term2;  
}

int main() {

    double x;

    //give me the number to compute sin
    printf("x=");

    //we need to use %lf format specifier to read a double 
    scanf("%lf", &x);

    //we'll need to use  %lf format specifier to print out the results as well.
    printf("cos(%.3lf) = %.5lf\n", x , myCos( x ));

    printf("cos(%.3lf) = %.5lf", x , cos( x )); 

 return 0;
}
