/*
** EPITECH PROJECT, 2023
** my_messaging
** File description:
** ms_usefull
*/

char *my_addchar(char *str, char c);

int my_pow(int nb, int p)
{
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    if (p > 1)
        nb = nb * my_pow(nb, p - 1);
    return nb;
}

int my_getbin(char *bin, int bytes)
{
    int nb = 0;
    int n = 0;

    while (bin[n] != '\0') {
        bytes -= 1;
        nb += bin[n] == '1' ? my_pow(2, bytes) : 0;
        n += 1;
    }
    return nb;
}

char *my_bin_convert(int nb, int bits)
{
    char *str = "";
    while (bits) {
        if (nb >= my_pow(2, bits - 1)) {
            str = my_addchar(str, '1');
            nb -= my_pow(2, bits - 1);
        } else {
            str = my_addchar(str, '0');
        }
        bits -= 1;
    }
    return str;
}
