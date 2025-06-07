// /*Modifying the stack to store characters instead of integers...
//     Project 1*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define STACK_SIZE 100

// char contents[STACK_SIZE];
// int top = 0;

// void make_empty(void);
// bool is_empty(void);
// bool is_full(void);
// void push(char i);
// char pop(void);
// void stack_overflow(void);
// int stack_underflow(void);

// int main() {
//     char ch, temp;
//     bool nested_properly;

//     printf("Enter parentheses and/or braces: ");
//     while ((ch = getchar()) != '\n') {
//         if (ch == '(' || ch == '{')   // Pushes the Braces/Parenthesis
//             push(ch);
//         else if (ch == ')' || ch == '}') {  // Pops the Braces/Parenthesis
//             temp = pop();
//             if (ch == ')' && temp == '(')   // Checks whether the Parenthesis match the popped one or not
//                 nested_properly = true;    
//             else if (ch == '}' && temp == '{') // Checks whether the Braces match the popped one or not
//                 nested_properly = true;
//             else {                          // Checks for any other case i
//                 nested_properly = false;
//                 printf("Parenthesis/braces are not nested properly.");
//                 return 0;
//             }
//         }
//     }
    
//     if (nested_properly) // Checks whether the Braces/Parenthesis are nested properly.
//         printf("Parenthesis/braces are nested properly.");
//     if (is_empty() == false)       // Checks whether the array is empty or not if not then not nested properly.
//         printf("Parenthesis/braces are not nested properly.");
    
//     return 0;
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

// void push(char i) {
//     if(is_full()) 
//         stack_overflow();
//     else 
//         contents[top++] = i;
// }

// char pop(void) {
//     if(is_empty())
//         stack_underflow();
//     else
//         return contents[--top];
// }

// void stack_overflow(void) {
//     printf("\nStack Overflow");
//     exit(EXIT_FAILURE);
// }

// int stack_underflow(void) {
//     printf("Parenthesis/braces are not nested properly.");
//     exit(EXIT_FAILURE);
// }



// /*Modifying the poker.c program by moving num_in_rank and num_in_suit arrays into main passing them as arguments
//     Project 2*/

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// #define NUM_RANKS 13
// #define NUM_SUITS 4
// #define NUM_CARDS 5

// bool straight, flush, four, three;
// int pairs;

// void read_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]);
// void analyze_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]);
// void print_result(void);

// /***********************************************************************
//  * main: Calls read_cards, analyze_hand, and print_result repeatedly   *
//  *                                                                     *
//  ***********************************************************************/

// int main() {
//     int num_in_rank[NUM_RANKS];
//     int num_in_suit[NUM_SUITS];

//     for(;;) {
//         read_cards(num_in_rank, num_in_suit);
//         analyze_cards(num_in_rank, num_in_suit);
//         print_result();
//     }
// }

// /********************************************************************************
//  * read_cards: Reads cards into external variables num_in_rank, num_in_suit;    *
//  *             checks for bad cards and duplicate cards.                        *
//  ********************************************************************************/

// void read_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]) {
//     bool card_exists[NUM_RANKS][NUM_SUITS];
//     char ch, rank_ch, suit_ch;
//     int rank, suit;
//     bool bad_card;
//     int cards_read = 0;

//     for (rank = 0; rank < NUM_RANKS; rank++) {
//         num_in_rank[rank] = 0;
//         for (suit = 0; suit < NUM_RANKS; suit++)
//             card_exists[rank][suit] = false;
//     }

//     for (suit = 0; suit < NUM_SUITS; suit++) {
//         num_in_suit[suit] = 0;
//     }

//     while (cards_read < NUM_CARDS) {
//         bad_card = false;

//         printf("Enter a card: ");

