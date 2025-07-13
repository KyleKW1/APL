// === MATH, LOGIC, CONTROL ===
let a = 20;
let b = 10;
let c = 3.5;

int total = a + b;
float ratio = b / c;
bool check = (a < b) && (c > 1.0);
let diff = b - a;    // negative result: -10

print(total);
print(ratio);
print(check);
print(diff);

// Nested logic
if (a < b) {
    if (c < 4.0) {
        print(1);
    } else {
        print(2);
    }
} else {
    print(0);
}

