#include <stdio.h>

//prototipos de funcao
float calculateAverage(int grades[], int size);
int findHighestGrade(int grades[], int size);
char determineLetterGrade(int grade);

int main() {
    int size;
    scanf("%d", &size);
    int grades[size];
    for(int i = 0; i < size; i++){
        scanf("%d", &grades[i]);
    }
    
    printf("Average grade: %.2f\n", calculateAverage(grades, size));
    printf("Highest grade: %d\n\n", findHighestGrade(grades, size));
    
    printf("Student Grades:\n");
    for(int i = 0; i < size; i++){
        printf("Student %d: %d - %c\n",i+1, grades[i], determineLetterGrade(grades[i]));
    }
    
    return 0;
}

float calculateAverage(int grades[], int size) {
    float sum = 0.0;
    for(int i = 0; i < size; i++){
            sum += grades[i];
    }
    return sum/size;
}

int findHighestGrade(int grades[], int size) {
    int highest_grade = 0;
    for(int i = 0; i < size; i++){
        if(grades[i] > highest_grade){
            highest_grade = grades[i];
        }
    }
    return highest_grade; 
}

char determineLetterGrade(int grade) {
    grade /= 10;
    if(grade == 10 || grade == 9){
        return 'A';
    }
    else if(grade == 8){
        return 'B';
    }
    else if(grade == 7){
        return 'C';
    }
    else if(grade == 6){
        return 'D';
    }
    else{
        return 'F';
    } 
}