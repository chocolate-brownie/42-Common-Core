#include <stdio.h>  
#include "ft_printf.h" 

int main(void)
{
    // Test 1: Basic string
    printf("Test 1: Basic string\n");
    ft_printf("My name is %s and I am %d years old.\n", "John", 25);
    printf("Expected: My name is John and I am 25 years old.\n\n");

    // Test 2: Integer and Character
    printf("Test 2: Integer and Character\n");
    ft_printf("Character: %c, Number: %d\n", 'A', 1234);
    printf("Expected: Character: A, Number: 1234\n\n");

    // Test 3: Hexadecimal
    printf("Test 3: Hexadecimal\n");
    ft_printf("Hexadecimal: %x\n", 255);
    printf("Expected: Hexadecimal: ff\n\n");

    // Test 4: Multiple Arguments
    printf("Test 4: Multiple Arguments\n");
    ft_printf("First: %d, Second: %s, Third: %x\n", 42, "Answer", 42);
    printf("Expected: First: 42, Second: Answer, Third: 2a\n\n");

    // Test 5: Percent Sign
    printf("Test 5: Percent Sign\n");
    ft_printf("Print a percent sign: %%\n");
    printf("Expected: Print a percent sign: %%\n\n");

    // Test 6: Edge Cases
    printf("Test 6: Edge Cases\n");
    ft_printf("Empty string: '%s'\n", "");
    printf("Expected: Empty string: ''\n");

    ft_printf("Zero: %d\n", 0);
    printf("Expected: Zero: 0\n");

    ft_printf("Null string: %s\n", (char *)NULL);
    printf("Expected: Null string: (null)\n\n");

    // Test 7: Large numbers
    printf("Test 7: Large Numbers\n");
    ft_printf("Large number: %d\n", 2147483647);
    printf("Expected: Large number: 2147483647\n\n");

    // Test 8: Negative numbers
    printf("Test 8: Negative Numbers\n");
    ft_printf("Negative number: %d\n", -12345);
    printf("Expected: Negative number: -12345\n\n");

    // Test 9: Pointers (if your ft_printf supports %p)
    printf("Test 9: Pointer\n");
    int a = 42;
    ft_printf("Pointer: %p\n", (void *)&a);
    printf("Expected: Pointer: %p\n\n", (void *)&a);
    return 0;
}
