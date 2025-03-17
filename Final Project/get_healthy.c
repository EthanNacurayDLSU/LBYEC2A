#include <stdio.h>

int main()
{
    // login/signup options
    printf("======= Login/Signup =======\n"
           "(1) Login\n"
           "(2) Signup\n"); //

    // menu system here
    printf("========================\n"
           "     MENU Options\n"
           "========================\n"
           "(1) BMI Calculation\n"
           "(2) BMI value and classification\n"
           "(3) Exercise/Diet Plan\n"
           "(4) Weekly Progress\n");
    printf("\nEnter choice: ");
    int menu;
    scanf("%d", &menu);

    switch (menu)
    {
    case 1: // height and weight
        float BMI, h, w;

        puts("======== BMI Calculation ======="); // banner so the user knows what menu they are in.

        printf("Please put your Height in meters : ");
        scanf("%f", &h);
        printf("\nPlease put your Weight in Kilograms : ");
        scanf("%f", &w);
        BMI = w / (h * h);

        // these if statements are basically the classification right? you can copy these under case 2.
        if (BMI < 18.5)
        {
            printf("Your BMI is %.1f", BMI);
        }
        break;
    case 2: // bmi value and classification

        break;
    case 3: // exercise/diet plan

        break;
    case 4: // weekly progress

        break;
    }
    return 0;
}