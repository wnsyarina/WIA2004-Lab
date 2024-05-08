#include <stdio.h>
#include <stdlib.h>

int main() {
    int memory_size, page_size, num_pages_available, num_processes, remaining_pages, i, j, process_id,page_num;
    int page_table[10][20],page_required[20];
    int offset, physical_address;

    // Clear screen
    system("cls");

    printf("Enter the total memory size: ");
    scanf("%d", &memory_size);

    printf("Enter the page size: ");
    scanf("%d", &page_size);

    num_pages_available = memory_size / page_size;
    printf("Number of pages available in memory: %d\n", num_pages_available);

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    remaining_pages = num_pages_available;
    for (i = 1; i <= num_processes; i++) {
        printf("Enter number of pages required for Process %d: ", i);
        scanf("%d", &page_required[i]);

        if (page_required[i] > remaining_pages) {
            printf("Memory is full.\n");
            break;
        }

        remaining_pages -= page_required[i];

        // Input page table for each process
        printf("Enter page table for Process %d:\n", i);
        for (j = 0; j < page_required[i]; j++) {
            printf("Page %d: ", j);
            scanf("%d", &page_table[i][j]);
        }
    }

    // Input logical address to find physical address
    printf("\nEnter Logical Address to find Physical Address\n");
    printf("Enter Process ID, Page Number, and Offset: ");
    scanf("%d %d %d", &process_id, &page_num, &offset);

    if (process_id > num_processes || page_num >= page_required[process_id] || offset >= page_size) {
        printf("Invalid Process ID, Page Number, or Offset\n");
    } else {
        // Calculate physical address
        physical_address = page_table[process_id][page_num] * page_size + offset;
        printf("The Physical Address is: %d\n", physical_address);
    }

    return 0;
}


