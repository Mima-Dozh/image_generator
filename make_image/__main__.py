# import the libraries
import sqlite3
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.axes._axes import _log as matplotlib_axes_logger
matplotlib_axes_logger.setLevel('ERROR')


con = sqlite3.connect('./data_base/image.db')
data = pd.read_sql_query('select * from point_info;', con)

con.close()

categories = data[['file_name', 'point_group']].drop_duplicates().to_numpy()
colors = [plt.cm.tab10(i/float(len(categories)-1)) for i in range(len(categories))]


for i, v in enumerate(categories):
    now = data[(data['file_name'] == v[0]) & (data['point_group'] == v[1])]
    print(now)
    plt.scatter('x', 'y',
                data=data.loc[(data['file_name'] == v[0]) & (data['point_group'] == v[1]), :],
                label=str(v), s=20)

# plotting a scatter plot
print("Scatter Plot:  ")
plt.gca().set(xlabel='x', ylabel='y')

plt.xticks(fontsize=12); plt.yticks(fontsize=12)
plt.title("Scatterplot of Midwest Area vs Population", fontsize=22)
plt.legend(fontsize=12)
plt.show()
