# Resource Utilization

## Vitis HLS Synthesis

Target device:

```text
xc7z020clg400-1
```

| Resource | Used |
|---|---:|
| LUT | 674 |
| FF | 799 |
| BRAM | 0 |
| DSP | 3 |

Reported latency:

```text
690000
```

## Verification

The C simulation produced the expected matrix multiplication result:

```text
4   6   5   5
12 14  13 13
20 22  21 21
28 30  29 29
```

## Hardware Status

- HLS synthesis: Completed
- IP packaging: Completed
- Vivado integration: Completed
- Design validation: Successful
- Implementation: Completed
- Bitstream generation: Completed
- PYNQ-Z2 programming: Successful
