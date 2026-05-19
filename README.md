# C++
# 🖥️ Learning C++ from Scratch

A personal repository tracking my progress through a structured C++ bootcamp. Each folder corresponds to a topic, containing my notes, practice exercises, and solutions. My learning takes place in the order of the module presented below.
---

## 📋 Study Philosophy
- Self-practice in Visual Studio to truly understand each concept
- **Prefer the C++ way**, not the C way:
  - `std::cout` over `printf`
  - Header files without `.h`
  - `string` over `char[]` arrays
  - String functions over C-style manipulation

---

## 🗂️ Curriculum & Progress

### ✅ Module 1 — Programming Basics I
**Topics:** Program structure, compiling & linking, `#include`, writing to console, variables & data types, operators, basic I/O, `if` control flow

Key concepts: 
- using `cout`
- naming conventions (PascalCase vs camelCase)
- signed vs unsigned types
- data sizes
- operator precedence
- `++i` vs `i++`
- short-circuit evaluation (`||` vs `|`)

**Exercises:**
- [X] Min/max/sum/average calculator (no arrays, no `for` loop)

---

### ✅ Module 2 — Programming Basics II
**Topics:** Loops (`for`, `while`, `do-while`), `switch`, `break`/`continue`, fixed-size & multi-dimensional arrays

Key concepts: Loop nesting best practices, cache hits/misses, branch prediction, performance considerations for multi-dimensional array access

**Exercises:**
- [X] 3D array (50×50×50) application — read, write, and search values by coordinates

---

### ✅ Module 3 — Programming Basics III
**Topics:** Functions, overloads, templates, strings & string manipulation, ASCII vs Unicode (`wcout` vs `cout`), dynamic memory allocation (`new`/`delete`), structs

Key concepts: 
- divide and conquer with functions
- one function per purpose
- POD structs
- tokenisation
- substring
- concatenation

**Exercises:**
- [X] Palindrome checker (case-insensitive, no helper string functions)
- [X] Character/digit/punctuation frequency counter for a paragraph
- [X] Word counter for a sentence

---

### ✅ Module 4 — Programming Basics IV
**Topics:** Variable scope, pointers, constant pointer vs pointer-to-constant, type casting, optional function parameters, function pointers

Key concepts: 
- flexibility of function pointers vs hardcoding
- scoping
- memory management

**Exercises:**
- [X] Sum function with 2 mandatory + 3 optional parameters
- [X] Calculator using function pointers (plus, minus, multiply, divide, power)

---

### ✅ Module 5 — File I/O
**Topics:** Writing/reading ASCII text files, file access modes, binary vs ASCII file access, file positioning

Key concepts: 
- Locked files
- excessive flush vs no flush
- binary representation of data types (e.g. `double`)

**Exercises:**
- [X] Console-based Diary app (Add, Display All, Exit) — data persists to disk using `struct`

---

### ✅ Module 6 — Binary Data & Bit Manipulation
**Topics:** Data casting between types, storage in `char` arrays, reading via pointers, byte order (host vs network, little/big endian)

**Exercises:**
- [X] Upgrade Diary app to write/read data in binary format with a fixed struct layout (Date: 4 bytes, Subject: 50 bytes, Entry: 1024 bytes)

---

### ✅ Module 7 — Enumerations, Math, Templates
**Topics:** `enum`, math library functions (trig), function overloading, function templates

Key concepts: 
- Ambiguous overload errors
- `template<T>` syntax

**Exercises:**
- [] Template function to compute the sum of a primitive-type array

---

### ✅ Module 8 — Recursion
**Topics:** Recursion, stack overflow pitfalls, terminating conditions

Key concepts: Break problem → pass down the chain → collect results → process locally → return

**Exercises:**
- [] Factorial calculator using recursion + function templates (no math/standard libraries)

---

### ✅ Module 9 — Programming Practice & SDLC
**Topics:** SDLC methodologies (Waterfall, Iterative, Spiral, Agile, Scrum, TDD), pair programming, code reviews, problem-solving approaches (divide & conquer, top-down vs bottom-up)

**Exercises:**
- [] Leap year checker
- [] Digit-in-number checker (parsed as `long long`, no string functions)
- [] String compression (e.g. `aaabbbcc` → `a3b3c2`)

---

### ✅ Module 10 — STL Containers
**Topics:** `vector`, `list`, linked list, `map`; pros/cons of each; storing copies vs pointers in containers

**Exercises:**
- [] ID-to-name lookup using a suitable container
- [] Sorted insertion of random numbers into a container

---

### ✅ Module 11 — Object-Oriented Programming I
**Topics:** 4 pillars of OOP (encapsulation, abstraction, inheritance, polymorphism), classes, access modifiers, fields, methods, constructors, destructors, copy constructors

**Exercises:**
- [] Class hierarchy for `Administrator`, `BankOfficer`, and `Customer` with a shared base class

---

### ✅ Module 12 — Object-Oriented Programming II
**Topics:** OOP relationships (inheritance, dependency, association, composition, aggregation), UML diagrams (class, component, package, use case, state machine, sequence)

**Exercises:**
- [] Car simulator class hierarchy with UML class diagram (Chassis, Engine, Wheels, Seats)

---

### ✅ Module 13 — OOP Best Practices I
**Topics:** Clean handover, open/closed principle, backward compatibility ("if it ain't broken, don't fix it")

