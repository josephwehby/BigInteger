#!/usr/bin/python3

import matplotlib.pyplot as plt
import numpy as np

file1 = "multiply.txt"

x_mult = []
y_mult = []

with open(file1, "r") as f:
    for line in f:
        values = line.split()
        x_mult.append(int(values[0]))
        y_mult.append(float(values[1])/1000)

file2 = "divide.txt"

x_div = []
y_div = []

with open(file2, "r") as f:
    for line in f:
        values = line.split()
        x_div.append(int(values[0]))
        y_div.append(float(values[1])/1000)

file3 = "bytes.txt"

x_bytes = []
y_bytes = []

with open(file3, "r") as f:
    for line in f:
        values = line.split()
        x_bytes.append(int(values[0]))
        y_bytes.append(float(values[1])/1000)

plt.figure(figsize=(10,6))
plt.plot(x_mult, y_mult, linestyle="solid", color="blue", label="BigInt * BigInt")
plt.plot(x_div, y_div, linestyle="solid", color="orange", label="BigInt / SmallInt")
plt.plot(x_bytes, y_bytes, linestyle="solid", color="green", label="Bytes to BigInt")
plt.title("Various BigInt Operations")
plt.xlabel("Number of Digits and Length of Input")
plt.ylabel("Time in Seconds")
plt.legend();
plt.show()

plt.savefig("metrics.jpg", format="jpg")
