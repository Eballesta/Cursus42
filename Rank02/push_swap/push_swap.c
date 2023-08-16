/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eballest <eballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:08:29 by eballest          #+#    #+#             */
/*   Updated: 2023/07/28 20:14:53 by eballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	initialize_stacks(&a, &b);
	if (control_errors(argv, argc, &a) == 0)
		sort_stacks(&a, &b);
	else
		write(2, "Error\n", 6);
	free_stacks(&a);
	free_stacks(&b);
	return (0);
}

int	control_errors(char **argv, int argc, t_stack *a)
{
	int	*nums;
	int	i;

	nums = NULL;
	nums = (int *)malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (-1);
	i = 0;
	while (i < argc -1)
	{
		if (correct_number(argv[i +1]) == -1)
			return (ft_free(nums));
		nums[i] = ft_atoi(argv[i +1]);
		if ((nums[i] == 0 && argv[i +1][0] != '0'))
			return (ft_free(nums));
		i++;
	}
	if (save_stack(nums, argc - 1, a) < 0)
		return (ft_free(nums));
	ft_free(nums);
	return (0);
}

int	save_stack(int *nums, int len, t_stack *a)
{
	int			i;
	int			index;
	t_element	*element;

	i = 0;
	while (i < len)
	{
		index = get_index(nums, i, len);
		if (index == -1)
			return (-1);
		element = new_element(nums[i], index, i);
		if (!element)
			return (-1);
		save_stack2(a, element);
		i++;
	}
	return (0);
}

void	save_stack2(t_stack *a, t_element *element)
{
	if (a->first == NULL)
	{
		a->first = element;
		a->last = element;
		a->len = 1;
	}
	else
	{
		element->previous = a->last;
		a->last->next = element;
		a->last = element;
		a->len += 1;
	}
}

int	get_index(int *nums, int i, int len)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (j < len)
	{
		if (j != i)
		{
			if (nums[j] < nums[i])
				index++;
			else if (nums[i] == nums[j])
				return (-1);
		}
		j++;
	}
	return (index);
}
