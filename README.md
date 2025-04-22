# 🧮 Matrix_nxn Project

A modular and extensible C++ project implementing a `squaredMatrix` class with full operator overloading, matrix algebra operations, scalar arithmetic, and inversion logic using cofactors and transposition. This project includes unit testing using `doctest`, and builds via `make`.

---

## 📁 Project Structure

```
Matrix_nxn/
├── Matrix_nxn.hpp       # Matrix class definition and function declarations
├── Matrix_nxn.cpp       # Matrix method implementations
├── Matrix_output.cpp    # Demo and example usage of the matrix class
├── Matrix_tests.cpp     # Unit tests using doctest
├── makefile             # Build automation and test runner
├── AI_Prompts           # Documentation of iterative development decisions
```

---

## 🚀 Features

### ✅ Core Matrix Operations

| Operation        | Operator Overload | Description                                  |
|------------------|-------------------|----------------------------------------------|
| Addition         | `+`, `+=`         | Matrix-wise addition                         |
| Subtraction      | `-`, `-=`         | Matrix-wise subtraction                      |
| Multiplication   | `*`, `*=`         | Matrix multiplication and scalar multiplication |
| Division         | `/`, `/=`         | Scalar division, or multiplication by inverse |
| Modulo           | `%`, `%=`         | Element-wise multiplication and mod with scalar |
| Transpose        | `~`               | In-place transpose                           |
| Determinant      | `!`               | Recursive cofactor-based determinant         |
| Power            | `^`               | Matrix exponentiation                        |
| Increment        | `++`, `--`        | Pre/post increment & decrement               |
| Index Access     | `[]`              | Row access (mutable & const)                 |
| Comparison       | `==`, `!=`, `<`, `>`, `<=`, `>=` | Sum-based matrix comparisons         |
| Stream Output    | `<<`              | Overloaded `ostream` for printing            |

---

## 🧠 Matrix Inversion

The method used for inverting a matrix in this project is the **Cofactor-Transpose-Determinant** method. This was chosen for its clarity and educational value.

### 🧪 Comparison of Inversion Methods

| Method                         | Description                                              |
|--------------------------------|----------------------------------------------------------|
| Gauss-Jordan Elimination       | Row reduction to identity matrix                         |
| LU Decomposition               | Factorizes matrix into lower and upper triangular forms  |
| ✅ Cofactor-Transpose-Determinant | Current method. Cofactor matrix, transpose, then divide by determinant |

**Rationale**: This method was implemented to meet assignment constraints and for pedagogical transparency. The inversion logic is implemented in `invertHelper()`.

---

## 🧪 Testing with `doctest`

Unit tests are provided using the lightweight `doctest` framework. They cover:

- Matrix arithmetic
- Transpose and determinant
- Power and scalar operations
- Modulo and element-wise multiplication
- All comparison operators
- Stream output

To run tests:
```bash
make test
```

---

## 🔧 Build Instructions

Use the provided `makefile` to build the project:

```bash
make          # Builds the main executable: Matrix_output
make run      # Runs the demo
make test     # Runs doctest test cases
make clean    # Removes object files and binaries
```

---

## 🧩 Sample AI Prompt Documentation

From `AI_Prompts`:
> "To invert the matrix I decided to use the cofactor method followed by transposition, then scaled by the reciprocal of the determinant. This provides a straightforward and accurate inversion for square matrices."

The file logs reasoning for design decisions, function enhancements, and debugging traces.

---

## 📌 Notes

- Only supports **square matrices**.
- Handles out-of-bounds access via runtime exceptions.
- Determinant uses recursive minor expansion (costly for large matrices).

---

## 👨‍💻 Author

Amit Nachum  
Matrix Implementation, Testing & Documentation by AI-guided programming