//         rank_ch = getchar();
//         switch (rank_ch) {
//             case '0':           exit(EXIT_SUCCESS);
//             case '2':           rank = 0; break;
//             case '3':           rank = 1; break;
//             case '4':           rank = 2; break;
//             case '5':           rank = 3; break;
//             case '6':           rank = 4; break;
//             case '7':           rank = 5; break;
//             case '8':           rank = 6; break;
//             case '9':           rank = 7; break;
//             case 't': case 'T': rank = 8; break;
//             case 'j': case 'J': rank = 9; break;
//             case 'q': case 'Q': rank = 10; break;
//             case 'k': case 'K': rank = 11; break;
//             case 'a': case 'A': rank = 12; break;
//             default:            bad_card = true;
//         }

//         suit_ch = getchar();
//         switch (suit_ch) {
//             case 'c': case 'C': suit = 0; break;
//             case 'd': case 'D': suit = 1; break;
//             case 'h': case 'H': suit = 2; break;
//             case 's': case 'S': suit = 3; break;
//             default:            bad_card = true;
//         }

//         while ((ch = getchar()) != '\n')
//             if(ch != ' ')
//                 bad_card = true;

//         if(bad_card)
//             printf("Bad card; ignored.\n");
//         else if(card_exists[rank][suit])
//             printf("Duplicate card; ignored.\n");
//         else {
//             num_in_rank[rank]++;
//             num_in_suit[suit]++;
//             card_exists[rank][suit] = true;
//             cards_read++;
//         }
//     }
// }

// /************************************************************************************************
//  * analyze_hand: Determines whether the hand contains a straight, a flush, four-of-a-kind,      *
//  *               and/or three-of-a-kind; determines the number of pairs; stores the result      *
//  *               into the external variables straight, flush, four, three, and pairs.           *
//  ************************************************************************************************/

// void analyze_cards(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]) {
//     int num_consec = 0;
//     int rank, suit;

//     straight = false;
//     flush = false;
//     four = false;
//     three = false;
//     pairs = 0;

//     /*Check for flush*/
//     for (suit = 0; suit < NUM_SUITS; suit++) 
//         if (num_in_suit[suit] == NUM_CARDS)
//             flush = true;
    
//     /*Check for straight*/
//     rank = 0;
//     while (num_in_rank[rank] == 0)
//         rank++;
//     for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
//         num_consec++;
//     if (num_consec == NUM_CARDS) {
//         straight = true;
//         return;
//     }

//     /*Check for 4-of-a-kind, 3-of-a-kind, and pairs*/
//     for (rank = 0; rank < NUM_RANKS; rank++) {
//         if(num_in_rank[rank] == 4) 
//             four = true;
//         if(num_in_rank[rank] == 3) 
//             three = true;
//         if(num_in_rank[rank] == 2) 
//             pairs++;
//     }
// }

// /*********************************************************************************
//  * print_result: Prints the classification of the hand, based on the values of   *
//  *               the external variables straight, flush, four, three, and pairs. *
//  *********************************************************************************/

// void print_result(void) {
//     if (straight && flush)
//         printf("Straight flush");
//     else if (four)
//         printf("Four of a kind");
//     else if (three && pairs == 1)
//         printf("Full house");
//     else if (straight)
//         printf("Straight");
//     else if (three)
//         printf("Three of a kind");
//     else if (pairs == 2)
//         printf("Two pairs");
//     else if (pairs == 1)
//         printf("Pair");
//     else 
//         printf("High card");
    
//     printf("\n\n");
// }



// /*Modifying the poker.c program by removing num_in_rank and num_in_suit arrays and making a 5x2 array named hand
//     passing them as arguments.
//     Project 3*/

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// #define NUM_RANKS 13
// #define NUM_SUITS 4
// #define NUM_CARDS 5
// #define RANK_SUITS 2
// #define RANK 0
// #define SUIT 1

// bool straight, flush, four, three;
// int pairs;

// void read_cards(int hand[NUM_CARDS][RANK_SUITS]);
// void analyze_cards(int hand[NUM_CARDS][RANK_SUITS]);
// void print_result(void);
// void bubble_sort(int hand[NUM_CARDS][RANK_SUITS]);


// /***********************************************************************
//  * main: Calls read_cards, analyze_hand, and print_result repeatedly   *
//  *                                                                     *
//  ***********************************************************************/

// int main() {
//     int hand[NUM_CARDS][RANK_SUITS];

