/*

gcc l.c -Wall -lm
./a.out
*/


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>		// M_PI; needs -lm also
#include <complex.h> 

#define iMax 1000000
#define length (iMax+1)

	int p; // aproximated period
	// input c = re+im*I
    	long double re;
    	long double im;
    	// algorithm parameters 
    	long double exponent = -6;
    	long double precision; //= 1.0E-6;
    	//int iMax = 10000; // it should be more the maximal period
    	
//------------------complex numbers -----------------------------------------------------
// = cnorm = fast cabs
long double cabs2(complex long double z) {
  return creal(z) * creal(z) + cimag(z) * cimag(z);
}


int SameValue(complex long double Z1, complex long double Z2, long double precision)
{
    if (fabsl(Z1- Z2) <precision ) 
       {return 1; /* true */ }
       else return 0; /* false */
    }
    

int escapes(complex long double z){
	if (cabs2(z) > 4.0) 
		return 1; // escapes 
	return 0; // not escapes

}



//  https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/qpolynomials
complex long double fc( const long double complex z , const complex long double c ){

	return z*z +c;
}


// ***************************************************************************************************************************
// ************************** PER = Period ****************************************************************** ************
// ****************************************************************************************************************************


int GivePeriod (const long double complex c ){

	// int period = 0;
	
	int i;
	complex long double z = 0.0; // critical point
	
	
	
	// iteration without saving points 
	for(i=0; i<iMax; ++i)
    	{ 
    		z  = fc(z, c); 
      		 if (escapes(z) ) {return 0; } // escaping = exterior of M set  so break the procedure
   	} // for(i
	
	
	// iteration = computing the orbit = fiil the array
	// dynamic array
	long double complex *orbit;
	orbit  = malloc(length * sizeof(long double complex ));
	
	orbit[0] = z; 
  	for(i=1; i<iMax+1; ++i)
    	{ 
    		z  = fc(z, c); 
      		 if ( escapes(z)) {free (orbit); return 0; } // escaping = exterior of M set  so break the procedure
   		orbit[i] = z;
   		//printf(" i = %d z = %f+%f \n", i, creal(orbit[i]), cimag(orbit[i]));
      
    	} // for(i=0
	
	// look for similar points = attractor 
	// go from the last point of the orbit 
	//z = orbit[0];
	for(i=iMax-1; i>0; --i){
		if ( SameValue( z, orbit[i], precision))
			{//printf(" z = %f+%f diff = %e\n", creal(orbit[i]), cimag(orbit[i]), cabs(z - orbit[i])); 
			free (orbit);
			return iMax - i;} // period
			//else printf(" z = %f+%f diff = %e\n", creal(orbit[i]), cimag(orbit[i]), cabs(z - orbit[i]));
	
	
	
	}
	
	
	
	free (orbit);
	return -1; // period not found , maybe precision is to low

}






// *******************************************************************************************    	
 /*
 
 real slice of Mandelbrot set :  c in [-2, 0.25]
 period doubling cascade :  c in [ cF , 0.25]
 
 
 */   	
	
int tests (){



	complex long double cF = -1.4011551890; /* The Feigenbaum Point of period doubling cascade */ 
	
	complex long double c = 0.0;
	long double x = 0.7; // xMax > xMin
	long double xMin =  -100;  
	long double dx = 0.02; 
	
	
	
	precision = pow(10, exponent);
	
	
	while(x > xMin) {
		
		// dx is proportional to (c-cf)
		//dx *=
		x -= dx;
		c = cF + exp(x);
		int p = GivePeriod(c);
		
		if (p> 2048) // increase precision
					{ exponent = exponent - (dx/2.0);
					//printf("%.16f\t %d \n", creal(c),  -2); // p.txt
			  		}
			
		precision = pow(10, exponent);
		
		// output for reading
		// printf("x = %.16f\tc = %.16f\t period = %d \n", x, creal(c),  p); // r.txt
		// output for gnuplot
		printf("%.18Lf\t %d \t %.1Lf\n", creall(c),  p, exponent); // p.txt
		//printf("%.16f\t %.16f \n", x, creal(c)); // c.txt
		//printf("%.16f\t %.16f \n", x, cabs(c - cF)); // d.txt
   			
	}

	
	return 0; // 

}




int main(void)
{

	
	tests(); 
   	// printf(" period ( c = %f%+f) = %d \n", 0.0, 0.0, GivePeriod(0.0));
   	
   	return 0;
}
