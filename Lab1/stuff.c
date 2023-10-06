/* stuff.c --- 
 * 
 * Filename: stuff.c
 * Description: 
 * Author: Lukas
 * Maintainer: 
 * Created: Wed Sep 20 11:38:45 2023 (+0100)
 * Last-Updated: Wed Sep 20 11:46:34 2023 (+0100)
 *           By: Lukas
 *     Update #: 2
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */

/**
 * A brief history of JavaDoc-style (C-style) comments.A javadoc style comment for Doxygen
 *
 * This is the typical JavaDoc-style C-style comment. It starts with two
 * asterisks. This is a longer comment detailing algorithm (as required)
 *
 * @param N Integer input to function
 * @return the factorial of N
 *               
 */
int factorial(int N) 
{
    int result = 1;
    while (N > 0)
    {
        result *= N;
        N--;
    }
    return result;
}

/*******************************************************************************
 * A brief history of JavaDoc-style (C-style) banner comments.
 *
 * This is the typical JavaDoc-style C-style "banner" comment. It starts with
 * a forward slash followed by some number, n, of asterisks, where n > 2. It's
 * written this way to be more "visible" to developers who are reading the
 * source code.
 *
 * Often, developers are unaware that this is not (by default) a valid Doxygen
 * comment block!
 *
 * However, as long as JAVADOC_BLOCK = YES is added to the Doxyfile, it will
 * work as expected.
 *
 * This style of commenting behaves well with clang-format.
 *
 * @param theory Even if there is only one possible unified theory. it is just a
 *               set of rules and equations.
 * @return The fibonacci of N 
 ******************************************************************************/
int fibonacci(int N)
{
    if (N <= 0)
    {
        return 0;
    }
    if (N == 1)
    {
        return 1;
    }

    int current = 1;
    int previous = 1;
    int sum = 2;

    for (int i = 2; i < N; ++i) {
        int temp = current;
        current += previous;
        previous = temp;

        sum += current;  // Add the new Fibonacci number to the sum
    }

    return sum;
}

/* stuff.c ends here */
