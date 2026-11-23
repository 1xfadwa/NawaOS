#include <stdio.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

int main(){
        struct utsname sys_data;// Structure to store kernel and hardware inf
	struct sysinfo memo_data;// Structure to store uptime and memory info
	// Fetch system and memory details directly from the Linux kernel
	unane(&sys_data);
	sysinfo(&memo_data);
	// Convert RAM sizes from Bytes to Megabytes (MB)
	long total_ram_mb = memo_data.totalram / (1024*1024);
	long free_ram_mb = memo_data.freeram / (1024*1024);
	printf("\n***********************************\n");
        printf("        NawaOS - System Info       \n");
        printf("***********************************\n");
        printf(" Kernel Name: %s\n", sys_data.sysname);
        printf(" Kernel Release: %s\n", sys_data.release);
        printf(" Architecture: %s\n", sys_data.machine);
        printf(" Uptime: %ld seconds\n", memo_data.uptime);
        printf(" Total RAM: %ld MB\n", total_ram_mb);
        printf(" Free RAM: %ld MB\n", free_ram_mb);
        printf("***********************************\n\n");
	
	return 0;
}
