#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal) {
    if (signal == SIGUSR1) {
        write(1, "1", 1);
    } else if (signal == SIGUSR2) {
        write(1, "0", 1);
    }
}

int main() {
    printf("PID du serveur : %d\n", getpid());

    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    while (1) {
        pause();
    }

    return 0;
}
