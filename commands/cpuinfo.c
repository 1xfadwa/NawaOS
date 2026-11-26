#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open the virtual kernel file /proc/cpuinfo just like a regular text file
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/cpuinfo! Make sure /proc is mounted.\n");
        return 1;
    }

    char line[256];
    char model_name[128] = "Unknown CPU";
    char cpu_mhz[64] = "Unknown";
    int core_count = 0;

    // Read /proc/cpuinfo line by line
    while (fgets(line, sizeof(line), fp)) {
        // Count each logical processor core
        if (strncmp(line, "processor", 9) == 0) {
            core_count++;
        }
        // Extract CPU model name
        else if (strncmp(line, "model name", 10) == 0) {
            char *colon = strchr(line, ':');
            if (colon != NULL) {
                strncpy(model_name, colon + 2, sizeof(model_name) - 1);
                model_name[strcspn(model_name, "\n")] = 0; // Remove trailing newline
            }
        }
        // Extract CPU clock speed in MHz
        else if (strncmp(line, "cpu MHz", 7) == 0) {
            char *colon = strchr(line, ':');
            if (colon != NULL) {
                strncpy(cpu_mhz, colon + 2, sizeof(cpu_mhz) - 1);
                cpu_mhz[strcspn(cpu_mhz, "\n")] = 0; // Remove trailing newline
            }
        }
    }

    fclose(fp); 

    printf("*********************************\n");
    printf("          NawaOS - CPU Info      \n");
    printf("*********************************\n");
    printf(" Processor Model: %s\n", model_name);
    printf(" Logical Cores: %d\n", core_count);
    printf(" Clock Speed: %s MHz\n", cpu_mhz);
    printf("*********************************\n");

    return 0;
}
