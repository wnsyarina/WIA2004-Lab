#include <stdio.h>
#define max 25

void main() {
  int b[max], p[max], i, j, numberOfBlocks, numberOfProcesses;
  int allocated[max]; // Array to track allocated blocks

  printf("\nEnter the number of blocks:");
  scanf("%d", &numberOfBlocks);
  printf("Enter the number of processes:");
  scanf("%d", &numberOfProcesses);

  printf("\nEnter the size of the blocks:\n");
  for (i = 1; i <= numberOfBlocks; i++) {
    printf("Block %d:", i);
    scanf("%d", &b[i]);
    allocated[i] = 0; // Mark all blocks as initially unallocated
  }

  printf("Enter the memory requirement of each process:\n");
  for (i = 1; i <= numberOfProcesses; i++) {
    printf("Process %d:", i);
    scanf("%d", &p[i]);
  }

  // First Fit allocation
  for (i = 1; i <= numberOfProcesses; i++) {
    int allocatedBlock = -1; // Initialize allocated block to -1 (not found)

    for (j = 1; j <= numberOfBlocks && allocatedBlock == -1; j++) {
      if (b[j] >= p[i] && !allocated[j]) {
        allocatedBlock = j; // Found a suitable block
        allocated[j] = 1; // Mark the block as allocated
        printf("Process %d allocated to block %d\n", i, allocatedBlock);
      }
    }

    if (allocatedBlock == -1) {
      printf("Process %d not allocated\n", i);
    }
  }
}
