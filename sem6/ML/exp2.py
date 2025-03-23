import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
df=pd.read_csv("housing.csv")
df
#corr_matrix=df.corr()
corr_matrix = df.select_dtypes(include=[np.number]).corr()
plt.figure(figsize=(10,9))
sns.heatmap(corr_matrix,annot=True,fmt='.2f',cmap='coolwarm',linewidth=0.5)
plt.title('correlation matrix heatmap')
sns.pairplot(df)
            
