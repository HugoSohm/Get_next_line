/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** Made by Hugo SOHM
*/

#include <stdlib.h>
#include <unistd.h>

int	end_buffer(char *buff)
{
	for (int i = 0; buff[i]; i++)
		if (buff[i] == '\n')
			return (0);
	return (1);
}

int	my_str_len(char *str, char c)
{
	int length = 0;

	if (str == NULL)
		return (-1);
	for (; str[length] != '\0' || str[length] == c; length++)
		if (str[length] == c)
			return (length);
	return (-1);
}

char	*check_str(char *begin, char *end, int i)
{
	char *tmp;

	if (!(tmp = malloc (sizeof(char) * (i + 1))))
		return (NULL);
	tmp[i] = '\0';
	for (int k = 0; k < i - 1; k++)
		tmp[k] = begin[k];
	tmp[i - 1] = end[0];
	free(begin);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char buffer[1];
	int i = 0;
	char *ret;
	int test = 0;

	if (!(ret = malloc (sizeof(char) * 1)))
		return (NULL);
	ret[0] = '\0';
	while ((test = read(fd, buffer, 1)) != 0) {
		i++;
		if (!end_buffer(buffer)) {
			buffer[0] = '\0';
			return (ret);
		}
		ret = check_str(ret, buffer, i);
	}
	if (!ret[0]) {
		free(ret);
		return (NULL);
	} else
		return (ret);
}
