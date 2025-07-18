/*Maintains a parts dadabse (array version)*/

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

int find_part(const struct part inventory[], int number, int num_parts);
void insert(struct part inventory[], int *num_parts);
void search(const struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(const struct part inventory[], int num_parts);

/********************************************************************************************
 * main: prompts the user to enter an operation code, then calls a function to perform      *
 *       the requested action. Repeats until user enters the command 'q'. Prints an         *
 *       error message if the user enters an illegal code.                                  *
 *                                                                                          *
 ********************************************************************************************/
int main(void) {
    struct part inventory[MAX_PARTS];
    int num_parts = 0; /*number of parts currently stored*/
    char code;

    for(;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n');   /*Skips to end of line*/
        switch(code) {
            case 'i':   insert(inventory, &num_parts);
                        break;
            case 's':   search(inventory, num_parts);
                        break;
            case 'u':   update(inventory, num_parts);
                        break;
            case 'p':   print(inventory, num_parts);
                        break;
            case 'q': return 0;
            default: printf("Illegal Code\n");
        }
        printf("\n");
    }
}

/********************************************************************************************
 * find_part: Looks up a part number in the inventory array. Returns the array              *
 *            index if the part number is found; otherwise, returns -1.                     *
 *                                                                                          *
 ********************************************************************************************/
int find_part(const struct part inventory[], int number, int num_parts) {
    int i;

    for(i = 0; i < num_parts; i++)
        if(inventory[i].number == number)
            return i;
    return -1;
}

/********************************************************************************************
 *insert: Prompts the user for information about a new part and then inserts the part into  *
 *        the database. Prints an error message and returns prematurely if the part         *
 *        already exists or the database is full.                                           *
 *                                                                                          *
 ********************************************************************************************/
void insert(struct part inventory[], int *num_parts) {
    int part_number;

    if(*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if(find_part(inventory, part_number, *num_parts) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;
    printf("Enter Part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);
    printf("Enter Price: ");
    scanf("%lf", &inventory[*num_parts].price);
    printf("Enter Quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);
    (*num_parts)++;
}

/********************************************************************************************
 * search: Prompts the user to enter a part number, then looks up the part in the database. *
 *         If the part exists, prints the name and quantity on hand; if not, prints an      *
 *         error message.                                                                   *
 *                                                                                          *
 ********************************************************************************************/
void search(const struct part inventory[], int num_parts) {
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, number, num_parts);
    if(i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Price: %lf", inventory[i].price);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else
        printf("Part not found.\n");
}

/********************************************************************************************
 * update: Prompts the user to enter a part number. Prints an error message if the part     *
 *         doesn't exist; otherwise, prompts the user to enter change in quantity on hand   *
 *         and updates the database.                                                        *
 *                                                                                          *
 ********************************************************************************************/
void update(struct part inventory[], int num_parts) {
    int i, number, change;
    char command;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, number, num_parts);
    printf("Enter a command[price = P/quantity = Q]: ");
    scanf("%c", &command);

    if(i >= 0) {
        if(command == 'Q') {
            printf("Enter change in quantity on hand: ");
            scanf("%d", &change);
            inventory[i].on_hand += change;
        } 
        if(command == 'P') {
            printf("Enter change in price of part: ");
            scanf("%d", &change);
            inventory[i].price += change;
        } 
    else
        printf("Part not found.\n");
    }
}

/********************************************************************************************
 * print: Prints a listing of all parts in the database, showing the part number, part      *
 *        name, and quantity on hand. Parts are printed in the order in which they were     *
 *        entered into the database.                                                        *
 *                                                                                          *
 ********************************************************************************************/
void print(const struct part inventory[], int num_parts) {
    int i;

    printf("Part Number     Price($)       Part Name                  Quantity on Hand\n");
    for(i = 0; i < num_parts; i++) 
        printf("%7d         %.2lf        %-25s%10d\n", inventory[i].number, inventory[i].price, inventory[i].name, inventory[i].on_hand);
}