import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
df=pd.read_csv("housing.csv")
numerical=df.select_dtypes(include=[np.number]).columns
for columns in numerical:
    plt.figure(figsize=(8,5))
    sns.histplot(df[columns],bins=30)
    plt.show()
for columns in numerical:
    plt.figure(figsize=(8,5))
    sns.boxplot(x=df[columns])
    plt.show()
for columns in numerical :
    q1=df[columns].quantile(0.25)
    q3=df[columns].quantile(0.75)
    iqr=q3-q1
    lower_bound= q1-1.5*iqr
    higher_bound=q3+1.5*iqr
outliers=df[(df[columns]<lower_bound)| (df[columns]>higher_bound)]
print(f'{columns}:{len(outliers)}')
