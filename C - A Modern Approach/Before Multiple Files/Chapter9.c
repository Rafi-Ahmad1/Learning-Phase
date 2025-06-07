// /*Selection Sort Reverse implementation using recursion
//     Project 1*/

// #include <stdio.h>

// void selection_sort(int [], int);
// void display(int [], int);

// int main() {
//     int n;

//     printf("Enter size of array: ");
//     scanf("%d",&n);

//     int arr[n];
//     printf("Enter Elements of array: ");
//     for (int i = 0; i < n; i++)
//         scanf("%d",&arr[i]);

//     selection_sort(arr, n);
//     printf("\nSorted: ");
//     display(arr, n);

//     return 0;
// }

// void display(int a[], int n) {
//     for (int i = 0; i < n; i++)
//         printf("%d ",a[i]);
// }

// void selection_sort(int a[], int n) {
//     int max = 0;

//     if (n > 0) {
//         for (int i = 0; i < n; i++) {
//             if (a[i] > a[max])
//                 max = i;
//         }
//         int temp = a[n-1];
//         a[n-1] = a[max];
//         a[max] = temp;
        
//         return selection_sort(a,n-1);
//     }
//     else 
//         return;
// }



// /*Modifying Project 5 from Chap 5 to use function
//     Project 2*/

// #include <stdio.h>

// float tax(int taxable_income);

// void main()
// {
//     float taxable_income;

//     printf("Enter your income($): ");
//     scanf("%f",&taxable_income);

//     printf("The Tax due is: %.2f", tax(taxable_income));
// }

// float tax(int taxable_income) {
//     float tax_due;

//     if(taxable_income < 750)
//         tax_due = 0.01 * taxable_income;
//     else if(taxable_income < 2250)
//         tax_due = 7.50 + 0.02 * (taxable_income - 750);
//     else if(taxable_income < 3750)
//         tax_due = 37.50 + 0.03 * (taxable_income - 2250);
//     else if(taxable_income < 5250)
//         tax_due = 82.50 + 0.04 * (taxable_income - 3750);
//     else if(taxable_income < 7000)
//         tax_due = 142.50 + 0.05 * (taxable_income - 5250);
//     else if(taxable_income > 7000)
//         tax_due = 230.00 + 0.06 * (taxable_income - 7000);

//     return tax_due;
// }



// /*Modifying Project 9 from Chap 8 to include functions
//     Project 3*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define ROWS 10
// #define COLUMNS 10

// void generate_random_walk(char walk[ROWS][COLUMNS]);
// void print_array(char array[ROWS][COLUMNS]);

// void main() {
//     char array[ROWS][COLUMNS];

//     generate_random_walk(array);
//     print_array(array);
// }

// void print_array(char walk[ROWS][COLUMNS]) {
//     for (int i = 0; i < ROWS; i++) {
//         for (int j = 0; j < COLUMNS; j++) {
//             printf("%c  ",walk[i][j]);
//         }
//         printf("\n");
//     }
// }

// void generate_random_walk(char walk[ROWS][COLUMNS]) {
//     int direction, i=0, j=0;
//     srand(time(NULL));
    
//     for (int i = 0; i < ROWS; i++)
//         for (int j = 0; j < COLUMNS; j++)
//             walk[i][j] = '.';
//     walk[0][0] = 'A';

//     for (int n = 0; walk[i][j] != 'Z'; n++) {
//         AGAIN:
        
//         direction = rand()%4;

//         if (direction == 0 && walk[i-1][j] == '.' && i-1 > 0) /*Going Up*/
//             walk[--i][j] = 'B'+n;
//         else if (direction == 1 && walk[i][j+1] == '.' && j+1 < COLUMNS) /*Going Right*/
//             walk[i][++j] = 'B'+n;
//         else if (direction == 2 && walk[i+1][j] == '.' && i+1 < ROWS) /*Going Down*/
//             walk[++i][j] = 'B'+n;
//         else if (direction == 3 && walk[i][j-1] == '.' && j-1 > 0) /*Going Left*/
//             walk[i][--j] = 'B'+n;
//         else if (walk[i-1][j] != '.' && walk[i][j+1] != '.' && walk[i+1][j] != '.' && walk[i][j-1] != '.')
//             break;
//         else 
//             goto AGAIN;
//     }
// }



// /*Modifying Project 16 from Chap 8 to include functions
//     Project 4*/

// #include <stdio.h>
// #include <ctype.h>
// #include <stdbool.h>

// void read_word(int seen1[26]);
// bool equal_array(int counts1[26], int counts2[26]);

// void main() {
//     int seen1[26] = {0}, seen2[26] = {0};

//     printf("Enter First Word: ");
//     read_word(seen1);

