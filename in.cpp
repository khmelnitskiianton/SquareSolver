/*!
    \file 
    \brief Running file of input and entering 
*/

#include "head.h"

void clean_buffer (void)
{
    int ch = 0;                     
    while ((ch = getchar ()) != '\n') {}   
}

double enter_double (void)
{
    double num = NAN;
    while((scanf ("%lf", &num) != 1) || !(check_double (num)))
    {   
        clean_buffer ();
        printf ("\n" RED "Wtf? Its not normal double number. Maybe it is infinite/NAN number or letters. Another attempt you piece of shit, hey you, MAAAAN!" RESET "\n");
    }
    return num;
}

void input_args (double *args)
{
    int amount = 0;
    for (int i = 0; i < QUANTITY; i++)
    {
        args[i] = enter_double ();
        amount += 1;
        if (amount == 1) printf (BLUE "You enter a = %.2lf !" RESET "\n", args[0]);
        if (amount == 2) printf (BLUE "Now you enter a = %.2lf and b = %.2lf !!" RESET "\n", args[0], args[1]);
        if (amount == 3) printf (BLUE "Super, you enter a = %.2lf and b = %.2lf and c = %.2lf !!!" RESET "\n", args[0], args[1], args[2]);
    }
}

int welcome (void)
{   
    rtrtrt();
    printf ("\n" MAGENTA "    QUADRATIC EQUATION SOLVER BY KHMELNITSKII ANTON SUMMER PROGRAMM CAMP 2023\n"
           "----------------------------------------------------------------------------------" RESET "\n");
    printf ("\n" CYAN "Enter arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
            "   Please enter only normal double numbers!!!" RESET "\n");
    printf ("\n" YELLOW "    YOU WANT TO USE AUTO TESTING ???\n"
           "        Enter Y or N" RESET "\n            ");

    if (user_choice () == 'Y') test_allfile ();

    printf (YELLOW "    Do you want to continue use this program ??? \n    "
        "   Enter Y or N" RESET"\n           ");

    if (user_choice () == 'Y')
    {
        printf (GREEN "Enter 3 arguments(numbers) of quadratic equation: ax^2 + bx + c = 0.\n"
               "    After every number press enter/tab/space!" RESET "\n");
        return 0;    
    }
    else
    { 
    return 1;
    }
}

void filler_coeffs (double *args)
{
    for (int i = 0; i < QUANTITY; i++)             
    {
        args[i] = NAN;
    }
}

int user_choice (void)
{
    int ch = 0;
    ch = getchar ();
    while (toupper (ch) != 'N')
    {
        if ((toupper (ch)) == 'Y') break;
        printf ( RED "PRINT Y OR N! WHAT THE FUCK DONT YOU UNDERSTAND, BASTARD?" RESET "\n");
        clean_buffer ();
        ch = getchar ();
    }
    printf (CYAN "You choose %c !" RESET "\n", ch);
    clean_buffer ();
    return toupper (ch);
}

void rtrtrt(void)
{                                                                                      
printf( RED "                                                    ..::^^^::..                          .:^:.            \n"
"                                                 :~7JY5PPPP5555555YJ7~:                .^!??!^.                       \n"
"                                             .^?5PG5J7~^:.......::^!?JYY7^.        :~?5PY7^.                          \n"
"                                           :?PGPJ~:.                  .:!?J!.  :!JGBGJ~.                              \n"
"                                         ^JGGJ~.                          .!??P##G?^                                  \n"
"                                      .?GG?:                           .~JG#&BY^                                      \n"
"                                      ^5BY^                           ~JG#&&G7.:!.                                    \n"
"                                     ^PG?.                          .5####G7.   .~.                                   \n"
"                                    :PG7                           .P&###Y.      .~.                                  \n"
"                                ...:7YJ~~!!!77777~.                Y&###7         .:                                  \n"
"                    ..:^~!?JY5PPGBBBBB###&#####&##GY~.            !&###!           ..                                 \n"
"          .:^~!?JY55PG##&&&&&&&&&&###################GJ~         .G###?             .                                 \n"
"   :^^~!7?????7!~~7YGBBBGGP5YJ??7!!7Y7~~!7J5G###########G?:      7&##P                                                \n"
"   :::..         :~~^::..          ~B7      .^75B########&B5~.  .B###~        .::                                     \n"
"                                   .P5          .!5#&########G?:7&##P.:^!?J5PGB5!                                     \n"
"                                    !G^            ^Y##########BB###BGB#&&&#GY~                                       \n"
"                                     J5.             :5#############&&#BGY7^.                                         \n"
"                                     .?J.        .^!J5G##########BGPY7~:                                              \n"
"                                       !J: ..^!7JJY#&&&##BGP5J?!^:.                                                   \n"
"                                        :~^~^^^:..J5Y?7~^:.                                                           \n"
"                                          :~^.   ..                                                                   \n"
"                                            :^:..                                                                     \n"
"                                               .....                                                                  \n"
"                                                   ..                                                                 \n\n" RESET);                                                                                                   
}

