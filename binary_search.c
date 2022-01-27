/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:11:22 by plouvel           #+#    #+#             */
/*   Updated: 2022/01/27 15:47:29 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	*binary_search(int *tab, int x, unsigned int n)
{
	int	p;
	int	q;
	int	r;

	p = 0;
	r = n - 1;
	while (p <= r)
	{
		q = (p + r) / 2;	/* Milieu du tableau ou du sous tableau. */
		if (tab[q] == x)
			return (&tab[q]);
		else if (tab[q] > x)
			r = q - 1;	/* Sous tableau du tableau tab, partie gauche. */
		else
			p = q + 1;	/* Sous tableau du tableau tab, partie droite. */
	}
	return (NULL);
}

int	*linear_search(int *tab, int x, unsigned int n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (tab[i] == x)
			return (&tab[i]);
		i++;
	}
	return (NULL);
}

int	*create_tab(int argc, char **argv)
{
	int		*tab;
	size_t	n;

	n = 1;
	tab = (int *) malloc((argc - 1) * sizeof(int));
	if (!tab)
		return (NULL);
	while (n < argc)
	{
		tab[n - 1] = atoi(argv[n]);
		n++;
	}
	return (tab);
}

void	display_tab(int *tab, unsigned int n)
{
	size_t	i;

	i = 0;
	while (i++ < n)
		printf("%d\n", n);
}

int	main(int argc, char **argv)
{
	int		*tab;
	int		*n;
	double	cpu_time;
	clock_t	start;
	clock_t	end;

	tab = create_tab(argc, argv);
	if (!tab)
		return (1);
	puts("Using binary search !");
	start = clock();
	n = binary_search(tab, VALUE, argc - 1);
	end = clock();
	cpu_time = ((double) (end - start) / CLOCKS_PER_SEC);
	if (!n)
		puts("Value not found !");
	else
		puts("Value found !");
	printf("Done under %lf sec.\n", cpu_time);
	puts("Using linear search !");
	start = clock();
	n = linear_search(tab, VALUE, argc - 1);
	end = clock();
	cpu_time = ((double) (end - start) / CLOCKS_PER_SEC);
	if (!n)
		puts("Value not found !");
	else
		puts("Value found !");
	printf("Done under %lf sec.\n", cpu_time);
	free(tab);
}
