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
flags   description
-       Left-justify within the given field width; Right justification is the default (see width sub-specifier).
+       Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative         numbers are preceded with a - sign.
(space) If no sign is going to be written, a blank space is inserted before the value.
#       Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
0       Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).
```
