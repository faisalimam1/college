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
#extra code
n_samples=10
plt.figure(figsize=(20,10))
for i in range(n_samples):
  ax=plt.subplot(1,n_samples,i+1)
  ax.imshow(x_test[i].reshape(64,64),cmap='grey')
  ax.set_title(f"{y_predict[i]}\nTrue:{y_test[i]}")
plt.show()

#extra codes
new_sample=np.array([x_test[0]])
prediction=dtclf.predict(new_sample)
prediction_class="Benign" if prediction==1 else "Malignant"
print(f"Predicted class :{prediction_class}")
