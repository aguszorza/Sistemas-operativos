#include <errno.h>
#include <stdio.h>      // perror(3)
#include <string.h>
#include <sys/types.h>  // ssize_t

extern ssize_t __attribute__((cdecl))
write2(int fd, const void *buf, size_t count);
#define write write2

const char msg[] = "Escribiendo a nadie\n";

int main(void) {
    ssize_t ret = write(17, msg, sizeof msg - 1);

    if (ret < 0){
    	errno = -ret;
        perror("Falló write");
    }

    return ret;
}
