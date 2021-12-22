Numerical period detection of [complex quadratic polynomial](https://en.wikipedia.org/wiki/Complex_quadratic_polynomial)


# algorithm
* choose parameter c
* compute critical orbit ( forward orbit of critical point z = 0)
* find period: 
  * make iMax forward iterations to fall into attracting cycle
  * make iMax forward iterations to compute attracting cycle
  * check backwards whether the last iterate has already been visited before
  
Max iteration and precision ( epsilon ) might need to be adjusted
Numerical precision: double numbers




# input data for tests
List centers = hyperbolic components centers of Mandelbrot sets  = Nucleus of a Mu-Atoms
* REALONLY.TXT = real component centers of Mandelbrot Set for period less than 16 by Jay R. Hill. probably computed using : FINDPERC.EXE , here modified version is used
* [ feature-database.csv = a database of all islands up to period 16, found by tracing external rays by 	Claude Heiland-Allen](http://mathr.co.uk/mandelbrot/feature-database.csv.bz2)


##  failed tests
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




# Files
* [r.txt](./src/r.txt) input data : only real centers . This is modified version of REALONLY.TXT with updates
* [n.txt](./src/n.txt) input data : centers . This is modified version of feature-database.csv


# see also
* [Describe-iterated-map](https://github.com/adammaj1/Describe-iterated-map-) - numerical periodicity detection of a polynomial and rational Julia set in C++


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
