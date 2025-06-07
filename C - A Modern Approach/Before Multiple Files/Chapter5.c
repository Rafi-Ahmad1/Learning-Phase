// /*Program to calculate digits of given number
//   Program 1*/

// #include <stdio.h>

// void main()
// {
//     int n;

//     printf("Enter a number: ");
//     scanf("%d",&n);

//     printf("The number %d has ",n);

//     if (n>=0 && n<10)
//         printf("1 digit.");
//     else if (n>=10 && n<100)
//         printf("2 digits.");
//     else if (n>=100 && n<1000)
//         printf("3 digits.");
//     else if (n>=1000 && n<10000)
//         printf("4 digits.");
//     else 
//         printf("Man Fuck You digits");
// }



// /*Converting 24-hour time to 12-hour
//   Program 2*/

// #include <stdio.h>

// void main()
// {
//     int hour,minute;

//     printf("Enter a 24-hour time: ");
//     scanf("%d:%d",&hour,&minute);

//     printf("Equivalent 12-hour time: ");

//     if(hour>0 && hour < 12)
//         printf("%d:%.2d AM",hour,minute);
//     else if (hour == 0)
//         printf("12:%.2d AM",minute);
//     else if (hour == 12)
//         printf("12:%.2d PM",minute);
//     else
//         printf("%d:%.2d PM", hour - 12, minute);
// }



// /*Calculating brokers' commission
//   Program 3*/

// #include <stdio.h>

// void main()
// {
//     int number_of_shares, price_per_share, value_of_trade;
//     float broker_commission, rival_broker_com;

//     printf("Enter the number of shares: ");
//     scanf("%d",&number_of_shares);
//     printf("Enter price per share: ");
//     scanf("%d",&price_per_share);

//     value_of_trade = price_per_share * number_of_shares;

//     if (value_of_trade < 2500)
//         broker_commission = 30 + 0.017 * value_of_trade;
//     else if (value_of_trade < 6250)
//         broker_commission = 56 + 0.0066 * value_of_trade;
//     else if (value_of_trade < 20000)
//         broker_commission = 76 + 0.0034 * value_of_trade;
//     else if (value_of_trade < 50000)
//         broker_commission = 100 + 0.0022 * value_of_trade;
//     else if (value_of_trade < 500000)
//         broker_commission = 155 + 0.0011 * value_of_trade;
//     else if (value_of_trade >= 500000)
//         broker_commission = 255 + 0.0009 * value_of_trade;
//     else 
//         printf ("BRO WTF!");

//     if (broker_commission < 39.00f)
//         broker_commission = 39;

//     printf("\nOriginal Broker's Commission: %.2f",broker_commission);


//     if(value_of_trade < 2000)
//         rival_broker_com = 33 + 0.03 * number_of_shares;
//     else 
//         rival_broker_com = 33 + 0.02 * number_of_shares;

//     printf("\nRival Broker's Commission: %.2f",rival_broker_com);

// }



// /*Receiving Wind Speed(in knots) by user and displaying description using Beaufort Scale
//   Program 4*/

// #include <stdio.h>

// void main()
// {
//     float air_speed;

//     printf("Enter Wind Speed (in knots): ");
//     scanf("%f",&air_speed);

//     printf("Description: ");

//     if (air_speed < 1)
//         printf("Calm");
//     else if (air_speed <= 3)
//         printf("Light air");
//     else if (air_speed <= 27)
//         printf("Breeze");
//     else if (air_speed <= 47)
//         printf("Gale");
//     else if (air_speed <= 63)
//         printf("Storm");
//     else if (air_speed > 63)
//         printf("Hurricane");    
// }



// /*Enter Taxable income and display tax due
//   Program 5*/

// #include <stdio.h>

// void main()
// {
//     float taxable_income;

//     printf("Enter your income($): ");
//     scanf("%f",&taxable_income);

//     printf("The Tax due is: ");

