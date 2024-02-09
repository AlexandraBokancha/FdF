/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albokanc <albokanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:50:43 by albokanc          #+#    #+#             */
/*   Updated: 2024/02/08 19:42:30 by albokanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*end;

	if (!lst || !new_lst)
		return ;
	if (*lst == NULL)
	{	
		*lst = new_lst;
		return ;
	}
	else
	{
		end = ft_lstlast(*lst);
		end->next = new_lst;
	}
}
