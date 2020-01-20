#include <stdio.h>
#include <stdlib.h>
struct mydatatype{
int i;
char ch;
}inputValue();
void run();
int check(char symbol[9],char ch[1],int count);
struct mydatatype inputValue(char symbol[9],int count);
void display(char sym[9]);

int main()
{
    char choice[1];
    restart:
    run();
    printf("\n\nIf you want to play again ? \n press 1 \n or press any key    : ");
    scanf("%s",choice);
    if(*choice=='1'){
        system("cls");
        goto restart;
    }
    else{
        exit(0);
    }
    return 0;
}
void run(){
    int count ;
    struct mydatatype info;
    char symbol[9]={'1','2','3','4','5','6','7','8','9'};
    display(symbol);
    again:
    info = inputValue(symbol,count);
    symbol[info.i]=info.ch;
    system("cls");
    display(symbol);
    if(check(symbol,info.ch,count)==1);
    else{
    count++;
    goto again;
    }
}
int check(char sym[9],char ch[1],int count){
    int i;
    for(i=0;i<3;i++)
        if(sym[i]==ch && sym[i+1]==ch && sym[i+2]==ch){
            printf("\n\n\t\t THE WINNER IS %c",ch);return 1;
        }
    for(i=0;i<3;i++)
        if(sym[i]==ch && sym[i+3]==ch && sym[i+6]==ch){
            printf("\n\n\t\t THE WINNER IS %c",ch);return 1;
    }
      if(sym[0]==ch && sym[4]==ch && sym[8]==ch){
            printf("\n\n\t\t THE WINNER IS %c",ch);return 1;}
      else if(sym[2]==ch && sym[4]==ch && sym[6]==ch){
            printf("\n\n\t\t THE WINNER IS %s",ch);return 1;}
      else if(count == 8){
        printf("THE GAME IS DRAW");return 1;
      }
      else{
        return 0;
      }

}


struct mydatatype inputValue(char symbol[9],int count){
    int i;
    char value[1];
    struct mydatatype info;
    InputAgain:
    if(count%2==0){
        printf("\nEnter the your choice X :  ");
    }else{
        printf("\nEnter the your choice O :   ");
    }
    scanf("%s",value);
    for(i=0;i<9;i++)
    {
        if(*value==symbol[i])
        {
            info.i=i;
            if(count%2==0)
                info.ch='X';
            else
                info.ch='O';
             break;
        }else{
            info.i =- 1;
            info.ch =" ";
        }
    }
    if(info.i==-1){
        printf("Invalid Input");
        goto InputAgain;
    }
    return info;
}

void display(char sym[9]){
    printf("\n\t\t\t --------------------------------- ");
    printf("\n\t\t\t |    T I C    T A C    T O E    |");
    printf("\n\t\t\t --------------------------------- ");
    printf("\n\n PLAYER 1 SYMBOL : X");
    printf("\n PLAYER 2 SYMBOL : O");
    printf("\n\n");
    printf("\n\t\t\t |----------|----------|----------|");
    printf("\n\t\t\t |     %c    |    %c     |    %c     |",sym[0],sym[1],sym[2]);
    printf("\n\t\t\t |----------|----------|----------|");
    printf("\n\t\t\t |     %c    |    %c     |    %c     |",sym[3],sym[4],sym[5]);
    printf("\n\t\t\t |----------|----------|----------|");
    printf("\n\t\t\t |     %c    |    %c     |    %c     |",sym[6],sym[7],sym[8]);
    printf("\n\t\t\t |----------|----------|----------|\n\n");

}
