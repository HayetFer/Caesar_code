#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------1
struct Message{
    char* texte;
    int taille;
};
//-------------------2

//--------------------a
void alloueMsg (struct Message * msg, int taille){
    msg = malloc(sizeof(struct Message));
    
    msg->texte=malloc(sizeof(char)*taille);
    msg->taille=taille;

}
//------------------b
void freeMsg(struct Message *msg){
    free(msg->texte);
    free(&msg);
}
void copieMsg(struct Message *msg, struct Message *copie){
    
    alloueMsg(copie, msg->taille);
    copie->texte=msg->texte;
}
//--------------------3

//--------------------a
//remember how to access message->taille!
 void simplify (struct Message * msg){
    char* cpy=malloc(sizeof(char)*25);
   int i,j;
    for(i=0,j=0;i<25;i++){
        if((65 <= msg->texte[i] && msg->texte[i] <= 90) || (97 <= msg->texte[i] && msg->texte[i] <= 122)){
        cpy[j]=msg->texte[i];
        j++;
        }
    }
    
   msg->texte=cpy;
}



 
//--------------------b
//---------A FINIR 
char shift (char c, int k){
    
    char g = ' ';
    if(65< (c + k) && (c + k)<90){
        char g = c + k;
        return g;
    }
    else if(96< (c + k) && (c+k)<123 ){
        char g = c + k;
        return g;
    }
    else if((c + k)>='A' && (c + k)<='Z'){
      
        while(c<91){
            printf(" \n al \n");
            c++;
            k--;
        }
        c='A';
        c+=k;
        g=c;
        return g;
    }
    
    return g;
}



int main(){
    struct Message temp;
    alloueMsg(&temp, 25);
    temp.texte = "Hello my name are 9 but";
    simplify(&temp);
   // printf("%s \n",temp.texte);
    char c = 'g';
    int b = 1; 
    printf("\n");
    printf("%c \n",shift(c, b));
    struct Message temp2;
    copieMsg(&temp, &temp2);
    free(&temp);
    free(&temp2);
    return 0;
}
