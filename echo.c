#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[256];
    fgets(buf, sizeof(buf), stdin);
    printf("%s", buf);
}
