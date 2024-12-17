/** 
IMPORTANT NOTES:
- The 'All Parts' and the 'Used Parts' list must be in numeric order, smallest to largest
for this to work. 
- The 'All Parts' list must also exactly match with the list on Excel otherwise this 
will not work as intended.
- Online compiler: https://www.programiz.com/c-programming/online-compiler/
**/

// Libraries used
#include <stdio.h>
#include <string.h>
 
// Unique parts of all IMD models, declared as global variable 
/** Notes:
- If using a different model (like IMDL/IMDLQ) then this list must be changed
- This list is ordered numerically, check that this matches with Excel parts list 
**/
char *all_part_numbers[311] =  {
	// Paste here
};
 
 
// Function to print out the quantity amount for each used part (Do not change!)
/**  Note: 
The printing is aligned with the all_part_numbers list above. Make sure the order 
of list above matches with Excel. If any rows are added or deleted on Excel, the same 
must be done above. This is very important otherwise the list cannot be directly copied
and pasted onto the Excel sheet. 
**/ 
void print_quantity (char *used_parts[], float quantity[]){
    
	// Initialise indexing variables
    int i = 0;
    int j = 0;
	
	// Header
	printf("Quantity (copy values AFTER this line)\n");
	
    // Loop through all the parts once 
	// Note: This is only done once because the list is ordered numerically. 
	// This loop cannot work if the list is not in numeric order!
    for(i = 0; i <= (sizeof(all_part_numbers)/sizeof(all_part_numbers[0])); i++){
        
		// Print index (used for testing)
        // printf("Index i: %d: ", i);

        // A used part is found 
        if(!(strcmp(all_part_numbers[i], used_parts[j]))){
            
			// Print out the quantity number only
			printf("%f\n", quantity[j]);
			
            // increment the used_index
            j++;
        }
		
        // Part is not used in the model
        else{
			// Print nothing (empty row)
            printf("\n");
		}

    }
}
 
int main() {
	
	// List of the used parts, in numeric order (Change this for every model!)
    char *used_parts[100] = {
        // Paste here
    };
 
	// List of the quantity of the used parts (Change this for every model!)
	// IMPORTANT: Make sure that the order is the same and aligned with the list above!
	// Do not put this in numeric order 
    float quantity[100] =  {
       // Paste here
    };
 
 
 
    // Call function 
    print_quantity(used_parts, quantity);
    
	// // Print all part numbers (used for testing)
    // for (int i = 0; i < sizeof(all_part_numbers) / sizeof(all_part_numbers[0]); i++) {
    //     // printf("Index: %d ", i);
    //     printf("%s\n", all_part_numbers[i]);
    // }
 
    return 0;
}