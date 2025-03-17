import pandas as pd
import matplotlib.pyplot as plt
#scikit learn library
from sklearn import datasets
#load iris dataset that will be in dictionary-key value pair
iris=datasets.load_iris()
print(iris.keys())
print(iris["data"])
print(iris["target_names"])
print(iris["target"])
print(iris["DESCR"])
df=pd.DataFrame(iris['data'],columns=iris['feature_names'])
df
from sklearn.preprocessing import StandardScaler
scaler= StandardScaler()
scaler.fit(df)
scaled_data=scaler.transform(df)
print(scaled_data)
#apply PCA by importing
from sklearn.decomposition import PCA
pca=PCA(n_components=4)
pca.fit(scaled_data)
print("Varience value: ",pca.explained_variance_ratio_)
pca=PCA(n_components=2)
pca.fit(scaled_data)
print("Varience value: ",pca.explained_variance_ratio_)
x_pca= pca.transform(scaled_data)
print(x_pca)
plt.figure(figsize=(12,10))
y=iris.target
target_names=iris.target_names
for i,target_names in enumerate('target_names'):
    plt.scatter(x_pca[y==i,0],x_pca[y==i,1],label=target_names)
plt.legend()
plt.show()
