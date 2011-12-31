/**
 * @file Addresses/report.c    Helper program to format the table of addresses.
 * @brief  Helper program that properly formats the addresses for ease of reading.
 * 
 * @author George Heineman
 * @date 6/15/08
 */
#include <stdio.h>
#include <string.h>

/**
 * The two arguments are files with the same number of lines of input.
 *
 * First file has lines of the form 'var'
 * Second file has lines of the form '$n = value'
 *
 * lines are read from both files and output as 'var = addr'.
 *
 * note that individual lines from each file are limited to 256 chars.
 */
int main(int argc, char **argv) {
  FILE *fvars, *faddresses;
  char buf1[256], buf2[256];

  fvars = fopen (argv[1], "r");
  faddresses = fopen (argv[2], "r");

  for (;;) {
    char *var = fgets (buf1, 256, fvars);
    char *addr = fgets (buf2, 256, faddresses);

    if (addr == NULL) break;

    /* strip off carriage returns. */
    buf1[strlen(var)-1]='\0';
    buf2[strlen(addr)-1]='\0';

    /* update addr point to be at the = sign */
    addr = strstr(addr, "=");

    printf ("%s\t%s\n", var, addr);
  }

  return 0;
}
