/*!
    \file 
    \brief Header file of Unit Testing
*/

/*!
    \brief Function of check one unit test
    \param[in] n counter of tests
    \param[in] test_data array of coefficients and correct roots
    \param[in] amount_cor amount of correct roots
    \return 1 for counter of tests 
    This function take parametrs of one unit test and check them for results of my solving function
    Result of unit test will be output in message
*/
int test_solofile (int *n,double test_data[], int amount_cor);

/*!
    \brief Function of process all unit tests from file
    \param[in] test_data array of coefficients and correct roots
    \param[in] amount_cor amount of correct roots
    \return amount of tests
    This function scaning file tests.txt and with call test_solofile() checking all lines in file
*/
int test_allfile (void);

/*!
    \brief Function of opening file
    \return address of open file
    Open file and check for correct opening
*/
FILE * fileopening (void);

/*!
    \brief Function of checking for NAN in file
    \param stroka number but in string type
    \return double number NAN or value
    It take string and check for "NAN", and in dependence of result it can be NAN(we scan nan at the end) or standart double value
*/
double nan_file (char stroka[]);
