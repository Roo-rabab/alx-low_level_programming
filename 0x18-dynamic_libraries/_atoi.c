#include "main.h"
/**
 * _atoi - string to integer
 * @s: string
 * Return: integer
 */
int _atoi(char *s)
{
int so = 1, i = 0;
unsigned int in = 0;
while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
{
if (s[i] == '-')
so *= -1;
i++;
}
while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
{
in = (in * 10) + (s[i] - '0');
i++;
}
in *= so;
return (in);
}
