#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR_MSG "Not yet implemented.\r\n"
#define NO_NEW_MESSAGES "No new messages.\r\n"


int main()
{
    int secret = 1337;
    char buf[64];
    char sub[5];

    fgets(buf, 128, stdin);

    memcpy(sub, buf, 4*sizeof(char));

    if (strcmp(sub, "exit") == 0) {
        return 0;
    } else if (strcmp(sub, "send") == 0) {
        printf("[SEND] %s", buf+5);
    } else if (strcmp(sub, "recv") == 0) {
        puts(NO_NEW_MESSAGES);
    } else if (strcmp(sub, "xcmd") == 0) {
        /// TODO: Secure debug shell 
        if (secret == 0xdeadbeef)
            system("/bin/sh");
    }
    puts("ACK - FIN");

    return 0;
}
