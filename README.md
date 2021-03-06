Numerical period detection of [complex quadratic polynomial](https://en.wikipedia.org/wiki/Complex_quadratic_polynomial)


# algorithm
* choose parameter c
* compute critical orbit ( forward orbit of critical point ) and find period of it's limit cycle:  
  * start with critical point:  z = z0 = 0.0 
  * make n forward iterations of z0 to (possibly) fall into attracting cycle
  * now z = zn
  * make n forward iterations of zn to compute attracting cycle
  * check backwards whether the last iterate z has already been visited before 
  
Max iteration and precision ( epsilon ) might need to be adjusted  

Numerical precision: double numbers

# efficiency
*  ["for example, c=1/4−10^{−10} takes over 800000 iterations to reach a fixed point in double precision floating point, but 20 iterations of Newton's method suffice to reach a fixed point. The two fixed points are slightly different, but both are fixed (each to themselves) in double precision."](https://math.stackexchange.com/questions/4502546/function-to-calculate-the-period-of-a-mandelbrot-set-point) - [Claude Heiland-Allen  ](https://mathr.co.uk/)


# Tests
* check the center ( = nucleus) of Mandelbrot set's hyperbolic component  with known period. It uses list of centers
* use [period doubling cascade along real axis](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/1over2_family). 

## input data for center tests
[List of centers](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/Mandelbrot_set/centers#Lists_of_centers) = hyperbolic components centers of Mandelbrot sets  = Nucleus of a Mu-Atoms
* REALONLY.TXT = real component centers of Mandelbrot Set for period less than 16 by Jay R. Hill. probably computed using : FINDPERC.EXE , here modified version is used
* [ feature-database.csv = a database of all islands up to period 16, found by tracing external rays by 	Claude Heiland-Allen](http://mathr.co.uk/mandelbrot/feature-database.csv.bz2): period, islandhood, angled internal address, lower external angle numerator, denominator, upper numerator, denominator, orientation, size, centre realpart, imagpart
* [largest-islands.txt by Robert Munafo, (c) 1987-2020](https://www.mrob.com/pub/muency/largestislands.html): Rank, Period, Coordinates, Size, itmax used for area measurement, area estimate, and R2-name 

###  failed tests
only 8 from  values failed ( one value is listed twice): 
```
not OK c = -1.9999999862123214+0.0000000000000000 period = 15 != -1
not OK c = 0.3394108199960000-0.0506682851620000 period = 12 != 11
not OK c = 0.3255895095510000-0.0380478809340000 period = 13 != 12
not OK c = 0.3145594899840000-0.0292739690790000 period = 14 != 13
not OK c = 0.3056765414950000-0.0229934263740000 period = 15 != 14
not OK c = -1.9999999862123214+0.0000000000000000 period = 15 != -1
not OK c = 0.2984480089040000-0.0183833673220000 period = 16 != 15
not OK c = -1.9999999965530804+0.0000000000000000 period = 16 != -1
not OK c = -1.9999999138269977+0.0000000000000000 period = 16 != -1
```
Check input values from 
* c = -1.9999999862123214 is wrong. It should be c = -1.999999986212321  +0.000000000000000 i    period = 15 ( computed with program Mandel by Wolf Jung)
* c = -1.9999999965530804 is wrong. It should be c = -1.999999996553080  +0.000000000000000 i    period = 16 ( computed with program Mandel by Wolf Jung)
* c = -1.9999999138269977 is wrong. It should be c = -1.999999913826998  +0.000000000000000 i    period = 16 ( computed with program Mandel by Wolf Jung)
* c = 0.339410819996  -0.050668285162643 i    period = 11, so input period is wrong
* c = 0.325589509550660  -0.038047880934756 i    period = 12, so input period is wrong
* c = 0.314559489984000  -0.029273969079000 i    period = 13, so input period is wrong
* c = 0.305676541495292  -0.022993426374099 i    period = 14, so input period is wrong
* c = 0.298448008903995  -0.018383367322073 i    period = 15, so input period is wrong

## Period doubling cascade


Real slice of Mandelbrot set : [-2,0.25]  

[Check the period for values along real axis between root points](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/1over2_family#Root_points): 
* real c greater then 0.25. Critical points escapes so period = 0
* real c from 0.25 to -0.75 should give period = 1 = 2^0
* real c from -0.75 to -1.25 should give period = 2 = 2^1
* real c from -1.25 to -1.3680989 should give period = 4 = 2^2
* ...
* real c from c(n) to c(n+1) should give period = 2^n

[Exponential mapping](https://en.wikibooks.org/wiki/Fractals/Computer_graphic_techniques/2D/plane#Exponential_map) helps to make it endlessly




# Files

## list of centers
[Lists :  Period Center_x center_y](./src/centers/lists/)
* [realonly.txt](./src/centers/lists/realonly.txt) input data : only real centers . This is modified version of REALONLY.TXT with updates
* [feature-database.txt](./src/centers/lists/feature-database.txt) input data : centers . This is modified version of feature-database.csv

Period Center_x center_y Size itmax 
* [largest-islands.txt](./src/centers/lists/largest-islands.txt) by [Robert Munafo, (c) 1987-2020] (https://www.mrob.com/pub/muency/largestislands.html)


# see also
* [Describe-iterated-map](https://github.com/adammaj1/Describe-iterated-map-) - numerical periodicity detection of a polynomial and rational Julia set in C++
* [mandelbrot-numerics-nucleus](https://gitlab.com/adammajewski/mandelbrot-numerics-nucleus) - [wikibooks](https://en.wikibooks.org/wiki/Fractals/mandelbrot-numerics#nucleus)
* [the code in C to compute the roots ( centers of comoponents of Mandelbrot sets ) via the homotopy continuation method by Dr. Piers Lawrence](https://gitlab.com/adammajewski/lawrence)
* [Program for finding centers of Mandelbrot set components by knighty](https://gitlab.com/adammajewski/cpp-mandelbrot-center-by-knighty)
* [fractalforums.com: the-mandelbrot-polynomial-roots-challenge](https://www.fractalforums.com/theory/the-mandelbrot-polynomial-roots-challenge/)



# git
```git
echo "# period_complex_quadratic_polynomial" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin git@github.com:adammaj1/period_complex_quadratic_polynomial.git
git push -u origin main
```



```git
cd existing_folder
git add .
git commit -m "Initial commit"
git push -u origin main
```


subdirectory

```git
mkdir images
git add *.png
git mv  *.png ./images
git commit -m "move"
git push -u origin main
```


to overwrite

```git
git mv -f 
```

Local repo 
```
~/Dokumenty/mandelbrot_chaotic/period/period_complex_quadratic_polynomial/
```





