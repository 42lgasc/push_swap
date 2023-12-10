/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:57:12 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/21 18:30:57 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Applies the `iterator` function on each character of the `string`
 * 	passed as argument, passing its index as first argument.
 * Each character is passed by address to the `iterator`
 * 	function to be modified if necessary.
 * @param[in,out] string The string on which to iterate.
 * @param[in] iterator The function to apply to each character.
 */
void	ft_striteri(char *string, void (*iterator)(unsigned int, char *))
{
	unsigned int	i;

	if ((! string) || (! iterator))
		return ;
	i = 0;
	while (string[i])
	{
		iterator(i, &string[i]);
		i++;
	}
}
