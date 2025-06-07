// /*Program to find the greatest in a series of numbers entered by the user
//   Program 1*/

// #include <stdio.h>

// void main () {
//     float num, max = 0;
    
//     for(;;) {
//         printf("Enter a number: ");
//         scanf("%f",&num);
//         if(num>max)
//             max = num;
//         if(num == 0)
//             break;
//     }
//     printf("The largest number entered was %f",max);
// }



// /*Program to display GCD of two numbers.
//   Program 2*/

// #include <stdio.h>

// void main() {
//     int num_1,num_2,gcd,temp;

//     printf("Enter two integers: ");
//     scanf("%d %d",&num_1,&num_2);

    // while(num_1 != 0) {
    //     temp = num_1;
    //     num_1 = num_2 % num_1;
    //     num_2 = temp;
    // }
    // gcd = num_2;
    
//     printf("Greatest Common Divisor: %d",gcd);
// }



// /*Program that reduces entered fraction to lowest terms
//   Program 3*/


// #include <stdio.h>

// void main() {
//     int nume,deno,gcd,temp;

//     printf("Enter a fraction: ");
//     scanf("%d/%d",&nume,&deno);

//     int n=nume,d=deno;

//     while(n != 0) {
//         temp = n;
//         n = d % n;
//         d = temp;
//     }
//     gcd = d;
    
//     printf("In lowest terms is: %d/%d",nume/gcd,deno/gcd);
// }



// /*Adding loop to broker.c of Section 5.2
//   Program 4*/

// #include <stdio.h>

// void main()
// {
//     int value_of_trade;
//     float broker_commission, rival_broker_com;

//     while(value_of_trade != 0) {

//         printf("Enter value of trade: ");
//         scanf("%d",&value_of_trade);

//         if (value_of_trade < 2500)
//             broker_commission = 30 + 0.017 * value_of_trade;
//         else if (value_of_trade < 6250)
//             broker_commission = 56 + 0.0066 * value_of_trade;
//         else if (value_of_trade < 20000)
//             broker_commission = 76 + 0.0034 * value_of_trade;
//         else if (value_of_trade < 50000)
//             broker_commission = 100 + 0.0022 * value_of_trade;
//         else if (value_of_trade < 500000)
//             broker_commission = 155 + 0.0011 * value_of_trade;
//         else if (value_of_trade >= 500000)
//             broker_commission = 255 + 0.0009 * value_of_trade;
//         else 
//             printf ("BRO WTF!");

//         if (broker_commission < 39.00f)
//             broker_commission = 39;

//         printf("Commission: %.2f\n",broker_commission);
//     }
// }



// /*Program that reverts the digits of number entered by user
//   Program 5*/

// #include <stdio.h>

// void main()
// {
//     int n,i;

//     printf("Enter a number: ");
//     scanf("%d",&n);

//     printf("The number Reversed is: ");

//     for(;;) {
//         i = n % 10;
//         n = n / 10;
//         if(i==0)
//             break;
//         else 
//             printf("%d",i);
//     }
// }



// /*Program that prints even squares between 1 and n
//   Program 6*/

// #include <stdio.h>

// void main() {
//     int n;

//     printf("Enter a number: ");
//     scanf("%d",&n);

//     for(int i=1; i*i<=n; i++) {
//         if(i%2==0)
//             printf("%d\n",i*i);
//     }
// }



// /*Program that prints table of squares using odd method
//   Program 7*/

// #include <stdio.h>

// void main() {
//     int n,odd,square;

//     printf("This program prints a table of squares.\n");
//     printf("Enter number of entries in table: ");
//     scanf("%d",&n);

//     square = 1;
//     odd=3;
//     for (int i=1; i <= n; i++) {
//         printf("%10d%10d\n",i,square);
//         square += odd;
//         odd += 2;
//     }
// }



// /*Program that prints a one-month calender
//   Program 8*/

// #include <stdio.h>

// void main() {
//     int no_of_days,day;

//     printf("Enter number of days in the month: ");
//     scanf("%d",&no_of_days);
//     printf("Enter starting day of the week [Mon=1, Sun=7]: ");
//     scanf("%d",&day);

//     for(int i = 1; i < day; i++) 
//         printf("    ");
    
//     for(int i=1, j=0; i <= no_of_days ; i++) {
//         printf("%2d  ",i);

//         if(i == (8-day)+j) {
//             printf("\n");
//             j += 7;
//         }
//     }
// }



// /*Program that calculates balance remaining on a loan after some monthly payments
//   Program 9*/

// #include <stdio.h>

// void main()
// {
//     float loan_amount, final_amount, interest_rate, monthly_payment;
//     int num;

//     printf("Enter amount of loan: ");
//     scanf("%f",&loan_amount);
//     printf("Enter interest rate: ");
//     scanf("%f", &interest_rate);
//     printf("Enter monthly payment: ");
//     scanf("%f",&monthly_payment);
//     printf("Number of monthly payments done: ");
//     scanf("%d",&num);
    
//     final_amount = loan_amount;

//     for(int i = 1; i <= num; i++) {
//         printf("Balance after %d Payment(s): %.2f\n", i, final_amount + final_amount * interest_rate/1200 - monthly_payment);   
//         final_amount = final_amount + final_amount * interest_rate/1200 - monthly_payment;
//     }
// }



// /*Program that tells which of the entered date comes first
//   Program 10*/

// #include <stdio.h>

// void main() {
//     int dd, mm, yyyy;
//     int e_dd, e_mm, e_yyyy=0;
    
//     for(;;) {
//         printf("Enter a date (dd/mm/yyyy): ");
//         scanf("%d/%d/%d",&dd,&mm,&yyyy);

//         if(dd==0 && mm==0 && yyyy==0)
//             break;

//         if(e_yyyy==0) {
//             e_yyyy = yyyy;
//             e_mm = mm;
//             e_dd = dd;
//         }

//         if(yyyy<e_yyyy) {
//             e_yyyy = yyyy;
//             e_mm = mm;
//             e_dd = dd;
//         }
//         else if(yyyy > e_yyyy)
//             continue;

//         else if (mm<e_mm) {
//             e_yyyy = yyyy;
//             e_mm = mm;
//             e_dd = dd;
//         }
//         else if(mm > e_mm)
//             continue;

//         else if(dd<e_dd) {
//             e_yyyy = yyyy;
//             e_mm = mm;
//             e_dd = dd;
//         }
//         else if(dd > e_dd)
//             continue;
        
//     }
//     printf("The Earliest date is: %d/%d/%d", e_dd, e_mm, e_yyyy);
// }



// /*Approximating euler's number e
//   Program 11*/

// #include <stdio.h>

// void main() {
//     int n,fact=1;
//     float e=1;

//     printf("Enter a positive integer: ");
//     scanf("%d",&n);

//     for(int i=1; i <= n; i++) {
//         fact = fact*i;
//         e = e + 1/(float)fact;
//     }
//     printf("The Approximate value of e is: %f",e);
// }



// /*Approximating euler's number e
//   Program 12*/

// #include <stdio.h>

// void main() {
//     float e=1,term=1, n, fact=1;

//     printf("Enter a small floating point number: ");
//     scanf("%f",&n);

//     for(int i=1; term >= n; i++) {
//         fact = fact*i;
//         term = 1/fact;
//         e = e + term;
//     }
//     printf("The Approximate value of e is: %f",e);
// }