// /* Modifying Project 7 from Chapter 2 to include a function
//     Program 1*/

// #include <stdio.h>

// void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

// void main()
// {
//     int dollars, twenties, tens, fives, ones;

//     printf("Enter the amount in dollars: ");
//     scanf("%d", &dollars);
//     pay_amount(dollars, &twenties, &tens, &fives, &ones);
    
//     printf("20$ Bills = %d\n", twenties);
//     printf("10$ Bills = %d\n", tens);
//     printf("5$ Bills = %d\n", fives);
//     printf("1$ Bills = %d\n", ones);
// }

// void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
//     *twenties = dollars/20;
//     *tens = (dollars - *twenties*20)/10;
//     *fives = (dollars - *tens*10 - *twenties*20)/5;
//     *ones = (dollars - *twenties*20 - *tens*10 - *fives*5);
// }



// /* Modifying Project 8 from Chapter 5 to include a function
//     Program 2*/

// #include <stdio.h>

// void find_closest_time(int desired_time, int *departure_time, int *arrival_time);

// void main()
// {
//     int hour, minute;
//     int desired_time, departure_time, arrival_time, mins_since_mdnght;


//     printf("Enter Current time[24-hour]: ");
//     scanf("%d:%d", &hour, &minute);

//     desired_time = (hour * 60) + minute;
//     find_closest_time(desired_time, &departure_time, &arrival_time);

//     printf("Closest departure time is %d:%.2d, arriving at %.2d:%.2d", departure_time/60, departure_time%60, arrival_time/60, arrival_time%60);
// }

// void find_closest_time(int desired_time, int *departure_time, int *arrival_time) {
//     int dep1, dep2, dep3, dep4, dep5, dep6, dep7, dep8;

//     dep1 = (8 * 60); //8:00 AM
//     dep2 = (9 * 60) + 43; //9:43 AM
//     dep3 = (11 * 60) + 19; //11:19 AM
//     dep4 = (12 * 60) + 47; //12:47 PM
//     dep5 = ( (12+2) * 60); //2:00 PM
//     dep6 = ( (12+3) * 60) + 45; //3:45 PM
//     dep7 = ( (12+7) * 60); //7:00 PM
//     dep8 = ( (12+9) * 60) + 45; //9:45 PM

//     if (desired_time <= (dep1 + dep2)/2 ) {
//         *departure_time = dep1;
//         *arrival_time = ( (10) * 60) + 16; // 10:16 AM
//     }
//     else if (desired_time <= (dep2 + dep3)/2 ) {
//         *departure_time = dep2;
//         *arrival_time = ( (11) * 60) + 52; // 11:52 AM
//     }
//     else if (desired_time <= (dep3 + dep4)/2 ) {
//         *departure_time = dep3;
//         *arrival_time = ( (12+1) * 60) + 31; // 1:31 PM
//     }
//     else if (desired_time <= (dep4 + dep5)/2 ) {
//         *departure_time = dep4;
//         *arrival_time = ( (12+3) * 60); // 3:00 PM
//     }
//     else if (desired_time <= (dep5 + dep6)/2 ) {
//         *departure_time = dep5;
//         *arrival_time = ( (12+4) * 60) + 8; // 4:08 PM
//     }
//     else if (desired_time <= (dep6 + dep7)/2 ) {
//         *departure_time = dep6;
//         *arrival_time = ( (12+5) * 60) + 55; // 5:55 PM
//     }
//     else if (desired_time <= (dep7 + dep8)/2 ) {
//         *departure_time = dep7;
//         *arrival_time = ( (12+9) * 60) + 20; //  9:20 PM
//     }
//     else {
//         *departure_time = dep8;
//         *arrival_time = ( (12+11) * 60) + 58; // 11:58 PM
//     }
// }


// /* Modifyong Project 3 from Chapter 6 to include a function
//     Program 3*/

// #include <stdio.h>

// void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

// void main() {
//     int nume,deno,red_nume,red_deno,gcd,temp;

//     printf("Enter a fraction: ");
//     scanf("%d/%d",&nume,&deno);
//     reduce(nume, deno, &red_nume, &red_deno);

//     printf("In lowest terms is: %d/%d", red_nume, red_deno);
// }

// void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
//     int temp;
//     *reduced_numerator = numerator, *reduced_denominator = denominator;
//     while(numerator != 0) {
//         temp = numerator;
//         numerator = denominator % numerator;
//         denominator = temp;
//     }
//     int gcd = denominator;
//     *reduced_numerator = *reduced_numerator/gcd;
//     *reduced_denominator = *reduced_denominator/gcd;
// }



// /* Modifying poker.c by moving all external variable into main and using arguments
//     Program 4*/

// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// #define NUM_RANKS 13
// #define NUM_SUITS 4
// #define NUM_CARDS 5

// int num_in_rank[NUM_RANKS];
// int num_in_suit[NUM_SUITS];

// void read_cards(void);
// void analyze_cards(bool *straight, bool *flush, bool *four, bool *three, int *pairs);
// void print_result(bool straight, bool flush, bool four, bool three, int pairs);

// /***********************************************************************
//  * main: Calls read_cards, analyze_hand, and print_result repeatedly   *
//  *                                                                     *
//  ***********************************************************************/

// int main() {
//     bool straight, flush, four, three;
//     int pairs;

//     for(;;) {
//         read_cards();
//         analyze_cards(&straight, &flush, &four, &three, &pairs);
//         print_result(straight, flush, four, three, pairs);
//     }
// }

// /********************************************************************************
//  * read_cards: Reads cards into external variables num_in_rank, num_in_suit;    *
//  *             checks for bad cards and duplicate cards.                        *
//  ********************************************************************************/

// void read_cards(void) {
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

// void analyze_cards(bool *straight, bool *flush, bool *four, bool *three, int *pairs) {
//     int num_consec = 0;
//     int rank, suit;

//     *straight = false;
//     *flush = false;
//     *four = false;
//     *three = false;
//     *pairs = 0;

//     /*Check for flush*/
//     for (suit = 0; suit < NUM_SUITS; suit++) 
//         if (num_in_suit[suit] == NUM_CARDS)
//             *flush = true;
    
//     /*Check for straight*/
//     rank = 0;
//     while (num_in_rank[rank] == 0)
//         rank++;
//     for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
//         num_consec++;
//     if (num_consec == NUM_CARDS) {
//         *straight = true;
//         return;
//     }

//     /*Check for 4-of-a-kind, 3-of-a-kind, and pairs*/
//     for (rank = 0; rank < NUM_RANKS; rank++) {
//         if(num_in_rank[rank] == 4) 
//             *four = true;
//         if(num_in_rank[rank] == 3) 
//             *three = true;
//         if(num_in_rank[rank] == 2) 
//             *pairs++;
//     }
// }

// /*********************************************************************************
//  * print_result: Prints the classification of the hand, based on the values of   *
//  *               the external variables straight, flush, four, three, and pairs. *
//  *********************************************************************************/

// void print_result(bool straight, bool flush, bool four, bool three, int pairs) {
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