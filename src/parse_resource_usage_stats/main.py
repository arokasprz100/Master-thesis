import datetime
import pandas as pd
import matplotlib.pyplot as plt


def plot_data(x, y, xlabel=None, ylabel=None, title=None, verticals=list(), legend_pos='upper left'):
    plt.figure(figsize=(10, 5), dpi=400)
    ax = plt.subplot()
    plt.yscale("log")
    if ylabel:
        ax.set_ylabel(ylabel)
    if xlabel:
        ax.set_xlabel(xlabel)
    if title:
        plt.title(title)
    for vertical in verticals:
        plt.axvline(vertical[0], linestyle='dotted', linewidth=0.5, color=vertical[1], label=vertical[2])
    plt.xticks(rotation=70)
    plt.plot(x, y, label=ylabel)
    plt.legend(loc=legend_pos)
    plt.tight_layout()


data = pd.read_csv("./data/ggss_resource_usage_05_08_2021.txt", delim_whitespace=True, na_values=["GGSS", "is", "not", "running!"])
data.rename(columns={data.columns[0]: "DATE", data.columns[1]: "TIME"}, inplace=True)
data["DATETIME"] = data[["DATE", "TIME"]].apply(lambda row: "-".join(row.values.astype(str)), axis=1)
data["DATETIME"] = pd.to_datetime(data["DATETIME"], format="%Y.%m.%d-%H:%M:%S")

subdata = data[data["DATETIME"].between(datetime.datetime(2021, 8, 10, 12), datetime.datetime(2021, 8, 12))]

verticals = [
    (datetime.datetime(2021, 8, 10, 18, 14), 'red', 'Rozpoczęcie testu z użyciem Valgrind'),
    (datetime.datetime(2021, 8, 11, 13, 44), 'red', ''),
    (datetime.datetime(2021, 8, 9, 19, 42), 'red', '')
]
plot_data(data["DATETIME"], data["RSS"], "Data", "RSS(kB)", "RSS względem czasu", verticals=verticals, legend_pos='upper right')
plt.savefig("rss_long.pdf")

verticals = [
    (datetime.datetime(2021, 8, 10, 20, 40), 'green', 'Uruchomienie aplikacji'),
    (datetime.datetime(2021, 8, 11, 16, 42), 'green', ''),
    (datetime.datetime(2021, 8, 10, 18, 14), 'red', 'Rozpoczęcie testu z użyciem Massif'),
    (datetime.datetime(2021, 8, 11, 13, 44), 'purple', 'Rozpoczęcie testu z użyciem Memcheck')
]
plot_data(subdata["DATETIME"], subdata["RSS"], "Data", "RSS(kB)", "RSS względem czasu", verticals=verticals)
plt.savefig("rss_short.pdf")

plot_data(data["DATETIME"], data["VSZ"], "Data", "VSZ(kB)", "VSZ względem czasu")
plt.savefig("vsz.pdf")

plot_data(data["DATETIME"], data["CPU"], "Data", "CPU(%)", "CPU względem czasu")
plt.savefig("cpu.pdf")

plot_data(data["DATETIME"], data["MEM"], "Data", "MEM(%)", "MEM względem czasu")
plt.savefig("mem.pdf")

exit()
