#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

static void sighandler(int signal) {
  if(signal == SIGINT) {
    int file = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if(file == -1) {
      printf("%s\n", strerror(errno));
    }
    char *returnmsg = "program exited due to SIGINT\n";
    int writing = write(file,returnmsg, strlen(returnmsg));
    if(writing == -1) {
      printf("%s\n", strerror(errno));
    }
    exit(0);
  } else if (signal == SIGUSR1) {
    printf("ppid: %d\n", getppid());
  }
}

int main () {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while(1) {
        printf("pid: %d\n", getpid());
        sleep(1);
    }
    return 0;
}
