#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellsort(int vet[], int n){
	
	int gap= 1;
	
	int j= 0;
	
    int aux= 0;
	
	
	while(gap<n){

        gap= 3 * gap+1;
    }   

        while(gap>0){

            gap= gap/3;
	        for(int i=gap; i<n; i++){
	        
	            j=i;
	            aux= vet[i];
	        
	        
	
	
	            while(j>= gap && vet[j-gap]>aux){
	    
	            vet[j]=vet[j-gap];
	            j= j-gap;
	 
	    
	            }
	
                vet[j]= aux;	
	            
	
	    
	            
	    
            }
	       
	    }
    
}