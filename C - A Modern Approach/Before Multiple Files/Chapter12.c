// /*Reversing a Message
//     Program 1(a)*/

// #include <stdio.h>

// #define MSG_LEN 100

// int main() {
//     int i;
//     char msg[MSG_LEN];

//     printf("Enter a message: "); 
//     for(i = 0; i < MSG_LEN; i++) {
//         msg[i] = getchar();
//         if(msg[i] == '\n')
//             break;
//     }
        
//     printf("Reversal is: ");
//     for(i--; i >= 0; i--)
//         putchar(msg[i]);

//     return 0;
// }



// /*Reversing a Message
//     Program 1(b)*/

//     #include <stdio.h>

//     #define MSG_LEN 100
    
//     int main() {
//         char msg[MSG_LEN], *p;
 
//         printf("Enter a message: ");
//         for(p = &msg[0]; p < &msg[MSG_LEN]; p++) {
//             *p = getchar();
//             if(*p == '\n')
//             break;
//         }
    
//         printf("Reversal is: ");
//         for(*p-- == '\n'; p >= msg; p--)
//             putchar(*p);
    
//         return 0;
//     }



// /*Checking Palindrome
//     Program 2(a)*/

// #include <stdio.h>
// #include <ctype.h>

// #define MSG_LEN 100

// int main() {
//     int i;
//     char msg[MSG_LEN];
    
//     printf("Enter a message: "); 
//     for(i = 0; i < MSG_LEN; i++) {
//         msg[i] = getchar();
//         if(msg[i] == '\n')
//             break;
//     }
    
//     int j = i-1;
//     i = 0;
//     for(;i != j; i++, j--) {
//         while(toupper(msg[i]) < 65 || toupper(msg[i]) > 90 || toupper(msg[j]) < 65 || toupper(msg[j]) > 90) {
//             if(toupper(msg[i]) < 65 || toupper(msg[i]) > 90) i++; 
//             if(toupper(msg[j]) < 65 || toupper(msg[j]) > 90) j--;
//             if(j - i <= 1)
//                 break;
//         }
//         if(toupper(msg[i]) != toupper(msg[j]))
//             break;
//     }
//     if(j - i <= 1)
//         printf("Palindrome");
//     else
//         printf("Not a Palindrome");

//     return 0;
// }



// /*Checking Palindrome
//     Program 2(b)*/

// #include <stdio.h>
// #include <ctype.h>

// #define MSG_LEN 100

// int main() {
//     char msg[MSG_LEN], *p;
    
//     printf("Enter a message: "); 
//     for(p = &msg[0]; p < &msg[MSG_LEN]; p++) {
//         *p = getchar();
//         if(*p == '\n')
//             break;
//     }
    
//     char *q = p-1;
//     p = msg;
//     for(;p != q; p++, q--) {
//         while(toupper(*p) < 65 || toupper(*p) > 90 || toupper(*q) < 65 || toupper(*q) > 90) {
//             if(toupper(*p) < 65 || toupper(*p) > 90) p++; 
//             if(toupper(*q) < 65 || toupper(*q) > 90) q--;
//             if(q - p <= 1)
//                 break;
//         }
//         if(toupper(*p) != toupper(*q))
//             break;
//     }
//     if(q - p <= 1)
//         printf("Palindrome");
//     else
//         printf("Not a Palindrome");

//     return 0;
// }



// /*Simplifying 1(b) using array as pointer
//     Program 3*/

// #include <stdio.h>

// #define MSG_LEN 100

// int main() {
//     char msg[MSG_LEN], *p;

//     printf("Enter a message: ");
//     for(p = msg; p < msg + MSG_LEN; p++) {
//         *p = getchar();
//         if(*p == '\n')
//         break;
//     }

//     printf("Reversal is: ");
//     for(*p-- == '\n'; p >= msg; p--)
//         putchar(*p);

//     return 0;
// }



// /*Simplifying 2(b) using array as pointer
//     Program 4*/