//     for(;;) {
//         read_cards(hand);
//         analyze_cards(hand);
//         print_result();
//     }
// }

// /********************************************************************************
//  * read_cards: Reads cards into external variables num_in_rank, num_in_suit;    *
//  *             checks for bad cards and duplicate cards.                        *
//  ********************************************************************************/

// void read_cards(int hand[NUM_CARDS][RANK_SUITS]) {
//     char ch, rank_ch, suit_ch;
//     int rank, suit;
//     bool bad_card, duplicate_card;

//     for (int i = 0; i < NUM_CARDS; i++) {
//         for (int j = 0; j < RANK_SUITS; j++)
//             hand[i][j] = 0;
//     }

//     for (int cards_read = 0; cards_read < NUM_CARDS;) {
//         bad_card = false;

//         printf("Enter a card: ");

//         rank_ch = getchar();
//         switch (rank_ch) {
//             case '0':           exit(EXIT_SUCCESS);
//             case '2':           rank = 1; break;
//             case '3':           rank = 2; break;
//             case '4':           rank = 3; break;
//             case '5':           rank = 4; break;
//             case '6':           rank = 5; break;
//             case '7':           rank = 6; break;
//             case '8':           rank = 7; break;
//             case '9':           rank = 8; break;
//             case 't': case 'T': rank = 9; break;
//             case 'j': case 'J': rank = 10; break;
//             case 'q': case 'Q': rank = 11; break;
//             case 'k': case 'K': rank = 12; break;
//             case 'a': case 'A': rank = 13; break;
//             default:            bad_card = true;
//         }

//         suit_ch = getchar();
//         switch (suit_ch) {
//             case 'c': case 'C': suit = 1; break;
//             case 'd': case 'D': suit = 2; break;
//             case 'h': case 'H': suit = 3; break;
//             case 's': case 'S': suit = 4; break;
//             default:            bad_card = true;
//         }

//         while ((ch = getchar()) != '\n')
//             if(ch != ' ')
//                 bad_card = true;

//         if(bad_card)
//             printf("Bad card; ignored.\n");
//         else if(hand[cards_read-1][RANK] == rank && hand[cards_read-1][SUIT] == suit)
//             printf("Duplicate card; ignored.\n");
//         else {
//             hand[cards_read][RANK] = rank;
//             hand[cards_read][SUIT] = suit;
//             cards_read++;
//         }
//     }
// }

// /************************************************************************************************
//  * analyze_hand: Determines whether the hand contains a straight, a flush, four-of-a-kind,      *
//  *               and/or three-of-a-kind; determines the number of pairs; stores the result      *
//  *               into the external variables straight, flush, four, three, and pairs.           *
//  ************************************************************************************************/

// void analyze_cards(int hand[NUM_CARDS][RANK_SUITS]) {
//     int num_consec = 1;
//     int rank, suit;

//     straight = false;
//     flush = false;
//     four = false;
//     three = false;
//     pairs = 0;

//     /*Sorting cards by rank*/
//     bubble_sort(hand);

//     /*Check for flush*/
//     for (suit = 1; suit < NUM_SUITS; suit++) 
//         if (hand[suit][SUIT] == hand[suit - 1][SUIT])
//             flush = true;
//         else {
//             flush = false;
//             break;
//         }
    
//     /*Check for straight*/
//     for (rank = 1; hand[rank][RANK] == (hand[rank - 1][RANK] + 1); rank++)
//         num_consec++;
//     if (num_consec == NUM_CARDS) {
//         straight = true;
//         return;
//     }

//     /*Check for 4-of-a-kind, 3-of-a-kind, and pairs*/
//     int temp = 1;   /*To check for 4's and 3's of a kind*/
//     for (rank = 1; rank < NUM_CARDS; rank++) {
//         if(hand[rank][RANK] != hand[rank - 1][RANK]) 
//             break;    
//         temp++;
//     }
//     for (rank = 1; rank < NUM_CARDS; rank++)
//         if(hand[rank][RANK] == hand[rank - 1][RANK])     
//             pairs++;

