// /*Modifying repdigit.c to show which digits were repeated
//   Program 1*/

// #include <stdio.h>

// void main() {
//     int seen[10] = {0};
//     int num,digit;

//     printf("Enter a number: ");
//     scanf("%d",&num);

//     while(num > 0) {
//         digit = num%10;
//         seen[digit]++;
//         num /= 10;
//     }

//     printf("Repeated digit(s): ");
//     for (int i = 0; i < 10; i++) {

//     if (seen[i] > 1)
//         printf("%d ",i);
//     }
// }



// /*Modifying repdigit.c to print table showing frequency of repeated digits
//   Program 2*/

// #include <stdio.h>

// int main() {
//     int seen[10] = {0};
//     int num,digit;

//     printf("Enter a number: ");
//     scanf("%d",&num);

//     while(num > 0) {
//         digit = num%10;
//         seen[digit]++;
//         num /= 10;
//     }

//     printf("Digit:      ");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ",i);
//     }

//     printf("\nOccurences: ");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ",seen[i]);
//     }
// }



// /*Modifying repdigit.c yet again so we can enter more than one number to be tested for repeated digits
//   Program 3*/

// #include <stdio.h>
// #define SIZE sizeof(num)/sizeof(num[0])

// void main() {
//     int digit,temp;

//     printf("Enter numbers to be tested: ");
    
//     int num[99] = {0};
//     int i=-1;
//     do{
//         i++;
//         scanf("%d",&num[i]);
//     } while(num[i] > 0);

//     int seen[10][SIZE] = {0};
//     for(int i = 0; i < SIZE; i++) {
//         temp = num[i];
//         while (temp > 0) {
//             digit = temp%10;
//             seen[digit][i]++;
//             temp /= 10;
//         }
//     }

//     printf("\nDigit:            ");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ",i);
//     }

//     for(int i = 0; i < SIZE; i++) {
//         if(num[i] == 0)
//             continue;
//         printf("\nOccurences for %d: ",i+1);
//         for(int j = 0; j < 10; j++) {
//             printf("%d ",seen[j][i]);
//         }
//     }
// }



// /*Reversing a series of numbers
//   Program 4*/

// #include <stdio.h>
// #define N sizeof(a)/sizeof(a[0])

// void main() {
//     int a[10];

//     printf("Enter %d numbers: ",N);
//     for(int i=0;i<N;i++) {
//         scanf("%d",&a[i]);
//     }
    
//     printf("Reverse Order: ");
//     for(int i=(N-1);i>=0;i--) {
//         printf("%d ",a[i]);
//     }
// }



// /*Modifying interest.c to compound interest monthly
//   Program 5*/

// #include <stdio.h>

// #define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
// #define INITIAL_BALANCE 100.00

// void main() {
//     int i, num_yrs, year;
//     double low_rate;
//     double value[5];

//     printf("Enter interest rate: ");
//     scanf("%lf",&low_rate);
//     printf("Enter number of years: ");
//     scanf("%d",&num_yrs);

//     printf("\nYears\t");
//     for(i = 0; i < NUM_RATES; i++) {
//         printf("%4.1lf%%\t",low_rate+i);
//         value[i] = INITIAL_BALANCE;
//     }

//     printf("\n\n");
//     for(year = 1; year <= num_yrs; year++) {
//         printf("%3d\t",year);
//         for(i = 0; i < NUM_RATES; i++) {
//             for(int month = 0; month <= 12; month++) {
//                 value[i] += ((value[i] * (low_rate + i)) / (100 * 12));
//             }
//             printf("%7.2lf\t",value[i]); 
//         }
//         printf("\n");
//     }
// }



// /*B1FF Filter
//   Program 6*/

// #include <stdio.h>
// #include <ctype.h>
// #define SIZE (sizeof(r) / sizeof(r[0]))

// void main() {
//     char r[25];

//     printf("Enter a message: ");

//     for(int i = 0; i < SIZE; i++) {
//         scanf("%c",&r[i]);