// #include <stdio.h>
// #include <ctype.h>

// #define MSG_LEN 100

// int main() {
//     char msg[MSG_LEN], *p;
    
//     printf("Enter a message: "); 
//     for(p = msg; p < msg + MSG_LEN; p++) {
//         *p = getchar();
//         if(*p == '\n')
//             break;
//     }
    
//     char *q = p-1;
//     p = msg;
//     for(;p != q; p++, q--) {
//         while(toupper(*p) < 65 || toupper(*p) > 90 || toupper(*q) < 65 || toupper(*q) > 90) {
//             if(toupper(*p) < 65 || toupper(*p) > 90) p++; 
//             if(toupper(*q) < 65 || toupper(*q) > 90) q--;
//             if(q - p <= 1)
//                 break;
//         }
//         if(toupper(*p) != toupper(*q))
//             break;
//     }
//     if(q - p <= 1)
//         printf("Palindrome");
//     else
//         printf("Not a Palindrome");

//     return 0;
// }



// /*Modifying Project 13 from Chapter 8 to use pointer
//     Program 5*/

// #include <stdio.h>

// #define SENT_LEN 100

// void main() {
//     char sent[SENT_LEN] = {0}, term, *p, *q, *r;

//     printf("Enter a Sentence: ");
//     for (p = sent; p < sent + SENT_LEN; p++) {
//         scanf("%c",p);
//         if (*p == '.' || *p == '!' || *p == '\n' || *p == '?') {
//             term = *p;
//             *p = ' ';
//             break;
//         }
//     }

//     printf("Reversal of Sentence: ");
//     while (p >= sent) {
//         for (q = p; *q != ' '; q--);
//         for (r = q+1; r < sent + SENT_LEN; r++) {
//             printf("%c",*r);
//             if (*r == ' ')
//                 break;
//         }
//         p = q-1;
//     }
//     printf("\b%c",term);
// }



// /*Modifyiong quicksort.c to include pointers
//     Program 6*/

// #include <stdio.h>

// #define N 10

// void quicksort(int a[], int *low, int *high);
// int *split(int a[], int *low, int *high);

// int main() {
//     int a[N],i;
    
//     printf("Enter %d numbers to be sorted: ",N);
//     for(i = 0; i < N; i++) 
//         scanf("%d",&a[i]);
    
//     quicksort(a,a,a+N-1);

//     printf("In sorted order: ");
//     for(i = 0; i < N; i++)
//         printf("%d ",a[i]);
//     printf("\n");

//     return 0;
// }

// void quicksort(int a[], int *low, int *high) {
//     int *middle;

//     if (low >= high) 
//         return;

//     middle = split(a,low,high);
//     quicksort(a, low, middle - 1);
//     quicksort(a, middle + 1, high);
// }

// int *split (int a[], int *low, int *high) {
//     int pivot = *low;

//     for (;;) {
//         while (low < high && pivot <= *high)
//             high--;
//         if (low >= high)
//             break;
//         *(low++) = *high;

//         while (low < high && *low <= pivot) 
//             low++;
//         if (low >= high)
//             break;
//         *(high--) = *low;
//     }

//     *high = pivot;
//     return high;
// }



// /*Modifying maxmin.c of Chapter 11.4 to use more pointers
//     Program 7*/

// #include <stdio.h>

// #define N 5

// void max_min(int a[], int n, int *max, int *min);

// int main() {
//     int b[N], *p, big, small;

//     printf("Enter %d numbers: ",N);
//     for(p = b; p < b + N; p++)
//         scanf("%d",p);

//     max_min(b, N, &big, &small);

//     printf("\nLargest: %d", big);
//     printf("\nSmallest: %d", small);

//     return 0;
// }

// void max_min(int a[], int n, int *max, int *min) {
//     int *p;

//     *max = *min = a[0];
//     for(p = a + 1; p < a + n; p++) {
//         if(*p > *max)
//             *max = *p;
//         else if(*p < *min)
//             *min = *p;
//     }
// }