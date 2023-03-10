/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "../include/messaging.h"

int my_printf(char *str, ...);
char *my_scanf(char *what_to_say);
int my_convstrnb(char *str, int place);
void ms_chat(int other_pid);


void ms_hosting_getpid(int a, siginfo_t *info, void *b)
{
    (void) a;
    (void) b;
    GLOBAL = info->si_pid;
}

void ms_hosting(void)
{
    my_printf("- Hosting Channel [%d] -\n", getpid());
    struct sigaction action;
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = ms_hosting_getpid;
    sigaction(SIGUSR1, &action, NULL);
}

void ms_join(char *text)
{
    GLOBAL = my_convstrnb(text, 0);
    my_printf("- Joining Channel [%d] -\n", GLOBAL);
    kill(GLOBAL, SIGUSR1);
}

int main(int ac, char **av)
{
    int other_pid = 0;
    if (ac > 3)
        return 84;
    if (ac == 1)
        ms_hosting();
    if (ac == 2)
        ms_join(av[1]);
    
    while (!GLOBAL);
    other_pid = GLOBAL;
    my_printf(" [%d]==[%d]\n\n", getpid(), other_pid);
    GLOBAL = 0;
    ms_chat(other_pid);
    return 0;
}
