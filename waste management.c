#include <stdio.h>
#include <string.h>

#define MAX 50

void addWaste(int *count, int id[], char area[][30], char type[][15], float weight[]);
void displayWaste(int count, int id[], char area[][30], char type[][15], float weight[]);
void totalWaste(int count, float weight[]);

int main()
{
    int id[MAX], count = 0;
    char area[MAX][30], type[MAX][15];
    float weight[MAX];
    int choice;

    do 
    {
        printf("\n\n Waste Management System ");
        printf("\n 1. Add Waste Record");
        printf("\n 2. Display Waste Records");
        printf("\n 3. Total Waste Collected");
        printf("\n 4. Exit");
        printf("\n Enter your choice: ");
        scanf("\n %d", &choice);

        switch (choice)
        {
            case 1:
                addWaste(&count, id, area, type, weight);
                break;

            case 2:
                displayWaste( count, id, area, type, weight);
                break;

            case 3:
                totalWaste(count, weight);
                break;


            case 4:
                printf("\n Program exited.");
                break;

            default:
                printf("\n Invalid choice! Try again.");
        }

    } while (choice != 4);

    return 0;
}

void addWaste(int *count, int id[], char area[][30], char type[][15], float weight[])
{
    if (*count >= MAX) 
    {
        printf("Storage full!\n");
        return;
    }

    printf("Enter Waste ID: ");
    scanf("%d", &id[*count]);

    printf("Enter Area Name: ");
    scanf(" %[^\n]", area[*count]);

    printf("Enter Waste Type (Dry/Wet/E-waste): ");
    scanf("%s", type[*count]);

    printf("Enter Weight (kg): ");
    scanf("%f", &weight[*count]);

    (*count)++;
    printf("Waste record added successfully!\n");
}

void displayWaste(int count, int id[], char area[][30], char type[][15], float weight[]) 
{
    int i;

    if (count == 0)
    {
        printf("No waste records available.\n");
        return;
    }

    printf("\nID\tArea\t\tType\t\tWeight(kg)\n");
    for (i = 0; i < count; i++) 
    {
        printf("%d\t%s\t\t%s\t\t%.2f\n",
               id[i], area[i], type[i], weight[i]);
    }
}

void totalWaste(int count, float weight[]) 
{
    int i;
    float total = 0;

    for (i = 0; i < count; i++) 
    {
        if (weight[i] < 0)
            continue;   // jumping statement

        total += weight[i];
    }

    printf("Total Waste Collected: %.2f kg\n", total);
}
