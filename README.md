# LoopUnrolledVector
Mathematical vector class for N dimensional real and complex vectors. Loop operations are unrolled using templates.

Due to the removed looping variables and operations, loop unrolled vector operations are about 2 times faster.

Here are the results of a performance test:

```
Summing 100 million vectors...

(-5.91307e+06,-1.34707e+06,-9.05868e+06)
Array: 338 msec

(-5.91307e+06,-1.34707e+06,-9.05868e+06)
Loop unrolled array: 113 msec

(-5.91307e+06,-1.34707e+06,-9.05868e+06)
LuVector: 112 msec
```

## How to use?
Just include the headers and start using it. See the examples in "main.cpp".
