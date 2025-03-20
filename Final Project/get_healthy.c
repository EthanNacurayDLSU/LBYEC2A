#include <stdio.h>

int main(){
    float bmi, h, w;
    //login/signup options
    printf ("======= Login/Signup =======\n"
            "(1) Login\n"
            "(2) Signup\n"); //
    
    
    //menu system here
    printf("==========================\n"
           "       MENU Options\n"
           "==========================\n"
           "(1) Height and Weight + BMI\n"
           "(2) Ideal BMI Comparison\n"
           "(3) Exercise/Diet Plan\n"
           "(4) Weekly Progress\n");
    printf("\nEnter choice: \n");
    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
        case 1: //height and weight + BMI
    printf("Please put your height in meters, and weight in kg.\n");
    scanf("%f %f", &h, &w);
    bmi = w/(h*h);
    if (bmi < 18.5)
        printf("Your BMI is %.1f, You are Underweight.", bmi);
    else if (bmi < 24.9)
        printf("Your BMI is %.1f, You are Healthy!", bmi);
    else if (bmi < 29.9)
        printf("Your BMI is %.1f, You are Overweight.", bmi);
    else if (bmi < 34.9)
        printf("Your BMI is %.1f, You are Obese.", bmi);
    else if (bmi < 39.9)
        printf("Your BMI is %.1f, You are Severely Obese.", bmi);
    else
        printf("Your BMI is %.1f, You are Morbiusly a Beast.", bmi);

        break;
        case 2: //bmi value

    if (bmi == (w/(h*h)))
        printf("What is your Ideal BMI?");
    else
        printf("Please input your BMI in Menu option No. 1.");
    
    
        break;
        case 3: //exercise/diet plan

        break;
        case 4: //weekly progress

        break;
    }
    return 0;
}