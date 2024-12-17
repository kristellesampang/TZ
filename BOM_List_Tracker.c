// Libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macros
#define MAX_LINE_LENGTH 12 // size of part number
#define NUMBER_OF_PARTS_USED 38 // Change this for every model 

// String input for used parts 
char string_input[MAX_LINE_LENGTH];
char used_parts[MAX_LINE_LENGTH][NUMBER_OF_PARTS_USED]; 
char float_input[MAX_LINE_LENGTH];
char used_quantity[MAX_LINE_LENGTH][NUMBER_OF_PARTS_USED]; 

// All unique parts of the model, make sure this is ordered numerically from
// smallest to largest This should match the order on the Excel sheet you have
// created Change the size of the array accordingly
char *all_part_numbers[86] = { 
    "010-000-095", "010-000-096", "012-000-180", "012-000-181", "012-000-302",
    "012-000-306", "012-000-307", "012-000-414", "012-000-416", "012-001-041",
    "012-001-111", "012-001-133", "012-001-134", "012-001-186", "012-001-191",
    "012-001-204", "012-001-206", "012-001-269", "012-001-271", "012-100-479",
    "012-100-481", "012-100-482", "056-000-042", "056-000-044", "056-000-046",
    "056-000-052", "056-000-055", "059-000-053", "059-000-058", "059-000-059",
    "059-000-067", "101-000-469", "101-000-484", "101-000-486", "119-000-109",
    "119-000-110", "119-000-111", "119-000-112", "201-000-092", "234-000-386",
    "234-000-387", "234-000-481", "234-000-483", "234-001-512", "234-001-515",
    "234-001-518", "234-001-519", "240-002-831", "240-002-836", "245-007-112",
    "245-007-190", "245-100-018", "245-100-020", "245-100-021", "245-100-022",
    "245-100-023", "245-100-024", "245-100-025", "245-100-026", "245-100-027",
    "245-100-028", "245-100-029", "245-100-030", "245-100-032", "245-100-034",
    "270-004-629", "270-004-980", "270-004-982", "270-100-333", "281-004-814",
    "281-004-856", "281-100-006", "281-100-007", "293-000-446", "293-000-467",
    "293-000-468", "325-000-020", "325-000-022", "325-000-024", "325-000-026",
    "325-000-027", "325-006-002", "325-006-003", "325-066-002", "325-096-002",
    "325-196-002"};

// Function to print ouf the quantity amount for each used part (Do not change!)
/**
Note: The pprinting is aligned with the all_part_numbers array above. Make sure
the order of list above matches with Excel. If any rows are added or deleted in
Excel, then this must be reflected on the all_parts_numbers above. This is very
important otherwise the list cannot be directly copied and pasted onto the Excel
sheet.
**/
void print_quantity(char *used_parts[], char *quantity[]) {

  // Initialise indexing variables
  int i = 0;
  int j = 0;

  // Header
  printf("Quantity (copy values AFTER this line until the very end)\n");

  // Loop through all the parts once
  // Note: This is only done once because the list is ordered numerically.
  // This loop cannot work if the list is not in numeric order!
  for (i = 0; i <= (sizeof(all_part_numbers) / sizeof(all_part_numbers[0]));
       i++) {

    // Print index (used for testing)
    // printf("Index i: %d: ", i);

    // A used part is found
    if (!(strcmp(all_part_numbers[i], used_parts[j]))) {

      // Print out the quantity number only
      printf("%s\n", quantity[j]);

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
    if(i >= NUMBER_OF_PARTS_USED){
      return;
    }
    else if(!(strcmp(string_input,"\n"))){
      continue;
    }
    else{
      // Copy the string input into the used_parts array
      strcpy(&used_parts[i], string_input);
      i++;
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
  // print_quantity(used_parts, used_quantity);

  return 0;
}