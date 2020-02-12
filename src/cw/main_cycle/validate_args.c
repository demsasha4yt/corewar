/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bharrold <bharrold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:25:28 by bharrold          #+#    #+#             */
/*   Updated: 2020/02/12 05:17:21 by bharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "cw_ops.h"

int			is_arg_types_valid(t_carry *carry, t_op *op)
{
	int32_t i;

	i = 0;
	// printf("args %d %d %d\n", carry->args_types[0], carry->args_types[1], carry->args_types[2]);
	while (i < op->args_num)
	{
		if (!(carry->args_types[i] & op->args_types[i]))
		{
			// printf("%d %d %d\n", carry->args_types[0], carry->args_types[1], carry->args_types[2]);
			// printf("%d invalid\n", i);
			// printf("is_args_type_valid false\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	is_register(t_cw *cw, t_carry *carry, int32_t step)
{
	int8_t r_id;

	r_id = arena_get_byte(cw, carry->position, step);
	return (r_id >= 1 && r_id <= REG_NUMBER);
}

int			is_args_valid(t_carry *carry, t_cw *cw, t_op *op)
{
	int32_t		i;
	uint32_t	step;

	i = 0;
	step = (OP_SIZE + (op->args_types_code ? ARGS_SIZE : 0));
	while (i < op->args_num)
	{
		if ((carry->args_types[i] == T_REG)
			&& !is_register(cw, carry, step))
			return (false);
		step += step_size(carry->args_types[i], op);
		i++;
	}
	return (1);
}
