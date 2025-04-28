import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
iris=datasets.load_iris(as_frame=True)
y=iris.target
df=pd.DataFrame(iris['data'])
X=df[['sepal length (cm)']]
#split the data
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.3,random_state=42)
#liner regression
from sklearn.linear_model import LinearRegression
lg=LinearRegression()
lg.fit(X_train,y_train)
y_predict=lg.predict(X_test)
print(y_predict)
#plotting the results
plt.scatter(X_test,y_test,color='blue')
plt.plot(X_test['sepal length (cm)'],y_predict,color='red')
plt.title("Linear Regression")
plt.show()

#polynomial regression
from sklearn.preprocessing import PolynomialFeatures,StandardScaler
from sklearn.pipeline import make_pipeline
poly=make_pipeline(PolynomialFeatures(degree=3),StandardScaler(),LinearRegression())
poly.fit(X_train,y_train)
y_predict=poly.predict(X_test)

import matplotlib.pyplot as plt
plt.scatter(X_test,y_test,color='blue',label='Actual')
plt.scatter(X_test['sepal length (cm)'],y_predict,color='red',label='Predicted')
plt.legend()
plt.show()
