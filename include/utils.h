/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:30:57 by mac               #+#    #+#             */
/*   Updated: 2021/04/18 10:54:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "../include/checker.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
# define BUFFER_SIZE 32

int			        gnl(int fd, char **line);

#endif