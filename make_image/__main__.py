# import the libraries
import sqlite3
import pandas as pd
import matplotlib.pyplot as plt


con = sqlite3.connect('./data_base/image.db')
data = pd.read_sql_query('select * from point_info;', con)

con.close()

categories = data[['file_name', 'point_group']].drop_duplicates().to_numpy()
colors = [plt.cm.tab10(i/float(len(categories)-1)) for i in range(len(categories))]


for i, v in enumerate(categories):
    now = data[(data['file_name'] == v[0]) & (data['point_group'] == v[1])]
    plt.scatter('x', 'y',
                data=data.loc[(data['file_name'] == v[0]) & (data['point_group'] == v[1]), :],
                label=str(v), s=20)

# plotting a scatter plot
plt.gca().set(xlabel='x', ylabel='y')

plt.legend(fontsize=12)
plt.savefig('./image/point.png')
