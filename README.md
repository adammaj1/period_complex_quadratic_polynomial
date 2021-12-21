period_complex_quadratic_polynomial

# input data for tests
List centers = hyperbolic components centers of Mandelbrot sets  = Nucleus of a Mu-Atoms
* [REALONLY.TXT](http://www.geocities.com/CapeCanaveral/Lab/3825/ ) = real component centers of Mandelbrot Set for period less than 16 by Jay R. Hill. probably computed using : FINDPERC.EXE 
* [ feature-database.csv = a database of all islands up to period 16, found by tracing external rays by 	Claude Heiland-Allen](http://mathr.co.uk/mandelbrot/feature-database.csv.bz2)


# failed tests
only 9 from  values failed 
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
