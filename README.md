# C++-Mathematical Generators

##📚 Description

This project focuses on creating 10 different mathematical generators using Object-Oriented Programming (OOP) principles.
- Each generator performs operations with randomly generated big numbers, demonstrating various mathematical and statistical algorithms.
- The goal is to provide a modular, extensible system for mathematical random number generation and analysis.

---

##🚀 Key Features

🛠️ **Object-Oriented Design**: Base abstract class RandomGenerator with multiple derived generator classes.

🎲 **Random Number Generation**: Implementation of different random number generation techniques.

📊 **Histogram Analysis**: Ability to build histograms based on generated data.

🔄 **Scalable Design**: Easily extendable to include more generators.

---

## 💻 Technologies Used

🧠 C++

📦 Standard Library (STL): For vectors, random number generation, and mathematical functions.

---

## 🛠️ Installation

1. **Clone the repository**:
```bash
git clone https://github.com/Ivan2330/-C-mathematical-generators.git
```
2. **Navigate to the project folder**:
```bash
cd C-mathematical-generators
```
3. **Compile the project**:
```bash
g++ main1.cpp -o generator
```
4. **Run the program**:
```bash
./generator
```
---

## 🌐 Online Debugging with GDB

You can also conveniently run and debug the project online using platforms like GDB online:

GDB Online Compiler

### Steps:

1. Copy the contents of main1.cpp.

2. Paste it into the GDB Online Compiler.

3. Run and debug directly in the browser.

## 📊 Usage

- Follow on-screen instructions after running the executable.

- Example output includes generated numbers and histogram data.

## 🧠 Explanation of the Task

- The main objective of this project is to create multiple mathematical generators capable of producing sequences of random numbers using different mathematical algorithms. 
- Each generator ensures randomness, uniformity, and scalability.

## 🔑 Core Components:

### 1️⃣ Abstract Base Class (RandomGenerator)

Serves as the foundation for all generators.

Defines virtual methods for:

generate(int n) – Generate random numbers.

buildHistogram() – Analyze data distribution.

### 2️⃣ Linear Congruential Generator (LinearCongruentialGenerator)

Implements the Linear Congruential Method (LCM).

Formula: X(n+1) = (a * Xn + c) % m

Suitable for generating uniformly distributed random sequences.

### 3️⃣ Multiplicative Congruential Generator

A variation of LCM without an additive constant.

Efficient for simple random number generation.

### 4️⃣ Fibonacci Generator

Generates numbers based on the Fibonacci sequence.

Formula: Xn = (Xn-1 + Xn-2) % m

### 5️⃣ Inverse Congruential Method

Squares the previous number and takes the middle digits.

Simple but less reliable for long sequences.

### 6️⃣ 3-Sigma Method Generator

Generates numbers by summing two previous values.

Balanced distribution across large ranges.

### 7️⃣ Polar Coordinate Method Generator

Uses XOR and bit-shifting for fast random number generation.

Suitable for high-speed requirements.

### 8️⃣ Ratio Method Generator

Produces low-discrepancy sequences.

Often used in quasi-random sampling.

9️⃣ Logarithm method Generator

Similar to Halton but optimized for higher dimensions.

Ideal for simulations.

🔟 Arens Method Generator

Generates numbers following a Gaussian (Normal) distribution.

Essential for statistical modeling.

## 📊 Histogram Analysis

Visual representation of number distribution.

Parameters:

Number of bins

Minimum and maximum values

Helps evaluate the randomness and uniformity of generated numbers.

## 📝 Example Workflow:

Select a generator type.

Specify the number of random numbers.

Generate and display results.

Build a histogram.

Analyze the output.

## 🧩 Example Code Snippet

LinearCongruentialGenerator generator;
std::vector<double> numbers = generator.generate(100);
generator.buildHistogram(numbers, 10, 0.0, 1.0);

## 🤝 Contribution

- Fork the repository.

- Create a new branch.

- Submit a pull request with improvements.

- Ensure code consistency and add comments.

## 📜 License

This project is licensed under the MIT License.

## 👤 Author

- Ivan Kozhevnyk

- https://github.com/Ivan2330  

📧 Email: ivankozhevnyk@gmail.com

📱 Phone: +380991797047

Thank you for exploring C-Mathematical Generators! 🚀
