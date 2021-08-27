import matplotlib.pyplot as plt
import numpy as np

timestamps = []
data = []
with open('data/data_long.txt', 'r') as f:
    for line in f.readlines():
        _, time, total, _, _, _ = [int(x.strip()) for x in line.split()]
        timestamps.append(time / 1000.0)
        data.append(total / (1024.0 * 1024.0))

plt.figure(figsize=(10, 5))
plt.xticks(np.arange(min(timestamps), max(timestamps) + 1, 500.0))
plt.yticks(np.arange(min(data), max(data) + 0.25, 0.5))
plt.fill_between(timestamps, data, step='post', alpha=0.4)
plt.step(timestamps, data, where="post", linewidth=0.5)
plt.title("Wynik działania narzędzia Massif")
plt.xlabel("Czas [s]")
plt.ylabel("Zużycie pamięci [MB]")
plt.savefig("massif_plot.pdf")