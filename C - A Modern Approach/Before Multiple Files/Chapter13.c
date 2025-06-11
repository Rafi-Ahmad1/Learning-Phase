// /*WAP to find First and Last in a series of words according to dictionary order
//     Program 1*/

// #include <stdio.h>
// #include <string.h>

// #define WORD_LEN 20

// int main() {    
//     char word[WORD_LEN + 1];
//     char smallest[WORD_LEN + 1] = "zzz", largest[WORD_LEN + 1] = "aaa";

//     while(strlen(word) != 4) {
//         printf("Enter word: ");
//         scanf("%s", word);

//         if(strlen(word) > 20) break;
//         if(strcmp(word, smallest) < 0)
//             strcpy(smallest, word);
//         else if(strcmp(word, largest) > 0)
//             strcpy(largest, word);
//     }
//     printf("\nSmallest Word: %s", smallest);
//     printf("\nLargest Word: %s", largest);
// }



// /*Improving remind.c of Section 13.5
//     Program 2*/

// #include <stdio.h>
// #include <string.h>

// #define MAX_REMIND 50
// #define MSG_LEN 60
// #define TIME_LEN 6
// #define DAY_LEN 6

// int read_line(char str[], int n);

// int main(void) {
//     char reminders[MAX_REMIND][MSG_LEN + 3];
//     char day_str[DAY_LEN], msg_str[MSG_LEN + 1], time_str[TIME_LEN + 1];
//     int day, month, i, j, num_remind = 0;

//     for(;;) {
//         if(num_remind == MAX_REMIND) {
//             printf("-- No Space left --n");
//             break;
//         }

//         printf("Enter day, time and reminder: ");
//         scanf("%2d/%2d", &month, &day);
//         if(day == 0 || month == 0)
//             break;

//         sprintf(day_str, "%2d", month);
//         strcat(day_str, "/");
//         sprintf(day_str + strlen(day_str), "%2d", day);
//         fgets(time_str, TIME_LEN + 1, stdin);
//         read_line(msg_str, MSG_LEN);
        
//         if(month > 12 || month < 0 || day > 31 || day < 0) {
//             printf("Error, Entered date is invalid\n");
//             continue;
//         }

//         for(i = 0; i < num_remind; i++) {
//             if(strcmp(day_str, reminders[i]) < 0)
//                 break;
//             else if(strcmp(day_str, reminders[i]) == 0 && strcmp(time_str, reminders[i + DAY_LEN]) < 0)
//                 break;
//         }
//         for(j = num_remind; j > i; j--)
//             strcpy(reminders[j], reminders[j-1]);
        
//         strcpy(reminders[i], day_str);
//         strcat(reminders[i], time_str);
//         strcat(reminders[i], msg_str);

//         num_remind++;
//     }

//     printf("\n  Day  Time Reminder\n");
//     for(i = 0; i < num_remind; i++) 
//         printf(" %s\n", reminders[i]);
    
//         return 0;
// }

// int read_line(char str[], int n) {
//     int ch, i = 0;
    
//     while((ch = getchar()) != '\n')
//         if(i < n)
//             str[i++] = ch;

//     str[i] = '\0';
//     return i;
// }



// /*Modifying deal.c from Section 8.2
//     Program 3*/

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <time.h>

// #define NUM_SUITS 4
// #define NUM_RANKS 13

// int main(void) {

//     bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
//     int num_cards, rank, suit;

//     const char *rank_code[] = {"Two of","Three of","Four of","Five of","Six of","Seven of","Eight of","Nine  of","Ten of","Jack of","Queen of","King of","Ace of"};
//     const char *suit_code[] = {" Clubs"," Spades"," Hearts"," Diamonds"};

//     srand((unsigned)time(NULL));
//     printf("Enter number of cards in hand: ");
//     scanf ("%d", &num_cards);
//     printf("Your hand: ");
//     while(num_cards > 0) {
//         suit = rand() % NUM_SUITS; 
//         rank = rand() % NUM_RANKS; 

//         if (!in_hand[suit][rank]) {
//         in_hand[suit][rank] = true;
//         num_cards--;
//         printf("\n%s%s", rank_code[rank], suit_code[suit]);
//         }
//     }
//     printf("\n");
//     return 0;
// }



