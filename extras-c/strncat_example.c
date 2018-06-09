#include <stdio.h>
#include <string.h>

int main(){
	char mem[256] = "Physical Memory: ";
	
	size_t size = sizeof(mem) - strlen(mem) - 1;

	strncat(mem, "126 MiB total.", size);

	printf("Con strncat: \n\n%s\n", mem);
}