# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long, and every measurement was taken on the same machine, a MacBook Pro, so the results are comparable. Time was measured with clock() from time.h and converted to seconds by dividing by CLOCKS_PER_SEC. I ran baseline_loop three times, comparison_algorithms three times, and instrumentation_lab twice. In instrumentation_lab.c, I placed a pair of clock() calls directly around each of the three phases (build, process, reduce) and another pair around all three phases, so that TOTAL encloses every sub-measurement. All printf calls happen after the last measurement, so printing cannot distort the timings. The algorithm logic and the data were not modified.

## Observed Performance Differences

The baseline loop of 100,000,000 iterations took 0.728520, 0.741909 and 0.732487 seconds. The gap between the fastest and slowest run was 0.013389 seconds, about 1.8% of the fastest run. Identical code therefore produced close but not identical times.

In the algorithm comparison, the naive implementation took 4.551391, 4.838175 and 4.919456 seconds, an average of 4.769674 seconds. The single-pass implementation took 0.000184, 0.000158 and 0.000158 seconds, an average of 0.000167 seconds. The naive version was about 28,600 times slower. This matches the complexity difference: the naive version is O(n^2) and performs about 1.25 billion checks for n = 50000, while the single-pass version is O(n) and performs 50000. The naive runs also varied more in absolute terms (0.368065 seconds, about 8.1%) than the baseline loop.

In the instrumentation lab, the first run gave TOTAL 0.000772, BUILD_DATA 0.000328, PROCESS 0.000334 and REDUCE 0.000105 seconds. The second run gave TOTAL 0.000741, BUILD_DATA 0.000302, PROCESS 0.000332 and REDUCE 0.000102 seconds. PROCESS was the largest phase in both runs, closely followed by BUILD_DATA, while REDUCE was about three times smaller. In the second run the three phases add up to 0.000736 seconds, slightly below TOTAL, because TOTAL also includes the small cost of the extra clock() calls.

## Relation Between Runtime and Energy Consumption

This project did not measure power in watts, so I cannot state real energy use. Runtime is used as a proxy: while a program runs, the CPU is active, so a longer runtime generally means more CPU activity. In my measurements, the naive algorithm kept the CPU busy for about 4.77 seconds, while the single-pass algorithm needed about 0.000167 seconds for the same kind of scan. If code like this ran many times on a server, the difference would likely accumulate into higher energy use. This remains an inference from runtime, not a measured result.

## Limitations of the Experiment

First, clock() has limited resolution. The single-pass and instrumentation values are in the range of 0.0001 to 0.0008 seconds, so small errors affect them strongly and the 28,600 ratio is approximate. Second, I ran each program only two or three times, which is a small sample. Third, other processes on my machine may affect timings, as the variation in the baseline loop shows. Fourth, clock() measures CPU time, not power draw, so no direct energy conclusion is possible. Finally, results from one laptop may differ on other hardware.

## Practical Engineering Takeaway

The largest gain in my data came from choosing a better algorithm, not from small tweaks: moving from O(n^2) to O(n) reduced the measured time from 4.769674 to 0.000167 seconds. Before optimizing, an engineer should measure, so effort goes to the phase that dominates, which in my lab was PROCESS at about 0.000332 seconds. Measurements should be repeated on the same machine, and conclusions should stay within what the data supports.
