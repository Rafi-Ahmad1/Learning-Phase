// /*Reversing a 2 digit number
//   Program 1*/

// #include <stdio.h>

// void main()
// {
//     int n,fir_digit,sec_digit;

//     printf("Enter a two digit number: ");
//     scanf("%d",&n);

//     fir_digit = n%10;
//     sec_digit = n/10;

//     printf("The Reversal is: %d%d",fir_digit,sec_digit);
// }



// /*Reversing 3 digit number
//   Program 2*/

// #include <stdio.h>

// void main()
// {
//     int n,fir_digit,sec_digit,third_digit;

//     printf("Enter a three digit number: ");
//     scanf("%d",&n);

//     fir_digit = n%10;
//     sec_digit = (n/10)%10;
//     third_digit = n/100;

//     printf("The Reversal is: %d%d%d",fir_digit,sec_digit,third_digit);
// }



// /*Reversing numbers without using arithmetic
//   Program 3*/

// #include <stdio.h>

// void main()
// {
//     int fir_digit,sec_digit,third_digit;

//     printf("Enter a three digit number: ");
//     scanf("%1d%1d%1d",&fir_digit,&sec_digit,&third_digit);
    
//     printf("The Reversal is: %d%d%d",third_digit,sec_digit,fir_digit);
// }



// /*Converting Base 10 to Base 8
//   Program 4*/

// #include <stdio.h>

// void main()
// {
//     int n,first_digit,sec_digit,third_digit,fourth_digit,fifth_digit;

//     printf("Enter a number in base 10: ");
//     scanf("%d",&n);

//     first_digit = n%8;
//     sec_digit = (n/ 8 )%8;
//     third_digit = (n/ (8*8) )%8;
//     fourth_digit = (n/ (8*8*8) )%8;
//     fifth_digit = (n/ (8*8*8*8) )%8;
    
//     printf("The number in base 8 is: %d%d%d%d%d",fifth_digit,fourth_digit,third_digit,sec_digit,first_digit);
// }



// /*Finding Check digit of an 12-1 digit a UPC number
//   Program 5*/

// #include <stdio.h>

// void main()
// {
//     int a,b,c,d,e,f,g,h,i,j,k,l;

//     printf("Enter UPC number: ");
//     scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k);

//     l = 9 - ( (3*(a+c+e+g+i+k) + (b+d+f+h+j)) - 1 ) % 10;

//     printf("Check Digit: %d",l);
// }



// /*Finding Check digits of 13-1 digit EAN number
//   Program 6*/

// #include <stdio.h>

// void main()
// {
//     int a,b,c,d,e,f,g,h,i,j,k,l,m;

//     printf("Enter EAN number: ");
//     scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l);

//     m = 9 - ( (3*(b+d+f+h+j+l) + (a+c+e+g+i+k)) - 1 ) % 10;

//     printf("Check Digit: %d",m);
// }