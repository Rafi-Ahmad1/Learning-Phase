// /*Displaying date in yyyymmdd form entered in mm/dd/yyyy
//   Program 1*/

// #include <stdio.h>

// void main()
// {
//     int month,date,year;

//     printf("Enter a date (mm/dd/yyyy): ");
//     scanf("%d/%d/%d",&month,&date,&year);

//     printf("You Entered the date %d%.2d%d",year,month,date);

// }



// /*Formatting product information entered by user
//   Program 2*/

// #include <stdio.h>

// void main()
// {
//     int month,date,year,item_number;
//     float price;

//     printf("Enter item number: ");
//     scanf("%d",&item_number);
//     printf("Enter unit price: ");
//     scanf("%f",&price);
//     printf("Enter purchase date (mm/dd/yyyy): ");
//     scanf("%d/%d/%d",&month,&date,&year);

//     printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%-d\t\t$%6.2f\t\t%d/%d/%d",item_number,price,month,date,year);

// }



// /*Breaking down ISBN number given by user
//   Program 3*/

// #include <stdio.h>

// void main()
// {
//     int gsi_prefix , group_identifier , publisher_code , item_number , check_digit;

//     printf("Enter an ISBN number: ");
//     scanf("%d-%d-%d-%d-%d" , &gsi_prefix , &group_identifier , &publisher_code , & item_number , &check_digit);

//     printf("GSI prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d",gsi_prefix,group_identifier,publisher_code,item_number,check_digit);

// }



// /*Displaying telephone number in the form xxx.xxx.xxxx entered in form (xxx) xxx-xxxx
//   Program 4*/

// #include <stdio.h>

// void main()
// {
//     int num1,num2,num3;

//     printf("Enter a telephone number [(xxx) xxx-xxxx]: ");
//     scanf("(%d) %d-%d" , &num1,&num2,&num3);

//     printf(" You Entered %d.%d.%d",num1, num2 , num3 );

// }



// /*Displaying numbers in 4 by 4 arrangements and finding sums of rows, columns, and diagonals
//   Program 5*/

// #include <stdio.h>
// void main()
// {
//     int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16;
//     int row_sum1, row_sum2, row_sum3, row_sum4;
//     int column_sum1, column_sum2, column_sum3, column_sum4;
//     int diagonal_sum1, diagonal_sum2;

//     printf("Enter the numbers from 1 to 16 in any order: \n");
//     scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&num1,&num2,&num3,&num4,&num5,&num6,&num7,&num8,&num9,&num10,&num11,&num12,&num13,&num14,&num15,&num16);

//     printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n",num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12,num13,num14,num15,num16);

//     row_sum1 = num1+num2+num3+num4;
//     row_sum2 = num5+num6+num7+num8;
//     row_sum3 = num9+num10+num11+num12;
//     row_sum4 = num13+num14+num15+num16;

//     column_sum1 = num1+num5+num9+num13;
//     column_sum2 = num2+num6+num10+num14;
//     column_sum3 = num3+num7+num11+num15;
//     column_sum4 = num4+num8+num12+num16;

//     diagonal_sum1 = num1+num6+num11+num16;
//     diagonal_sum2 = num4+num7+num10+num13;

//     printf("\nRow Sum: %d %d %d %d", row_sum1, row_sum2, row_sum3, row_sum4);
//     printf("\nColumn Sum: %d %d %d %d", column_sum1, column_sum2, column_sum3, column_sum4);
//     printf("\nDiagonal Sum: %d %d", diagonal_sum1, diagonal_sum2);

// }



// /*Adding Fractions entered a/b + c/d
//   Program 6*/

// #include <stdio.h>
// void main()
// {
//     int nume1, nume2, denom1, denom2, result_nume, result_denom;

//     printf("Enter: ");
//     scanf("%d/%d + %d/%d", &nume1, &denom1, &nume2, &denom2);

//     result_nume = (nume1 * denom2) + (nume2 * denom1);
//     result_denom = denom1 * denom2;

//     printf("The Sum is: %d/%d", result_nume, result_denom);
// }