//         r[i] = toupper(r[i]);
//         if(r[i] == 'A')
//             r[i] = '4';
//         else if(r[i] == 'B')
//             r[i] = '8';
//         else if(r[i] == 'E')
//             r[i] = '3';
//         else if(r[i] == 'I')
//             r[i] = '1';
//         else if(r[i] == 'O')
//             r[i] = '0';
//         else if(r[i] == 'S')
//             r[i] = '5';
//     }

//     for(int i = 0; i < SIZE; i++) {
//         printf("%c",r[i]);
//     }

//     for(int i = 0; i < 10; i++) {
//         printf("!");
//     }
// }



// /*5x5 Array sum of rows and columns
//   Program 7*/

// #include <stdio.h>

// #define ROW 5
// #define COLUMN 5

// void main() {
//     int r[ROW][COLUMN], sum[5][2] = {0};

//     for (int j = 0; j < ROW; j++) {
//         printf("Enter row %d: ",j+1);
//         for(int i = 0; i < 5; i++)
//             scanf("%d",&r[j][i]);
//     }

//     printf("\nRow totals: ");
//     for(int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++)
//             sum[i][0] += r[i][j];
//     printf("%d ",sum[i][0]);
//     }

//     printf("\nColumn totals: ");
//     for(int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++)
//             sum[i][1] += r[j][i];
//     printf("%d ",sum[i][1]);
//     }
// }



// /*Modifying the previous project for grades
//   Program 8*/

// #include <stdio.h>

// #define STUDENTS 5
// #define QUIZES 5

// void main() {
//     int r[STUDENTS][QUIZES];
//     int stu_total, quiz_total, low, high;

//     for (int j = 0; j < STUDENTS; j++) {
        
//         printf("Enter quiz grades for Student %d: ",j+1);
        
//         for(int i = 0; i < QUIZES; i++)
//             scanf("%d",&r[j][i]);
//     }

//     printf("\n\nStudent\t Total\t Average\n");
//     for(int i = 0; i < STUDENTS; i++) {

//         stu_total = 0;
        
//         for (int j = 0; j < QUIZES; j++) 
//             stu_total += r[i][j];

//         printf("%4d",i+1);
//         printf("    %5d    %5.1lf\n", stu_total, (double)stu_total/5);
//     }
    
//     printf("\nQuiz    Average    High    Low\n");
//     for(int i = 0; i < QUIZES; i++) {

//         high = 0;
//         low = 999999999;
        
//         for (int j = 0; j < STUDENTS; j++) {
//             quiz_total += r[j][i];
//             if (r[j][i] > high)
//                 high = r[j][i];
//             if (r[j][i] < low)
//                 low = r[j][i];
//         }
        
//         printf("%4d",i+1);
//         printf("    %5.1lf    %5d  %5d\n", (double)quiz_total/5, high, low);
//     }
// }



// /*Random Walk
//   Program 9*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define ROWS 10
// #define COLUMNS 10

// void main() {
//     char array[ROWS][COLUMNS];
//     int direction, i=0, j=0;
//     srand(time(NULL));

//     for (int i = 0; i < ROWS; i++)
//         for (int j = 0; j < COLUMNS; j++)
//             array[i][j] = '.';
//     array[0][0] = 'A';

//     for (int n = 0; array[i][j] != 'Z'; n++) {
//         AGAIN:
        
//         direction = rand()%4;

//         if (direction == 0 && array[i-1][j] == '.' && i-1 > 0) /*Going Up*/
//             array[--i][j] = 'B'+n;
//         else if (direction == 1 && array[i][j+1] == '.' && j+1 < COLUMNS) /*Going Right*/
//             array[i][++j] = 'B'+n;
//         else if (direction == 2 && array[i+1][j] == '.' && i+1 < ROWS) /*Going Down*/
//             array[++i][j] = 'B'+n;
//         else if (direction == 3 && array[i][j-1] == '.' && j-1 > 0) /*Going Left*/
//             array[i][--j] = 'B'+n;
//         else if (array[i-1][j] != '.' && array[i][j+1] != '.' && array[i+1][j] != '.' && array[i][j-1] != '.')
//             break;
//         else 
//             goto AGAIN;
//     }

