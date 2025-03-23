import pandas as pd
import numpy as np
df=pd.read_csv("job-offer.csv")
df
features=np.array(df)[:,:-1]
target=np.array(df)[:,-1]
for i,val in enumerate(target):
    if val=="Yes" :
        hypothesis=features[i]
        break
print(hypothesis)
for i,val in enumerate(features):
    if target[i]=="Yes" :
        for x in range(len(hypothesis)):
            if val[x]!=hypothesis[x]:
                hypothesis[x]='?'
print(hypothesis)
