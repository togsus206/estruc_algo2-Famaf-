#include "dna.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct _node {
    nucleobase_t elem;
    struct _node *next;
};


dna_t dna_T(){
    dna_t nucli;
    nucli = malloc(sizeof(struct _node));
    if (nucli == NULL){
          printf("Se acabo la memoria.");
          exit(1);
    }
    nucli -> elem = 'T';
    nucli -> next = NULL;
    
    return(nucli);
}
    

dna_t dna_C(){
    dna_t nucli;
    nucli = malloc(sizeof(struct _node));
    if (nucli == NULL){
          printf("Se acabo la memoria.");
          exit(1);
    }
    nucli -> elem = 'C';
    nucli -> next = NULL;
    
    return(nucli);
}

dna_t dna_A(){
    dna_t nucli;
    nucli = malloc(sizeof(struct _node));
    if (nucli == NULL){
          printf("Se acabo la memoria.");
          exit(1);
    }
    nucli -> elem = 'A';
    nucli -> next = NULL;
    
    return(nucli);
}



dna_t dna_G(){
    dna_t nucli;
    nucli = malloc(sizeof(struct _node));
    if (nucli == NULL){
          printf("Se acabo la memoria.");
          exit(1);
    }
    nucli -> elem = 'G';
    nucli -> next = NULL;
    
    return(nucli);
}


dna_t dna_join(dna_t first, dna_t second){
     dna_t aux;
     dna_t aux2;
     aux = first;
     while(aux != NULL){
          aux2 = aux;
          aux = aux -> next;
     }
     aux2 -> next = second;
   
     return first;
}

unsigned int dna_length(dna_t dna){
       int largo = 0u;
       dna_t aux = dna;
       while(aux != NULL){
           largo++;
           aux = aux -> next;
       }

       return largo;
}


void dna_print(dna_t dna){
     dna_t aux = dna; 
     while(aux != NULL){
          printf("%c", aux->elem);
          aux = aux -> next;
     }
}

bool dna_is_prefix(dna_t first, dna_t second){
     dna_t aux = first;
     dna_t aux2 = second;
     
     bool p = true;
     while(aux != NULL && p){
           if (aux -> elem != aux2 -> elem){
                p = false;
           }
           else{ 
               aux = aux -> next;
               aux2 = aux2 -> next;
           }
     }
     
     return p;
}


bool dna_is_equal(dna_t first, dna_t second){
          return(dna_length(first) == dna_length(second) && dna_is_prefix(first,second));
}


/*
dna_t *dna_cut(dna_t dna, unsigned int count){
    dna_t *nucli;
    nucli = calloc(count, sizeof(struct _node));
    

    if (nucli == NULL) {
        printf("Se acabó la memoria");
        exit(1);
    }
    
    for (unsigned int j = 0; j == count; j++){
         nucli[j] -> elem = dna -> elem;
         dna = dna -> next;
    }
    nucli[count] -> next = NULL;

    dna_t a[2];
    a[0] = nucli;
    a[1] = dna;
 
    return a;
} 

*/

dna_t dna_destroy(dna_t dna){
       dna_t aux;
       while(dna != NULL){
            aux = dna -> next;
            free(dna);
            dna = aux;
       }
       return(dna);
}








