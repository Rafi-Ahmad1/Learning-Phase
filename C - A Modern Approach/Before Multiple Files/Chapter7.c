// /*Testing square2.c from Section 6.3
//   Program 1*/

// #include <stdio.h>

// void main() {
//     int i, n;

//     printf("Enter number of Entries in table: ");
//     scanf("%d", &n);
    
    
//     for(i=1; i <= n; i++) {
//         printf("%10d\t%10d\n",i, i*i);
//     }
// }



// /*Modifying Square2.c from Section 6.3
//   Program 2*/

// #include <stdio.h>

// void main() {
//     long long int i, n;

//     printf("Enter number of Entries in table: ");
//     scanf("%lld", &n);
//     getchar();
    
//     for(i=1; i <= n; i++) {
        
//         printf("%10lld\t%10lld\n",i, i*i);

//         if(i%24==0) {
//             printf("Press Enter to continue...");
//             getchar();
//         }     
//     }
// }



// /*Modifying sum2.c from Section 7.1
//   Program 3*/

// #include <stdio.h>

// void main() {
//     double num, sum=0;

//     printf("Enter Series [0 to terminate]: ");
//     scanf("%lf", &num);

//     for (;num != 0;) {
//         sum += num;
//         scanf("%lf",&num);
//     }
//     printf("The sum is: %lf",sum);
// }



// /*Converting alphabetic phone number into numeric form
//   Program 4*/

// #include <stdio.h>

// void main() {
//     char ph_no;

//     printf("Enter phone number: ");
//     scanf("%c",ph_no);

//     for(;ph_no != '\n';) {
//         switch (ph_no)
//         {
//             case 'A': case 'B': case 'C':
//             printf("2"); break;
//             case 'D': case 'E': case 'F':
//             printf("3"); break;
//             case 'G': case 'H': case 'I':
//             printf("4"); break;
//             case 'J': case 'K': case 'L':
//             printf("5"); break;
//             case 'M': case 'N': case 'O':
//             printf("6"); break;
//             case 'P': case 'R': case 'S':
//             printf("7"); break;
//             case 'T': case 'U': case 'V':
//             printf("8"); break;
//             case 'W': case 'X': case 'Y':
//             printf("9"); break;
//             default: printf("%c",ph_no);
//         }
//         ph_no = getchar();
//     }
// }



// /*Determining the value of a word by summing the values of its letters [Scrabble]
//   Program 5*/

// #include <stdio.h>
// #include <ctype.h>

// void main() {
//     char ch;
//     int svalue = 0;

//     printf("Enter a word: ");
//     scanf("%c",ch);

//     while (ch != '\n') {
//         switch (toupper(ch))
//         {
//             case 'A': case 'E': case 'I': case 'L': case 'N': case 'O': case 'R': case 'S': case 'T': case 'U':
//             svalue += 1; break;
//             case 'D': case 'G':
//             svalue += 2; break;
//             case 'B': case 'C': case 'M': case 'P':
//             svalue += 3; break;
//             case 'F': case 'H': case 'V': case 'W': case 'Y':
//             svalue += 4; break;
//             case 'K': 
//             svalue += 5; break;
//             case 'J': case 'X':
//             svalue += 8; break;
//             case 'Q': case 'Z':
//             svalue += 10; break;
//             default: printf("%c",ch);
//         }
//         ch = getchar();
//     }
//     printf("Scrabble value: %d",svalue);
// }



// /*Printing sizeof values
//   Program 6*/

// #include <stdio.h>

// void main() {
//     printf("Size of int: %d\nshort: %d\nlong: %d\nfloat: %d\ndouble: %d\nlong double: %d\n",sizeof(int),sizeof(short),sizeof(long),sizeof(float),sizeof(double),sizeof(long double));
// }



// /*Modifying Project 6 from Chapter 3
//   Program 7*/

// #include <stdio.h>

// void main()
// {
//     int nume1, nume2, denom1, denom2, result_nume, result_denom;
//     char ope;

//     printf("Enter: ");
//     scanf("%d/%d %c %d/%d", &nume1, &denom1, &ope, &nume2, &denom2);

//     switch (ope) 
//     {
//         case '+': 
//             result_nume = (nume1 * denom2) + (nume2 * denom1);
//             result_denom = denom1 * denom2;
//             break;
//         case '-': 
//             result_nume = (nume1 * denom2) - (nume2 * denom1);
//             result_denom = denom1 * denom2;
//             break;
//         case '*': 
//             result_nume = (nume1 * nume2);
//             result_denom = denom1 * denom2;
//             break;
//         case '/': 
//             result_nume = (nume1 * denom2);
//             result_denom = (nume2 * denom1);
//             break;
//         default: printf("Invalid Input"); break;
//     }

//     int n,d,temp, gcd;
//     n=result_nume; d=result_denom;

