#include "dna.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef TEST

int main(){
//comienzo primera cadena   
   unsigned int largo;
   printf("De el largo de una cadena de DNA:");
   scanf("%u",&largo);


   dna_t primero = NULL;

   char t;
   printf("Escriba el primer nucleotido T,A,C o G (Mayusculas): ");
   scanf("%s",&t);



        if (t == 'T'){
            primero = dna_T();
            
         }
         else if (t == 'A'){
            primero = dna_A();
            
         }
         else if (t == 'C'){
            primero = dna_C();
            
         }
         else if (t == 'G'){
            primero = dna_G();
            
         }
         else {
           printf("Usted no digito un nucleotido correcto.");
           printf("\n");
           exit(1);
         }



   for(unsigned int i= 2; i <= largo; i++){
        char c;
        printf("Escriba un nucleotido T,A,C o G (Mayusculas): ");
        scanf("%s",&c);
   
        if (c == 'T'){
          dna_t nucli = dna_T();
          primero = dna_join(primero,nucli);
          
        }
        else if (c == 'A'){
          dna_t nucli = dna_A();
          primero = dna_join(primero,nucli);
          
        }
        else if (c == 'C'){
          dna_t nucli = dna_C();
          primero = dna_join(primero,nucli);
          
        }
        else if (c == 'G'){
          dna_t nucli = dna_G();
          primero = dna_join(primero,nucli);
          
       }
       else {
          printf("Usted no digito un nucleotido correcto.");
          printf("\n");
          i--;
       }
   }

   printf("Su cadena de nucleotidos es: \n");
   dna_print(primero);
   printf("\n");
   printf("Ademas, tiene una longitud de: \n");
   printf("%u",dna_length(primero));
   printf("\n");
   
//final primera cadena

//comienzo segunda cadena
   unsigned int largo2;
   printf("De el largo de otra cadena de DNA: ");
   scanf("%u",&largo2);
  
   dna_t segundo = NULL;

   char y;
   printf("Escriba el primer nucleotido T,A,C o G (Mayusculas): ");
   scanf("%s",&y);


   if (y == 'T'){
      segundo = dna_T();
            
   }
   else if (y == 'A'){
      segundo = dna_A();
            
   }
   else if (y == 'C'){
        segundo = dna_C();
            
   }
   else if (y == 'G'){
      segundo = dna_G();
            
   }
   else {
      printf("Usted no digito un nucleotido correcto.");
      printf("\n");
      exit(1);
   }


   for(unsigned int j= 2; j <= largo2; j++){
        char r;
        printf("Escriba un nucleotido T,A,C o G (Mayusculas): ");
        scanf("%s",&r);
   
        if (r == 'T'){
          dna_t nucli = dna_T();
          segundo = dna_join(segundo,nucli);
          
        }
        else if (r == 'A'){
          dna_t nucli = dna_A();
          segundo = dna_join(segundo,nucli);
          
        }
        else if (r == 'C'){
          dna_t nucli = dna_C();
          segundo = dna_join(segundo,nucli);
          
        }
        else if (r == 'G'){
          dna_t nucli = dna_G();
          segundo = dna_join(segundo,nucli);
          
       }
       else {
          printf("Usted no digito un nucleotido correcto.");
          printf("\n");
          j--;
       }
   }

   
   printf("Su segunda cadena de nucleotidos es: \n");
   dna_print(segundo);
   printf("\n");
   printf("Ademas, tiene una longitud de: \n");
   printf("%u",dna_length(segundo));
   printf("\n");
   


  
   if (dna_length(primero) == dna_length(segundo)){
          bool q = dna_is_equal(primero, segundo);
          if (q){
               printf("\n");
               printf("Sus dos cadenas son iguales\n");
          }
   }
   else{
               printf("\n");
               printf("Sus dos cadenas no son iguales\n");  
   }
   
   if (dna_length(primero) >= dna_length(segundo)){
           bool u = dna_is_prefix(primero,segundo);
           if (u){
               printf("\n");
               printf("su primer DNA es prefijo del segundo");
           }
   }
   
   if (dna_length(primero) < dna_length(segundo)){ 
        bool z = dna_is_prefix(segundo,primero);
        if (z){
           printf("\n");
           printf("su segundo DNA es prefijo del primero");
        }
        else{
           printf("\n");
           printf("su segundo DNA NO es prefijo del primero");
           printf("\n");
        }
   }
   
   
//final segunda cadena   
   dna_destroy(primero);
   dna_destroy(segundo);


   
    return (0);
}

#endif
