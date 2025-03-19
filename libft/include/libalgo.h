/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libalgo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rshin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:01:03 by rshin             #+#    #+#             */
/*   Updated: 2025/03/13 20:09:20 by rshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBALGO_H
# define LIBALGO_H

# include <stddef.h>

long	ft_power(long nbr, long pow);
long	ft_sqrt(long nbr);
long	ft_factorial(long nbr);
long	ft_fibonacci(size_t i);
long	ft_is_prime(long nbr);
long	ft_next_prime(long nbr);
void	ft_swap_value(int *a, int *b);

#endif
