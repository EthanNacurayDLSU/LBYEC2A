#include <stdio.h>

int main(void){
    // 1. Variable declaration
    float level;
    // 2. User-input prompt and scan
    printf("\nEnter earthquake level: \n");
    scanf("%f", &level);
    // 3. Decision
    if (level < 5.0) printf("Little or no damage \n");
    else if (/*your code here*/0) printf("Some damage \n");
    else if (/*your code here*/0) printf("Serious damage \n");
    else if (/*your code here*/0) printf("Disaster \n");
    else printf("Catastrophe \n");
    // Exit
    return 0;
}