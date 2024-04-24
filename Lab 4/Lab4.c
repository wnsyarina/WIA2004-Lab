#include<stdio.h>
#define max 25

void main()
{
    int fragmentSize[max], b[max], f[max], i, j, numberOfBlocks, numberOfFiles, temp;
    static int bf[max], ff[max];

    printf("\nEnter the number of blocks:");
    scanf("%d", &numberOfBlocks);
    printf("Enter the number of files:");
    scanf("%d", &numberOfFiles);
    printf("\nEnter the size of the blocks:\n");
    for(i = 1; i <= numberOfBlocks; i++) {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the files:\n");
    for(i = 1; i <= numberOfFiles; i++) {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= numberOfFiles; i++)
    {
        int lowest = 10000; // Initialize lowest inside the loop
        for(j = 1; j <= numberOfBlocks; j++)
        {
            if(bf[j] != 1)
            {
                temp = b[j] - f[i];
                if(temp >= 0 && lowest > temp)
                {
                    ff[i] = j;
                    lowest = temp;
                }
            }
        }
        fragmentSize[i] = lowest;
        bf[ff[i]] = 1;
    }

    printf("\n------------------- Memory Allocation Table -----------------------------\n");
    printf("\nFile No    File Size\tBlock No\tBlock Size\tFragment");
    for(i = 1; i <= numberOfFiles && ff[i] != 0; i++)
        printf("\n%3d%13d%11d%18d%15d", i, f[i], ff[i], b[ff[i]], fragmentSize[i]);
}
