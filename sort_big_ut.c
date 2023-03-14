/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:32:30 by nuno              #+#    #+#             */
/*   Updated: 2023/03/14 17:13:07 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* radix sort 
bitwise right shift (>>) 
so it starts by checking the lsb(least significant bit)
>> takes two operands - the first operand is the value to be shifted, 
and the second operand is the number of bits to shift it to the right. 
In this case, the value being shifted is the content of the top element of stack_a,
 and the number of bits to shift it to the right is i.
    44 in binary: 101100, LSB: 0
    100 in binary: 1100100, LSB: 0
    2 in binary: 10, LSB: 0
    500 in binary: 111110100, LSB: 0
    1000 in binary: 1111101000, LSB: 0
    20 in binary: 10100, LSB: 0
   int i is the number of bits in each number that needs to be check
   Ex:
   1.
loop 1:
i = 0
j = 0

Number   Binary      Lsb
44       101100      0
100      1100100     0
2        10          0
500      111110100   0
1000     1111101000  0
20       10100       0

Stack A: 44 100 2 500 1000 20
Stack B: 

loop  2:
i = 1
j = 0

Number   Binary      Lsb
44       10110       0
100      110010      1
2        1           0
500      11111010    1
1000     111110100   0
20       1010        0

Stack A: 2 100 44 20 500 1000
Stack B: 2 100 44 20 500 1000

loop  3:
i = 2
j = 0

Number   Binary      Lsb
2        0           0
100      11001       1
44       1011        1
20       101         1
500      1111101     0
1000     11111010    1

Stack A: 2 20 44 100 500 1000
Stack B: 

loop  4:
i = 3
j = 0

Number   Binary      Lsb
2        0           0
20       101         1
44       1011        1
100      11001       0
500      1111101     1
1000     11111010    0

Stack A: 2 20 100 44 500 1000
Stack B: 

loop  5:
i = 4
j = 0

Number   Binary      Lsb
2        0           0
20       101         1
100      11001       0
44       1011        1
500      1111101     0
1000     1111101     0

Stack A: 2 20 100 500 44 1000
Stack B: 

loop  6:
i = 5
j = 0

Number   Binary      Lsb
2        0           0
20       101         1
100      11001       1
500      111110      1
44       1011        0
1000     111110      0

Stack A: 2 20 100 500 44 1000
Stack B: 

loop  7:
i = 6
j = 0

Number   Binary      Lsb
2        0           0
20       101         0
100      1100        1
500      11111       0
44       101         0
1000     11111       0

Stack A: 2 20 44 100 500 1000
Stack B: 

loop  8:
i = 7
j = 0

Number   Binary      Lsb
2        0           0
20       10          0
100      11          1
500      1111        1
44       10100       0
1000     11111       1

Stack A: 2 20 44 100 500 1000
Stack B:
3.

stack_a: 5 -> 3 -> 8 -> 1 -> 6
stack_b:

1 = 1
j= 0
lsb = 5 >> 0 = 5 (binary: 101)
5 & 1 = 1, so rotate_a -> stack_a: 3 -> 8 -> 1 -> 6 -> 5
j = 1

lsb = 3 >> 0 = 3 (binary: 11)
3 & 1 = 1, so rotate_a -> stack_a: 8 -> 1 -> 6 -> 5 -> 3
j = 2

lsb = 8 >> 0 = 8 (binary: 1000)
8 & 1 = 0, so push_b -> stack_a: 1 -> 6 -> 5 -> 3; stack_b: 8
j = 3

lsb = 1 >> 0 = 1 (binary: 1)
1 & 1 = 1, so rotate_a -> stack_a: 6 -> 5 -> 3 -> 1; stack_b: 8
j = 4

lsb = 6 >> 0 = 6 (binary: 110)
6 & 1 = 0, so push_b -> stack_a: 5 -> 3 -> 1; stack_b: 8 -> 6

stack_a: 5 -> 3 -> 1
stack_b: 8 -> 6

i = 2
j = 0
lsb = 5 >> 1 = 2 (binary: 10)
2 & 1 = 0, so push_b -> stack_a: 3 -> 1; stack_b: 8 -> 6 -> 5
j = 1

lsb = 3 >> 1 = 1 (binary: 1)
1 & 1 = 1, so rotate_a -> stack_a: 1 -> 3; stack_b: 8 -> 6 -> 5
j = 2

lsb = 1 >> 1 = 0 (binary: 0)
0 & 1 = 0, so push_b -> stack_a: 3; stack_b: 8 -> 6 -> 5 -> 1

stack_a: 3
stack_b: 8 -> 6 -> 5 -> 1

i = 3
j = 0
lsb = 3 >> 2 = 0 (binary: 0)
0 & 1 = 0, so push_b -> stack_a: ; stack_b: 8 -> 6 -> 5 -> 1 -> 3

stack_a:
stack_b: 8 -> 6 -> 5 -> 1 -> 3

final
tack_a: 1 -> 3 -> 5 -> 6 -> 8
stack_b:
*/

int has_negative_numbers(t_stack *stack) 
{
    while (stack) {
        if (stack->content < 0) {
            return 1; // list contains negative numbers
        }
        stack = stack->next;
    }
    return 0; // list does not contain negative numbers
}

int get_smallest_value(t_stack *stack)
{
    int smallest = stack->content;
    while (stack)
    {
        if (stack->content < smallest)
            smallest = stack->content;
        stack = stack->next;
    }
    return smallest;
}


int make_all_values_positive(t_stack **stack_a)
{
    int smallest = 0;
    if (has_negative_numbers(*stack_a))
    {
        smallest = get_smallest_value(*stack_a);
        t_stack *current = *stack_a;
        while (current)
        {
            current->content -= smallest;
            current = current->next;
        }
    }
    return smallest;
}

void return_to_original(t_stack **stack_a, int subtracted)
{
    t_stack *current = *stack_a;
    while (current)
    {
        current->content += subtracted;
        current = current->next;
    }
}

void sort_bigger(t_stack **stack_a, t_stack **stack_b)
{
    size_t length;
    size_t i;
    size_t j;
    int lsb;
    int subtracted;

    length = ft_lstsize(*stack_a);
    i = 0;
    subtracted = make_all_values_positive(stack_a);
    while (!sorted(stack_a))
    {
        j = 0;
        while (j < length)
        {
            lsb = (*stack_a)->content >> i;
            if (lsb % 2 == 1)
                rotate_a(stack_a);
            else
                push_b(stack_a, stack_b);
            j++;
        }
        while ((*stack_b))
            push_a(stack_b, stack_a);
        i++;
    }
    return_to_original(stack_a, subtracted);
}


