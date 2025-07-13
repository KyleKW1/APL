// ExplainScript Test File - test.apl
// This file demonstrates all core features of the ExplainScript language

// ============= VARIABLE DECLARATIONS =============
// Test automatic type inference
let x = 10;
let y = 3.14;
let flag = true;

// Test explicit type declarations
int counter = 0;
float pi = 3.14159;
bool isActive = false;

// ============= ARITHMETIC OPERATIONS =============
// Test PEMDAS/BODMAS precedence
let result1 = 2 + 3 * 4;          // Should be 14 (not 20)
let result2 = (2 + 3) * 4;        // Should be 20
let result3 = 2 ** 3 + 1;         // Should be 9 (8 + 1)
let result4 = 15 / 3 * 2;         // Should be 10 (left-to-right)
let result5 = 17 % 5;             // Should be 2 (modulo)

// Test with variables
let calc1 = x + y;                // 10 + 3.14 = 13.14
let calc2 = x * 2 - 5;            // 10 * 2 - 5 = 15

// ============= PRINT STATEMENTS =============
print(x);
print(result1);
print(calc1);
print(flag);

// ============= ASSIGNMENTS =============
x = 25;
y = x / 5;
flag = false;

// ============= SELECTION (IF/ELSE) =============
if (x > 20) {
    print(x);
    let temp = x * 2;
    print(temp);
}

if (flag) {
    print(1);
} else {
    print(0);
}

// Test complex conditions
if (x > 15 && y < 10) {
    print(x + y);
}

if (result1 == 14 || result2 == 20) {
    print(999);
}

// ============= ITERATION (LOOPS) =============
// While loop
let i = 5;
while (i < 9) {
    print(i);
    i = i + 1;
}

// For loop
for (counter = 1; counter <= 5; counter = counter + 1) {
    print(counter);
}

// ============= LOGICAL OPERATIONS =============
let bool1 = true;
let bool2 = false;
let logicResult1 = bool1 && bool2;    // false
let logicResult2 = bool1 || bool2;    // true
let logicResult3 = !bool1;            // false

print(logicResult1);
print(logicResult2);
print(logicResult3);

// ============= COMPARISON OPERATIONS =============
let comp1 = 5 > 3;                    // true
let comp2 = 10 <= 10;                 // true
let comp3 = 7 != 8;                   // true
let comp4 = 4.5 >= 4.0;               // true

print(comp1);
print(comp2);

// ============= COMPLEX EXPRESSIONS =============
let complex1 = (x + y) * 2 - 10 / 5;
let complex2 = x ** 2 + y ** 2;
let complex3 = (x > y) && (x < 100);

print(complex1);
print(complex2);
print(complex3);

// ============= NESTED STATEMENTS =============
if (x > 10) {
    let nested = x * 2;
    if (nested > 40) {
        print(nested);
        while (nested > 30) {
            nested = nested - 5;
            print(nested);
        }
    }
}

// ============= LLM INTERFACE TESTING =============
// Ask the LLM to explain variables
ask(x);
ask(pi);
ask(flag);

// ============= UNARY OPERATIONS =============
let negative = -x;
let positive = -negative;
let notFlag = !flag;

print(negative);
print(positive);
print(notFlag);

// ============= MIXED TYPE OPERATIONS =============
let mixedInt = 5;
let mixedFloat = 2.5;
let mixedResult = mixedInt + mixedFloat;  // Should be 7.5

print(mixedResult);

// ============= SEQUENCE TESTING =============
// Multiple statements in sequence
let a = 1;
let b = 2;
let c = 3;
let sum = a + b + c;
print(sum);

// Compound statements
{
    let localVar = 100;
    print(localVar);
    localVar = localVar + 50;
    print(localVar);
}

// ============= EDGE CASES =============
// Test precedence with parentheses
let prec1 = 2 + 3 * 4 ** 2;           // 2 + (3 * (4^2)) = 2 + 48 = 50
let prec2 = (2 + 3) * 4 ** 2;         // (2 + 3) * (4^2) = 5 * 16 = 80
let prec3 = 2 + (3 * 4) ** 2;         // 2 + (12^2) = 2 + 144 = 146

print(prec1);
print(prec2);
print(prec3);

// Test boolean expressions
let boolExpr1 = true && false || true;   // Should be true
let boolExpr2 = true && (false || true); // Should be true
let boolExpr3 = (true && false) || true; // Should be true

print(boolExpr1);
print(boolExpr2);
print(boolExpr3);

// ============= FINAL VALIDATION =============
// Test all comparison operators
let val1 = 10;
let val2 = 20;

print(val1 < val2);   // true
print(val1 > val2);   // false
print(val1 <= val1);  // true
print(val2 >= val1);  // true
print(val1 == val1);  // true
print(val1 != val2);  // true

// Test unary minus with expressions
let negExpr = -(val1 + val2);  // -30
print(negExpr);

// Test exponentiation associativity (right-to-left)
let expTest = 2 ** 3 ** 2;     // 2^(3^2) = 2^9 = 512
print(expTest);

// Test division producing float results
let divTest = 7 / 2;           // 3.5
print(divTest);

// Test modulo with variables
let modTest = val2 % 3;        // 20 % 3 = 2
print(modTest);

// Final LLM explanation request
ask(sum);