//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLUMNS; j++) {
//             printf("%c  ",array[i][j]);
//         }
//         printf("\n");
//     }
// }



// /*Sotring Departure and Arrival times in an array from Project 8 of Chapter 5
//   Program 10*/

// #include <stdio.h>
// #include <math.h>

// void main()
// {
//     int hour, minute, mins_since_mdnght;
//     int dep[8] = {
//         8 * 60,
//         9 * 60 + 43,
//         11 * 60 + 19,
//         12 * 60 + 47,
//         (12+2) * 60,
//         (12+3) * 60 + 45,
//         (12+7) * 60,
//         (12+9) * 60 + 45 
//     };
//     int arrival[8] = {
//         10 * 60 + 16,
//         11 * 60 + 52,
//         (12+1) * 60 + 31,
//         (12+3) * 60,
//         (12+4) * 8,
//         (12+5) * 55,
//         (12+9) * 20,
//         (12+11) * 58
//     };

//     printf("Enter Current time[24-hour]: ");
//     scanf("%d:%d", &hour, &minute);

//     mins_since_mdnght = minute + (hour * 60);
        
//     printf("Closest departure time is ");

//     for (int i = 0; i > -1 ;i++) {
//         if (mins_since_mdnght <= (dep[i] + dep[i+1])/2 ) {
//             printf("%0.2d:%0.2d, arriving at %0.2d:%0.2d.", dep[i]/60, dep[i]%60, arrival[i]/60, arrival[i]%60);
//             i = -2;
//         }
//     }
// }



// /*Modifying Project 4 from Chapter 7 so the program labels its outputs
//   Program 11*/

// #include <stdio.h>
// #include <ctype.h>

// #define MAX 15

// void main() {
//     char ph_no[MAX];

//     printf("Enter phone number: ");
//     for (int i = 0; i < MAX; i++) {
//         scanf("%c",&ph_no[i]);
//     }

//     for(int i = 6; ph_no[i] != '\n'; i++) {
//         switch (toupper(ph_no[i]))
//         {
//             case 'A': case 'B': case 'C':
//             ph_no[i] = '2'; break;
//             case 'D': case 'E': case 'F':
//             ph_no[i] = '3'; break;
//             case 'G': case 'H': case 'I':
//             ph_no[i] = '4'; break;
//             case 'J': case 'K': case 'L':
//             ph_no[i] = '5'; break;
//             case 'M': case 'N': case 'O':
//             ph_no[i] = '6'; break;
//             case 'P': case 'R': case 'S':
//             ph_no[i] = '7'; break;
//             case 'T': case 'U': case 'V':
//             ph_no[i] = '8'; break;
//             case 'W': case 'X': case 'Y':
//             ph_no[i] = '9'; break;
//         }
//     }

//     printf("In numeric form: ");
//     for (int i = 0; i < MAX; i++) {
//         printf("%c",ph_no[i]);
//     }
// }



// /*Modifying Project 5 from Chapter 7 so values of letters are stored in an array [Scrabble]
//   Program 12*/

// #include <stdio.h>
// #include <ctype.h>

// void main() {
//     int Scrabble[26] = {
//         1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 /*Storing Scrabble value of Alphabets*/
//     };
//     char ch;
//     int svalue = 0;

//     printf("Enter a word: ");
//     scanf("%c",ch);

//     while (ch != '\n') {
//         ch = toupper(getchar());

//         for (char i = 'A'; i <= 'Z'; i++) {
//             if (i == ch)
//                 svalue += Scrabble[i-'A'];
//         }
//     }
//     printf("Scrabble value: %d",svalue);
// }



// /*Modifying Project 11 from chapter 7
//   Program 13*/

// #include <stdio.h>

// void main() {
//     char ch[20] = {0};
//     char initial;

//     printf("Enter a first and last name: ");
//     initial = getchar();

//     while(ch[0] = getchar() != ' ');

//     for(int i = 0; ch[i-1] != '\n'; i++) {
//         ch[i] = getchar();
//     }

