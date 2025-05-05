import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
dataset=load_breast_cancer()
print(dataset)
#df=pd.DataFrame(dataset.data)
x=dataset.data
y=dataset.target
print(x)
print(y)
from sklearn.model_selection import train_test_split
x_train, x_test, y_train, y_test= train_test_split(x,y,test_size=0.2, random_state=42)
from sklearn.tree import DecisionTreeClassifier
dtclf= DecisionTreeClassifier(criterion="entropy",random_state=42)
dtclf.fit(x_train, y_train)
#x_predict=gnb.predict(x_test)
y_predict=dtclf.predict(x_test)
print(y_predict)
from sklearn.metrics import accuracy_score
accu= accuracy_score(y_test, y_predict)
print(f"accuracy of decision tree:{accu*100}%")
