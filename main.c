/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                               ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2024/11/08 15:29:32 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/02 05:10:58 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	remainder;
	int	quotient;
	int	a;
	int	b;

	a = 9765;
	b = 453;
	__asm
	{
		mov eax, a
		mov ecx, b
		xor edx, edx
		idiv ecx
		mov quotient, eax
		mov remainder, edx
	};
	printf("%d, %d\n", quotient, remainder);
}
