#include <stdio.h>
#include <stdlib.h>

/*
 *MP3 - Zombie Identification System
 *Author: Abdullah Aljandali
 */

char response;
int Num_Yes;
int probability;
int Calculate_Number_Of_Yes_Answers(char response);

int main()
{

    while(1){

        printf("Zombie Identification System\n");
        printf("Please answer the following questions regarding the subject:\n\n");

        Num_Yes = 0;
        printf("Does the subject have a glazed over look? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Is the subject moaning? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Is the subject missing any limbs? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Does the subject have pale or gray skin? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Does the subject have any exposed organs? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Is the subject on fire without showing pain? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Does the subject show little response to objects in its path? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Is the subject limping? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Is the subject wearing a jacket with shoulder pads? (y/n):");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);
        printf("Does subject crave brains and its not the first full week of October? (y/n):\n");
        Num_Yes +=  Calculate_Number_Of_Yes_Answers(response);

        probability = 0;
        probability = Num_Yes * 10 ;
        printf("Probability of zombiehood = %.0d%%\n",probability);

        if(probability >= 50){
                printf("RUN!\n\n");

        }else{
            printf("Potential Ally! Sober them up!\n\n");
            }

        char repeat;
        printf("Do you wish to identify another target? (y/n):");
        scanf(" %c",&repeat);
        repeat = tolower(repeat);

         while(repeat!= 'y' && repeat!='n')
        {
            printf("Please enter 'y' or 'n':");
            scanf(" %c",&repeat);
        }
        if(repeat=='n')
        {
            break;
        }



    }

    return 0;
}

int Calculate_Number_Of_Yes_Answers(char response){
    scanf(" %c", &response);
    response = tolower(response);
    while(response!= 'y' && response!='n')
        {
            printf("Please enter 'y' or 'n':");
            scanf(" %c",&response);
        }
        if (response == 'n'){
          return  0;
        }else if (response == 'y'){
           return  1;
        }

}




