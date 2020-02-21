#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <tcl8.5/expect.h>

int main() {
    FILE *fp = exp_popen("telnet google.com 80");
    if(fp == NULL) {
        fprintf(stderr, "failed %s\n", strerror(errno));
        return -1;
    }
    printf("ok..?");
    return 0;
}
