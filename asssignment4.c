#include <stdio.h>
#include <stdlib.h>

void distanceConversion(float Distance_Input, char Distance_UnitFrom, char Distance_UnitTo) {

    float result;
    int while_distance_flag = 1; // starts the flag for distance math

    if (Distance_Input < 0.0 ||  Distance_Input > 20000.1){
        printf("Distance must be between 0.0 and 20000.1.\n");
        return;
    }

    //while (while_distance_flag != 0) {// distance while loop
       
        switch (Distance_UnitFrom) { // CANNOT USE STR FOR CASE, USE A SINGLE CHAR
            case 'k': // Kilometers
                switch (Distance_UnitTo)
                {
                    case 'k': result = Distance_Input; break; // same unit
                    case 'm': result = Distance_Input * 1000; break; // Kilometers to Meters
                    case 'f': result = Distance_Input * 3280.84; break; // Kilometers to Feet
                    case 'i': result = Distance_Input * 0.621371; break; // Kilometers to Miles
                    default: printf("Invalid input."); return;
                }
                break;

            case 'm': // Meters
                switch (Distance_UnitTo)
                {
                    case 'k': result = Distance_Input * 0.001; break; // same logic as prior
                    case 'm': result = Distance_Input; break;
                    case 'f': result = Distance_Input * 3.28084; break;
                    case 'i': result = Distance_Input * 0.000621371; break;
                    default: printf("Invalid input."); return;

                }
                break;
                case 'f': // Feet
                switch(Distance_UnitTo)
                {
                    case 'k': result = Distance_Input * 0.0003048; break;
                    case 'm': result = Distance_Input * .3048; break;
                    case 'f': result = Distance_Input; break;
                    case 'i': result = Distance_Input * 0.000189394; break;
                    default: printf("Invalid input."); return;
                }

                break;

            case 'i': // Miles
            switch (Distance_UnitTo){
                case 'k': result = Distance_Input * 1.60934; break;
                case 'm': result = Distance_Input * 1609.34; break;
                case 'f': result = Distance_Input * 5280; break;
                case 'i': result = Distance_Input; break;
                default: printf("Invalid Input."); return;
            }
                break;

            default:
                printf("Invalid unit to convert from.\n");
                return;
        }
        
        printf("%.4f %c is %.4f %c\n", Distance_Input, Distance_UnitFrom, result, Distance_UnitTo);
        printf("\n");
    //}
}

void temperatureConversions(float Temp_Input,  char Temp_UnitFrom, char Temp_UnitTo) {
    float result;
    int while_temp_flag = 1; //starts the flag for temperature


    if (Temp_Input < -110.0 || Temp_Input > 1000.0){
        printf("Distance must be between -110.0 and 1000.0.\n");
        return;
    }

    // temp loop
   //while (while_temp_flag != 0) {// temp while loop
 

        switch (Temp_UnitFrom) {
            case 'C': // Corrected to uppercase 'C'
                switch (Temp_UnitTo){
                    case 'C': result = Temp_Input; break;
                    case 'F': result = (Temp_Input * 9/5) + 32 ; break;
                    case 'K': result = Temp_Input + 273.15; break; 
                    default: printf("Invalid input."); return;
                }
                break;

            case 'F': // Corrected to uppercase 'F'
                switch (Temp_UnitTo){
                    case 'C': result = (Temp_Input -32) * (5.0/9.0) ; break; // Corrected to use floating-point division
                    case 'F': result = Temp_Input; break;
                    case 'K': result = (Temp_Input - 32) * 5.0/9.0 + 273.15; break; // Corrected to use floating-point division

                    default: printf("Invalid input.\n"); return;

                }
                break;

                case 'K': // Corrected to uppercase 'K'
                switch(Temp_UnitTo){
                    case 'C': result = Temp_Input  - 273.15; break;
                    case 'F': result = (Temp_Input - 273.15) * 9/5 + 32 ; break;
                    case 'K': result = Temp_Input; break;
                    default: printf("Invalid input.\n"); return;
                }
                break;

            default:
                printf("Invalid unit to convert from.\n");
                return;
        }
        
        printf("%.4f %c is %.4f %c\n", Temp_Input, Temp_UnitFrom, result, Temp_UnitTo);
        printf("\n");
    //}
}

int main() {
    int choice_number;
    int while_flag = 1; // flag for main switch
// ---------------------------
//          Distance
    float Distance_Input;
    char Distance_UnitFrom;
    char Distance_UnitTo;
// ---------------------------
//          Temprature
    float Temp_Input;
    char Temp_UnitFrom;
    char Temp_UnitTo;

    while (while_flag != 0) {
        //menu and menu choice
        printf("Convert Temperatures and Measurements\n1. Distance Conversion\n2. Temperature Conversion\n3. Quit\nChoice: ");
        scanf("%d", &choice_number);
        printf("\n");

        switch (choice_number) {
            case 1:
                printf("Enter the distance from 0.0 to 20000.1: ");
                scanf("%f", &Distance_Input);

                printf("Enter unit to convert from (k, m, f, i): ");
                scanf(" %c", &Distance_UnitFrom); // Add a space before %c

                printf("Enter unit to convert to (k, m, f, i): ");
                scanf(" %c", &Distance_UnitTo); // Add a space before %c

                distanceConversion( Distance_Input, Distance_UnitFrom, Distance_UnitTo);
                break;

            case 2:
                printf("Enter the temperature from -110.0 to 1000.0: ");
                scanf("%f", &Temp_Input);

                printf("Enter unit to convert from (C, F, K): ");
                scanf(" %c", &Temp_UnitFrom); // Add a space before %c

                printf("Enter unit to convert to (C, F, K): ");
                scanf(" %c", &Temp_UnitTo); // Add a space before %c
                
                temperatureConversions(Temp_Input, Temp_UnitFrom, Temp_UnitTo);
                break;

            case 3:
                while_flag = 0; //stops main menu
                break;
                
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