//     if (temp == 4)
//         four = true;
//     if (temp == 3)
//         three = true;
// }

// /*********************************************************************************
//  * print_result: Prints the classification of the hand, based on the values of   *
//  *               the external variables straight, flush, four, three, and pairs. *
//  *********************************************************************************/

// void print_result(void) {
//     if (straight && flush)
//         printf("Straight flush");
//     else if (four)
//         printf("Four of a kind");
//     else if (three && pairs == 1)
//         printf("Full house");
//     else if (flush)
//         printf("Flush");
//     else if (straight)
//         printf("Straight");
//     else if (three)
//         printf("Three of a kind");
//     else if (pairs == 2)
//         printf("Two pairs");
//     else if (pairs == 1)
//         printf("Pair");
//     else 
//         printf("High card");
    
//     printf("\n\n");
// }

// void bubble_sort(int hand[NUM_CARDS][RANK_SUITS]) {
//     for (int j = 0; j < NUM_CARDS - 1; j++) 
//     for (int i = 0; i < NUM_CARDS -1 -j; i++) 
//         if (hand[i][RANK] > hand[i+1][RANK]) {
//             int temp1 = hand[i][RANK];
//             hand[i][RANK] = hand[i+1][RANK];
//             hand[i+1][RANK] = temp1;

//             int temp2 = hand[i][SUIT];
//             hand[i][SUIT] = hand[i+1][SUIT];
//             hand[i+1][SUIT] = temp2;
//         } 
// }



// /*Modifying poker.c to add royal flush and ace-low straights
//     Project 4 and 5*/

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// #define NUM_RANKS 13
// #define NUM_SUITS 4
// #define NUM_CARDS 5
// #define RANK_SUITS 2
// #define RANK 0
// #define SUIT 1

// bool low_ace, royal, straight, flush, four, three;
// int pairs;

// void read_cards(int hand[NUM_CARDS][RANK_SUITS]);
// void analyze_cards(int hand[NUM_CARDS][RANK_SUITS]);
// void print_result(void);
// void bubble_sort(int hand[NUM_CARDS][RANK_SUITS]);


// /***********************************************************************
//  * main: Calls read_cards, analyze_hand, and print_result repeatedly   *
//  *                                                                     *
//  ***********************************************************************/

// int main() {
//     int hand[NUM_CARDS][RANK_SUITS];

//     for(;;) {
//         read_cards(hand);
//         analyze_cards(hand);
//         print_result();
//     }
// }

// /********************************************************************************
//  * read_cards: Reads cards into external variables num_in_rank, num_in_suit;    *
//  *             checks for bad cards and duplicate cards.                        *
//  ********************************************************************************/

// void read_cards(int hand[NUM_CARDS][RANK_SUITS]) {
//     char ch, rank_ch, suit_ch;
//     int rank, suit;
//     bool bad_card, duplicate_card;

//     for (int i = 0; i < NUM_CARDS; i++) {
//         for (int j = 0; j < RANK_SUITS; j++)
//             hand[i][j] = 0;
//     }

//     for (int cards_read = 0; cards_read < NUM_CARDS;) {
//         bad_card = false;

//         printf("Enter a card: ");

//         rank_ch = getchar();
//         switch (rank_ch) {
//             case '0':           exit(EXIT_SUCCESS);
//             case '2':           rank = 1; break;
//             case '3':           rank = 2; break;
//             case '4':           rank = 3; break;
//             case '5':           rank = 4; break;
//             case '6':           rank = 5; break;
//             case '7':           rank = 6; break;
//             case '8':           rank = 7; break;
//             case '9':           rank = 8; break;
//             case 't': case 'T': rank = 9; break;
//             case 'j': case 'J': rank = 10; break;
//             case 'q': case 'Q': rank = 11; break;
//             case 'k': case 'K': rank = 12; break;
//             case 'a': case 'A': rank = 13; break;
//             default:            bad_card = true;
//         }

