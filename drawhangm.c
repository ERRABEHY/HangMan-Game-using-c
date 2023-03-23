#include <stdio.h>      
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>
// the libraryies of all the fuctions ,prints and operations the will use here 
void body(int mistakes,char bodyman[]){
switch(mistakes) {
		case 0: bodyman[16] = '|',bodyman[17]='\\'; break;
		case 1: bodyman[14] = '|',bodyman[15]='\\'; break;
		case 2: bodyman[13] = 'O'; break;
		case 3: bodyman[12] = '|'; break;
		case 4: bodyman[11] = '_'; break;
		case 5: bodyman[10] = '_'; break;
		case 6: bodyman[9] = '_'; break;
		case 7: bodyman[8] = '_'; break;
    case 8: bodyman[7] = '|'; break;
		case 9: bodyman[6] = '|'; break;
		case 10: bodyman[5] = '|'; break;
		case 11: bodyman[4] = '|'; break;
		case 12: bodyman[3] = '|'; break;
		case 13: bodyman[2] = '-'; break;
		case 14: bodyman[1] = '-'; break;
		default: break;
}
	printf("\t\t\t\t\t%c%c%c%c\n"
	       "\t\t\t\t\t%c   %c\n"
	       "\t\t\t\t\t%c   %c\n"
	       "\t\t\t\t\t%c   %c%c\n"
	       "\t\t\t\t\t%c   %c%c\n"
	       "\t\t\t\t\t%c        \n "
		   "\t\t\t\t\t%c%c        \n ", bodyman[8], bodyman[9], bodyman[10],
	       bodyman[11], bodyman[7], bodyman[12], bodyman[6], bodyman[13],bodyman[5]
		   ,bodyman[14],bodyman[15],bodyman[4],bodyman[16],bodyman[17],bodyman[3],bodyman[2],bodyman[1]);
         }
