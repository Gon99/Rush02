/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gliano-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:30:27 by gliano-r          #+#    #+#             */
/*   Updated: 2020/02/22 20:14:19 by gliano-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void	print_error()
{
	write(1, "Error\n", 7);
}

typedef struct numbers_dict
{
	int *key;
	char *value;
	struct numbers_dict *next;
} num_dict;

/*num_dict **dictAlloc(void)
{
	return malloc(sizeof(num_dict));
}

void	dictDealloc(num_dict **dict)
{
	free(dict);
}*/

int		ft_atoi(char *str)
{
	int resp;

	resp = 0;
	while (*str != '\0')
	{
		resp = resp * 10 + *str - '0';
		str++;
	}
	return (resp);
}

int		is_numeric_char(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int x;

	x = 0;
	i = 0;
	if (to_find[i] == '\0')
		return (&str[i]);
	while (str[i] != '\0')
	{
		x = 0;
		while (str[i + x] == to_find[x])
		{
			x++;
			if (to_find[x] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

char	*get_value(char *str, char *key)
{
	char *resp;
	int i;

	resp = ft_strstr(str, key);
	if (!resp)
		return ("Error\n");
	while (*resp != '\n')
	{
		if (*resp == ' ')
		{
			resp++;
			break;
		}
		else
			resp++;
	}
	i = 0;
	while (resp[i] != '\n')
		i++;

	while (resp[i] != '\0')
	{
		resp[i] = '\0';
		i++;
	}
	return (resp);
}

char	*get_keys(char *str)
{
	char *keys;
	int i;

	keys = (char *) malloc(10000 * sizeof(char));
	i = 0;
	while (*str != '\0')
	{
		keys[i] = *str;
		i++;
		str++;
		if (*str == ':')
		{
			*str = ' ';
			str++;
			while (*str != '\n')
			{
				*str = ' ';
				str++;
			}
		}
	}
	return (keys);
}

int		open_file()
{
	int fd;
	int sz;
	char *file_c;
	char *resp;

	file_c = (char *) malloc(690 * sizeof(char));
	fd = open("numbers.dict.txt", O_RDONLY);
	if (fd < 0)
		print_error();
	sz = read(fd, file_c ,690);
	if (sz == 0)
	{
		print_error();//Empty file
		return (0);
	}
	file_c[sz + 1] = '\0';
	if (close(fd) < 0)
	{
		print_error();
		return (0);
	}
	close(fd);
	//resp = get_keys(file_c);
	//printf("Resp%c", resp[1]);
	resp = get_value(file_c, "15 ");
	printf("%s",resp);
	return (1);
}

int		main()
{
	open_file();
}