//         suit_ch = getchar();
//         switch (suit_ch) {
//             case 'c': case 'C': suit = 1; break;
//             case 'd': case 'D': suit = 2; break;
//             case 'h': case 'H': suit = 3; break;
//             case 's': case 'S': suit = 4; break;
//             default:            bad_card = true;
//         }

//         while ((ch = getchar()) != '\n')
//             if(ch != ' ')
//                 bad_card = true;

//         if(bad_card)
//             printf("Bad card; ignored.\n");
//         else if(hand[cards_read-1][RANK] == rank && hand[cards_read-1][SUIT] == suit)
//             printf("Duplicate card; ignored.\n");
//         else {
//             hand[cards_read][RANK] = rank;
//             hand[cards_read][SUIT] = suit;
//             cards_read++;
//         }
//     }
// }

// /************************************************************************************************
//  * analyze_hand: Determines whether the hand contains a straight, a flush, four-of-a-kind,      *
//  *               and/or three-of-a-kind; determines the number of pairs; stores the result      *
//  *               into the external variables straight, flush, four, three, and pairs.           *
//  ************************************************************************************************/

// void analyze_cards(int hand[NUM_CARDS][RANK_SUITS]) {
//     int num_consec = 1;
//     int rank, suit;

//     royal = true;
//     straight = false;
//     flush = false;
//     four = false;
//     three = false;
//     pairs = 0;

//     /*Sorting cards by rank*/
//     bubble_sort(hand);

//     /*Checking for Low-Ace*/
//     low_ace = (hand[NUM_CARDS-1][RANK] == 13);
//     for (int i = 0; i < NUM_CARDS - 1; i++) {
//         if (hand[i][RANK] > 4)
//         low_ace = false;
//     }

//     /*Check for royal*/
//     for (int i = 0; i < NUM_CARDS; i++) {
//         if (hand[i][RANK] < 9)
//         royal = false;
//     }

//     /*Check for flush*/
//     for (suit = 1; suit < NUM_SUITS; suit++) 
//         if (hand[suit][SUIT] == hand[suit - 1][SUIT])
//             flush = true;
//         else {
//             flush = false;
//             break;
//         }
    
//     /*Check for straight*/
//     for (rank = 1; hand[rank][RANK] == (hand[rank - 1][RANK] + 1); rank++)
//         num_consec++;
//     if (num_consec == NUM_CARDS) {
//         straight = true;
//         return;
//     }

//     /*Check for 4-of-a-kind, 3-of-a-kind, and pairs*/
//     int temp = 1;   /*To check for 4's and 3's of a kind*/
//     for (rank = 1; rank < NUM_CARDS; rank++) {
//         if(hand[rank][RANK] != hand[rank - 1][RANK]) 
//             break;    
//         temp++;
//     }
//     for (rank = 1; rank < NUM_CARDS; rank++)
//         if(hand[rank][RANK] == hand[rank - 1][RANK])     
//             pairs++;

//     if (temp == 4)
//         four = true;
//     if (temp == 3)
//         three = true;
// }

// /*********************************************************************************
//  * print_result: Prints the classification of the hand, based on the values of   *
//  *               the external variables straight, flush, four, three, and pairs. *
//  *********************************************************************************/

// void print_result(void) {
//     if (low_ace)
//         printf("Ace-low Straight");
//     else if (royal && flush)
//         printf("Royal Flush");
//     else if (straight && flush)
//         printf("Straight flush");
//     else if (four)
//         printf("Four of a kind");
//     else if (three && pairs == 1)
//         printf("Full house");
//     else if (flush)
//         printf("Flush");
//     else if (straight)
//         printf("Straight");
//     else if (three)
//         printf("Three of a kind");
//     else if (pairs == 2)
//         printf("Two pairs");
//     else if (pairs == 1)
//         printf("Pair");
//     else 
//         printf("High card");
    
//     printf("\n\n");
// }

// void bubble_sort(int hand[NUM_CARDS][RANK_SUITS]) {
//     for (int j = 0; j < NUM_CARDS - 1; j++) 
//     for (int i = 0; i < NUM_CARDS -1 -j; i++) 
//         if (hand[i][RANK] > hand[i+1][RANK]) {
//             int temp1 = hand[i][RANK];
//             hand[i][RANK] = hand[i+1][RANK];
//             hand[i+1][RANK] = temp1;

