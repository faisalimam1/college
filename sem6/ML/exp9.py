import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import fetch_olivetti_faces
dataset=fetch_olivetti_faces()
print(dataset)
#df=pd.DataFrame(dataset.data)
x=dataset.data
y=dataset.target
print(x)
print(y)
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test= train_test_split(x,y,test_size=0.2, random_state=42)
from sklearn.naive_bayes import GaussianNB
gnb= GaussianNB()
gnb.fit(x_train, y_train)
#x_predict=gnb.predict(x_test)
y_predict=gnb.predict(x_test)
print(y_predict)
from sklearn.metrics import accuracy_score
accu= accuracy_score(y_test, y_predict)
print(f"accuracy of naive bayes:{accu}%")
