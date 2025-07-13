////// EXPLAINSCRIPT COMPREHENSIVE//Test SUITE //////
//Test file for all parser functions and language features
//Run with: ./explainscript < //Test_suite.apl

////// VARIABLE DECLARATION //TestS //////
//Test basic variable declarations with 'let'
let x = 42;
let y = 3.14159;
let name = "ExplainScript";
let flag = true;

//Test typed variable declarations
int age = 25;
float pi = 3.14159;
string greeting = "Hello, World!";
bool isActive = true;

 ////// EXPRESSION EVALUATION //TestS //////
//Test arithmetic operations
let sum = 10 + 5;
let difference = 20 - 8;
let product = 6 * 7;
let quotient = 15 / 3;
let remainder = 17 % 5;
let power = 2 ** 8;

//Test mixed type arithmetic
let mixed1 = 5 + 2.5;
let mixed2 = 10.0 - 3;
let mixed3 = 4 * 2.5;

//Test comparison operations
//let equal = 5 // 5;
//let notEqual = 5 != 3;
//let lessThan = 3 < 7;
//let lessEqual = 5 <= 5;
//let greaterThan = 8 > 4;
//let greaterEqual = 6 >= 6;

//Test logical operations
let andResult = true && false;
let orResult = true || false;
let notResult = !true;

//Test unary operations
let negative = -42;
let positive = +15;

//Test parentheses for precedence
let complex = (5 + 3) * 2 - 1;
let nested = ((10 + 5) / 3) * 2;

//////// ASSIGNMENT //TestS //////
//Test regular assignment
x = 100;
y = 2.71828;
name = "Updated Name";
flag = false;

//Test compound assignment
x += 10;
y -= 0.5;
sum *= 2;
difference /= 2;

 ////// CONTROL FLOW //TestS //////
//Test if statements
if (x > 50) {
    print("x is greater than 50");
}

//Test if-else statements
if (flag) {
    print("Flag is true");
} else {
    print("Flag is false");
}

//Test nested if statements
if (x > 0) {
    if (y > 0) {
        print("Both x and y are positive");
    } else {
        print("x is positive, y is not");
    }
}

//Test while loops
int counter = 0;
while (counter < 3) {
    print(counter);
    counter += 1;
}

//Test for loops
for (int i = 0; i < 5; i += 1) {
    print(i);
}

//Test nested loops
for (int i = 0; i < 2; i += 1) {
    for (int j = 0; j < 2; j += 1) {
        print(i * 2 + j);
    }
}

 ////// INPUT/OUTPUT //TestS //////
//Test print statements with different types
print(x);
print(y);
print(name);
print(flag);
print(sum);

//Test print with expressions
print(x + y);
print(name + " - Version 1.0");
print(flag && true);

//Test input statements
 input(userAge);
 input(userName);

 ////// EXPLAIN FEATURE //TestS //////
//Test explaining variables
explain(x);
explain(y);
explain(name);
explain(flag);

//Test explaining with custom messages
explain("This is a custom explanation");
explain("//Testing arithmetic operations");
explain("Demonstrating control flow");

 ////// SEMANTIC ANALYSIS //TestS //////
//These will trigger semantic analysis during parsing
let semantic//Test1 = 5 + 3 * 2;
let semantic//Test2 = (10 > 5) && (3 < 7);
let semantic//Test3 = "Hello" + " " + "World";

 ////// ERROR HANDLING //TestS //////
//Test division by zero (should be caught)
 let divZero = 10 / 0;

//Test modulo by zero (should be caught)
 let modZero = 10 % 0;

//Test undeclared variable (should be caught)
 print(undeclaredVar);

 ////// COMPLEX EXPRESSION //TestS //////
//Test complex mathematical expressions
let mathExpr1 = 2 * 3 + 4 * 5 - 6 / 2;
let mathExpr2 = (2 + 3) * (4 - 1) / 2;
let mathExpr3 = 2 ^ 3 + 4 ^ 2 - 5 ^ 1;

//Test complex logical expressions
let logicExpr1 = (5 > 3) && (2 < 4) || (1 // 1);
let logicExpr2 = !(false || true) && (true && !false);
let logicExpr3 = (x > 0) && (y > 0) && (sum > 0);

 ////// FUNCTION INTEGRATION //TestS //////
//Test all parser functions indirectly through language constructs

 Symbol table operations
let symbol//Test1 = 1;
let symbol//Test2 = 2;
let symbol//Test3 = 3;
symbol//Test1 = symbol//Test2 + symbol//Test3;

//Type checking and conversion
int intVar = 42;
float floatVar = 3.14;
bool boolVar = true;
string stringVar = "Test";

//Memory management Tests
string str1 = "First string";
string str2 = "Second string";
str1 = str2;
str1 = "Third string";

 ////// CLOUD FUNCTION TEST //////
 These should trigger cloud function calls if enabled
explain("Testing cloud integration");
let cloudTest = 1 + 1;
explain(cloudTest);

 ////// LLM INTEGRATION //TestS //////
//Test different types of explanations
explain("variable declaration");
explain("arithmetic operation");
explain("conditional statement");
explain("loop iteration");
explain("assignment operation");
explain("comparison operation");

 ////// PRECEDENCE AND ASSOCIATIVITY TESTS //////
//Test operator precedence
let precedence1 = 2 + 3 * 4;           Should be 14, not 20
let precedence2 = 2 * 3 + 4;           Should be 10, not 14
let precedence3 = 10 - 5 + 2;          Should be 7 (left associative)
let precedence4 = 16 / 4 / 2;          Should be 2 (left associative)
let precedence5 = 2 ^ 3 ^ 2;           Should be 512 (right associative)

//Test logical precedence
let logicPrecedence1 = true || false && true;   Should be true
let logicPrecedence2 = !true || false;          Should be false
let logicPrecedence3 = true && false || true;   Should be true

 ////// BLOCK STATEMENT //TESTS //////
{
    let blockVar = 42;
    print(blockVar);
    {
        let nestedBlockVar = 24;
        print(nestedBlockVar);
    }
}

 ////// STRESS //TestS //////
//Test with many variables
let stress1 = 1;
let stress2 = 2;
let stress3 = 3;
let stress4 = 4;
let stress5 = 5;
let stressSum = stress1 + stress2 + stress3 + stress4 + stress5;

//Test with deep nesting
if (true) {
    if (true) {
        if (true) {
            if (true) {
                print("Deep nesting works");
            }
        }
    }
}

//Test with long expressions
let longExpr = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
let longLogic = true && true && true && true && true;

 ////// FINAL OUTPUT //TestS //////
print("=Test Results =");
print("Integer Test: ");
print(x);
print("Float Test: ");
print(y);
print("String Test: ");
print(name);
print("Boolean Test: ");
print(flag);
print("Arithmetic Test: ");
print(sum);
print("Logic Test: ");
print(andResult);
print("Comparison Test: ");
print(equal);

 ////// EXPLAIN ALL MAJOR VARIABLES //////
explain(x);
explain(y);
explain(name);
explain(flag);
explain(sum);
explain(andResult);
explain(equal);

 ////// CLEANUP //TestS //////
//Test variable reassignment and cleanup
x = 0;
y = 0.0;
name = "";
flag = false;

print("= CleanupTest =");
print(x);
print(y);
print(name);
print(flag);

 ////// END OF TESTS //////
print("All Tests completed!");
explain("Test suite execution finished");