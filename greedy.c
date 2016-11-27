#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>
#include <stdio.h>
#include <math.h>


int main() 
{
	// 0x0000400000000000
	// 0x0000640000000000
	// 0x00007effffffffff
	// 0x00007f0000000000
	// 0x0000800000000000
	size_t region_size = 0x0000640000000000u;// 100TB

	void *ptr = mmap(NULL, region_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_NORESERVE, -1, 0);
	if (ptr == MAP_FAILED) {
		perror("mmap failure");
		return 1;
	}

	getchar();

	if (munmap(ptr, region_size) == -1) {
		perror("munmap failure");
		return 1;
	}

	return 0;
}