// /*reverse.c
//     Program 4*/

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char *argv[]) {
//     for(int i = argc - 1; i > 0; i--)
//         printf("%s ", argv[i]);
//     printf("\n");
//     return 0;
// }



// /*sum.c
//     Program 5*/

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[]) {
//     int sum = 0;
//     for(int i = 1; i < argc; i++)
//         sum += atoi(argv[i]);
//     printf("%d\n",sum);
//     return 0;
// }



// /*Improving planets.c by ignoring case
//     Program 6*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define NUM_PLANETS 9

// int compare_strings(char *str1, char *str2);

// int main(int argc, char *argv[]) {
//     char *planets[] = {"Mercury","Venus","Earth",
//                         "Mars","Jupiter","Saturn",
//                         "Uranus","Neptune","Pluto"};

//     int i, j;
    
//     for(i = 1; i < argc; i++) {
//         for(j = 0; j < NUM_PLANETS; j++)
//             if(compare_strings(argv[i], planets[j])){
//             printf("%s is planet %d\n", argv[i], j + 1);
//             break;
//         }
//         if(j == NUM_PLANETS)
//             printf("%s is not a planet\n", argv[i]);
//     }

//     return 0;
// }

// int compare_strings(char *str1, char *str2) {
//     for(int i = 0; i < strlen(str1); i++)
//             if(toupper(str1[i]) != toupper(str2[i]))
//                 return 0;
//     return 1;
// }



// /*Improving Project 11 from Chapter 5
//   Program 7*/

// #include <stdio.h>

// void main()
// {
//     char *ones_place[] = {"One", "Two", "Three",
//                           "Four","Five", "Six", 
//                           "Seven", "Eight", "Nine"};

//     char *tens_place[] = {"Twenty", "Thirty",
//                           "Forty","Fifty", "Sixty", 
//                           "Seventy", "Eighty", "Ninety"};

//     char *special_case[] = {"Ten", "Eleven", "Twelve", "Thirteen",
//                             "Fourteen", "Fifteen", "Sixteen", 
//                             "Seventeen", "Eighteen", "Nineteen"};
//     int num;

//     printf("Enter a two-digit positive number: ");
//     scanf("%d", &num);

//     if (num >= 100 || num <= 0)
//         printf("I told you to enter a TWO DIGIT POSITIVE NUMBER.");
//     else if(num >= 10 && num < 20) {
//             printf("You Entered the number ");
//             puts(special_case[num - 10]);
//     }
//     else {
//         printf("You Entered the number ");

//         if(num/10)
//             printf("%s ", tens_place[num/10 - 2]);
//         if(num%10)
//             printf("%s ", ones_place[num%10 - 1]);
//     }
// }



// /*Improving Project 5 from Chapter 7 to include a function
//     Program 8*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define STRING_SIZE 100

// int compute_scrabble_value(const char *word);

// void main() {
//     char word[STRING_SIZE + 1];

//     printf("Enter a word: ");
//     scanf("%s", word);
//     printf("%d", compute_scrabble_value(word));
// }

// int compute_scrabble_value(const char *word) {
//     int svalue = 0;
//     char ch;

//     for(int i = 0; i < strlen(word); i++) {
//         switch (ch = toupper(word[i]))
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
//     }
//     return svalue;
// }



// /*Improving Project 10 from Chapter 7 to include a function
//     Program 9*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define SENT_SIZE 100

// int compute_vowel_count(const char *sentence);

// void main() {
//     char sentence[SENT_SIZE + 1];

//     printf("Enter a sentence: ");
//     fgets(sentence, SENT_SIZE, stdin);

//     printf("Your Sentence contains %d vowels", compute_vowel_count(sentence));
// }

// int compute_vowel_count(const char *sentence) {
//     char ch;
//     int vowel=0;

//     for(int i = 0; i != strlen(sentence); i++) {
//         ch = sentence[i];
//         switch (toupper(ch)) {
//             case 'A': case 'E': case 'I': case 'O': case 'U':
//                 vowel++; break;
//         }
//     }
//     return vowel;
// }



// /*Improving Project 11 from Chapter 7 to include a function
//     Program 10*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define NAME_SIZE 100

// void reverse_name(char *name);
// int read_line(char str[], int n);

// void main() {
//     char name[NAME_SIZE + 1];

//     printf("Enter a first and last name: ");
//     read_line(name, NAME_SIZE);
    
//     reverse_name(name);
// }

// void reverse_name(char *name) {
//     char initial[2];
//     strncpy(initial, name, 1);
//     int i = 0;

//     while(name[i++] != ' ');
    
//     strcpy(name, name + i);
//     strcat(name, ", ");
//     strcat(name, initial);

//     puts(name);
// }

// int read_line(char str[], int n) {
//     int ch, i = 0;
    
//     while((ch = getchar()) == ' '); //Ignore Space Before

//     while(ch != ' ') {
//         if(i < n)
//             str[i++] = ch;
//         ch = getchar();
//     }
//     str[i++] = ' ';
//     while((ch = getchar()) == ' '); //Ignore Space Between

//     while(!isspace(ch)) {
//         if(i < n)
//             str[i++] = ch;
//         ch = getchar();
//     }

//     str[i] = '\0';
//     return i;
// }



// /*Improving Project 13 from Chapter 7 to include a function
//     Program 11*/

// #include <stdio.h>
// #include <string.h>

// #define SENT_SIZE 100

// double compute_average_word_length(const char *sentence);
// int read_line(char str[], int n);

// void main() {
//     char sentence[SENT_SIZE + 1];

//     printf("Enter a sentence: ");
//     read_line(sentence, SENT_SIZE);

//     printf("Average word length: %.1lf", compute_average_word_length(sentence));
// }

// double compute_average_word_length(const char *sentence) {
//     int words = 0, count = strlen(sentence);
//     int i = 0;

//     while(sentence[i] != '\0') {
//         while(sentence[i++] != ' '); //ignore non spaces
//         words++;
//         while(sentence[i++] == ' '); //ignore spaces
//     }

//     return (double)count/(words+1);
// }

// int read_line(char str[], int n) {
//     int ch, i = 0;
    
//     while((ch = getchar()) != '\n')
//         if(i < n)
//             str[i++] = ch;

//     str[i] = '\0';
//     return i;
// }



// /*Modifying Project 14 from Chaper 8 to store words in a 2D array
//   Program 12*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// #define MAX_WORDS 30
// #define WORDS_SIZE 20

// void main() {
//     char sentence[MAX_WORDS][WORDS_SIZE + 1] = {0}, ch, term;
//     int i, j;

//     printf("Enter a Sentence: ");
//     for(i = 0; i < MAX_WORDS; i++) {
//         for(j = 0; j < WORDS_SIZE; j++) {
//             ch = getchar();
//             sentence[i][j] = ch;
//             if(isspace(ch))
//                 break;
//         }
//         sentence[i][j] = '\0';
//         if(ch == '\n')
//             break;
//     }
//     term = sentence[i][j-1];
//     sentence[i][j-1] = '\0';

//     printf("Reversal of Sentence:");
//     for (j = i; j >= 0; j--) {
//         printf(" %s",sentence[j]);
//     }
//     putchar(term);
// }



// /*Modifying Project 15 from Chaper 8 to include a function
//   Program 13*/

// #include <stdio.h>
// #include <string.h>

// #define MSG_LEN 100

// void encrypt(char *message, int shift);

// void main () {
//     char message[MSG_LEN + 1];
//     int shift;

//     printf("Enter message to be encrypted: ");
//     fgets(message, MSG_LEN, stdin);

//     printf("Enter shift amount (1-25): ");
//     scanf("%d",&shift);

//     printf("Encrypted Message: ");
//     encrypt(message, shift);
//     puts(message);
// }

// void encrypt(char *message, int shift) {
//     for (int i = 0; message[i] != '\0'; i++) {
//         if ((message[i] >= 'A' && message[i] <= 'Z'))
//         message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        
//         if ((message[i] >= 'a' && message[i] <= 'z'))
//         message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
//     }
// }



// /*Modifying Project 16 from Chaper 8 to include a function
//   Program 14*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>

// #define WORD_SIZE 50
// #define ALPHABETS 26

// bool are_anagrams(const char *word1, const char *word2);

// void main() {
//     char word1[WORD_SIZE + 1], word2[WORD_SIZE + 1];

//     printf("Enter First Word: ");
//     scanf("%s", word1);
//     printf("Enter Second Word: ");
//     scanf("%s", word2);

//     if(are_anagrams(word1, word2))
//         printf("The words are anagrams.");
//     else
//         printf("The words are not anagrams.");
// }

// bool are_anagrams(const char *word1, const char *word2) {
//     int seen[ALPHABETS] = {0};
//     char ch;

//     for (int i = 0; i < WORD_SIZE; i++) {
//         ch = word1[i];
//         for (int j = 0; j < ALPHABETS; j++)
//             if ((toupper(ch) - 'A') == j) {
//                 seen[j]++;
//             }
//         if (ch == '\0')
//         break;
//     }

//     for (int i = 0; i < WORD_SIZE; i++) {
//         ch = word2[i];
//         for (int j = 0; j < ALPHABETS; j++)
//             if ((tolower(ch) - 'a') == j) {
//                 seen[j]--;
//             }
//         if (ch == '\0')
//         break;
//     }

//     for (int i = 0; i < ALPHABETS; i++) {
//         if(seen[i])
//            return false;
//     }
//     return true;
// }



// /*Modifying Project 6 from Chapter 10 to include a function
//     Project 15*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define STACK_SIZE 100

// /*Initialized Stack as a global array*/
// int stack[STACK_SIZE];
// int top = 0;

// void make_empty(void);
// bool is_empty(void);
// bool is_full(void);
// void push(int i);
// int pop(void);
// int evaluate_RPN_expression(const char *expression);
// void stack_overflow(void);
// void stack_underflow(void);

// void main() {
//     char exp[STACK_SIZE + 1];
//     int answer;
    
//     for(;;) {
//         printf("\nEnter an RPN expression: ");
//         fgets(exp, STACK_SIZE, stdin);

//         answer = evaluate_RPN_expression(exp);
//         printf("Value of Expression: %d", answer);
//     }
// }

// int evaluate_RPN_expression(const char *expression) {
//     char ch = 0;
//     int j, k;

//     make_empty();
//     for (int i = 0; i < STACK_SIZE; i++) {
//         ch = expression[i];

//         if (ch >= '0' && ch <= '9')
//             push(ch - '0');
//         else if(ch == '\0')
//             break;
//         else {
//             switch(ch) {
//                 case '+': push(pop() + pop()); break;
//                 case '-': j = pop(), k = pop(); push(k-j); break;   /*Correct Order, Couldn't think of anything else*/
//                 case '*': push(pop() * pop()); break;
//                 case '/': j = pop(), k = pop(); push(k/j); break;   /*Correct Order, Couldn't think of anything else*/
//                 case '=': return stack[--top];
//                 case ' ': break;
//                 default:  printf("Invalid Input\n"); exit(EXIT_FAILURE);
//             }
//         }
//     }

// }

// void make_empty(void) {
//     top = 0;
// }
// bool is_empty(void) {
//     return top == 0;
// }
// bool is_full(void) {
//     return top == STACK_SIZE;
// }

// void push(int i) {
//     if(is_full())
//         stack_overflow();
//     else
//         stack[top++] = i;
// }
// int pop(void) {
//     if(is_empty())
//         stack_underflow();
//     else
//         return stack[--top];
// }

// void stack_overflow(void) {
//     printf("Expression is too complex.");
//     exit(EXIT_FAILURE);
// }
// void stack_underflow(void) {
//     printf("Not enough operands in expression.");
//     exit(EXIT_FAILURE);
// }



// /*Modifying Program 1 from Chapter 12 to include a function
//     Program 16*/

// #include <stdio.h>
// #include <string.h>

// #define MSG_LEN 100

// void reverse(char *message);
// int read_line(char str[], int n);

// int main() {
//     char msg[MSG_LEN];
 
//     printf("Enter a message: ");
//     read_line(msg, MSG_LEN);
    
//     printf("Reversal is: ");
//     reverse(msg);
//     puts(msg);

//     return 0;
// }

// void reverse(char *message) {
//     char *p = message, *q = message + strlen(message) - 1;
    
//     for(;p != q; p++, q--) {
//         *p = *p + *q;
//         *q = *p - *q;
//         *p = *p - *q;
//     }
//     message = p;
// }

// int read_line(char str[], int n) {
//     int ch, i = 0;
    
//     while((ch = getchar()) != '\n')
//         if(i < n)
//             str[i++] = ch;

//     str[i] = '\0';
//     return i;
// }



// /*Modifying Project 2 from Chapter 12 to include a function
//     Program 17*/

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdbool.h>

// #define MSG_LEN 100

// bool is_palindrome(const char *message);
// int read_line(char str[], int n);

// int main() {
//     char msg[MSG_LEN];
    
//     printf("Enter a message: "); 
//     read_line(msg, MSG_LEN);
    
//     if(is_palindrome(msg))
//         printf("Palindrome");
//     else
//         printf("Not a Palindrome");
    
//     return 0;
// }

// bool is_palindrome(const char *message) {
//     const char *p = message, *q = message + strlen(message) - 1;

//     while(p < q) {
//         while(p < q && !isalpha(*p)) p++;
//         while(p < q && !isalpha(*q)) q--;

//         if(p < q && toupper(*p) != toupper(*q))
//         return false;
         
//         p++;
//         q--;
//     }

//     return true;
// }

// int read_line(char str[], int n) {
//     int ch, i = 0;
    
//     while((ch = getchar()) != '\n')
//         if(i < n)
//             str[i++] = ch;

//     str[i] = '\0';
//     return i;
// }



// /*WAP that accepts and writes dates
//     Program 18*/

// #include <stdio.h>
// #include <string.h>

// void main() {
//     char *months[] = {"January", "February", "March", "April",
//                     "May", "June", "July", "August",
//                     "September", "October", "November", "December"};
//     int dd, mm, yyyy;

//     printf("Enter a date (mm/dd/yyyy): ");
//     scanf("%d/%d/%d", &mm, &dd, &yyyy);

//     printf("You entered the date %s %d, %d", months[mm-1], dd, yyyy);
// }