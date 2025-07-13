////// EXPLAINSCRIPT COMPREHENSIVE // Test SUITE //////
// Test file for all parser functions and language features
// Run with: ./explainscript < Test_Suite.apl

////// VARIABLE DECLARATION // TestS //////
// Test basic variable declarations with 'let'
let x = 42;
let y = 3.14159;
let name = "ExplainScript";
let flag = true;

// Test typed variable declarations
int age = 25;
float pi = 3.14159;
string greeting = "Hello, World!";
bool isActive = true;

////// EXPRESSION EVALUATION // TestS //////
// Test arithmetic operations
let sum = 10 + 5;
let difference = 20 - 8;
let product = 6 * 7;
let quotient = 15 / 3;
let remainder = 17 % 5;
let power = 2 ** 8;

// Test mixed type arithmetic
let mixed1 = 5 + 2.5;
let mixed2 = 10.0 - 3;
let mixed3 = 4 * 2.5;

////// SELECTION // TestS //////
// Test if-else control structure
if (x > 30) {
    print("x is greater than 30");
} else {
    print("x is 30 or less");
}

// Nested if-else
if (age >= 18) {
    if (isActive == true) {
        print("Adult and active");
    } else {
        print("Adult but inactive");
    }
} else {
    print("Minor");
}

////// ITERATION // TestS //////
// Test while loop
let count = 0;
while (count < 5) {
    print("Count is: " + count);
    count = count + 1;
}

// Test for loop
for (let i = 0; i < 3; i = i + 1) {
    print("Iteration #" + i);
}

////// SEQUENCE AND STRING CONCATENATION //////
// Test basic sequence of commands and string operations
print(greeting);
let fullMessage = greeting + " Welcome to " + name + "!";
print(fullMessage);

////// NATURAL LANGUAGE INTERFACE // TestS //////
// Ask LLM for explanation
explain("What does the variable 'power' represent?");
ask ChatGPT("Why do we use loops in programming?");

////// END OF FILE // TestS //////