//             int temp2 = hand[i][SUIT];
//             hand[i][SUIT] = hand[i+1][SUIT];
//             hand[i+1][SUIT] = temp2;
//         } 
// }



// /*Evaluating RPN expressions
//     Project 6*/

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
// void read_exp(void);
// void stack_overflow(void);
// void stack_underflow(void);

// void main() {
//     for(;;)
//     read_exp();
// }

// void read_exp(void) {
//     char ch = 0;
//     int i, j;

//     printf("\nEnter an RPN expression: ");
//     for (; ch != '\n';) {
//         scanf(" %c",&ch);

//         if (ch >= '0' && ch <= '9')
//             push(ch - '0');
//         else {
//             switch(ch) {
//                 case '+': push(pop() + pop()); break;
//                 case '-': i = pop(), j = pop(); push(j-i); break;   /*Correct Order, Couldn't think of anything else*/
//                 case '*': push(pop() * pop()); break;
//                 case '/': i = pop(), j = pop(); push(j/i); break;   /*Correct Order, Couldn't think of anything else*/
//                 case '=': printf("Value of Expression: %d\n",stack[--top]); make_empty(); return;
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



// /*Simulating a 7 Segment Display
//     Project 7*/

// #include <stdio.h>
// #include <stdbool.h>

// #define MAX_DIGITS 10

// const int segments[10][7] = {
//     {1,1,1,1,1,1,0},
//     {0,1,1},
//     {1,1,0,1,1,0,1},
//     {1,1,1,1,0,0,1},
//     {0,1,1,0,0,1,1},
//     {1,0,1,1,0,1,1},
//     {1,0,1,1,1,1,1},
//     {1,1,1},
//     {1,1,1,1,1,1,1},
//     {1,1,1,1,0,1,1}
// };
// int num[MAX_DIGITS] = {0};
// char digits[4][MAX_DIGITS * 4];

// void read_input(void);
// void clear_digits_array(void);
// void process_digit(void);
// void print_digits_array(void);

// int main() {
//     read_input();
//     clear_digits_array();
//     process_digit();
//     print_digits_array();
//     return 0;
// }

// void read_input(void) {
//     char ch, i = 0;
//     printf("Enter a number: ");
//     while((ch = getchar()) != '\n') {
//         if(ch >= '0' && ch <= '9') {
//             num[i] = ch - '0';
//             i++;
//         }
//     }
// }
// void clear_digits_array(void) {
//     for(int i = 0; i < 5; i++)
//     for(int j = 0; j < MAX_DIGITS * 4; j++)
//         digits[i][j] = ' ';
// }
// void process_digit(void) {
//     int i = 0, j = 0, k = 0;
//     while(k < MAX_DIGITS) {
//         switch(num[k]) {
//             case 0: 
//                 digits[i][j+1] = '_'; digits[i+2][j+1] = '_';
//                 digits[i+1][j] = '|'; digits[i+1][j+2] = '|'; digits[i+2][j] = '|'; digits[i+2][j+2] = '|'; 
//             break;
//             case 1:
//                 digits[i+1][j+2] = '|'; digits[i+2][j+2] = '|'; 
//             break;
//             case 2: 
//                 digits[i][j+1] = '_'; digits[i+1][j+1] = '_'; digits[i+2][j+1] = '_';
//                 digits[i+2][j] = '|'; digits[i+1][j+2] = '|'; 
//             break;
//             case 3: 
//                 digits[i][j+1] = '_'; digits[i+1][j+1] = '_'; digits[i+2][j+1] = '_';
//                 digits[i+1][j+2] = '|'; digits[i+2][j+2] = '|'; 
//             break;
//             case 4:
//                 digits[i+1][j+1] = '_';
//                 digits[i+1][j] = '|'; digits[i+1][j+2] = '|'; digits[i+2][j+2] = '|'; 
//             break;
//             case 5: 
//                 digits[i][j+1] = '_'; digits[i+1][j+1] = '_'; digits[i+2][j+1] = '_';
//                 digits[i+1][j] = '|'; digits[i+2][j+2] = '|'; 
//             break;
//             case 6: 
//                 digits[i][j+1] = '_'; digits[i+1][j+1] = '_'; digits[i+2][j+1] = '_';
//                 digits[i+1][j] = '|'; digits[i+2][j] = '|'; digits[i+2][j+2] = '|'; 
//             break;
//             case 7: 
//                 digits[i][j+1] = '_';
//                 digits[i+1][j+2] = '|'; digits[i+2][j+2] = '|'; 
//             break;
//             case 8: 
//                 digits[i][j+1] = '_'; digits[i+1][j+1] = '_'; digits[i+2][j+1] = '_';
//                 digits[i+1][j] = '|'; digits[i+1][j+2] = '|'; digits[i+2][j] = '|';  digits[i+2][j+2] = '|';
//             break;
//             case 9:
//                 digits[i][j+1] = '_'; digits[i+1][j+1] = '_'; digits[i+2][j+1] = '_';
//                 digits[i+1][j] = '|'; digits[i+1][j+2] = '|'; digits[i+2][j+2] = '|';
//             break;
//         }
//         j += 4, k++;
//     }
// }
// void print_digits_array(void) {
//     for(int i = 0; i < 4; i++) {
//         for(int j = 0; j < 4 * MAX_DIGITS; j++) {
//             printf("%c",digits[i][j]);
//         }
//         printf("\n");
//     }
// }



