/**
 *  Approximate the function COS with series Taylor.
 *
 *  cos(x) = 1 - x^2/2! + x^4/4! - x^6/6! + ....(-1)^n*x^(2n)/(2n)!;
 *  
 */

#include <stdio.h>
#include <math.h>

int fact(int n) {

    if(n == 0) return 1;

       else return n * fact(n - 1);
}

float myPow(int a, int b) {

      int i, 

          p = 1;

      for(i = 1; i <= b; ++i) p *= a;

   return p;
}

double modul(double a, double b) {

       if(a > b) return a - b;

             else return b - a;
}

float myCos(float x) {

    int i = 2;

    float EPS = 0.0001;

    float term1 = 1, 

           term2 = term1 - (float) myPow(x, 2) * 1.0/ fact(2);         

          while( modul(term1, term2) >= EPS ) {

                 term1 = term2;
    
                 term2 += (float) pow(-1, i) * (double) pow(x, (2 * i)) * 1.0 / fact(2 * i);
              
                 i++;
          }        

       
    return term2;  
}

int main() {

    float x;

    printf("x=");

    scanf("%f", &x);

    printf("sin(%.2f) = %.10f\n", x , myCos( x ));

    printf("sin(%.2f) = %.10f", x , cos( x )); 

 return 0;
}