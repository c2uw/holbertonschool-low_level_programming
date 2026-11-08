# Algorithmic Efficiency Comparison

## Raw results

| Run | Naive time (s) | Single-pass time (s) |
|-----|----------------|----------------------|
| 1   | 4.551391       | 0.000184             |
| 2   | 4.838175       | 0.000158             |
| 3   | 4.919456       | 0.000158             |

## Averages

- Naive average: 4.769674 seconds
- Single-pass average: 0.000167 seconds

## Relative difference

The naive implementation is ~28,600 times slower than the single-pass implementation (4.769674 / 0.000167).

## Notes

The naive version is O(n^2) (about 1.25 billion checks for n = 50000) while the single-pass version is O(n) (50000 checks). Runtime is used only as a proxy for CPU activity. The single-pass times are very small, so they are close to the resolution limit of clock().
