#include <stdio.h>

int main(void){
    // 1. Variable declaration
    float level;
    // 2. User-input prompt and scan
    printf("\nEnter earthquake level: \n");
    scanf("%f", &level);
    // 3. Decision
    if (level < 5.0) 
    {
        printf("Little or no damage \n");
    } //by default C only executes the first line after an if statement. if there is no curly braces (the scope operator), indents are not considered by the compiler. 
    else if (level < 5.5) printf("Some damage \n");
    else if (level < 6.5) printf("Serious damage \n");
    else if (level < 7.5) printf("Disaster \n");
    else printf("Catastrophe \n"); //"else is only needed if you have another code block"-sir (from what i get though, the if statement will be skipped if it returns false and move to the next code)
    // Exit
    return 0;
}