// this function is work for draw the body of player
void unknown_fuction(char word[],char unknown[]){
  for ( int i = 0; i < strlen(word); i++)  
 { 
   printf(" %c",unknown[i] );
 } 
} 
// this function is work for give us unknown (the word with '*')
void serach_function(char guess,char unknown[],char word[],bool *letter_found,int *nbrfin){
   for (int  i = 0; i < strlen(word); i++)
      {   if (guess==word[i])
          { if (unknown[i]==guess) {
           *letter_found=false;
           }else{
              unknown[i]=guess;
             *letter_found=true; // if the word there 'letter_found is true'
              *nbrfin=*nbrfin+1;// nbrfin is number of final  is for if the stars word (unknown) be a word that is in the wordlist (unknow without stars)
           }
           }
      }
}
// search function is  work for give if the guess(the character that player enter) in our wordslist or not 
// we use pointer two time  to give us a new number for nbrfin and new answer for letter_found
void getout(char guess){
  if (guess=='O')
           {
            printf(" \n\t\t\t\tyou are get out from the game");
           }
}
void main () 
{
  char guess,accessguess; //the character that player wil enter 
  char wordslist[][8]={"morocco","oman","souria"}; // our wordslist 
  char word[8]; // a character to help us for seraching and printing 
  char unknown[]={'*','*','*','*','*','*','*'};
  int hearts,mistakes=0; // hearts is number of times that the player have when enter false 'word' 
  bool letter_found ,access;
  int nbrfin=0,level2,level3; // level2,level3 will use them to jump from level to level(when the guess of player is true of all characters in the'word' )
  char bodydraw[20]={'-'}; 
  printf(" \n\n\t\t\t\t\t -------------------- "   // presentation of hangman game  and some conditions for player
         " \n\t\t\t\t\t    HANGMAN GAME    \n "
         " \t\t\t\t\t -------------------- \n"
         " \n\n\t\t\t /* the hangman is game that the player guess letters of word"
         " \n\n\t\t\t /* the number of starts mean number of letters or alphabets in the word"
         " \n\n\t\t\t /* the player have 15 hearts in all levels that mean when you lose the 15 time YOU LOST!");
   printf("\n\n\t\t     Do you want to play (Y/N):");
   accessguess=getche();
   if (accessguess=='Y' || accessguess=='y')
   {
     access=true;
     printf(" \n\n\t\t\t /* let's start and GOOD LUCK ");
   }else{
     printf(" \n\n\t\t\t ..error....'404'.");
   } 
   srand(time(NULL));   
   int nbr= rand() % 3; // for every time the player out an in the word will change 
   strcpy(word,wordslist[nbr]);  // the wordslidt give the word that must player guess to 'word'
  while (mistakes!=16 && access==true)   //the mistakes is 15 but  plus one because the instruction will become first 
  {      
        letter_found=false;
        printf(" \n\t\t\tLEVEL 1/3 :---------------"); 
        printf(" || \3 \3 \3  : %d\n",hearts=15-mistakes);
        body(hearts,bodydraw);
        printf("\n\t\t\t\t");
        unknown_fuction(word,unknown);
        printf(" \n\t\t\t Give me a letter please: ");
        guess=getche(); //  when the player enter first thing in him keyboard the code  will enter in the next 
        serach_function(guess,unknown,word,&letter_found,&nbrfin);
        if (letter_found==true){ 
          printf("\n\n\t\t\t\t-------------------- \n");
          printf(" \n\t\t\t\tthe letter is true \1 \n "   );
          if (nbrfin==strlen(word)){ // for compare if the 'unknown' is become 'word'
           printf(" \n\t\t\tLEVEL 1/3 :---------------"); 
           printf(" || \3 \3 \3  : %d\n",hearts=15-mistakes);
           body(hearts,bodydraw);
           printf("\n\t\t\t\t      ");
           unknown_fuction(word,unknown); 
           printf("\n\t\t\t\t \1 CONGRATULATION \1 ");
           printf("\n\t\t\t\t   YOU  WIN THE LEVEL 1 ");
           printf("\n\n\t\t     Do you want to carry on to level 2 (Y/N):");
           accessguess=getche();
           if (accessguess=='Y')
           {
             level2=20;
           }else{
             printf(" \n\n\t\t\t ..error....'404'.");
           } 
           break;
          }
          }else{
           mistakes++;
           printf("\n\n\t\t\t\t-------------------- \n");
           printf(" \n\t\t\t\tthe letter is false \n");
           getout(guess);
          } 
   }       if (level2==20){
            char wordslist[][8]={"NIGER","kuwit","QATAR"};
            char unknown[]={'*','*','*','*','*'};
            srand(time(NULL));   
            int nbr= rand() % 3;
            strcpy(word,wordslist[nbr]);
            nbrfin=0;
  while (mistakes!=16)
 {          letter_found=false; 
            printf("\n\t\t\t\t-------------------- \n\t\t\t");
            printf("\t-------------------- \n\t\t\t\t");
            printf(" \n\t\t\tLEVEL 2/3 :---------------"); 
            printf(" || \3 \3 \3  : %d\n",hearts=15-mistakes);
            body(hearts,bodydraw);
            printf("\n\t\t\t\t      ");
            unknown_fuction(word,unknown);   
            printf(" \n\t\t\t Give me a letter please: ");
            guess=getche();
            serach_function(guess,unknown,word,&letter_found,&nbrfin);
            if (letter_found==true){   
              printf("\n\t\t\t\t-------------------- \n");
              printf(" \n\t\t\t\tthe letter is true \1 \n "   );
              if (nbrfin==strlen(word)){
                printf(" \n\t\t\tLEVEL 1/3 :---------------"); 
                printf(" || \3 \3 \3  : %d\n",hearts=15-mistakes);
                body(hearts,bodydraw);
                printf("\n\t\t\t\t      ");
                unknown_fuction(word,unknown);
                printf("\n\t\t\t\t \1 CONGRATULATION  \1 ");
                printf("\n\t\t\t\t   YOU WIN THE LEVEL 2 ");
           printf("\n\n\t\t     Do you want to carry on to level 3 (Y/N):");
           accessguess=getche();
           if (accessguess=='Y' || accessguess=='y')
           {
             level3=10;
           }else{
             printf(" \n\n\t\t\t ..error....'404'.");
           } 
           break;
                break;
                }
            }else{
                mistakes++;
                printf("\n\t\t\t\t-------------------- \n");
                printf(" \n\t\t\t\tthe letter is false \n");
              } 
    }         }
          if (level3==10){ 
              nbrfin=0;;
              char wordslist[][10]={"US","thailand","palestine","MALI","china"};
              char unknown[]={'*','*','*','*','*','*','*','*','*'};
              int number_of_character,accessibility;
              printf("\n\t\t\t\t-------------------- \n\t\t\t");
              printf("\t-------------------- \n\t\t\t\t");
              printf(" \t\t\tLEVEL 3 : ");
              printf("\n\t\t\t\t-------------------- \n\t\t\t\t");
              printf("enter the number of letters word: ");
              scanf("%d",&number_of_character);
              for ( int i = 0; i < number_of_character; i++){
              if (number_of_character==strlen(wordslist[i])){
               accessibility=20;
               strcpy(word,wordslist[i]);   //accessibilty is for if siez that player enter is in our wordslist
              }
              }
  while (mistakes!=16 && accessibility==20)
  {            letter_found=false; 
               printf("\n\t\t\t\t-------------------- \n\t\t\t");
               printf(" \n\t\t\tLEVEL 3/3 :---------------"); 
               printf(" || \3 \3 \3  : %d\n",hearts=15-mistakes);
               body(hearts,bodydraw);
               printf("\n\t\t\t\t");
               unknown_fuction(word,unknown);
               printf(" \n\t\t\t Give me a letter please: ");
               guess=getche();
               serach_function(guess,unknown,word,&letter_found,&nbrfin);
              if (letter_found==true){
              printf("\n\t\t\t\t-------------------- \n");
              printf(" \n\t\t\t\tthe letter is true \1 \n "   );
              if (nbrfin==strlen(word))
                {
                 printf(" \n\t\t\tLEVEL 1/3 :---------------"); 
                 printf(" || \3 \3 \3  : %d\n",hearts=15-mistakes);
                 body(hearts,bodydraw);
                 printf("\n\t\t\t\t  ");
                 unknown_fuction(word,unknown);
                 printf("\n\t\t\t\t \1 CONGRATULATION  \1 ");
                 printf("\n\t\t\t\t    YOU WIN ,  YOU ARE AMAZING  ");
                 break;
                }
              }else{ 
                mistakes++;
                printf("\n\t\t\t\t-------------------- \n");
                printf(" \n\t\t\t\tthe letter is false \n");
             }
             }
       }
        if(mistakes==16)
        {
        printf("\n\t\t\t\t***********************");
        printf(" GAME OVER");
        printf("***********************\n");
        printf("\n   \t\t\t\t\t  **********");
        printf("the word is %s ",word);
        printf("**********          \n");
       }
       // when player not guess the characters that is the word 15 times will see this with the 'word'
    getch();
}

