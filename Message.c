//Problèmes de mémoire à corriger et de recursion dans shift a partir de 3 essais
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
    msg->taille=taille;
    msg->texte=malloc(sizeof(char)*taille);
}
//------------------b
void freeMsg(struct Message *msg){
    msg->texte=NULL;
    msg->taille=0;
    msg=NULL;
}
void copieMsg(struct Message *msg, struct Message *copie){
    
    alloueMsg(copie, msg->taille);
    copie->texte=msg->texte;
}
//--------------------3

//--------------------a
//remember how to access message->taille!
 void simplify (struct Message * msg){
    int a = msg->taille;
   char* cpy=malloc(sizeof(char)*a);
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
    if('A'<=c<='Z'){
        
        
        if('A'<= (c + k) && (c+k)<='Z' ){
       // printf("%d" , c+k);
        g = c + k;
        return g;
        
    }
    else if((c + k)>'Z'){
       
        while(c<91){
           // printf(" \n al \n");
            c++;
            k--;
        }
        c='A';
       
        shift(c,k);
    }
    }

    if('a'<=c<='z'){
        
        
        if('a'<= (c + k) && (c+k)<='z' ){
        printf("%d" , c+k);
        g = c + k;
        return g;
        
    }
    else if((c + k)>'z'){
       
        while(c<91){
           // printf(" \n al \n");
            c++;
            k--;
        }
        c='a';
       
        shift(c,k);
    }
    }

    
    return g;
}



int main(){
    struct Message temp;
    alloueMsg(&temp, 40);
    strcpy(temp.texte , "hello my98 name is ");
    simplify(&temp);
    printf("%s" , temp.texte);
    char c = 'v';
    int b = 28; 
    printf("\n");
    printf("%c \n",shift(c, b));
    struct Message temp2;
    copieMsg(&temp, &temp2);
    freeMsg(&temp);
    freeMsg(&temp2);
    return 0;
}
