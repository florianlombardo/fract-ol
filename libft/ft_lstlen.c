/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: flombard <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 12:38:38 by flombard     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/24 12:43:21 by flombard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *l)
{
	int		i;
	t_list	*lst;

	i = 0;
	lst = l;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
