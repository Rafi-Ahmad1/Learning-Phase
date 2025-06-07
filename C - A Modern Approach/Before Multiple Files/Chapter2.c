// /*Program to Display a pattern
//   Program 1*/

// #include <stdio.h>

// int main(void)
// {
//     printf("        *\n");
//     printf("       *\n");
//     printf("      *\n");
//     printf("     *\n");
//     printf("*   *\n");
//     printf(" * *\n");
//     printf("  *\n");
// }



// /*Computing the volume of a sphere
//   Program 2*/

// #include <stdio.h>

// int main(void)
// {
//     int radius = 10;
//     float volume;
//     volume = 4.0f/3.0f * 3.141592 * radius * radius * radius;
    
//     printf("The Volume of Sphere is: %f",volume);

//     return 0;
// }



// /*Computing the volume of sphere of given radius
//   Program 3*/

// #include <stdio.h>

// int main(void)
// {
//     int radius;
//     float volume;

//     printf("Enter the Radius of Sphere: ");
//     scanf("%d", &radius);

//     volume = 4.0f/3.0f * 3.141592 * radius * radius * radius;
    
//     printf("The Volume of Sphere is: %f",volume);

//     return 0;
// }



// /*5% tax added to given amount of money
//   Program 4*/

// #include <stdio.h>

// void main()
// {
//     float amount;

//     printf("Enter The Dollars and Cents: $");
//     scanf("%f", &amount);

//     printf("After 5 Percent Tax: $%.2f", amount + amount * 0.05);
// }



// /*Evaluating a polynomial for given value of x
//   Program 5*/

// #include <stdio.h>

// void main()
// {
//     int x;

//     printf("Enter the value of x: ");
//     scanf("%d", &x);

//     printf("The value of polynomial at x=%d is: %d", x, 3*x*x*x*x*x + 2*x*x*x*x - 5*x*x*x - x*x + 7*x - 6);
// }



// /*Evaluting a polynomial using different (Horner's Rule) formula
//   Program 6*/

// #include <stdio.h>

// void main()
// {
//     int x;

//     printf("Enter the value of x: ");
//     scanf("%d", &x);

//     printf("The value of polynomial at x=%d is: %d", x, ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6 );
// }



// /*Enter US dollar and convert into 20$ 10$ 5$ and 1$ bills
//   Program 7*/

// #include <stdio.h>

// void main()
// {
//     int inital_money, req_20_bills, req_10_bills, req_5_bills, req_1_bills;

//     printf("Enter the amount in dollars: ");
//     scanf("%d", &inital_money);

//     req_20_bills = inital_money/20;
//     req_10_bills = (inital_money - req_20_bills*20)/10;
//     req_5_bills = (inital_money - req_10_bills*10 - req_20_bills*20)/5;
//     req_1_bills = (inital_money - req_20_bills*20 - req_10_bills*10 - req_5_bills*5);

//     printf("20$ Bills = %d\n", req_20_bills);
//     printf("10$ Bills = %d\n", req_10_bills);
//     printf("5$ Bills = %d\n", req_5_bills);
//     printf("1$ Bills = %d\n", req_1_bills);
// }



// /*Calculation remaining balance after 1st 2nd and 3rd monthly payments
//   Program 8*/

// #include <stdio.h>

// void main()
// {
//     float initial_amount, interest_rate, monthly_payment;
//     float after_first_payment, after_second_payment, after_third_payment;

//     printf("Enter amount of loan: ");
//     scanf("%f",&initial_amount);
//     printf("Enter interest rate: ");
//     scanf("%f", &interest_rate);
//     printf("Enter monthly payment: ");
//     scanf("%f",&monthly_payment);

//     after_first_payment = initial_amount + initial_amount*interest_rate/1200 - monthly_payment;
//     after_second_payment = after_first_payment + after_first_payment*interest_rate/1200 - monthly_payment;
//     after_third_payment = after_second_payment + after_second_payment*interest_rate/1200 - monthly_payment; 

//     printf("Balance after 1st Payment: %.2f\n", after_first_payment);
//     printf("Balance after 2nd Payment: %.2f\n", after_second_payment);
//     printf("Balance after 3rd Payment: %.2f\n", after_third_payment);
// }