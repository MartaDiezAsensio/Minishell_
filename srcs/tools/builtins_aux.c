/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:34:47 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/01/25 19:49:38 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*copy_value_from_env(const char *env_value, size_t len)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(env_value) - len) + 1);
	if (!result)
		return (NULL);
	while (env_value[i++])
	{
		if (i > (int)len)
			result[j++] = env_value[i];
	}
	result[j] = '\0';
	return (result);
}
/********Export***********/
int	handle_export_no_args(t_env *secret)
{
	print_sorted_env(secret);
	return (SUCCESS);
}

int	ft_export(char **args, t_env *env, t_env *secret)
{
	if (!args[1])
		return (handle_export_no_args(secret));
	else
		return (handle_export_with_args(args, env, secret));
}

