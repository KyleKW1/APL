// === EDGE CASES + MIXED TYPES ===
let intNum = 7;
let floatNum = 2.5;

let sum = intNum + floatNum;     // 9.5
let prec1 = 2 + 3 * 4 ** 2;       // 50
let prec2 = (2 + 3) * 4 ** 2;     // 80
let expRight = 2 ** 3 ** 2;       // 512
let modCheck = intNum % 3;        // 1

print(sum);
print(prec1);
print(prec2);
print(expRight);
print(modCheck);

// Type test
int v = 10;
float f = 4.2;
bool b = true;

print(v + f);     // 14.2
ask(sum);
