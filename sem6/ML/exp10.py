import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.datasets import load_breast_cancer
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans

# Load the dataset
data = load_breast_cancer()
df = pd.DataFrame(data.data, columns=data.feature_names)

# Standardize the data
scaler = StandardScaler()
scaled_data = scaler.fit_transform(df)

# Dimensionality reduction for visualization
pca = PCA(n_components=2)
reduced_data = pca.fit_transform(scaled_data)

# Apply KMeans
kmeans = KMeans(n_clusters=2, random_state=42)
kmeans.fit(reduced_data)
labels = kmeans.labels_

# Add labels and reduced components to the DataFrame
df_pca = pd.DataFrame(reduced_data, columns=["PCA1", "PCA2"])
df_pca['Cluster'] = labels
df_pca['True Label'] = data.target

# Plot the clustering result
plt.figure(figsize=(12, 5))

# KMeans Clustering
plt.subplot(1, 2, 1)
sns.scatterplot(x="PCA1", y="PCA2", hue="Cluster", data=df_pca, palette='Set1')
plt.title("K-Means Clustering (2D PCA)")

# Actual Labels
plt.subplot(1, 2, 2)
sns.scatterplot(x="PCA1", y="PCA2", hue="True Label", data=df_pca, palette='Set2')
plt.title("True Labels (2D PCA)")

plt.tight_layout()
plt.show()
