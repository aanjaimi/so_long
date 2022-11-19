/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:39:53 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/02/14 12:40:10 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			ret;
	static char	*s;
	char		*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	if (check_n(s))
		return (stock = print_n(s), s = last_print(s), free(buf), stock);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret <= 0)
	{
		if (!s)
			return (free(buf), NULL);
		if (!*s)
			return (free(s), s = NULL, free(buf), NULL);
		stock = ft_strdup(s);
		return (free(s), s = NULL, free(buf), stock);
	}
	return (buf[ret] = 0, s = ft_strjoin(s, buf), free(buf), get_next_line(fd));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	int			s1_len;
	int			s2_len;

	if (!s1)
		s1 = ft_strdup("");
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (str);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*new;

	len = ft_strlen(s1) + 1;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	return ((char *)ft_memcpy(new, s1, len));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	char		*s;

	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	if (d == s)
		return (dst);
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
