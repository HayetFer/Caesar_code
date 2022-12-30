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
 void simplify (struct Message * msg){
    char* cpy=malloc(sizeof(char)*msg->taille);
    int i, j;
    int a = (int)msg->taille;
    printf("%d \n",a);
    for(i=0, j=0;i<a;i++){
         
        if(65<msg->texte[i] && msg->texte[i]<122){
            cpy[j]=msg->texte[i];
            j++;
        }
        else{
            continue;
        }
    }
    
    msg->texte=cpy;
 }
int main(){
    struct Message temp;
    alloueMsg(&temp, 25);
    temp.texte = "Hello my name is 9";
    simplify(&temp);
    printf(temp.texte);
    
    struct Message temp2;
    copieMsg(&temp, &temp2);
    free(&temp);
    free(&temp2);
    return 0;
}
