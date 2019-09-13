/*
 *File: main
 *MP4 - Zombie Infection Model
 *Programmer: Abdullah Aljandali
 *Instructor: Donald Roberts
 */
#include <stdio.h>
#include <stdlib.h>

/* getData: Collects data from user, the initial population and infection rate.*/
void get_Data(double *Inf_rate, int * In_pop);
/*Generate_Report: Generate a file that displays the results(change in humans and zombies over time)*/
void Generate_Report(double Inf_rate, int In_pop);


int main()
{

    printf("Zombie Infection Model\n");
    int In_pop;
    double Inf_rate;

    get_Data(&Inf_rate,&In_pop);
    Generate_Report(Inf_rate,  In_pop);

return 0;
}


void get_Data(double *Inf_rate, int * In_pop){

    int Initial_Population;
    double Infection_Rate;

    printf("Please enter initial population:");
    scanf("%d", &Initial_Population);

    while(Initial_Population < 0){
        printf("Population must be non-negative. Try again.\n");
        printf("Please enter initial population:");
        scanf("%d", &Initial_Population);
    }
    printf("Please enter infection rate as a decimal (e.g. 25%% = 0.25):");
    scanf("%lf", &Infection_Rate);

    while(Infection_Rate >1 || Infection_Rate < 0){
        printf("Infection rate must be between 0 and 1 inclusive. Try again.\n");
        printf("Please enter infection rate as a decimal (e.g. 25%% = 0.25):");
        scanf("%lf", &Infection_Rate);
    }
    printf("Report generated!\n");
    *Inf_rate = Infection_Rate;
    *In_pop = Initial_Population;
}

void Generate_Report(double Inf_rate, int In_pop){

    FILE* out_file;
    out_file = fopen("modelOutput.txt", "w");
    if (out_file == NULL) {
        printf("Unable to open modelOutput.txt\n");
}

    int Delta;
    int Zombie_Population;
    int Human_Population;
    int time;

    time = 1;
    Zombie_Population = 1;
    Human_Population = In_pop;
    fprintf(out_file, " Time\t      Humans\t     Zombies\n");
    while (Human_Population > 0){
         if (Inf_rate * Zombie_Population * Human_Population < Human_Population){
            Delta = Inf_rate * Zombie_Population * Human_Population;
         }else{
             Delta = Human_Population;}
         fprintf(out_file,"%5d\t%12d\t%12d\n", time, Human_Population, Zombie_Population);
         Human_Population = Human_Population - Delta;
         Zombie_Population = Zombie_Population + Delta;
         time++;
}

    fprintf(out_file,"%5d\t%12d\t%12d\n", time, Human_Population, Zombie_Population);
    fclose(out_file);

}
