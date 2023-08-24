
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// MY .h
#include "color.h"
#include "solution.h"
#include "testing.h"
#include "inout.h"

#define MYASSERT(condition) if (!(condition)) printf ("\033[1;%dmERROR!!! YOU HAVE SOME PIZDEC IN FILE %s , IN FUNCTION %s , LINE %d\033[1;%dm\n", RED, __FILE__, __PRETTY_FUNCTION__, __LINE__, RESET)

//--------------------------------------------------------------------------------------
//Initialization Functions

//1. Compare two double numbers
int compare (double x, double y);

//2. Function of checking for overflow numbers
int check_double (double z);

//12. Function for filler of NAN
void filler_coeffs (double *args);

