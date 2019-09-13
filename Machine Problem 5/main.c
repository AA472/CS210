#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_STR 1000

 void  translate_word(char English_word[],char Zombie_word[]);


int main()
{
    char English_word[100];
    char Zombie_word[100];
    strcmp(English_word, "hellar");
    Zombie_word[0] ='\0';

    translate_word(English_word,Zombie_word);

    printf("%s",Zombie_word);
    return 0;
}

 void  translate_word(char English_word[], char Zombie_word[]){


    int  Eng_word_length =0;
    int i;

    if(strcmp(English_word,"a")==0 || strcmp(English_word,"A")==0){
        strcpy(Zombie_word,"hra");
    }
   else{ for(i=0; English_word[i] != '\0'; i++){

        char a[2];
        a[1] = '\0';
        a[0] = English_word[i];

        if (strchr("zhrgbmna",English_word[i])){
            strcat(Zombie_word,a);}

        if(strchr("eiou", English_word[i])){
            strcat(Zombie_word,"r");}
    }

    if(Zombie_word[i-1] == 'r'){
        strcat(Zombie_word,"h");}
   }

 }




