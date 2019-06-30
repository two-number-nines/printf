# printf
I recoded a part of the the libc’s printf function.

it manages:
• The following conversions: csp
• The following conversions: diouxX with the following flags: hh, h, l and ll.
• The following conversion: f with the following flags: l and L.
• Manage %%
• The flags #0-+ and space
• You must manage the minimum field-width
• You must manage the precision

Allowed flags:
```
0 - puts this 
+ - puts that
- - puts that

```
