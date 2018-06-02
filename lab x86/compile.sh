gcc -m32 -g -std=c99 -Wall -Wextra -Wpedantic -O1 -fno-pic -fno-omit-frame-pointer -no-pie -o libc_hello libc_hello.S

gcc -m32 -g -std=c99 -Wall -Wextra -Wpedantic -O1 -fno-pic -fno-omit-frame-pointer -no-pie -o int80_hi int80_hi.S

gcc -m32 -g -std=c99 -Wall -Wextra -Wpedantic -O1 -fno-pic -fno-omit-frame-pointer -no-pie -nostartfiles -o sys_strlen sys_strlen.S

gcc -m32 -g -std=c99 -Wall -Wextra -Wpedantic -O1 -fno-pic -fno-omit-frame-pointer -no-pie -o libc_puts libc_puts.S

gcc -m32 -g -std=c99 -Wall -Wextra -Wpedantic -O1 -fno-pic -fno-omit-frame-pointer -no-pie -o write2 write2.S perror.c -DUSE_WRITE2

gcc -m32 -g -std=c99 -Wall -Wextra -Wpedantic -O1 -fno-pic -fno-omit-frame-pointer -no-pie -o libc_argv2 libc_argv2.S