//     while(n != 0) {
//         temp = n;
//         n = d % n;
//         d = temp;
//     }
//     gcd = d;

//     printf("The Answer is: %d/%d", result_nume/gcd, result_denom/gcd);
// }



// /* Modified version of Tells the nearest Departure and Arrival time for Flights entered by user
//   Program 8*/

// #include <stdio.h>

// void main()
// {
//     int hour, minute, mins_since_mdnght;
//     int dep1, dep2, dep3, dep4, dep5, dep6, dep7, dep8;
//     char mer;

//     dep1 = (8 * 60);
//     dep2 = (9 * 60) + 43;
//     dep3 = (11 * 60) + 19;
//     dep4 = (12 * 60) + 47;
//     dep5 = ( (12+2) * 60);
//     dep6 = ( (12+3) * 60) + 45;
//     dep7 = ( (12+7) * 60);
//     dep8 = ( (12+9) * 60) + 45;

//     printf("Enter Current time[12-hour]: ");
//     scanf("%d:%d %c", &hour, &minute, &mer);

//     switch (mer) {
//         case 'p': case 'P':
//             hour += 12; break;
//     }

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



// /*Converting 12-hour time to 24-hour
//   Program 9*/

// #include <stdio.h>

// void main() {
//     int hh, mm;
//     char mer;

//     printf("Enter a 12-Hour time: ");
//     scanf("%d:%d %c",&hh, &mm, &mer);

//     switch (mer) {
//         case 'p': case 'P':
//             hh += 12; break;
//     }
//     printf("24-hour equivalent is: %d:%d",hh, mm);
// }



// /*Counting number of strings in a sentence
//   Program 10*/

// #include <stdio.h>
// #include <ctype.h>

// void main() {
//     char ch;
//     int vowel=0;

//     printf("Enter a sentence: ");
//     ch = getchar();

//     while (ch != '\n') {
//         switch (toupper(ch)) {
//             case 'A': case 'E': case 'I': case 'O': case 'U':
//                 vowel++; break;
//         }
//         ch = getchar();
//     }
//     printf("Your Sentence contains %d vowels",vowel);
// }



// /*Last name + First Initial with a comma
//   Program 11*/

// #include <stdio.h>

// void main() {
//     char ch,initial;

//     printf("Enter a first and last name: ");
//     scanf("%c",&ch);

//     initial = ch;

//     while(ch = getchar() != ' ');

//     for(;;) {
//         ch = getchar();
//         if(ch != '\n')
//         putchar(ch);
//         else break;
//     }

//     printf(", %c", initial);
// }



// /*Evaluating an Expression
//   Program 12*/

// #include <stdio.h>

// void main() {
//     float num1, num2, result;
//     char ope1, ope2;

//     printf("Enter an Expression: ");
//     scanf("%f%c%f",&num1, &ope1, &num2);

//     switch (ope1) {
//         case '+': result = num1 + num2; break;
//         case '-': result = num1 - num2; break;
//         case '*': result = num1 * num2; break;
//         case '/': result = num1 / num2; break;
//     }

//     ope1=getchar();

//     while(ope1 != '\n') {
//         num1 = result;
//         scanf("%f%c", &num2, &ope2);

//         switch (ope1) {
//             case '+': result = num1 + num2; break;
//             case '-': result = num1 - num2; break;
//             case '*': result = num1 * num2; break;
//             case '/': result = num1 / num2; break;
//         }
//         ope1 = ope2;
//     }

//     printf("Value of Expression: %.1f",result);
// }



// /*Avg word length for a sentence
//   Program 13*/

// #include <stdio.h>

// void main() {
//     int words=0, count=0;
//     char i;
    
//     printf("Enter a sentence: ");

//     while( (i = getchar()) != '\n') {
//         if(i != ' ' && i != '\n')
//             count++;
//         if(i == ' ')
//             words++;
//     }

//     printf("Average word length: %.1f",(float)count/(words+1));
// }



// /*Using Newton's method to calculate the square root
//   Program 14*/

// #include <stdio.h>
// #include <math.h>

// void main() {
//     double num, guess=2, root = 1;

//     printf("Enter a positive number: ");
//     scanf("%lf",&num);

//     while (fabs(guess-root) > 0.00001 * guess) {
//         guess = root;
//         root = (guess + num/guess)/2;
//     }

//     printf("Square root: %lf",root);
// }



// /*Calculating Factorial of a positive integer
//   Program 15*/

// #include <stdio.h>

// void main() {
//     int num;
//     long long unsigned int fact=1;

//     printf("Enter a positive integer: ");
//     scanf("%d",&num);

//     for (int i = num; i > 0; i--) {
//         fact *= i;
//     }
//     printf("Factorial of %d is: %llu",num,fact);
// }