void mipt(void)
{                                                                                                                                            
printf( BLUE "                     .                                                                                                                              \n"                                                                                  
"                  :?55Y~                                                                                                                                        \n"
"                 ~PPJ?PP!                                                                                                                                       \n"
"                ^PPY. JPP^                                                                                                                                      \n"
"               .YP5:  ^PPJ                                                                                                                                      \n"
"               !PP7    YPP:                                                                                                                                     \n"
"              .5P5.    !PP7                                                    :~^^^^^^                                                                         \n"
"              !PP7     :5PY              .?JJJJJJJJJ?.   ^JJJJJJJJJJ7       ...JPPPPPP?..      .?JJJJJJJJJJJJJJJJJJJ::JJJJJJJ:   ^?JJJJJJJ!                     \n"
"             .5P5.      JPP:             ~PPPPPPPPPPP:  :5PPPPPPPPPP!  .~7JYY55PPPPPPP555YJ?~. !PPPPPPPPPPPPPPPPPPPY 7PPPPPPY   !PPPPPPPPP~                     \n"
"             !PP7       !PP!             JPPPPPJPPPPP^ :5PPP5YPPPPP5 :?5PPPPPPPPPPPPPPPPPPPPPY:J555555PPPPPPP555555~.5PPPPPP~ .JPPPPPPPPPY                      \n"
"             YP5:       :PPJ            ^PPPPP5^5PPPP^.YPPP5~5PPPPP!^5PPPPPY~:YPPPPP5:^YPPPPPP7 .....YPPPPPP7 ..... !PPPPPP5.^5PPPPPPPPPP!                      \n"
"            ^PP?         YP5.           ?PPPPP?.5PPPP!JPPP5:!PPPPP5^5PPPPP5. :PPPPPP7  ?PPPPPP~     ^PPPPPP5:       YPPPPPP7!PPP5JPPPPPP5.                      \n"
"            JPP^         7PP~          :5PPPPP:.5PPPP5PPP5^ 5PPPPP?:PPPPPP5~.?PPPPPP^:?PPPPPP?      JPPPPPP?       ^PPPPPPP5PPPY:JPPPPPP?                       \n"
"           :PPJ          ^PP?          7PPPPPJ  YPPPPPPP5^ ~PPPPPP^ ?PPPPPPP5PPPPPPP5PPPPPP5!      :PPPPPPP^       JPPPPPPPPPP7 :PPPPPPP:                       \n"
"           7PP~          .5PY.        .5PPPPP~  JPPPPPPP^  YPPPPPJ   ^7JY555PPPPPPP5555YJ7^.       7PPPPPPJ       :PPPPPPPPP5^  ?PPPPPPJ                        \n"
"          .5P5.           JPP^        !PPPPPY   JPPPPPP~  ^PPPPPP~      ...~PPPPPPP^...           .5PPPPPP~       ?PPPPPPPP?.  :PPPPPPP^                        \n"
"          7PP!            ~PP7        :^^^^^:   :^^^^^:   :^^^^^^          :!~~~~!~               .^^^^^^^        :^^^^^^^^    .^^^^^^^                         \n"
"     .~~~?PPJ.            :5PY    .^~~^^^^^^^~~~^^^^^^^~~~^^^^^^^~~~~~~~~~~^^^^^^^^~~~~~~~~~~~~~~~~^^^^^^^~~~~~~~~^^^^^^^^^~~~~~^^^^^^^~~~~~~^7J?!~^ |..        \n"
"     ~PP55J~               JPP:  ~5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPJ:PPPPP |PYJ7~.... \n"
"     .....                 !PP7 ~PPJ:.........................................................................................................^?!~^: |:""""     \n"
"                           .YP5!5PY.                                                                                                                            \n"
"                            :YPPPJ.                                                                                                                             \n"
"                              :::                                                                                                                               \n\n" RESET);                                                           
}