#include <stdio.h>
#include <math.h>

#define PI 3.1415929 // Constant

float sphereVolume(float r); //function prototypes, declares the existence of functions to main function
float sphereSurface(float r);
float cylinderVolume(float r, float h);
float cylinderSurface(float r, float h);
float coneVolume(float r, float h);
float coneSurface(float r, float h);

int main(void){
    
    float radius, height;
    
    printf("Enter the given radius and height: ");
    scanf("%f %f", &radius, &height);

    printf("=================================== RESULTS ===================================");
    
    printf("\n\nSphere Calculations :");
    printf("\nThe volume of the sphere with radius %0.2f is equal to %0.2f cu. units.\n", radius, sphereVolume(radius)/*variable radius to passed to sphereVolume function */);
    printf("The surface area of the sphere with radius %0.2f is equal to %0.2f cu. units.\n", radius, sphereSurface(radius));
    
    printf("\nCylinder Calculations : ");
    printf("\nThe volume of the cynlinder with radius %0.2f and height %.2f is equal to %0.2f cu. units.", radius, height, cylinderVolume(radius, height));
    printf("\nThe surface area of the cynlinder with radius %0.2f and height %.2f is equal to %0.2f cu. units.\n", radius, height, cylinderSurface(radius, height));

    printf("\nCone Calculations : ");
    printf("\nThe volume of the cone with radius %0.2f and height %.2f is equal to %0.2f cu. units.", radius, height, coneVolume(radius, height));
    printf("\nThe surface area of the cone with radius %0.2f and height %.2f is equal to %0.2f cu. units.\n", radius, height, coneSurface(radius, height));

    return 0; 
} 


float sphereVolume(float r /*this function takes the radius passed to it, and defines it as variable r*/){
    return (4.0*PI*pow(r,3)/3.0);
}

float sphereSurface(float r){
    return (4*PI*pow(r,2));    
}

float cylinderVolume(float r, float h){
    return (PI*pow(r,2)*h);       
}

float cylinderSurface(float r, float h){
    return ((2*PI*r*h)+(2*PI*pow(r,2)));       
}

float coneVolume(float r, float h){
    return (PI*pow(r,2)*(h/3));      
}

float coneSurface(float r, float h){
    return ((PI*r)*(r+sqrt((h*h)+(r*r))));    
}