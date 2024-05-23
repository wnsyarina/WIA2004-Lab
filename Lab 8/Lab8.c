#include <stdio.h>  
int main()  {  
  
    int numPageFrames;
    int numOfPages;
    int pageFaults = 0;  
    int hits;  
    
    printf("Enter number of Page Frames: ");
    scanf("%d", &numPageFrames);
    
    printf("Enter the number of Pages: ");
    scanf("%d", &numOfPages);
    
    int pageFrames[numPageFrames];
    int pages[numOfPages];
    
    printf("Enter pages in sequence :\n");
    for(int i = 0; i < numOfPages; i++) {
        scanf("%d", &pages[i]);
    }
    
    printf("Sequence");
    
    for (int k = 0; k <numPageFrames; k++) {
        printf("\t Frame %d", k+1);  
    }
    
    for(int j = 0; j < numPageFrames; j++) {  
        pageFrames[j] = -1;  
    }  
    
    for(int v = 0; v <numOfPages; v++){  
        hits = 0;   
        for(int n = 0; n <numPageFrames; n++){  
            
            if(pages[v] == pageFrames[n]){  
                hits++;  
                break;
            }  
        }  
        
        if(hits == 0){  
          pageFaults++;  
          pageFrames[(pageFaults - 1) % numPageFrames] = pages[v];  
        } 
    
        printf("\n");  
        printf("%d\t\t\t",pages[v]);  
        
        for(int n = 0; n <numPageFrames; n++){  
            if(pageFrames[n] != -1)  {
                printf(" %d\t\t\t ", pageFrames[n]);  
            }
       
        }  
         
    }
    
    printf("\n"); 
    printf("\nTotal Page Faults:\t%d\n", pageFaults); 
    printf("Total Page Hits:\t%d\n", numOfPages-pageFaults); 
    
    return 0;  
}  


