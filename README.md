# shellsort

Shell sort implementation with parameters as in the qsort function from stdlib.

The implementation is based on code from the [ShellSort article](https://www.geeksforgeeks.org/shellsort/).
But the ability to sort any kind of array was added, like in the qsort function.
The implementation doesn’t use dynamic memory allocation when swapping items, but
uses static allocation with a setting in the STATIC_ALLOC_BUFFER define. That lets to
use a sorting algorithm in embedded projects with smaller memory usage than the qsort
function from stdlib.

## qsort (C stdlib) vs. shell_sort (implementation) 

### On PC Windows -O3 Array 20 items
1. qsort  
   text	   data	    bss	    dec	    hex	filename  
  15656	   1656	    112	  17424	   4410	./prog.exe
2. shell_sort  
   text	   data	    bss	    dec	    hex	filename  
  15640	   1636	    112	  17388	   43ec	./prog.exe


### On MCU STM32F4 -O0 Array 10 items
1. before sorting  
   text	   data	    bss	    dec	    hex	filename  
   1516	     12	   1572	   3100	    c1c	cipher_suite.elf
2. qsort  
   text	   data	    bss	    dec	    hex	filename  
   2416	     12	   1572	   4000	    fa0	cipher_suite.elf
3. shell_sort (-520 bytes text ref qsort)  
   text	   data	    bss	    dec	    hex	filename  
   1896	     12	   1572	   3480	    d98	cipher_suite.elf

### On MCU STM32F4 -O3 Array 10 items
1. before sorting  
   text	   data	    bss	    dec	    hex	filename  
   1040	     12	   1572	   2624	    a40	cipher_suite.elf
2. qsort  
   text	   data	    bss	    dec	    hex	filename  
   1952	     12	   1572	   3536	    dd0	cipher_suite.elf
3. shell_sort (-596 bytes text ref qsort)  
   text	   data	    bss	    dec	    hex	filename  
   1356	     12	   1572	   2940	    b7c	cipher_suite.elf

## Sources 

1. [ShellSort](https://www.geeksforgeeks.org/shellsort/)
2. [Sorting (in) embedded systems](https://embeddedgurus.com/stack-overflow/2009/03/sorting-in-embedded-systems/)