**Exercises:**
- [ ] Extend crate management system with 4 new crate types (Violet/Malachite, Dark Green/Uranium, Brown/Barite, Blue+Green/Lead+Manganese)

---

### ✅ Module 14 — OOP Best Practices II
**Topics:** Extending existing systems without breaking them

**Exercises:**
- [ ] Upgrade crate system: support 1–2 materials per crate
- [ ] Upgrade crate system: support up to 3 materials and 5 sizes (including XL: 4000 kg, XXL: 8000 kg)

---

### ✅ Module 15 — Network Programming: UDP
**Topics:** UDP programming, pros and cons

**Exercises:**
- [ ] UDP client-server: client sends strings, server displays them

---

### ✅ Module 16 — Network Programming: TCP
**Topics:** TCP programming, pros and cons

**Exercises:**
- [ ] TCP client-server: client sends strings, server displays them

---

### ✅ Module 17 — Threading
**Topics:** Creating threads, race conditions, deadlocks, locks/mutex/semaphores, threading best practices

**Exercises:**
- [ ] Upgrade UDP and TCP apps to send and receive simultaneously using threads

---

### ✅ Module 18 — Events & Callbacks
**Topics:** Events vs polling, function pointers recap, passing global/member functions as pointers, `typedef`

**Exercises:**
- [ ] Timer class that triggers a list of callback functions at a set interval
- [ ] Extend timer to accept class instances implementing a callback interface

---

### ✅ Module 19 — OOP + Networking + Threading (Capstone I)
**Topics:** Best practices integration — single responsibility, encapsulation, principle of least knowledge, naming conventions

**Exercises:**
- [ ] Reusable `UDP` class (bind, send, receive events with remote endpoint info)
- [ ] Reusable `TCP` class (connect/listen, send, raise connection/disconnection/message events)

---

### ✅ Module 20 — Banking Backend (Capstone II)
**Topics:** Interface Control Documents (ICDs), TCP binary messaging, multi-client server architecture

**Exercises:**
- [ ] Full banking backend over TCP supporting `CreateAccount`, `DeleteAccount`, `EnquireBalance`, `DepositMoney`, `WithdrawMoney` with binary message encoding

---

### ✅ Module 21 — UDP File Transfer (Capstone III)
**Topics:** UDP for file transfer, UML use case / activity / sequence diagrams

**Exercises:**
- [ ] Multi-server/multi-client UDP file storage app with server broadcasting, file listing, concurrent upload/download — includes UML paperwork

---

### ✅ Module 22 — Kinematics & Physics Simulation
**Topics:** Vectors, velocity, acceleration, angular velocity, 6-DOF, projectile motion, SI vs Imperial units, forces, drag

**Exercises:**
- [ ] Bomb drop simulator at 30,000 ft (2D, gravity only, 60 Hz, Excel-friendly output)
- [ ] Improve bomb sim to include air drag: FD = ½ρv²CDA

---

### ✅ Module 23 — Proportional Navigation
**Topics:** Constant bearing decreasing range, proportional navigation guidance law

**Exercises:**
- [ ] Homing missile sim — strike target within 5 m accuracy (600 m/s missile, 300 m/s target, 120 Hz)
- [ ] Improve to maintain accuracy at 60 Hz

---

### ✅ Module 24 — Sorting Algorithms
**Topics:** Big-O notation, insertion sort, shell sort, bubble sort, merge sort, quicksort; when to use each

**Exercises:**
- [ ] Insertion sort (smallest to largest, no libraries)
- [ ] Bubble sort (smallest to largest, no libraries)
- [ ] Bonus: Performance profiling of all sorts on 2000 numbers using `GetTickCount()`

---

### ✅ Module 25 — Search Algorithms
**Topics:** Sequential search, binary search, jump search; O(n) comparison; usage scenarios

**Exercises:**
- [ ] Sequential search on user-entered series
- [ ] Binary search on sorted series

---

### ✅ Module 26 — Data Structures
**Topics:** Stack, queue, linked list (singly/doubly), hash table (`map`), trees & binary trees; read-only structs as return values

**Exercises:**
- [ ] Sorted doubly linked list — implement from scratch (no STL)

---

## 🛠️ Setup

- **IDE:** Visual Studio 2026
- **Language:** C++ (modern, not C-style)
- **Compiler:** MSVC

---

## 📁 Repo Structure

```
📦 cpp-learning
 ├── 01-basics-1/
 ├── 02-basics-2/
 ├── 03-functions-strings/
 ├── 04-pointers-scope/
 ├── 05-file-io/
 ├── 06-binary-data/
 ├── 07-enums-templates/
 ├── 08-recursion/
 ├── 09-practice-sdlc/
 ├── 10-stl-containers/
 ├── 11-oop-1/
 ├── 12-oop-2-uml/
 ├── 13-oop-best-practices-1/
 ├── 14-oop-best-practices-2/
 ├── 15-networking-udp/
 ├── 16-networking-tcp/
 ├── 17-threading/
 ├── 18-events-callbacks/
 ├── 19-capstone-networking-oop/
 ├── 20-capstone-banking-backend/
 ├── 21-capstone-file-transfer/
 ├── 22-kinematics/
 ├── 23-proportional-navigation/
 ├── 24-sorting-algorithms/
 ├── 25-search-algorithms/
 └── 26-data-structures/
```
- Revisit earlier modules during recap days
