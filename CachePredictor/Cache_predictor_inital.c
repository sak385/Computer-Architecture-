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

	unsigned int address;
	while(fscanf(input, "%x", &address) == 1){
		fprintf(output, "0x%x\n", address);
	}

	fclose(input);
	fclose(output);
	return EXIT_SUCCESS;
}
