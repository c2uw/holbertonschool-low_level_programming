#include "main.h"

/**
 * print_chessboard - Prints the chessboard
 * @a: Pointer to the 2D array representing the chessboard
 *
 * Return: Nothing
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; iتفضل، انسخ هذا الأمر والصقه في التيرمنال مباشرة لإنشاء ملف `7-print_chessboard.c`:

```bash
cat << 'EOF' > 7-print_chessboard.c
#include "main.h"

/**
 * print_chessboard - Prints the chessboard
 * @a: Pointer to a 2D array of characters (8x8)
 *
 * Return: Nothing
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
