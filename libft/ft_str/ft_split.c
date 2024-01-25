/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaspar- <mgaspar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:46:22 by cclaude           #+#    #+#             */
/*   Updated: 2024/01/25 18:28:18 by mgaspar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c)
			i++;
	}
	return (count);
}

static int	letter_count(char const *s, char c, int index)
{
	int		count;

	count = 0;
	while (s[index] != c && s[index] != '\0')
	{
		count++;
		index++;
	}
	return (count);
}

char	**loops(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[k] == c)
		k++;
	while (s[k] != '\0')
	{
		j = 0;
		tab[i] = malloc(sizeof(char) * letter_count(s, c, k) + 1);
		if (!(tab[i]))
			return (NULL);
		while (s[k] != c && s[k] != '\0')
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		while (s[k] == c)
			k++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !c || !(tab))
		return (NULL);
	return (loops(tab, s, c));
}
