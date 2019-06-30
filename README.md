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
specifier         Output                                    Example
d or i	          Signed decimal integer	                  392
u	                Unsigned decimal integer	                7235
o	                Unsigned octal	                          610
x	                Unsigned hexadecimal integer	            7fa
X	                Unsigned hexadecimal integer (uppercase)	7FA
f	                Decimal floating point, lowercase	        392.65
F	                Decimal floating point, uppercase	        392.65
```
### Flags
```
c - character
bla bla
```
it manages:
```
• The following conversions: csp
• The following conversions: diouxX with the following flags: hh, h, l and ll.
• The following conversion: f with the following flags: l and L.
• %%
• The flags #0-+ and space
• You must manage the minimum field-width
• You must manage the precision
```