//     if(taxable_income < 750)
//         printf("$%.2f", 0.01 * taxable_income);
//     else if(taxable_income < 2250)
//         printf("$%.2f",7.50 + 0.02 * (taxable_income - 750) );
//     else if(taxable_income < 3750)
//         printf("$%.2f",37.50 + 0.03 * (taxable_income - 2250) );
//     else if(taxable_income < 5250)
//         printf("$%.2f",82.50 + 0.04 * (taxable_income - 3750) );
//     else if(taxable_income < 7000)
//         printf("$%.2f",142.50 + 0.05 * (taxable_income - 5250) );
//     else if(taxable_income > 7000)
//         printf("$%.2f",230.00 + 0.06 * (taxable_income - 7000) );
// }



// /*Checking and Validating the UPC entered by user
//   Program 6*/

// #include <stdio.h>

// void main()
// {
//     int a,b,c,d,e,f,g,h,i,j,k,l,m;

//     printf("Enter the 12 digit UPC: ");
//     scanf("%1d %1d%1d%1d%1d%1d %1d%1d%1d%1d%1d %1d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l);

//     m = 9 - ( (3*(a+c+e+g+i+k) + (b+d+f+h+j)) - 1 ) % 10;

//     if(m==l)
//         printf("VALID");
//     else 
//         printf("NOT VALID");
// }



// /*Program to find largest and smallest of 4 number entered by the user
//   Program 7*/

// #include <stdio.h>

// void main()
// {
//     int int_1, int_2, int_3, int_4;

//     printf("Enter four integers: ");
//     scanf("%d %d %d %d", &int_1, &int_2, &int_3, &int_4);

//     if(int_1 > int_2 && int_1 > int_3 && int_1 > int_4)
//         printf("Largest: %d\n", int_1);
//     else if (int_2 > int_3 && int_2 > int_4)
//         printf("Largest: %d\n", int_2);
//     else if(int_3 > int_4)
//         printf("Largest: %d\n", int_3);
//     else
//         printf("Largest: %d\n", int_4);

//     if(int_1 < int_2 && int_1 < int_3 && int_1 < int_4)
//         printf("Smallest: %d\n", int_1);
//     else if (int_2 < int_3 && int_2 < int_4)
//         printf("Smallest: %d\n", int_2);
//     else if(int_3 < int_4)
//         printf("Smallest: %d\n", int_3);
//     else
//         printf("Smallest: %d\n", int_4);
// }



// /*Tells the nearest Departure and Arrival time for Flights entered by user
//   Program 8*/

// #include <stdio.h>

// void main()
// {
//     int hour, minute, mins_since_mdnght;
//     int dep1, dep2, dep3, dep4, dep5, dep6, dep7, dep8;

//     dep1 = (8 * 60);
//     dep2 = (9 * 60) + 43;
//     dep3 = (11 * 60) + 19;
//     dep4 = (12 * 60) + 47;
//     dep5 = ( (12+2) * 60);
//     dep6 = ( (12+3) * 60) + 45;
//     dep7 = ( (12+7) * 60);
//     dep8 = ( (12+9) * 60) + 45;

//     printf("Enter Current time[24-hour]: ");
//     scanf("%d:%d", &hour, &minute);

//     mins_since_mdnght = minute + (hour * 60);
    
//     printf("Closest departure time is ");

//     if (mins_since_mdnght <= (dep1 + dep2)/2 )
//         printf("8:00 AM, arriving at 10:16 AM.");
//     else if (mins_since_mdnght <= (dep2 + dep3)/2 )
//         printf("9:43 AM, arriving at 11:52 AM.");
//     else if (mins_since_mdnght <= (dep3 + dep4)/2 )
//         printf("11:19 AM, arriving at 1:31 PM.");
//     else if (mins_since_mdnght <= (dep4 + dep5)/2 )
//         printf("12:47 PM, arriving at 3:00 PM.");
//     else if (mins_since_mdnght <= (dep5 + dep6)/2 )
//         printf("2:00 PM, arriving at 4:08 PM.");
//     else if (mins_since_mdnght <= (dep6 + dep7)/2 )
//         printf("3:45 PM, arriving at 5:55 PM.");
//     else if (mins_since_mdnght <= (dep7 + dep8)/2 )
//         printf("7:00 PM, arriving at 9:20 PM.");    
//     else
//         printf("9:45 PM, arriving at 11:58 PM.");
// }



