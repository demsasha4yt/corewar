/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbessa <kbessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:18:58 by kbessa            #+#    #+#             */
/*   Updated: 2020/02/11 23:56:23 by kbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_ARG				"Error, wrong argument number"
# define ERR_FILE_EXT			"Error, wrong file extention"
# define ERR_OPEN				"Error, can't open file"
# define ERR_CREATE				"Error, can't create .cor file"
# define ERR_MALLOC				"Memory allocation error"
# define ERR_READ				"Read error"
# define ERR_QUOT_OR_CODE		"Error, no quotation after comment / blank champion code"
# define ERR_EOF				"Error, no \\n at the end of the file"
# define ERR_CLOSE				"Error, can't close the file"
# define ERR_COMMAND			"Error, invalid command"
# define ERR_TYPE_FIRST_ARG		"Error, invalid type of first argument"
# define ERR_TYPE_SECOND_ARG	"Error, invalid type of second argument"
# define ERR_TYPE_THIRD_ARG		"Error, invalid type of third argument"
# define ERR_ARG_NUMBER			"Error, wrong arguments number"
# define ERR_LABEL_NAME			"Error, wrong label name"
# define ERR_INSTR_FIRST_ARG	"Error, bad instruction in first argument"
# define ERR_INSTR_SECOND_ARG	"Error, bad instruction in second argument"
# define ERR_INSTR_THIRD_ARG	"Error, bad instruction in third argument"
# define ERR_NAME_LENGTH		"Error, bad name length"
# define ERR_BAD_SYM_NAME		"Error, bad symbols after name declaration"
# define ERR_COMMENT_LENGTH		"Error, bad comment length"
# define ERR_BAD_SYM_COMMENT	"Error, bad symbol after comment declaration"
# define ERR_QUOT_NAME			"Error, no quotation mark met after name declaration"
# define ERR_QUOT_COMMENT		"Error, no quotation mark met after comment declaration"
# define ERR_DOUBLE_NAME		"Error, second declaration of name"
# define ERR_DOUBLE_COMMENT		"Error, second declaration of comment"
# define ERR_SYM_BEFORE			"Error, command before name/comment declaration"

#endif
