/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:24:39 by mdiez-as          #+#    #+#             */
/*   Updated: 2024/01/25 19:30:15 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static size_t	env_size(char *env)
{
	size_t	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (i);
}

static void	free_node(t_mini *mini, t_env *env)
{
	if (mini->env == env && env->next == NULL)
	{
		ft_memdel(mini->env->value);
		mini->env->value = NULL;
		mini->env->next = NULL;
		return ;
	}
	ft_memdel(env->value);
	ft_memdel(env);
}

int	ft_unset(char **a, t_mini *mini)
{
	t_env	*env;
	t_env	*tmp;

	env = mini->env;
	if (!(a[1]))
		return (SUCCESS);
	if (ft_strncmp(a[1], env->value, env_size(env->value)) == 0)
	{
		if (env->next)
			mini->env = env->next;
		free_node(mini, env);
		return (SUCCESS);
	}
	while (env && env->next)
	{
		if (ft_strncmp(a[1], env->next->value, env_size(env->next->value)) == 0)
		{
			tmp = env->next->next;
			free_node(mini, env->next);
			env->next = tmp;
			return (SUCCESS);
		}
		env = env->next;
	}
	return (SUCCESS);
}
