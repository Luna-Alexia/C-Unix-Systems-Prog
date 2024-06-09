#include  <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>

 //struct 
    struct Grades {
        char name[1000];
        float assignment;
        float midterm;
        float final;
        float percentage;
        char letter[3];

    };

int main(){
    
    // open file
    FILE *fp;
    fp = fopen("students.csv","r");

       
    struct Grades students[100];
    int numStudent = 0;
    int A = 0 , Bplus = 0, B = 0, Cplus = 0, C = 0, D = 0, F = 0;
    float totalAssignment = 0, totalMid = 0, totalFinal = 0;
     

     //reads file seperated by commas and by three (include assignment mid and final)
    while (fscanf(fp, "%[^,],%f,%f,%f\n", students[numStudent].name, &students[numStudent].assignment, &students[numStudent].midterm, &students[numStudent].final) == 4) 
    {  
        
        // calc percentage grade
        students[numStudent].percentage = (0.4 * students[numStudent].assignment) + (0.3 * students[numStudent].midterm) + (0.3 * students[numStudent].final);


        //if spam
        if (students[numStudent].percentage >= 90){
            strcpy(students[numStudent].letter, "A");
            A++;
        } 
        else if (students[numStudent].percentage >= 85){
            strcpy(students[numStudent].letter, "B+");
            Bplus++;
        } 
        else if (students[numStudent].percentage >= 80){
            strcpy(students[numStudent].letter, "B");
            B++;
        } 
        else if (students[numStudent].percentage >= 75){
            strcpy(students[numStudent].letter, "C+");
            Cplus++;
        } 
        else if (students[numStudent].percentage >= 70){
            strcpy(students[numStudent].letter, "C");
            C++;
        } 
        else if (students[numStudent].percentage >= 60) {
            strcpy(students[numStudent].letter, "D");
            D++;
        } 
        else {
            strcpy(students[numStudent].letter, "F");
            F++;
        }


    // add up totals

    totalAssignment += students[numStudent].assignment;
    totalMid += students[numStudent].midterm;
    totalFinal += students[numStudent].final;

    // moves up a student (incrementing)
    numStudent ++;
    };



    // close reading file
    fclose(fp);


    //average calc
    float avgAssignments = totalAssignment / numStudent;
    float avgMid = totalMid / numStudent;
    float avgFinal = totalFinal / numStudent;



  //output time
   
    printf("Total Students: %d\n\n", numStudent);
    printf("Number of A's: %d\n", A);
    printf("Number of B+'s: %d\n", Bplus);
    printf("Number of B's: %d\n", B);
    printf("Number of C+'s: %d\n", Cplus);
    printf("Number of C's: %d\n", C);
    printf("Number of D's: %d\n", D);
    printf("Number of F's: %d\n\n", F);


//ouput file time
 fp = fopen("final.txt", "w");
    if (fp == NULL){ // if file for some reason is unable to be opened
        printf("ERROR, cannot open file. \n");
        return 1;
    };

    for (int i = 0; i < numStudent; i++) {
            fprintf(fp, "%s %.2f %s\n", students[i].name, students[i].percentage, students[i].letter);
            printf("%s %.2f %s\n", students[i].name, students[i].percentage, students[i].letter);
    }   


    fprintf(fp, "\nTotal Students: %d\n", numStudent);
    fprintf(fp, "\nAverage Assignments Grade: %.2f\n", avgAssignments);
    fprintf(fp, "Average Midterm Exam Grade: %.2f\n", avgMid);
    fprintf(fp, "Average Final Exam Grade: %.2f\n\n", avgFinal);

    fprintf(fp,"\nNumber of A's: %d\n", A);
    fprintf(fp,"Number of B+'s: %d\n", Bplus);
    fprintf(fp,"Number of B's: %d\n", B);
    fprintf(fp,"Number of C+'s: %d\n", Cplus);
    fprintf(fp,"Number of C's: %d\n", C);
    fprintf(fp,"Number of D's: %d\n", D);
    fprintf(fp,"Number of F's: %d", F);

    fclose(fp);


    return 0;
}
