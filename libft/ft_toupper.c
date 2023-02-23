/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:33:27 by eboulhou          #+#    #+#             */
/*   Updated: 2022/10/17 16:55:52 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c )
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
