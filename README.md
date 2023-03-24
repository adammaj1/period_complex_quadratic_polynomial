Numerical period detection of [complex quadratic polynomial](https://en.wikipedia.org/wiki/Complex_quadratic_polynomial)


# names
* Periodicity Checking ( Fractint)
* Orbit Detection ( MuEncy )
* [Periodicity scan ](https://mathr.co.uk/blog/2017-05-17_periodicity_scan.html)


# Theory
* [Cycle detection in wikipedia](https://en.wikipedia.org/wiki/Cycle_detection)
* [Orbit Detection by Robert P. Munafo, 2008 Mar 14.](https://mrob.com/pub/muency/orbitdetection.html)
* [Cycle detection and the stack algorithm by G. Nivasch](https://www.gabrielnivasch.org/fun/cycle-detection)



# Basic algorithm
* ["brute force checking each iteration vs all previous iterates" ](https://www.fractalforums.com/mandelbrot-and-julia-set/how-to-color-by-periodicity/)


 " A naive calculation of the period would be done by calculating a sufficiently large number of iterations {z_0, z_1, ...} and then comparing z_n against z_{n-k}$ for k in {1, 2, ..., m} where m is the largest period you want to detect.  If you can find that |z_n - z_{n-k}| < epsilon for sufficiently large n, this suggests a cycle of length k and you would confirm by looking at {|z_n - z_{n-k}|}_{n=n'}^{n'+k} and seeing that these are all sufficiently small. There are more sophisticated approaches, but this is the elementary way." [heropup](https://math.stackexchange.com/questions/4502546/function-to-calculate-the-period-of-a-mandelbrot-set-point)

Steps
* choose parameter c
* compute critical orbit ( forward orbit of critical point ) and find period of it's limit cycle:  
  * start with critical point:  z = z0 = 0.0 
  * make n forward iterations of z0 to (possibly) fall into attracting cycle
  * now z = zn
  * make n forward iterations of zn to compute attracting cycle
  * check backwards whether the last iterate z has already been visited before 
  
Max iteration and precision ( epsilon ) might need to be adjusted  

Numerical precision: double numbers

## efficiency
*  ["for example, c=1/4−10^{−10} takes over 800000 iterations to reach a fixed point in double precision floating point, but 20 iterations of Newton's method suffice to reach a fixed point. The two fixed points are slightly different, but both are fixed (each to themselves) in double precision."](https://math.stackexchange.com/questions/4502546/function-to-calculate-the-period-of-a-mandelbrot-set-point) - [Claude Heiland-Allen  ](https://mathr.co.uk/)
* " You may need very small epsilon and very large n, otherwise for example c=−3/4+10{−10} will probably give an incorrect period of 2 instead of the correct period of 1, which error will compound to an incorrect interior distance estimate (for example distance 3.8e-8 with your method (epsilon 1e-12, n 79,573,343) instead of 2e-10 with my method). " [Claude Heiland-Allen  ](https://mathr.co.uk/)


## Tests
* check the center ( = nucleus) of Mandelbrot set's hyperbolic component  with known period. It uses list of centers
* use [period doubling cascade along real axis](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/1over2_family). 

### input data for center tests
[List of centers](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/Mandelbrot_set/centers#Lists_of_centers) = hyperbolic components centers of Mandelbrot sets  = Nucleus of a Mu-Atoms
* REALONLY.TXT = real component centers of Mandelbrot Set for period less than 16 by Jay R. Hill. probably computed using : FINDPERC.EXE , here modified version is used
* [ feature-database.csv = a database of all islands up to period 16, found by tracing external rays by 	Claude Heiland-Allen](http://mathr.co.uk/mandelbrot/feature-database.csv.bz2): period, islandhood, angled internal address, lower external angle numerator, denominator, upper numerator, denominator, orientation, size, centre realpart, imagpart
* [largest-islands.txt by Robert Munafo, (c) 1987-2020](https://www.mrob.com/pub/muency/largestislands.html): Rank, Period, Coordinates, Size, itmax used for area measurement, area estimate, and R2-name 

####  failed tests
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

### Period doubling cascade


Real slice of Mandelbrot set : [-2,0.25]  

[Check the period for values along real axis between root points](https://en.wikibooks.org/wiki/Fractals/Iterations_in_the_complex_plane/1over2_family#Root_points): 
* real c greater then 0.25. Critical points escapes so period = 0
* real c from 0.25 to -0.75 should give period = 1 = 2^0
* real c from -0.75 to -1.25 should give period = 2 = 2^1
* real c from -1.25 to -1.3680989 should give period = 4 = 2^2
* ...
* real c from c(n) to c(n+1) should give period = 2^n

[Exponential mapping](https://en.wikibooks.org/wiki/Fractals/Computer_graphic_techniques/2D/plane#Exponential_map) helps to make it endlessly


# other algorithms


 solve these equations using numerical methods for solving polynomials - and even something simple such as Newton's method is going to converge a lot faster than finding the cycles just by iterating a single point (as is how bifurcations diagrams are usually made) under fc itself. Milo Brandt[math.stackexchange question: equations-for-mandelbrot-bifurcation-diagram?](https://math.stackexchange.com/questions/3994497/equations-for-mandelbrot-bifurcation-diagram?rq=1) 


## Algorithm by Claude Heiland-Allen 

What I do to create an image like the one you link, for f_c(z) = z^2 + c:
* start iteration from $z_0 := 0$, with $m := \infty$
* for each n = 1, 2, 3, ... in order
  * calculate z_n := f_c(z_{n-1})
  * if |z_n| < m
    * set m := |z_n|
    * use Newton's method to solve w = f_c^n(w) with initial guess w^{(0)} := z_n (this may fail to converge, in which case continue with the next n), the steps are w^{(i+1)} := w^{(i)} - \frac{f_c^{\circ n}(w^{(i)}) - w^{(i)}}{{f_c^{\circ n}}'(w^{(i)}) - 1}
    * calculate the derivative of the cycle \lambda := {f_c^{\circ n}}'(w)
    * if |\lambda| < 1, then the cycle is attractive and c is within a hyperbolic component of period $n$, stop (success).  \lambda$ may used as "interior coordinates" within the hyperbolic component. $w$ and $n$ can be used for interior distance estimation.

The point of using Newton's method is to accelerate the computation of $w$, a point in the limit cycle attractor.  Computing $w$ just by iterating $f_c$ could take many 1000s of iterations, especially when $\lambda$ is close to $1$.

I have no complete proof of correctness (but this doesn't mean I think it is incorrect; the images seem plausible).  It relies on the "atom domains" surrounding each hyperbolic component of a given period.

It also relies on the cycle reached by Newton's method being the same cycle as the limit cycle approached by iteration: this is true for the quadratic Mandelbrot set because there is only one finite critical point, $0$ ($\infty$ is a fixed point) and each attracting or parabolic cycle has a critical point in its immediate basin (see <https://math.stackexchange.com/a/3952801>), which means there can be at most one attracting or parabolic cycle.

For an implementation in C99 you can see my blog post at <https://mathr.co.uk/blog/2014-11-02_practical_interior_distance_rendering.html>










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
* [Mandelbrot Set Chaos by J. C. Sprott](https://sprott.physics.wisc.edu/chaos/manchaos.htm)
* [Fractint algorithm](https://web.archive.org/web/20150220012221/http://www.reocities.com/CapeCanaveral/5003/mandel.htm)
* [C implementation using Gnofract 4d ](https://github.com/HyveInnovate/gnofract4d/blob/master/examples/cpp/custom_mandelbrot_formula.c#L356-L389)
* [In Defense of Brent's Cycle Detection Algorithm by David Aramant](https://davidaramant.github.io/post/brents-cycle-detection-algorithm/)
* [algorithmist : Cycle detection](https://algorithmist.com/wiki/Cycle_detection)
* [projecteuler: Amicable chains (Problem 95) ](https://projecteuler.net/problem=95)
* [rosettacode : Cycle_detection](https://rosettacode.org/wiki/Cycle_detection)
 


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





