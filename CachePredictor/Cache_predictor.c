#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 3){
                return 1;
        }

        FILE *input = fopen(argv[1], "r");
        if(input == NULL){
                return 1;
        }

        FILE *output = fopen(argv[2], "w");
        if(output == NULL){
                fclose(input);
                return 1;
	}


	unsigned int current;

        while(fscanf(input, "%x", &current) == 1){
                fprintf(output, "0x%X\n", current + 4);
        }

        fclose(input);
	fclose(output);
        return EXIT_SUCCESS;
}