// /*Simulating a 7 Segment Display
//     Project 7
//     2nd Iteration*/

// #include <stdio.h>
// #include <stdbool.h>

// #define MAX_DIGITS 10

// const int segments[10][7] = {
//     {1,1,1,1,1,1,0}, // 0
//     {0,1,1},         // 1
//     {1,1,0,1,1,0,1}, // 2
//     {1,1,1,1,0,0,1}, // 3
//     {0,1,1,0,0,1,1}, // 4
//     {1,0,1,1,0,1,1}, // 5
//     {1,0,1,1,1,1,1}, // 6
//     {1,1,1},         // 7
//     {1,1,1,1,1,1,1}, // 8
//     {1,1,1,1,0,1,1}  // 9
// };
// int num[MAX_DIGITS] = {0};
// int digits_entered = 0;
// char digits[4][MAX_DIGITS * 4];

// void read_input(void);
// void clear_digits_array(void);
// void process_digit(void);
// void print_digits_array(void);

// int main() {
//     read_input();
//     clear_digits_array();
//     process_digit();
//     print_digits_array();
//     return 0;
// }

// void read_input(void) {
//     char ch, i = 0;
//     printf("Enter a number: ");
//     while((ch = getchar()) != '\n') {
//         digits_entered++;
//         if(ch >= '0' && ch <= '9') {
//             num[i] = ch - '0';
//             i++;
//         }
//     }
// }
// void clear_digits_array(void) {
//     for(int i = 0; i < 5; i++)
//     for(int j = 0; j < MAX_DIGITS * 4; j++)
//         digits[i][j] = ' ';
// }
// void process_digit(void) {
//     int i = 0, j = 0, k = 0;
//     while(k < digits_entered) {
//         if(segments[num[k]][0])     digits[i][j+1] = '_';
//         if(segments[num[k]][1])     digits[i+1][j+2] = '|';
//         if(segments[num[k]][2])     digits[i+2][j+2] = '|';
//         if(segments[num[k]][3])     digits[i+2][j+1] = '_';
//         if(segments[num[k]][4])     digits[i+2][j] = '|';
//         if(segments[num[k]][5])     digits[i+1][j] = '|';
//         if(segments[num[k]][6])     digits[i+1][j+1] = '_';
        
//         j += 4, k++;
//     }
// }
// void print_digits_array(void) {
//     for(int i = 0; i < 4; i++) {
//         for(int j = 0; j < 4 * MAX_DIGITS; j++) {
//             printf("%c",digits[i][j]);
//         }
//         printf("\n");
//     }
// }