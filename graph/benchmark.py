import matplotlib.pyplot as plt
import numpy as np

file = "../output.txt"

x = []
y = []

with open(file, "r") as f:
    for line in f:
        values = line.split()
        x.append(int(values[0]))
        y.append(int(values[1]))

plt.figure(figsize=(10,6))
plt.plot(x, y, linestyle="solid")

x_min, x_max = int(np.floor(min(x))), int(np.ceil(max(x)))
y_min, y_max = int(np.floor(min(y))), int(np.ceil(max(y)))

x_ticks = np.arange(x_min, x_max + 1, 200)
y_ticks = np.arange(y_min, y_max + 1, 10)

plt.xticks(x_ticks, rotation=45)
plt.yticks(y_ticks)

plt.title("Multiplication with BigInts")
plt.xlabel("Number of Digits")
plt.ylabel("Time in Milliseconds")
plt.show()
