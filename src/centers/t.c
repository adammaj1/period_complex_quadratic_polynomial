/*

gcc t.c -Wall -lm
./a.out
*/


#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>		// M_PI; needs -lm also
#include <complex.h> 



	int p; // aproximated period
	// input c = re+im*I
    	double re;
    	double im;
    	//
    	double precision= 1.0E-15;
    	
    	
//------------------complex numbers -----------------------------------------------------
// = cnorm = fast cabs
double cabs2(complex double z) {
  return creal(z) * creal(z) + cimag(z) * cimag(z);
}


int SameValue(complex double Z1, complex double Z2, double precision)
{
    if (fabs(Z1- Z2) <precision ) 
       {return 1; /* true */ }
       else return 0; /* false */
    }
    

int escapes(complex double z){
	if (cabs2(z) > 4.0) 
		return 1; // escapes 
	return 0; // not escapes

}



//  https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/qpolynomials
complex double fc( const double complex z , const complex double c ){

	return z*z +c;
}


// ***************************************************************************************************************************
// ************************** PER = Period ****************************************************************** ************
// ****************************************************************************************************************************


int GivePeriod (const double complex c ){

	// int period = 0;
	int iMax = 2000;
	int i;
	complex double orbit[2001]; // length(orbit) = iMax + 1
	complex double z = 0.0; // critical point
	
	
	
	// iteration without saving points 
	for(i=0; i<iMax; ++i)
    	{ 
    		z  = fc(z, c); 
      		 if (escapes(z) ) {return 0; } // escaping = exterior of M set  so break the procedure
   	} // for(i
	
	
	// iteration = computing the orbit = fiil the array
	 orbit[0] = z; 
  	for(i=1; i<iMax+1; ++i)
    	{ 
    		z  = fc(z, c); 
      		 if ( escapes(z)) {return 0; } // escaping = exterior of M set  so break the procedure
   		orbit[i] = z;
   		//printf(" i = %d z = %f+%f \n", i, creal(orbit[i]), cimag(orbit[i]));
      
    	} // for(i=0
	
	// look for similar points = attractor 
	// go from the last point of the orbit 
	//z = orbit[0];
	for(i=iMax-1; i>0; --i){
		if ( SameValue( z, orbit[i], precision))
			{//printf(" z = %f+%f diff = %e\n", creal(orbit[i]), cimag(orbit[i]), cabs(z - orbit[i])); 
			return iMax - i;} // period
			//else printf(" z = %f+%f diff = %e\n", creal(orbit[i]), cimag(orbit[i]), cabs(z - orbit[i]));
	
	
	
	}
	
	
	
	
	return -1; // period not found 

}

// *******************************************************************************************    	
    	
    	
int test (int period, double re, double im){

	complex double c = re + im*I;
	int p = GivePeriod(c);
	
	if ( p == period ) 
		{//printf("period OK c = %f+%f\n", creal(c), cimag(c)); 
		return 1; } // test passed
		
	printf("not OK c = %.16f%+.16f period = %d != %d\n", creal(c), cimag(c), period , p);
	return 0; // test failed

}



// https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
int read_test_file(char *FileName){

	FILE * fp; // file with test data : period re im 
    	char * line = NULL;
    	size_t len = 0;
    	ssize_t read;
    	
    

    fp = fopen(FileName, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("length %zu:\n", read);
        //printf("%s", line);
        
        int number_of_filled_variables = sscanf(line, "%d %lf %lf\n", &p, &re, &im);
        if ( number_of_filled_variables == 3)  // skip bad input lines 
        	{
        		//printf("%d %.16f %+.16f\n", p, re, im );
        		test(p,re,im);
        	}
        
        
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);


}




int main(void)
{
   read_test_file("./m.txt"); 
   // printf(" period ( c = %f%+f) = %d \n", 0.0, 0.0, GivePeriod(0.0));
   return 0;
}
