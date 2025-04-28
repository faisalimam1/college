import numpy as np
import pandas as pd

import warnings
warnings.filterwarnings('ignore')

values=np.random.rand(100)#generates values between (0-1)
print(values)
labels=[]
for i in values[:50]:
    if i<0.5:
        labels.append('Class 1')
    else:
        labels.append('Class 2')
        
print(labels)
labels += [None]*50
print(labels)
data={"Point":[f"x{i+1}" for i in range(100)],"Values":values,"Labels":labels}
df=pd.DataFrame(data)
df
labeled_df=df[df["Labels"].notna()]
X_train=labeled_df[["Values"]]
Y_train=labeled_df[["Labels"]]

unlabeled_df=df[df["Labels"].isna()]
X_test=unlabeled_df[["Values"]]
true_labels=["Class1" if x<=0.5 else "Class2" for x in values[50:]]
print(true_labels)
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report
k_values=[1,2,3,4,5,20,30]

for k in k_values:
    knn=KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train,Y_train)
    predictions=knn.predict(X_test)
    print(f"Accuracy for k={k}")
    print(classification_report(true_labels,predictions))
