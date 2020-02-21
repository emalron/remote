#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void error(char *msg);

int main() {
    char buf[40];
    int inlet[2], outlet[2];
    pipe(inlet);
    pipe(outlet);
    pid_t pid = fork();
    if(pid == -1) {
        error("cannot create child process");
    }
    if(pid == 0) {
        dup2(inlet[0], 0);
        close(inlet[1]);
        close(inlet[0]);
        dup2(outlet[1], 1);
        close(outlet[0]);
        close(outlet[1]);
        if(execl("/usr/games/nethack", "/usr/games/nethack", NULL)) {
            error("cannot open file on child process");
        }
    }
    close(outlet[1]);
    close(inlet[0]);
    while(1) {
        fgets(buf, sizeof(buf), stdin);
        write(inlet[1], buf, strlen(buf));
        while(read(outlet[0], buf, sizeof(buf)) != 0) {
            fprintf(stdout, "%s", buf);
        }
    }
}

void error(char *msg) {
    fprintf(stderr, "%s: %s", msg, strerror(errno));
}