// /*Program to enter two dates and then indicate which date comes earlier
//   Program 9*/

// #include <stdio.h>

// void main()
// {
//     int dd_1, mm_1, yyyy_1;
//     int dd_2, mm_2, yyyy_2;

//     printf("Enter first date (dd/mm/yyyy): ");
//     scanf("%d/%d/%d", &dd_1, &mm_1, &yyyy_1);
//     printf("Enter Second date (dd/mm/yyyy): ");
//     scanf("%d/%d/%d", &dd_2, &mm_2, &yyyy_2);

//     if (yyyy_1 > yyyy_2)
//         printf("%d/%d/%d is earlier than %d/%d/%d", dd_2, mm_2, yyyy_2, dd_1, mm_1, yyyy_1);   
//     else if (yyyy_1 < yyyy_2)
//         printf("%d/%d/%d is earlier than %d/%d/%d", dd_1, mm_1, yyyy_1, dd_2, mm_2, yyyy_2);
//     else {
//         if (mm_1 > mm_2)
//             printf("%d/%d/%d is earlier than %d/%d/%d",dd_2, mm_2, yyyy_2, dd_1, mm_1, yyyy_1);
//         else if (mm_1 < mm_2)
//                 printf("%d/%d/%d is earlier than %d/%d/%d",dd_1, mm_1, yyyy_1, dd_2, mm_2, yyyy_2);
//         else {
//             if (dd_1 > dd_2)
//                 printf("%d/%d/%d is earlier than %d/%d/%d",dd_2, mm_2, yyyy_2, dd_1, mm_1, yyyy_1);
//             else
//                 printf("These are the same dates.");
//         }
//     }

// }



// /*Using Switch statement a program to convert numerical grade into letter grade
//   Program 10*/

// #include <stdio.h>

// void main()
// {
//     int num_grade;

//     printf("Enter numerical grade: ");
//     scanf("%d", &num_grade);

//     if (num_grade < 0 || num_grade > 100)
//         printf("Error, Invalid Grade");
//     else
//         switch (num_grade/10) {
//             case 9: case 10:
//                     printf("A Grade");
//                     break;
//             case 8: printf("B Grade");
//                     break;
//             case 7: printf("C Grade");
//                     break;
//             case 6: printf("D Grade");
//                     break;
//             case 5: case 4: case 3: case 2: case 1: case 0:
//                     printf("F Grade");
//                     break;
//             default: printf("Error, Invalid Grade");
//                      break;
//         }   
// }



// /*Displaying the English word for a two digit number
//   Program 11*/

// #include <stdio.h>

// void main()
// {
//     int num;

//     printf("Enter a two-digit number: ");
//     scanf("%d", &num);

//     if (num >= 100 || num < 0)
//         printf("I told you to enter a TWO DIGIT NUMBER.");
//     else {
//         printf("You Entered the number ");

//         switch (num/10) {
//             case 9: printf("Ninety "); break;
//             case 8: printf("Eighty "); break;
//             case 7: printf("Seventy "); break;
//             case 6: printf("Sixty "); break;
//             case 5: printf("Fifty "); break;
//             case 4: printf("Forty "); break;
//             case 3: printf("Thirty "); break;
//             case 2: printf("Twenty "); break;
//             case 1: case 0:
//                     break;
//         }

//         switch (num%10) {
//             case 9: printf("Nine"); break;
//             case 8: printf("Eight"); break;
//             case 7: printf("Seven"); break;
//             case 6: printf("Six"); break;
//             case 5: printf("Five"); break;
//             case 4: printf("Four"); break;
//             case 3: printf("Three"); break;
//             case 2: printf("Two"); break;
//             case 1: printf("One"); break;
//             case 0: break;
//         }
//     }
// }