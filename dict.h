/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gliano-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:46:11 by gliano-r          #+#    #+#             */
/*   Updated: 2020/02/22 11:57:44 by gliano-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H

#define DICT_H

typedef struct numbers_dict {
	int *key;
	char *value;
	struct numbers_dict *next;
} numbers_dict;

#endif
