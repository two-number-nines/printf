# printf
I recoded a part of the the libc’s printf function.

## Getting started
Run make and to get libftprint.a and then compile it with your source file.
```
gcc main.c libftprintf.a
```

## Functionality
### Conversion characters
```
SPECIFIER         OUTPUT                                    EXAMPLE
d or i            Signed decimal integer                    392
u                 Unsigned decimal integer                  7235
o                 Unsigned octal                            610
x                 Unsigned hexadecimal integer              7fa
X                 Unsigned hexadecimal integer (uppercase)  7FA
f                 Decimal floating point, lowercase         392.65
F                 Decimal floating point, uppercase         392.65
```
### Flags
```
FLAGS   DESCRIPTION
-       Left-justify within the given field width; Right justification is the default (see width sub-specifier).
+       Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers.
        By default, only negative numbers are preceded with a - sign.
(space) If no sign is going to be written, a blank space is inserted before the value.
#       Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
0       Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
```
### Width
```
WIDTH       DESCRIPTION
(number)    Minimum number of characters to be printed. If the value to be printed is shorter than this number, 
            the result is padded with blank spaces. The value is not truncated even if the result is larger.
*           The width is not specified in the format string, but as an additional integer value argument preceding the
            argument that has to be formatted.
```
### Precision
```
.PRECISION  DESCRIPTION
.number     For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. 
            If the value to be written is shorter than this number, the result is padded with leading zeros. 
            The value is not truncated even if the result is longer. 
            A precision of 0 means that no character is written for the value 0.
            For f and F specifiers: this is the number of digits to be printed after the decimal point 
            (by default, this is 6).
            For s: this is the maximum number of characters to be printed. 
            By default all characters are printed until the ending null character is encountered.
            If the period is specified without an explicit value for precision, 0 is assumed.
.*          The precision is not specified in the format string, 
            but as an additional integer value argument preceding the argument that has to be formatted.
```