//     printf("Enter Second Word: ");
//     read_word(seen2);

//     if (equal_array(seen1, seen2))
//         printf("The words are anagrams.");
//     else 
//         printf("The words are not anagrams.");
// }

// void read_word(int count[26]) {
//     int ch;

//     for (int i = 0; ; i++) {
//         ch = getchar();
//         for (int j = 0; j < 26; j++)
//             if ((toupper(ch) - 'A') == j) {
//                 count[j]++;
//             }
//         if (ch == '\n')
//         break;
//     }
// }

// bool equal_array(int counts1[26], int counts2[26]) {
//     int num_same = 0;

//     for (int i = 0; i < 26; i++) {
//         if (counts1[i] - counts2[i] == 0)
//             num_same++;
//     }

//     if(num_same == 26)
//         return true;
//     else
//         return false;
// }



// /*Modifying Project 17 form Chap 8 to include Functions
//     Project 5*/

// #include <stdio.h>

// void create_magic_square(int n, int magic_square[n][n]);
// void print_magic_square (int n, int magic_square[n][n]);

// int main() {
//     int n;

//     printf("This program creates a magic square of a specified size.");
//     printf("\nThe size must be an odd number between 1 and 99.");
//     printf("\nEnter size of magic square: ");
//     scanf("%d",&n);

//     int magic[n][n];
//     for (int i = 0; i < n; i++) 
//         for (int j = 0; j < n; j++) 
//             magic[i][j] = 0;

//     create_magic_square(n, magic);
//     print_magic_square(n, magic);

//     return 0;
// }

// void create_magic_square(int n, int magic_square[n][n]) {
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
            
//             if (magic_square[i][j]) {
//                 j -= 1;
//                 i += 2;
//                 continue;
//             }
//             else
//                 magic_square[i][j] = k++; 

//         i--; 
//         j++;
//         }
        
//     }
// }

// void print_magic_square(int n, int magic_square[n][n]) {
//     printf("\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%2d   ",magic_square[i][j]);
//         }
//         printf("\n");
//     }
// }



// /*WAP that computes the value of the polynomial
//     Project 6*/

// #include <stdio.h>
// #include <math.h>

// double poly(double);

// int main() {
//     double x;

//     printf("Enter the value of x = ");
//     scanf("%lf",&x);

//     printf("The Value of the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 is %.2lf", poly(x));
// }

// double poly(double x) {
//     return 3 * pow(x,5) + 2* pow(x,4) - 5 * pow(x,3) - pow(x,2) + 7 * x - 6;
// }



// /*Better Power function
//     Project 7*/

// #include <stdio.h>

// long long int power(int, int);

// int main() {
//     int base, exp;
//     printf("Enter Base and Exponent (x^n): ");
//     scanf("%d^%d",&base,&exp);

//     printf("%lld",power(base,exp));
// }


// long long int power(int x, int n) {
//     if (n < 1)
//         return 1;
//     else if (n%2 == 0)
//         return power(x,n/2) * power(x,n/2);
//     else
//         return x * power(x,n-1);
// }



// /*Simulating the game of craps
//     Project 8*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <time.h>

// int roll_dice(void);
// bool play_game(void);

// int main() {
//     srand(time(NULL));
//     int score, wins = 0, losses = 0;
//     char yn = 'y';

//     while (yn == 'y') {
//         if (play_game()) {
//             printf("\nYou win!");
//             wins++;
//         }
//         else {
//             printf("\nYou lose!");
//             losses++;
//         }
//         printf("\n\nPlay again? (y/n): ");
//         scanf(" %c",&yn);
//     }
//     printf("Wins: %d   Losses: %d", wins, losses);
//     return 0;
// }

// int roll_dice(void) {
//     int dice1 = rand() % 6 + 1;
//     int dice2 = rand() % 6 + 1;

//     return dice1 + dice2;
// }

// bool play_game(void) {
//     int sum1 = roll_dice();

//     if (sum1 == 7 || sum1 == 11) {
//         printf("\nYou rolled: %d",sum1);
//         return true;
//     }
//     else if (sum1 == 2 || sum1 == 3 || sum1 == 12) {
//         printf("\nYou rolled: %d",sum1);
//         return false;
//     }
//     else {
//         printf("\nYou rolled: %d",sum1);
//         printf("\nYour point is: %d",sum1);
//         int sum2 = roll_dice();

//         while (sum2 != sum1) {
//             printf("\nYou rolled: %d",sum2);
//             if (sum2 == 7)
//                 return false;
//             sum2 = roll_dice();
//         }
//         if (sum2 == 7)
//             return false;
        
//         printf("\nYou rolled: %d",sum2);
//         return true;
//     }
// }