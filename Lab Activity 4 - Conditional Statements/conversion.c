#include <stdio.h>

int main(void){
    // 1. Declare variables
    int choice;
    // Your code here! (More declarations)
    // 2. Display the menu
    printf("========================\n"
    "     MENU Options\n"
    "========================\n"
    "(1) Conversions from miles to km\n"
    "(2) Conversions from pounds to kg\n"
    "(3) Conversions from deg. F to deg. R\n");
    // 3. Prompt the user and scan value
    printf("\nEnter choice: \n");
    scanf("%d", &choice);
    
    // 4. Decision
    switch (choice) //switch cases only work with integers and characters. effectively it is the "==" comparative operator. It cannot do decimals.
    {
        case 1:
            float mi, km;
            #define MIK 1.60934 //miles to km conversion factor
            printf("You chose conversions from miles to km\n\n");
            printf("How many miles would you like to convert?\n");
            scanf("%f", &mi);

            km = (mi*MIK);

            printf("%.2f miles in km is %.2f \n", mi, km);
            printf("Goodbye!");
            break;
       case 2:
            float lb, kg;
            #define LBKG 2.205 //pound to kg conversion factor
            printf("You chose conversions from pounds to kg");
            printf("How many pounds would you like to convert?\n");
            scanf("%f", &lb);

            kg = (lb/LBKG);

            printf("%.2f lbs in kg is %.2f \n", lb, kg);
            printf("Goodbye!");
            break;
       case 3:
            float f, r;
            #define FR 459.67 //pound to kg conversion factor
            printf("You chose conversions from deg. F to deg. R");
            printf("What is the deg. F you would like to convert?\n");
            scanf("%f", &f);

            r = (f+FR);

            printf("%.2f deg.F in deg.R is %.2f deg.R \n", f, r);
            printf("Goodbye!");
            break;
        default:
            printf("This is an invalid option!"); 
    }
    // Exit
    return 0;
}
