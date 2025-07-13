// Basic Operations Test - test_basic.apl
// This file tests basic arithmetic and variable operations

// Variable declarations with type inference
let x = 10;
let y = 20;
let z = 5;

// Basic arithmetic operations (PEMDAS/BODMAS)
let sum = x + y;
let difference = y - x;
let product = x * z;
let quotient = y / z;
let remainder = y % 3;
let power = z ** 2;

// Print results
print(sum);        // Expected: 30
print(difference); // Expected: 10
print(product);    // Expected: 50
print(quotient);   // Expected: 4.0
print(remainder);  // Expected: 2
print(power);      // Expected: 25.0

// Complex expression
let complex = 2 + 3 * 4 - 1;
print(complex);    // Expected: 13

// Explanation feature
explain("Testing basic arithmetic operations");
explain(sum);

// Parentheses for precedence
let precedence1 = 2 + 3 * 4;      // 14
let precedence2 = (2 + 3) * 4;    // 20
print(precedence1);
print(precedence2);

// Unary minus
let negative = -x;
print(negative);   // Expected: -10