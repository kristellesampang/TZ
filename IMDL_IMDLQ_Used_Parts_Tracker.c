/** 
IMPORTANT NOTES:
- The 'All Parts' and the 'Used Parts' list must be in numeric order, smallest to largest
for this to work. 
- The 'All Parts' list must also exactly match with the list on Excel otherwise this 
will not work as intended.
- Online Compiler: https://www.programiz.com/c-programming/online-compiler/
**/

// Libraries used
#include <stdio.h>
#include <string.h>
 
// Unique parts of all IMDL/Q models, declared as global variable 
/** Notes:
- If using a different model (like IMD) then this list must be changed
- This list is ordered numerically, check that this matches with Excel parts list 
**/
char *all_part_numbers[311] =  {
	"010-000-095","010-000-096","012-000-180","012-000-181","012-000-302","012-000-306",
	"012-000-307","012-000-414","012-000-416","012-001-041","012-001-111","012-001-133",
	"012-001-134","012-001-186","012-001-191","012-001-204","012-001-206","012-001-269",
	"012-001-271","012-100-479","012-100-481","012-100-482","056-000-042","056-000-044",
	"056-000-044","056-000-046","056-000-052","056-000-055","056-000-055","056-000-055",
	"059-000-053","059-000-058","059-000-059","059-000-067","101-000-469","101-000-484",
	"101-000-486","119-000-109","119-000-110","119-000-111","119-000-112","201-000-092",
	"234-000-386","234-000-387","234-000-481","234-000-483","234-001-512","234-001-515",
	"234-001-518","234-001-519","240-002-831","240-002-836","245-007-112","245-007-190",
	"245-100-018","245-100-020","245-100-021","245-100-022","245-100-023","245-100-024",
	"245-100-025","245-100-026","245-100-027","245-100-028","245-100-029","245-100-030",
	"245-100-032","245-100-034","270-004-629","270-004-980","270-004-982","270-100-333",
	"281-004-814","281-004-856","281-100-006","281-100-007","293-000-446","293-000-467",
	"293-000-468","325-000-020","325-000-022","325-000-024","325-000-026","325-000-027",
	"325-006-002","325-006-003","325-066-002","325-096-002","325-196-002"
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
    };
 
	// List of the quantity of the used parts (Change this for every model!)
	// IMPORTANT: Make sure that the order is the same and aligned with the list above!
	// Do not put this in numeric order 
    float quantity[100] =  {
    };
 
 
 
    // Call function 
    // print_quantity(used_parts, quantity);
    
	// Print all part numbers (used for testing)
    for (int i = 0; i < sizeof(all_part_numbers) / sizeof(all_part_numbers[0]); i++) {
        // printf("Index: %d ", i);
        printf("%s\n", all_part_numbers[i]);
    }
 
    return 0;
}