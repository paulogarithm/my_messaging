/*
** EPITECH PROJECT, 2023
** my_messaging
** File description:
** ms_chat
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "../include/messaging.h"

char *my_scanf(char *txt);
int my_printf(char *txt, ...);

char *my_addstr(char *str, char *str2);
char *my_addchar(char *str, char c);
int my_countstr(char *str);
int my_compstr(char *str1, char *str2);

char *my_bin_convert(int nb, int bits);
int my_getbin(char *bin, int bytes);


void ms_procedure(int sig)
{
    char c = 1;

    BIN = my_addstr(BIN, sig == 1 ? "1" : "0");
    if (my_countstr(BIN) >= 8) {
        c = my_getbin(BIN, 8);
        MSG = my_addchar(MSG, c);
        BIN = "";
    }
    if (c == '\0') {
        my_printf("%s[%d]%s\t %s\n", C_GRN, PID, C_DEF, MSG);
        MSG = "";
    }
    kill(PID, SIGUSR1);
}

void ms_get_signal(int sig)
{
    sig = sig == SIGUSR1 ? 1 : 2;
    GLOBAL = sig;
    if (!IS_SENDING) {
        ms_procedure(sig);
    }
}

/* -- -- -- -- -- -- -- -- */

void ms_send_character(int pid, char c)
{
    int n = 0;
    char *bin = my_bin_convert((int) c, 8);

    while (bin[n]) {
        kill(pid, bin[n] == '1' ? SIGUSR1 : SIGUSR2);
        while (!GLOBAL);
        GLOBAL = 0;
        n += 1;
    }
}

void ms_send_message(int pid, char *message)
{
    int n = 0;
    while (message[n]) {
        ms_send_character(pid, message[n]);
        n += 1;
    }
    ms_send_character(pid, 0);
}

void ms_chat(int other_pid)
{
    PID = other_pid;
    if (signal(SIGUSR1, ms_get_signal) == SIG_ERR)
        return;
    if (signal(SIGUSR2, ms_get_signal) == SIG_ERR)
        return;

    while (1) {
        char *str = my_scanf("");
        IS_SENDING = 1;
        ms_send_message(other_pid, str);
        my_printf("%s[You]%s\t %s\n", C_BLU, C_DEF, str);
        IS_SENDING = 0;
    }
}
