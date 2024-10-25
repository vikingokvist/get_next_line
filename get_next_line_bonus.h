/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctommasi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:54:53 by ctommasi          #+#    #+#             */
/*   Updated: 2024/10/08 12:54:56 by ctommasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *total_chars);
char	*ft_save_line(char *total_chars);
char	*ft_save_static(char *total_chars);
void	*ft_calloc_z(size_t nmemb, size_t size);
char	*ft_strjoin_free(char *total_chars, char *temp);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
