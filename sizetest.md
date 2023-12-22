# qsort (C stdlib) vs. shell_sort (own) 

## on PC Windows -O3 Array 20 items
1. qsort
   text	   data	    bss	    dec	    hex	filename
  15656	   1656	    112	  17424	   4410	./prog.exe
2. shell_sort
   text	   data	    bss	    dec	    hex	filename
  15640	   1636	    112	  17388	   43ec	./prog.exe


## On MCU STM32 -O0 Array 10 items
1. before
   text	   data	    bss	    dec	    hex	filename
   1516	     12	   1572	   3100	    c1c	cipher_suite.elf
2. qsort
   text	   data	    bss	    dec	    hex	filename
   2416	     12	   1572	   4000	    fa0	cipher_suite.elf
3. shell_sort (-520 bytes text ref qsort)
   text	   data	    bss	    dec	    hex	filename
   1896	     12	   1572	   3480	    d98	cipher_suite.elf

## On MCU STM32 -O3 Array 10 items
1. before
   text	   data	    bss	    dec	    hex	filename
   1040	     12	   1572	   2624	    a40	cipher_suite.elf
2. qsort
   text	   data	    bss	    dec	    hex	filename
   1952	     12	   1572	   3536	    dd0	cipher_suite.elf
3. shell_sort (-596 bytes text ref qsort)
   text	   data	    bss	    dec	    hex	filename
   1356	     12	   1572	   2940	    b7c	cipher_suite.elf