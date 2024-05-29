#include <stdio.h>
#include <math.h>

int totalph,status[20], totalhungry, hu[20];

int main()
{
    printf("\n\nDINING PHILOSOPHER PROBLEM");
    printf("\nEnter the total number of philosophers: ");
    scanf("%d", &totalph);
    // Store status of philosopher
    for (i = 0; i < totalph; i++)
    {
        status[i] = 1; // Status 1 means thinking
    }

    printf("How many are hungry: ");
    scanf("%d", &totalhungry);

    // Check if all are hungry
    if (totalhungry == totalph)
    {
        printf("\nAll philosophers are hungry! Deadlock will occur!");
        printf("\nExit the programs\n");
        return 0;
    }
    // If not all are hungry
    else
    {
        printf("Enter hungry philosopher position: ");
        for (i = 0; i < totalhungry; i++)
        {
            scanf("%d",&hu[i]);
            status[hu[i]] = 2; // Status 2 means hungry
        }

        allowEating();
    }
    return 0;
}

void allowEating()
{
    int i, j;

    for (i = 0; i < totalhungry; i++)
    {
        // Check side by side philosophers
        int left = hu[i] - 1;
        int right = (hu[i] + 1) % totalph;
        int conflict = 0;

        // Check for conflicts with other philosophers
        for (j = 0; j < totalhungry; j++)
        {
            if (hu[j] == left || hu[j] == right)
            {
                conflict = 1;
                break;
            }
        }

        if (!conflict)
        {
            status[hu[i]]= 3; // Mark philosopher as able to eat
        }
    }

    //display output
    printf("\nPhilosopher states : \n");
    for(int i =0;i<totalph;i++){
    if (status[i] == 3){
            printf("\nP %d is eating", i+1);
    }
    else if (status[i] == 2){
            printf("\nP %d is waiting", i+1);

    }else{
            printf("\nP %d is thinking", i+1);
    }
    }
}

