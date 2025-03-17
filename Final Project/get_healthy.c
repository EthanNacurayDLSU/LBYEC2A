#include <stdio.h>

int main(){
    //login/signup options
    printf ("======= Login/Signup =======\n"
            "(1) Login\n"
            "(2) Signup\n"); //
    
    
    //menu system here
    printf("========================\n"
           "     MENU Options\n"
           "========================\n"
           "(1) Height and Weight\n"
           "(2) BMI value\n"
           "(3) Exercise/Diet Plan\n"
           "(4) Weekly Progress\n");
    printf("\nEnter choice: \n");
    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
        case 1: //height and weight
    float BMI, h, w;
    printf("Please put your height in meters, and weight in kg.\n");
    scanf("%f %f", &h, &w);
    BMI = w/(h*h);
    if BMI < 18.5 
    printf("Your BMI is %.1f", BMI);
        break;
        case 2: //bmi value

        break;
        case 3: //exercise/diet plan

        break;
        case 4: //weekly progress

        break;
    }
    return 0;
}