// START CODE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//A simple, reliable string hashing algorithm (DJB2)

unsigned long hash_token(const char *str) {
	unsigned long hash = 5381;
	int c;

	while ((c = *str++)) {
		hash = ((hash << 5) + hash) + c; // hash * 33 + c
	}

	return hash;
}

int main() {
	 FILE *fp = fopen("/etc/machine-id", "r");
	
	if (fp == NULL) {
		// Fallback for some systems where machine-id might be in /var/lib/dbus/
		fp = fopen("/var/lib/dbus/machine-id", "r");
	}

	if (fp == NULL) {
		fprintf(stderr, "Error: System identification file could not be read.\n");
		return 1;
	}

	char machine_id[64];

	if (fscanf(fp, "%63s", machine_id) != 1) {
		fprintf(stderr, "Error: Failed to parse system identifier.\n");
		fclose(fp);
		return 1;
	}

	fclose(fp);

	// Append a secret salt unique to your course to prevent raw ID lookup
	const char *salt = "CS211-Midterm-2026";
	char combined_string[128];

	snprintf(combined_string, sizeof(combined_string), "%s%s", machine_id, salt);

	// Generate the unique hash
	unsigned long unique_token = hash_token(combined_string);

	printf("--- Midterm Environment Verification ---\n");
	printf("Machine Token: %016lx\n", unique_token);
	printf("----------------------------------------\n");

	return  EXIT_SUCCESS;
}

// END CODE

