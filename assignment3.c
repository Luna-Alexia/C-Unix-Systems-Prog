#include <stdio.h>

int main() {
    int choice_number;
    int while_flag = 1; // flag for outer switch

    while (while_flag != 0) {

        //menu and menu choice
        printf("Convert Temperatures and Measurements\n1. Distance Conversion\n2. Temperature Conversion\n3. Quit\nChoice: ");
        scanf("%d", &choice_number);

        switch (choice_number) {
            case 1: {
                int Distance_choice;
                int while_distance_flag = 1; // starts the flag for distance math

                while (while_distance_flag != 0) {// distance while loop
                    printf("Distance Converter\n1. Kilometers to Miles\n2. Miles to Kilometers\n3. Main Menu\n4. Quit\nChoice: ");
                    scanf("%d", &Distance_choice);

                    switch (Distance_choice) {
                        case 1: {
                            float kilometers;
                            printf("Enter a distance in Kilometers: ");
                            scanf("%f", &kilometers);

                            if (kilometers <= 0.0) 
                            {
                                printf("Cannot be below or equal to 0.0\n");
                            } 

                            else if (kilometers > 20000.1) 
                            {
                                printf("Number too large.\n");
                            } 

                            else {
                                //math conversion for k to m (used google to find deci value)
                                printf("%.2f Kilometers is %.2f Miles\n",kilometers, kilometers * 0.621371);
                            }

                            break;
                        }

                        case 2: {
                            float miles;
                            printf("Enter a distance in Miles: ");
                            scanf("%f", &miles);

                            //condtionals
                            if (miles <= 0.0) {
                                printf("Cannot be below or equal to 0.0\n");
                            } else if (miles > 20000.1) {
                                printf("Number too large.\n");
                            } else {
                                // math for m to k (google for deci value)
                                printf("%.2f Miles is %.2f Kilometers\n", miles, miles * 1.60934);
                            }
                            break;
                        }

                        case 3:
                            while_distance_flag = 0; // return to main menu 
                            break;

                        case 4:
                            exit(0); //terminate program
                            return(0);
                            break;
                    }
                }
                break; //distance break
            }


            case 2: {
                int Temperature_choice;
                int while_temp_flag = 1; //starts the flag for temperature

                // temp loop
                while (while_temp_flag != 0) { 
                    printf("Temperature Converter\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Main Menu\n4. Quit\nChoice: ");
                    scanf("%d", &Temperature_choice);

                    switch (Temperature_choice) {
                        case 1: {
                            float Celsius;
                            printf("Enter a temp in Celsius: ");
                            scanf("%f", &Celsius);

                            // conditionals
                            if (Celsius < -110.0) 
                            {
                                printf("Cannot be below -110.0");
                            } 
                            
                            else if (Celsius > 1000.0) 
                            {
                                printf("Number too large.");
                            } 

                            else 
                            {
                                // c to F dimensional analysis
                                printf("%.2f Celsius is %.2f Fahrenheit\n",Celsius, (Celsius * 9/5) + 32);
                            }

                            break;
                        }

                        case 2: {
                            float Fahrenheit;
                            printf("Enter a temp in Fahrenheit: ");
                            scanf("%f", &Fahrenheit);

                            // conditionals
                            if (Fahrenheit < -110.0) 
                            {
                                printf("Cannot be below -110.0");
                            } 

                            else if (Fahrenheit > 1000.0) 
                            {
                                printf("Number too large.");
                            } 

                            else 
                            {
                                // F to c dimensional analysis
                                printf("%.2f Fahrenheit is %.2f Celsius\n",Fahrenheit, (Fahrenheit - 32) * 5/9);
                            }

                            break;
                        }
                        case 3:
                            while_temp_flag = 0; // return to main menu
                            break;


                        case 4:
                            exit(0);
                            return(0);
                            break;
                    }
                }
                break; //temperature break
            }
            
            case 3: {
                while_flag = 0; //stops main menu 
                break; //outer switch break
            }
            
        }// <--- outer switch (personal)

    }// <-- outer while (personal notes)

    return 0; // <--main (personal notes)
}