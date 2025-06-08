#include <stdio.h>
#include <string.h>

#define COUNTRY_COUNT (sizeof(country_codes) / sizeof(country_codes[0]))

typedef struct {
    char *country;
    int code;
} dialing_code;

dialing_code country_codes[] = {
        {"Argentina",            54}, {"Bangladesh",      880},
        {"Brazil",               55}, {"Burma (Myanmar)",  95},
        {"China",                86}, {"Colombia",         57},
        {"Congo, Dem. Rep. of", 243}, {"Egypt",            20},
        {"Ethiopia",            251}, {"France",           33},
        {"Germany",              49}, {"India",            91},
        {"Indonesia",            62}, {"Iran",             98},
        {"Italy",                39}, {"Japan",            81},
        {"Mexico",               52}, {"Nigeria",         234},
        {"Pakistan",             92}, {"Philippines",      63},
        {"Poland",               48}, {"Russia",            7},
        {"South Africa",         27}, {"South Korea",      82},
        {"Spain",                34}, {"Sudan",           249},
        {"Thailand",             66}, {"Turkey",           90},
        {"Ukraine",             380}, {"United Kingdom",   44},
        {"United States",         1}, {"Vietnam",          84}
    };

char *check_code(int code);

int main(void) {

    int code;
    char *country;

    printf("Enter an International Dialing Code: ");
    scanf("%d",&code);
    
    country = check_code(code);

    if(country == NULL)
        printf("Country code not found.");
    else
        printf("The %d is the dialing code for %s", code, country);
        
    return 0;
}

char *check_code(int code) {
    for(int i = 0; i < COUNTRY_COUNT; i++) {
        if(country_codes[i].code == code)
            return country_codes[i].country;
    } 
    return NULL;
}