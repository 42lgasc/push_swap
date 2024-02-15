/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:25:10 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/15 15:41:25 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>

//#include "stacks.h"
#include "types.h"

# ifdef TEST
#  include "ft_printf/ft_printf.h"
# endif

void	ft_print_stacks(struct s_stacks stacks)
{
	//size_t				i;
	t_int_node	*node;
	//const char *const	mask_names[] = {"O", "A", "B", "AB"};

	//ft_printf("{size: %u, masks: {", (unsigned)stacks.size);
	//i = 0;
	//while (i < stacks.size)
		//(ft_printf("%s", mask_names[stacks.masks[i++]]),
		//	ft_print_if(i < stacks.size, ", "));
	//ft_printf("}, primary_top: %u, primary: {", (signed)stacks.primary_top);
	ft_putstr_fd("stacks: { primary: [", 1);
	//i = 0;
	node = stacks.primary;
	//while (i < stacks.size)
	while (node != NULL)
		//(ft_print_if(i == stacks.primary_top, "\x1B[1m"),
		//	ft_print_if(!(stacks.masks[i] & Primary), "\x1B[2m"),
		//	ft_printf("%i", stacks.primary[i]),
		//	ft_print_if(!(stacks.masks[i] & Primary)
		//		|| i == stacks.primary_top, "\x1B[0m"),
		//	ft_print_if(++i < stacks.size, ", "));
		node = (ft_printf("%i", node->datum), 
			ft_print_if(node->next != NULL, ", "), node->next);
	//ft_printf("}, secondary_top: %u, secondary: {", stacks.secondary_top);
	ft_putstr_fd("], secondary: [", 1);
	//i = 0;
	node = stacks.secondary;
	//while (i < stacks.size)
	while (node != NULL)
		//(ft_print_if(i == stacks.secondary_top, "\x1B[1m"),
		//	ft_print_if(!(stacks.masks[i] & Secondary), "\x1B[2m"),
		//	ft_printf("%i", stacks.secondary[i]),
		//	ft_print_if(!(stacks.masks[i] & Secondary)
		//		|| i == stacks.secondary_top, "\x1B[0m"),
		//	ft_print_if(++i < stacks.size, ", "));
		node = (ft_printf("%i", node->datum), 
			ft_print_if(node->next != NULL, ", "), node->next);
	ft_putendl_fd("] }", 1);
}

struct s_int_option	ft_primary_top(struct s_stacks stacks)
{
	if (stacks.primary == NULL)
		return ((t_int_option){ .type = None });
	return ((t_int_option){ .type = Some, .value = stacks.primary->datum});
}

struct s_int_option	ft_primary_next(struct s_stacks stacks)
{
	/*size_t	i;

	i = 0;
	while (i < stacks.size)
		if (stacks.masks[(stacks.primary_top + i++) % stacks.size] & Primary)
			while (1)
				if (stacks.masks
					[(stacks.primary_top + i++) % stacks.size] & Primary)
					return ((struct s_int_option){.type = Some, .value = stacks
						.primary[(stacks.primary_top + --i) % stacks.size]});
	return ((struct s_int_option){.type = None});*/(void) stacks;
	exit(TODO + 3);
}

t_int_option	ft_primary_bottom(const struct s_stacks stacks)
{
	//*size_t	i;

	//i = 0;
	//while (i < stacks.size)
	//	if (stacks.masks[(stacks.primary_top - ++i) % stacks.size] & Primary)
	//		return ((struct s_int_option){.type = Some, .value
	//			= stacks.primary[(stacks.primary_top - i) % stacks.size]});
	//return ((struct s_int_option){.type = None});*/(void) stacks;
	if (stacks.primary == NULL)
		return ((t_int_option){ .type = None});
	return ((t_int_option)
		{ .type = Some, .value = ft_lstlast_int(stacks.primary)->datum});
	exit(TODO + 4);
}

t_int_option	ft_secondary_top(const struct s_stacks stacks)
{
	//*size_t	i;

	//i = 0;
	//while (i < stacks.size)
	//	if (stacks.masks[(stacks.secondary_top + i++) % stacks.size]
	//		& Secondary)
	//		return ((struct s_int_option){.type = Some, .value = stacks
	//			.secondary[(stacks.secondary_top + --i) % stacks.size]});
	//return ((struct s_int_option){.type = None});*/(void) stacks;
	if (stacks.secondary == NULL)
		return ((t_int_option){ .type = None });
	return ((t_int_option){ .type = Some, .value = stacks.secondary->datum});
	exit(TODO + 5);
}

t_int_option	ft_secondary_bottom(const struct s_stacks stacks)
{
	//*size_t	i;

	//i = 0;
	//while (i < stacks.size)
	//	if (stacks.masks[(stacks.secondary_top - ++i) % stacks.size]
	//		& Secondary)
	//		return ((struct s_int_option){.type = Some, .value
	//			= stacks.secondary[(stacks.secondary_top - i) % stacks.size]});
	//return ((struct s_int_option){.type = None});*/(void) stacks;
	if (ft_lstplast_int(stacks.secondary) == NULL)
		return ((t_int_option){ .type = None });
	return ((t_int_option)
		{ .type = Some, .value = ft_lstplast_int(stacks.secondary)->datum });
	exit(TODO + 6);
}
