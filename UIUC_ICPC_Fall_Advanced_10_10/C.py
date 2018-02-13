import numpy as np
C = int(raw_input())
for t in range(C):
    line = raw_input()
    k = int(line)
    line = raw_input()
    b = np.zeros(k)
    for i, bi in enumerate(line.split()):
        b[i] = bi
