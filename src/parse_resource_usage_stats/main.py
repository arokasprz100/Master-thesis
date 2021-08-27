import datetime
import pandas as pd
import matplotlib.pyplot as plt


def plot_data(x, y, xlabel=None, ylabel=None, title=None):
    plt.figure(figsize=(10, 8), dpi=400)
    ax = plt.subplot()
    if xlabel:
        ax.set_ylabel(ylabel)
    if ylabel:
        ax.set_xlabel(xlabel)
    if title:
        plt.title(title)
    plt.xticks(rotation='vertical')
    plt.plot(x, y)
    plt.tight_layout()


data = pd.read_csv("./data/ggss_resource_usage_05_08_2021.txt", delim_whitespace=True, na_values=["GGSS", "is", "not", "running!"])
data.rename(columns={data.columns[0]: "DATE", data.columns[1]: "TIME"}, inplace=True)
data["DATETIME"] = data[["DATE", "TIME"]].apply(lambda row: "-".join(row.values.astype(str)), axis=1)
data["DATETIME"] = pd.to_datetime(data["DATETIME"], format="%Y.%m.%d-%H:%M:%S")

subdata = data[data["DATETIME"].between(datetime.datetime(2021, 8, 10, 12), datetime.datetime(2021, 8, 12))]

plot_data(data["DATETIME"], data["RSS"], "datetime", "RSS(kB)", "RSS względem czasu")
plt.show()

plot_data(subdata["DATETIME"], subdata["RSS"], "datetime", "RSS(kB)", "RSS względem czasu")
plt.show()

plot_data(data["DATETIME"], data["VSZ"], "datetime", "VSZ(kB)", "VSZ względem czasu")
plt.show()

plot_data(data["DATETIME"], data["CPU"], "datetime", "CPU(%)", "CPU względem czasu")
plt.show()

plot_data(data["DATETIME"], data["MEM"], "datetime", "MEM(%)", "MEM względem czasu")
plt.show()

exit()
