# Basic Syntax (Level 1)

## 1. Structure of a C++ Program

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!";
    return 0;
}
```

- `#include <iostream>` — imports input/output library  
- `using namespace std;` — allows use of `cout`, `cin` without `std::`  
- `int main()` — entry point of a C++ program  
- `return 0;` — indicates program ended successfully  

---

## 2. Variables & Data Types
### Common types:
- `int` — integers  
- `long long` — large integers  
- `double` — floating point numbers  
- `char` — single character  
- `string` — text  
- `bool` — true/false  

Example:
```cpp
int a = 10;
double pi = 3.14;
char c = 'A';
string name = "Ray";
bool ok = true;
```

---

## 3. Input and Output
### Output
```cpp
cout << "Hello!";
```

### Input
```cpp
int x;
cin >> x;
```

---

## 4. Conditions (if / else)
```cpp
if (x > 10) {
    cout << "big";
} else if (x == 10) {
    cout << "equal";
} else {
    cout << "small";
}
```

---

## 5. Loops

### For loop
```cpp
for (int i = 0; i < 5; i++) {
    cout << i << " ";
}
```

### While loop
```cpp
while (x > 0) {
    x--;
}
```

---

## 6. Arrays
```cpp
int a[5] = {1, 2, 3, 4, 5};
cout << a[2]; // prints 3
```

---

## 7. Functions
```cpp
int add(int a, int b) {
    return a + b;
}
```
Calling:
```cpp
cout << add(3, 4);
```

---

## 8. Strings
```cpp
string s = "hello";
cout << s.size();
cout << s[0];
```

---

## 9. Comments
```cpp
// Single-line comment

/* Multi-line
   comment */
```

---

## 10. Using std::vector
```cpp
#include <vector>
vector<int> v = {1, 2, 3};
v.push_back(4);
sort(v.begin(), v.end());
```

---

## 11. Compilation & Execution
### Compile:
```
g++ main.cpp -o main
```

### Run:
```
./main
```

---