//     printf("You entered the name: ");
//     for (int i = 0; ch[i] != '\n'; i++) {
//         putchar(ch[i]);
//     }

//     printf(", %c", initial);
// }



// /*Reversing the words in a sentence
//   Program 14*/

// #include <stdio.h>

// void main() {
//     char sent[100] = {0}, term;
//     int i, j, k;

//     printf("Enter a Sentence: ");
//     for (i = 0; i < 100; i++) {
//         scanf("%c",&sent[i]);
//         if (sent[i] == '.' || sent[i] == '!' || sent[i] == '\n' || sent[i] == '?') {
//             term = sent[i];
//             sent[i] = ' ';
//             break;
//         }
//     }

//     printf("Reversal of Sentence: ");
//     while (i >= 0) {
//         for (j = i; sent[j] != ' '; j--);
//         for (k = j+1; k < 100; k++) {
//             printf("%c",sent[k]);
//             if (sent[k] == ' ')
//                 break;
//         }
//         i = j-1;
//     }
//     printf("\b%c",term);
// }



// /*Caesar Cipher
//   Program 15*/

// #include <stdio.h>

// void main () {
//     char ch[80];
//     int shift;

//     printf("Enter message to be encrypted: ");
//     for (int i = 0; ch[i-1] != '\n'; i++) {
//         scanf("%c",&ch[i]);
//     }

//     printf("Enter shift amount (1-25): ");
//     scanf("%d",&shift);

//     for (int i = 0; ch[i] != '\n'; i++) {
//         if ((ch[i] >= 'A' && ch[i] <= 'Z'))
//         ch[i] = ((ch[i] - 'A') + shift) % 26 + 'A';
        
//         if ((ch[i] >= 'a' && ch[i] <= 'z'))
//         ch[i] = ((ch[i] - 'a') + shift) % 26 + 'a';
        
//         printf("%c",ch[i]);
//     }
// }



// /*Write a program that tests whether two words are anagrams
//   Program 16*/

// #include <stdio.h>
// #include <ctype.h>

// void main() {
//     int seen1[26] = {0}, seen2[26] = {0};
//     char ch;

//     printf("Enter First Word: ");
//     for (int i = 0; ; i++) {
//         ch = getchar();
//         for (int j = 0; j < 26; j++)
//             if ((toupper(ch) - 'A') == j) {
//                 seen1[j]++;
//             }
//         if (ch == '\n')
//         break;
//     }

//     printf("Enter Second Word: ");
//     for (int i = 0; ; i++) {
//         ch = getchar();
//         for (int j = 0; j < 26; j++)
//             if ((tolower(ch) - 'a') == j) {
//                 seen1[j]--;
//             }
//         if (ch == '\n')
//         break;
//     }

//     int j = 0;
//     for (int i = 0; i < 26; i++) {
//         if (seen1[i] == 0)
//            ++j;
//     }
//     if (j == 26)
//         printf("The words are anagrams.");
//     else 
//         printf("The words are not anagrams.");
// }



// /*Printing an nxn magic square
//   Program 17*/

// #include <stdio.h>

// void main() {
//     int n;

//     printf("This program creates a magic square of a specified size.");
//     printf("\nThe size must be an odd number between 1 and 99.");
//     printf("\nEnter size of magic square: ");
//     scanf("%d",&n);

//     int magic[n][n];
//     for (int i = 0; i < n; i++) 
//         for (int j = 0; j < n; j++) 
//             magic[i][j] = 0;

//     int i = 0, j = n/2;
//     for (int k = 1; k <= n*n;) {
//         if (i < 0 && j >= n) {
//             i += 2;
//             j = n-1;
//         }
//         else {
//             if (j >= n)
//                 j = 0;
//             if (i < 0)
//                 i = n - 1;
            
//             if (magic[i][j]) {
//                 j -= 1;
//                 i += 2;
//                 continue;
//             }
//             else
//                 magic[i][j] = k++; 

//         i--; 
//         j++;
//         }
        
//     }

//     printf("\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%2d   ",magic[i][j]);
//         }
//         printf("\n");
//     }
// }