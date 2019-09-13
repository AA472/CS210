/*
 *File: main.c
 *MP7 - Endless Hordes of Zombies
 *Programmer: Abdullah Aljandali
 *Instructor: Dr.Donald Roberts
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_GRADES 20
#define MAX_NAMES 50


typedef struct{
    char name[MAX_NAMES];
    int id;
    int scores[MAX_GRADES];
    int num_scores;
} student_t;


student_t single_student(FILE* f);
double average_grade(student_t b);
void sort_names(student_t students[], int Num_students);
void swapper(student_t* a, student_t* b);
void copy_students(FILE* f,student_t students[],int count);
void print_report(student_t students[],int student_num);

int main()
{   int student_num;
    student_t *students;

    FILE* Input;
    char filename[30];
    printf("Welcome to the automated grade book program.\n");

    while(1){
        printf("Enter student data filename:");
        fgets(filename,30,stdin);
        filename[strlen(filename)-1] = '\0';
        Input = fopen(filename,"r");
        if (Input == NULL){
            printf("Unable to open %s. Try again.\n",filename);
        }else
            break;
    }

    fscanf(Input, "%d\n", &student_num);
    students =  malloc(sizeof(student_t)*student_num);
    copy_students(Input,students,student_num);
    sort_names(students,student_num);
    print_report(students,student_num);

    free(students);
    fclose(Input);
    return 0;
}

/*Takes an open file, reads a single student t from it and returns it.*/
student_t single_student(FILE* f){
    student_t a;
    fscanf(f, "%d\n", &a.id);
    fgets(a.name,50,f);
    a.name[strlen(a.name)-1] ='\0';

    int i=0;

    while(1){
        fscanf(f, "%d" , &(a.scores[i]));
        if (a.scores[i] == -99){
            i--;

            break;
        }
        i++;
    }

    a.num_scores = i;


    return a;
}

/*Takes a single student t and returns the average grade*/
double average_grade(student_t b){
    int i;
    int grades_sum =0;

    for (i=0;i<b.num_scores; i++){
        grades_sum+= b.scores[i];
    }
    if(b.num_scores == 0){
        return 0;
    }
    double average = grades_sum/b.num_scores;
    return average;
}

/*Given an array of student t and the number of elements in the array, sorts the array
by name.*/
void sort_names(student_t students[], int Num_students){

    student_t min;
    int i,j,k;
    for(j=0;j<Num_students;j++){
        for(min = students[j],i=j;i<Num_students;i++){
            if(strcmp(students[i].name,min.name)<0)
            {
                min = students[i];
                }

            }

        for(k=0;k<Num_students;k++){
            if(students[k].id== min.id)
                break;
        }
        swapper(&students[j],&students[k]);
        }
    }

/*Given two references to student t, swaps them*/
void swapper(student_t* a, student_t* b){
    student_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*takes an already open file, an array of student t, and a count and reads count
students from the file into the array.*/
void copy_students(FILE* f,student_t students[],int count){

    int i;
    for(i=0;i<count;i++){
        students[i] = single_student(f);
    }


}
/*given an array of student t and the number of elements, prints the entire report.*/
void print_report(student_t students[],int student_num){

    char letter_grades[student_num];
    int i;
    int j;

    for(i = 0; i< student_num; i++){
        if (average_grade(students[i])>=90)
            letter_grades[i] = 'A';
        if (average_grade(students[i])>=80 && average_grade(students[i]) <90)
            letter_grades[i] = 'B';
        if (average_grade(students[i])>=70 && average_grade(students[i]) <80)
            letter_grades[i] = 'C';
        if (average_grade(students[i])>=60 && average_grade(students[i]) <70)
            letter_grades[i] = 'D';
        if (average_grade(students[i])<60)
            letter_grades[i] = 'F';
    }

    printf("Name \t\t     ID   Average Grade  Scores\n");
    for(i=0;i<student_num;i++){
        printf("%-20s %4d %7.1lf %5c ",students[i].name,students[i].id,average_grade(students[i]), letter_grades[i]);
        for(j=0;j<students[i].num_scores;j++)
            printf("%3d ",students[i].scores[j]);
            printf("%3d\n",students[i].scores[students[i].num_scores]);
    }


}

