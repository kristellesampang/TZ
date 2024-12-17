// Libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define MAX_LINE_LENGTH 12 // size of part number
#define NUMBER_OF_PARTS_USED 38 // Change this for every model 
#define UNIQUE_PARTS_SIZE 194 // Change this for every model

// String input for used parts 
char string_input[MAX_LINE_LENGTH];
// char used_parts[MAX_LINE_LENGTH][NUMBER_OF_PARTS_USED]; 
char used_parts[NUMBER_OF_PARTS_USED][MAX_LINE_LENGTH]; 
char float_input[MAX_LINE_LENGTH];
// char used_quantity[MAX_LINE_LENGTH][NUMBER_OF_PARTS_USED]; 
char used_quantity[NUMBER_OF_PARTS_USED][MAX_LINE_LENGTH]; 

// All unique parts of the model, make sure this is ordered numerically from
// smallest to largest This should match the order on the Excel sheet you have created 
char *all_part_numbers[UNIQUE_PARTS_SIZE] = { 
 "010-000-096","010-000-097","010-000-098","010-000-099","010-000-100","012-000-060","012-000-302","012-000-306","012-000-307","012-000-321","012-000-322","012-000-414","012-000-416","012-001-041","012-001-111","012-001-131","012-001-132","012-001-133","012-001-134","012-001-186","012-001-191","012-001-203","012-001-204","012-001-206","012-001-269","012-001-271","012-001-275","012-100-071","012-100-479","012-100-480","012-100-481","012-100-489","012-100-499","029-000-005","029-000-064","029-000-065","029-000-367","029-000-580","029-070-001","029-143-001","029-146-001","029-147-001","029-200-003","029-200-004","029-200-005","029-200-102","029-200-131","029-206-004","053-000-029","053-000-035","053-000-042","053-000-045","053-000-048","053-000-068","053-000-073","056-000-003","056-000-043","056-000-044","056-000-045","056-000-051","056-000-054","056-000-055","056-000-167","058-000-011","059-000-021","059-000-035","059-000-053","059-000-058","101-000-479","101-000-481","101-000-482","201-000-092","234-100-015","234-100-016","234-100-017","234-100-018","234-100-019","234-100-020","234-100-021","234-100-022","234-100-023","234-100-024","234-100-025","234-100-026","234-100-027","234-100-028","234-100-029","234-100-030","234-100-031","234-100-032","234-100-033","234-100-034","234-100-035","234-100-036","234-100-037","234-100-039","234-100-040","234-100-044","234-100-045","240-002-836","240-002-844","240-002-845","240-002-846","240-100-015","240-100-019","245-100-026","245-100-031","245-100-035","245-100-036","245-100-037","245-100-038","245-100-039","245-100-040","245-100-041","245-100-042","245-100-043","245-100-044","245-100-045","245-100-047","245-100-048","245-100-049","245-100-050","245-100-051","245-100-052","245-100-053","245-100-054","245-100-055","245-100-056","245-100-057","245-100-058","245-100-059","245-100-060","245-100-061","245-100-062","245-100-063","245-100-064","245-100-065","245-100-066","245-100-067","245-100-068","245-100-069","245-100-070","246-002-453","246-002-460","246-002-466","246-100-016","246-100-018","246-100-019","246-100-021","246-100-022","246-100-023","246-100-024","246-100-025","246-100-026","246-100-027","246-100-028","246-100-029","246-100-030","281-100-008","281-100-009","281-100-010","281-100-011","281-100-012","281-100-013","281-100-014","281-100-015","281-100-016","281-100-017","281-100-018","293-000-447","293-000-468","293-000-470","293-000-472","296-100-001","296-100-002","296-100-003","296-100-005","296-100-006","296-100-007","296-100-008","296-100-009","296-100-010","307-001-102","325-126-012","325-126-013","325-236-012","325-276-012","325-316-012","325-356-012","325-436-001","325-436-002","325-456-001","325-596-001","325-636-001"
};

// Function to print ouf the quantity amount for each used part (Do not change!)
/**
Note: The pprinting is aligned with the all_part_numbers array above. Make sure
the order of list above matches with Excel. If any rows are added or deleted in
Excel, then this must be reflected on the all_parts_numbers above. This is very
important otherwise the list cannot be directly copied and pasted onto the Excel
sheet.
**/
void print_quantity(char parts[][MAX_LINE_LENGTH], char quantity[][MAX_LINE_LENGTH]) {

  // Initialise indexing variables
  int i = 0;
  int j = 0;

  // Header
  printf("Quantity (copy values AFTER this line until the very end)\n");

  // Loop through all the parts once
  // Note: This is only done once because the list is ordered numerically.
  // This loop cannot work if the list is not in numeric order!
  for (i = 0; i <= UNIQUE_PARTS_SIZE; i++){
      // Print index (used for testing)
    // printf("Index i: %d: ", i);
    // printf("All part numbers: %s\t", all_part_numbers[i]);
    // printf("Part: %s\t", parts[i]);

    // A used part is found
    if (!(strcmp(all_part_numbers[i], parts[j]))) {
      // Print out the quantity number only
      printf("%s", quantity[j]);

      // increment the used_index
      j++;
    }

    // Part is not used in the model
    else {
      // Print nothing (empty row)
      printf("\n");
    }

  }
}

// Function to read string user inputted values from Excel
void read_string_input() {
  // Prompt the user
  printf("Please paste all the used part of this model\n");
  int i = 0;
  // Reads the user input
  while (fgets(string_input, sizeof(string_input), stdin)) {
    
    if(!(strcmp(string_input,"\n"))){
      continue;
    }
    else{
      // Copy the string input into the used_parts array
      strcpy(&used_parts[i], string_input);
      i++;
      if(i >= NUMBER_OF_PARTS_USED){
        return;
      }
    }
  }
  return;
  
}

// Function to read float user inputted values from Excel
void read_float_input() {
  // Prompt the user
  printf("Please paste the quantities used in this model\n");
  int i = 0;
  // Reads the user input
  while (fgets(float_input, sizeof(float_input), stdin)) {
    if(!(strcmp(float_input, "\n"))){
      continue;
    }
    else{
      strcpy(&used_quantity[i], float_input);
      i++;
      if(i >= NUMBER_OF_PARTS_USED){
        return;
      }
    }
  }
  return;
}

int main(void) {
  printf("WARNING: Please make sure you have modified the all_part_numbers "
         "array before using this!\nAlso, change NUMBER_OF_PARTS_USED macro to the amount of parts used in the model\n");
  read_string_input();
  read_float_input();
  printf("Completed reading input\n");
  // for(int i = 0; i < NUMBER_OF_PARTS_USED; i++){
  //   printf("Used Parts: %s\t", used_parts[i]);
  //   printf("Used Quantity: %s\n", used_quantity[i]);
  // }
  print_quantity(used_parts, used_quantity);

  return 0;
}