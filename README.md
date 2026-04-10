# 🚆 Railway Ticket Booking System using OpenMP
## 📌 Overview

This project demonstrates a **Railway Ticket Booking System** implemented using **OpenMP (parallel programming in C++)**.

The main goal is to show:

* How **parallel execution** works
* What is a **race condition**
* How **synchronization techniques** solve it
* Trade-off between **performance and correctness**

---

## 🎯 Objectives

* Understand **OpenMP parallel programming**
* Implement **serial and parallel versions**
* Identify and demonstrate **race conditions**
* Apply synchronization techniques:

  * Atomic
  * Critical Section
  * Locks
* Compare performance and correctness

---

## ⚙️ Implementations

### 🔵 1. Serial Version (Baseline)

* Runs on a single thread
* Processes passengers one by one

✔ Correct output
❌ No parallelism (slow)

---

### 🔴 2. Parallel WITHOUT Synchronization (Race Condition)

* Uses `#pragma omp parallel for`
* Multiple threads access shared variable `seats`

✔ Fast execution
❌ Incorrect results (race condition)
❌ Overbooking / negative seats possible

---

### 🟡 3. Parallel WITH Atomic (Partial Fix)

* Uses `#pragma omp atomic`
* Protects only the update operation (`seats--`)

✔ Faster than critical
❌ Condition check still unsafe
❌ Not fully reliable

---

### 🟢 4. Parallel WITH Critical Section (Full Fix)

* Uses `#pragma omp critical`
* Entire booking logic is protected

✔ Correct output
✔ No race condition
❌ Slower due to thread waiting

---

### 🔵 5. Parallel WITH Locks (Advanced Synchronization)

* Uses `omp_lock_t`
* Manual locking mechanism

✔ Safe and flexible
✔ Full control
❌ Complex implementation
❌ Risk of deadlock

---

## 🧠 Key Concepts

### 🔸 Parallelism

Execution of multiple tasks simultaneously using multiple threads.

### 🔸 Race Condition

Occurs when multiple threads access shared data simultaneously, leading to incorrect results.

### 🔸 Synchronization

Techniques used to control access to shared data:

* Atomic → protects single operation
* Critical → protects block of code
* Lock → manual control

---

## 📊 Comparison Table

| Method   | Correctness | Performance | Complexity |
| -------- | ----------- | ----------- | ---------- |
| Serial   | ✅           | Slow        | Easy       |
| No Sync  | ❌           | Fast        | Easy       |
| Atomic   | ⚠️          | Medium      | Easy       |
| Critical | ✅           | Medium      | Easy       |
| Lock     | ✅           | Medium      | Advanced   |

---

## ▶️ How to Run

### 📂 Step 1: Open Terminal (MinGW / Linux / Mac)

Navigate to your project folder:

```bash
cd "your-folder-path"
```

---

### ⚙️ Step 2: Compile

```bash
g++ -fopenmp "Serial_Version.cpp" -o serial
g++ -fopenmp "PARALLEL WITHOUT SYNCHRONIZATION.cpp" -o nosync
g++ -fopenmp "PARALLEL WITH ATOMIC (Partial Fix).cpp" -o atomic
g++ -fopenmp "PARALLEL WITH CRITICAL (Full Fix).cpp" -o critical
g++ -fopenmp "PARALLEL WITH LOCK (Advanced Control).cpp" -o lock
```

---

### ▶️ Step 3: Run

```bash
./serial
./nosync
./atomic
./critical
./lock
```

---

## 📷 Output Demonstration

* Serial → Correct sequential booking
* No Sync → Race condition (incorrect output)
* Atomic → Partial correction
* Critical → Fully correct output
* Lock → Fully correct with advanced control

---

## 🏁 Conclusion

This project demonstrates:

> Parallel execution improves speed, but without synchronization it leads to race conditions. OpenMP provides multiple synchronization techniques, each with trade-offs between performance and correctness.

---

## 🚀 Future Improvements

* Add graphical interface (GUI)
* Implement real-time booking simulation
* Optimize synchronization for better performance
* Extend to distributed systems

---

## 👨‍💻 Author

**Aditya Prasad**
