
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
        strcpy(copie->texte,msg->texte);
    }
    //--------------------3
    
    //--------------------a
    //remember how to access message->taille!
     void simplify (struct Message * msg){
        int a = msg->taille;
       char* cpy=malloc(sizeof(char)*a);
       int i,j;
        for(i=0,j=0;i<a;i++){
            if((65 <= msg->texte[i] && msg->texte[i] <= 90) || (97 <= msg->texte[i] && msg->texte[i] <= 122)){
            cpy[j]=msg->texte[i];
            j++;
            }
        }
        
       msg->texte=cpy;
       
    }
    
    
    
     
    //--------------------b
    char shift(char c, int k) {
        if (c >= 'a' && c <= 'z') {
            
            int shift = (c - 'a' + k) % 26;
            if (shift < 0) {
                shift += 26;
            }
            return 'a' + shift;
        } else if (c >= 'A' && c <= 'Z') {
            
            int shift = (c - 'A' + k) % 26;
            if (shift < 0) {
                shift += 26;
            }
            return 'A' + shift;
        } else {
            
            return c;
        }
    }

//--------------------c
    void do_cesar (struct Message * msg, int k, struct Message* res){
        int a = msg->taille;
        alloueMsg(res, a);
        int i = 0;
        do{
            res->texte[i]=shift(msg->texte[i],k);
        }
            
        while(msg->texte[++i]!='\0');
        res->texte[i] = '\0';
    
       
    }
    
//--------------------d
     void undo_cesar (struct Message * msg, int k, struct Message * res){
        int a = msg->taille;
        alloueMsg(res, a);
        int i = 0;
        do{
            res->texte[i]=shift(msg->texte[i],-k);
        }
            
        while(msg->texte[++i]!='\0');
        res->texte[i] = '\0';
    
       
     }

    
    int main(){
        struct Message temp;
        alloueMsg(&temp, 40);
        strcpy(temp.texte , "hello my98 name is ");
        simplify(&temp);
        printf("%s" , temp.texte);
        char c = 's';
        int b = 3; 
        printf("\n");
        printf("%c \n",shift(c, b));
        struct Message temp2;
        do_cesar(&temp, 3,&temp2);
        printf("%s \n", temp2.texte);
        struct Message temp3;
        undo_cesar(&temp2, 3,&temp3);
        printf("%s", temp3.texte);
        freeMsg(&temp);
        freeMsg(&temp2);
        return 0;
    }
