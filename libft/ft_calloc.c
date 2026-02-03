/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yucchen <yucchen@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:46:08 by yucchen           #+#    #+#             */
/*   Updated: 2025/05/20 20:06:37 by yucchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief	Allocate memory for an array of nmemb elements of size bytes each and
    return a pointer to the allocated memory. The memory is set to zero.
	If nmemb or size is 0, then calloc() returns either NULL, 
	or a unique pointer value that can later be successfully passed to free().  
	If the multiplication of nmemb and size would result in integer overflow,
    then calloc() returns an error.

	The malloc() function allocates size bytes and returns a pointer 
	to the allocated memory. The memory is not initialized. 
	If size is 0, then malloc() returns either NULL, or a unique pointer value 
	that can later be successfully passed to free().

	The free() function frees the memory space pointed to by ptr, 
	which must have been returned by a previous call to 
	malloc(), calloc(), or realloc(). 
	Otherwise, or if free(ptr) has already been called before, 
	undefined behavior occurs. If ptr is NULL, no operation is performed.
 *	@param nmemb size_t
 *	@param size size_t
 *	@return A pointer to the allocated memory, which is suitably aligned 
 	for any built-in type. On error, return NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* #include <stdio.h>

int	main(void)
{
	size_t	i;

	i = 0;

	// Test 1: Normal allocation
	int *arr_std = (int *)calloc(5, sizeof(int));
	int *arr_ft = (int *)ft_calloc(5, sizeof(int));

	if (!arr_std || !arr_ft)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("Test 1 - Compare contents (should be all zeros):\n");
	while (i < 5)
	{
		printf("std[%zu] = %d, ft[%zu] = %d\n", i, arr_std[i], i, arr_ft[i]);
		i++;
	}

	free(arr_std);
	free(arr_ft);

	// Test 2: Zero size
	void *zero_std = calloc(0, sizeof(int));
	void *zero_ft = ft_calloc(0, sizeof(int));

	printf("\nTest 2 - Zero size allocation:\n");
	printf("std = %p, ft = %p\n", zero_std, zero_ft);

	free(zero_std);
	free(zero_ft);

	// Test 3: Overflow check (should return NULL)
	printf("\nTest 3 - Overflow check:\n");
	void *overflow = ft_calloc((size_t)-1, (size_t)-1);
	printf("overflow = %p (expected: NULL)\n", overflow);

	free(overflow); // Safe to call even if NULL

	return (0);
} */