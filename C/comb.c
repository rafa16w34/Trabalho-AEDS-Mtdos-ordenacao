#include "comb.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void combsort(int vet[], int n){

    int gap= n;
    
    int troca =1;
    
    int aux;
    
    
    while(gap!= 1 || troca != 0){
        
        gap= gap/1.3;
        
        if(gap< 1){
            
            gap= 1;
        }
        
        troca = 0;
        
        for(int i=0; i+ gap<n; i++){
            
            if(vet[i]>vet[i+gap]){
                
                aux=vet[i];
                vet[i]= vet[i+gap];
                vet[i+gap]= aux;
            
                troca++;
            }
            
            
            
        }
        
        
    }
} 







