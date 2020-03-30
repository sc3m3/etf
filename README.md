# etf - encrypt text file
easy to use and minimalistically sized c program to encrypt any given text file.

the program will write the newly crypted data to the same file and append .etfc (etf-crypted) to indicate that it's an encrypted file.

# usage
simply compile etf.c with gcc and run the created binary.

(syntax for braindead people)<br>
Windows: `gcc etf.c`<br>
GNU/Linux: `gcc etf.c`<br>

(examples for braindead people)<br>
example for GNU/Linux: `./a.out example.txt 1 example-key`<br>
example for Windows: `a.exe example.txt 1 example-key`<br>
