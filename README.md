# Hardware Matrix Multiplication Accelerator using Vitis HLS

> FPGA-based 4×4 matrix multiplication accelerator implemented using **Vitis HLS, Vivado 2026.1, and the PYNQ-Z2 (Zynq-7000) platform**.

## Overview

This project implements a hardware accelerator for multiplying two **4×4 integer matrices**:

\[
C = A \times B
\]

The matrix multiplication algorithm is written in C/C++ and synthesized into FPGA hardware using **Vitis High-Level Synthesis (HLS)**. The generated HLS IP is then packaged and integrated with the **Zynq Processing System** in Vivado through an AXI interface.

The complete flow covered in the experiment was:

```text
C/C++ Algorithm
      ↓
Vitis HLS
      ↓
C Simulation
      ↓
C Synthesis
      ↓
RTL / HLS IP
      ↓
Package IP
      ↓
Vivado Block Design
      ↓
Zynq Processing System
      ↓
Implementation
      ↓
Bitstream
      ↓
PYNQ-Z2 FPGA
```

## Objectives

- Implement 4×4 matrix multiplication in C/C++.
- Verify the algorithm using an HLS testbench.
- Synthesize the algorithm into FPGA hardware using Vitis HLS.
- Analyze FPGA resource utilization.
- Package the synthesized design as reusable IP.
- Integrate the IP with the Zynq Processing System in Vivado.
- Generate and download the FPGA bitstream to the PYNQ-Z2.

## Hardware & Software

### Hardware

- PYNQ-Z2 FPGA Board
- USB cable
- PC

### Software

- Vitis Unified IDE 2026.1
- Vivado 2026.1

### Target Device

```text
xc7z020clg400-1
```

## Matrix Multiplication

For two 4×4 matrices, each output element is calculated using the dot product of one row of `A` and one column of `B`.

A complete 4×4 multiplication requires:

- 16 output elements
- 4 multiplications per output element
- **64 multiplication operations**


## Project Structure

```text
Hardware-Matrix-Multiplication-Vitis-HLS/
│
├── README.md
│
├── src/
│   └── matrix_mul.cpp
│
├── tb/
│   └── matrix_mul_tb.cpp
│
├── results/
│   └── resource_utilization.md
│
└── docs/
    └── Hardware_Matrix_Multiplication_Vitis_HLS_Report.pdf
```

## HLS Source

The top-level HLS function is:

```cpp
void matrix_mul(int A[N][N], int B[N][N], int C[N][N])
```

The implementation uses three nested loops:

1. Row loop
2. Column loop
3. Product/accumulation loop

The inner loop performs the multiply-accumulate operation:

```cpp
sum += A[i][k] * B[k][j];
```

The output is then stored in:

```cpp
C[i][j] = sum;
```

AXI4-Lite interfaces are specified for the function arguments and return control.

## Testbench

The testbench uses the following matrices.

### Matrix A

```text
1   2   3   4
5   6   7   8
9  10  11  12
13 14  15  16
```

### Matrix B

```text
1  0  0  1
0  1  1  0
1  0  1  0
0  1  0  1
```

### Expected Output

```text
4   6   5   5
12 14  13 13
20 22  21 21
28 30  29 29
```

The HLS C simulation matched the expected matrix multiplication result, confirming functional correctness.

## Synthesis Results

The reported HLS synthesis results were:

| Resource | Utilization |
|---|---:|
| LUT | 674 |
| FF | 799 |
| BRAM | 0 |
| DSP | 3 |
| Reported Latency | 690000 |

The synthesis report confirmed successful scheduling and hardware generation for the matrix multiplication function.

## Vivado Integration

The synthesized HLS IP was packaged and integrated into a Vivado block design with the **Zynq Processing System** through the AXI interface.

The design was successfully validated before implementation.

## Bitstream & Hardware Programming

Vivado successfully completed:

- Synthesis
- Implementation
- Timing checks
- Bitstream generation

The generated bitstream was downloaded to the **PYNQ-Z2 FPGA through JTAG using Vivado Hardware Manager**. The Hardware Manager confirmed successful FPGA programming.

## Applications

Matrix multiplication accelerators are commonly used in:

- Artificial Intelligence
- Machine Learning
- Digital Signal Processing
- Image Processing
- Computer Vision
- Robotics
- Scientific Computing
- Embedded Hardware Acceleration

## Key Concepts Learned

- High-Level Synthesis (HLS)
- C/C++ to RTL conversion
- FPGA hardware acceleration
- Matrix multiplication hardware architecture
- AXI interfaces
- Zynq Processing System
- Vivado IP integration
- FPGA resource utilization
- DSP-based arithmetic acceleration
- Bitstream generation and FPGA programming

## Result

The **4×4 hardware matrix multiplication accelerator** was successfully designed using Vitis HLS, verified through C simulation, synthesized into FPGA hardware, packaged as an IP core, integrated with the Zynq Processing System in Vivado, and programmed onto the PYNQ-Z2 FPGA.

This experiment demonstrates the complete workflow from a **high-level C/C++ algorithm to a working FPGA hardware accelerator**.

## Documentation

The complete experiment report is available in:

```text
docs/Hardware_Matrix_Multiplication_Vitis_HLS_Report.pdf
```

## Author

**Chinmay N. Yalawatti**  
Electronics & Communication Engineering  
KLE Technological University, BVB Campus

---

### Tools

`Vitis HLS` · `Vivado 2026.1` · `C/C++` · `AXI` · `Zynq-7000` · `PYNQ-Z2` · `FPGA`
