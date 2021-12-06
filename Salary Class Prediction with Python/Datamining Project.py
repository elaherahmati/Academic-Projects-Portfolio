import numpy as np
import pandas as pd
from statsmodels.stats.outliers_influence import variance_inflation_factor
from sklearn.model_selection import train_test_split
from sklearn.decomposition import PCA
from sklearn.cluster import DBSCAN
from sklearn.preprocessing import MinMaxScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import cross_val_score
from sklearn import tree
from sklearn.metrics import confusion_matrix
from sklearn.ensemble import RandomForestClassifier
from imblearn.over_sampling import SMOTE
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis,QuadraticDiscriminantAnalysis
from sklearn.linear_model import LogisticRegression
from sklearn.naive_bayes import GaussianNB
import matplotlib.pyplot as plt
import seaborn as sns
from mlxtend.plotting import plot_confusion_matrix



## Preprocessing

#some brief infomramtion are stored in new dataframes to recognize the data in a better way
df = pd.read_csv('C:/Users/user/Documents/DM Prokect/HR_comma_sep.csv')
df_type = df.dtypes
df_des = df.describe()
df.shape
#checking missing values
df.isna().sum()

#plot for number of labels
sns.countplot(df['salary'],label="Count")
plt.show()
#data is imbalanced so we need the solve this problem
df.groupby(['salary']).size()

#we need to convert the sales and salary attributes to categorical ones also numeric ti have better operations
df.sales=df.sales.astype("category").cat.codes
df.salary=df.salary.astype("category").cat.codes

#we need to check correlation between attributes
df_cor = df.corr(method='pearson')

#VIF check has to be done to control whether there's multicollinearity or not
X_VIF = df.iloc[:,0:9].assign(const=1)
df_VIF=pd.Series([variance_inflation_factor(X_VIF.values, i) for i in range(X_VIF.shape[1])],index=X_VIF.columns)

#it's essential to normalize some attirbutes to have a better model
scaler = MinMaxScaler(copy=True, feature_range=(0, 1))
scaler.fit(df.iloc[:,2:5])
df.iloc[:,2:5] = scaler.transform(df.iloc[:,2:5])

#box plots for each attribute
df.drop('salary', axis=1).plot(kind='box', subplots=True, layout=(3,3), sharex=False, sharey=False, figsize=(9,9), title='Box Plot for each input variable')
plt.show()

#set indext for records
s = np.arange(1,df.shape[0]+1,1)
df = df.set_index([s],append = True , drop = False)

#Remove duplicates
#df.drop_duplicates(keep= 'last', inplace=True)


#because of the datatype it's better to use DBSCAN method to remove the outliers
model = DBSCAN(eps = 0.5 , min_samples = 5 ).fit(df)
outliers_df = pd.DataFrame(df)
outliers_df[model.labels_ == -1]
df = outliers_df[model.labels_ != -1]

#we usue SMOTE function to generate records an balance the data
sm = SMOTE(sampling_strategy='auto', random_state=None, k_neighbors=5, m_neighbors='deprecated', out_step='deprecated', kind='deprecated', svm_estimator='deprecated', n_jobs=1, ratio=None)
Y_temp = df.salary
X_temp = df.drop(columns='salary', axis=1)
# X is the predictor
# Y is the target
X, Y = sm.fit_resample(X_temp, Y_temp)


##Modeling

#as dimension reduction we use pca method
#data is scaled
pca = PCA(whiten=True)
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.2)
pca.fit(X_train)
W=pca.components_.T


comp=np.arange(1,10,1)
#cross validation folds
cv=10
cvscorespca_KNN=[]
cvscorespca_Tree=[]
cvscorespca_RF=[]
cvscorespca_qda=[]
cvscorespca_lda=[]
cvscorespca_logreg=[]
cvscorespca_NV=[]

#KNN
nneighbors=np.arange(1,5)
for c in comp:
    for k in nneighbors:
        X_train_pca = pca.transform(X_train)[:,:c]
        Knnpca=KNeighborsClassifier(n_neighbors=k,metric='minkowski',p=2)
        cvscorespca_KNN.append([c,k,np.mean(cross_val_score(Knnpca, X_train_pca, y_train, cv=cv))])

cvscorespca_KNN = pd.DataFrame(cvscorespca_KNN)
cvscorespca_KNN = cvscorespca_KNN.sort_values(2,ascending = False )
#the best parameters are c=9 and k=1

Knnpca=KNeighborsClassifier(n_neighbors=1,metric='minkowski',p=2)
X_train_pca = pca.transform(X_train)[:,:10]
X_test_pca = pca.transform(X_test)[:,:10]
Knnpca.fit(X_train_pca,y_train)
print('Knn-PCA Train Accuracy:',Knnpca.score(X_train_pca,y_train))
print('Knn-PCA Prediction Accuracy:',Knnpca.score(X_test_pca,y_test))
print('Knn-PCA Model for Testing Data\n',confusion_matrix(y_test,Knnpca.predict(X_test_pca)))
fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,Knnpca.predict(X_test_pca))).values,
                                colorbar=True,
                                show_absolute=False,
                                show_normed=True)
plt.show()


#Decision Tree
depth = np.arange(1,20,1)
for k in depth:
    for c in comp:
     X_train_pca = pca.transform(X_train)[:,:c]
     clf = tree.DecisionTreeClassifier(max_depth= k)
     cvscorespca_Tree.append([k,c,np.mean(cross_val_score(clf, X_train_pca, y_train,cv=cv))])


cvscorespca_Tree = pd.DataFrame(cvscorespca_Tree)
cvscorespca_Tree = cvscorespca_Tree.sort_values(2,ascending = False )
#the best parameters are c=9 and k=19

clf = tree.DecisionTreeClassifier(max_depth=19)
X_train_pca = pca.transform(X_train)[:,:10]
X_test_pca = pca.transform(X_test)[:,:10]
clf.fit(X_train_pca,y_train)
#confusion_matrix plot
print('Decision Tree-PCA Train Accuracy:',clf.score(X_train_pca,y_train))
print('Decision Tree-PCA Prediction Accuracy:',clf.score(X_test_pca,y_test))
print('Decision Tree-PCA Model for Testing Data\n',confusion_matrix(y_test,clf.predict(X_test_pca)))
fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,clf.predict(X_test_pca))).values,
                                colorbar=True,
                                show_absolute=False,
                                show_normed=True)
plt.show()

#tree plot
tree.plot_tree(clf.fit(X_train, y_train))
plt.show()



#Random Forest
nest = np.arange(1,1000,10)
for c in comp:
     X_train_pca = pca.transform(X_train)[:,:c]
     rf = RandomForestClassifier(n_estimators=1000,oob_score=True,max_features='auto')
     cvscorespca_RF.append([k,c,np.mean(cross_val_score(rf, X_train_pca, y_train,cv=cv))])

cvscorespca_RF = pd.DataFrame(cvscorespca_RF)
cvscorespca_RF = cvscorespca_RF.sort_values(1,ascending = False )
#the best parameters are c=9

rf = RandomForestClassifier(n_estimators=1000,oob_score=True,max_features='auto')
X_train_pca = pca.transform(X_train)[:,:10]
X_test_pca = pca.transform(X_test)[:,:10]
rf.fit(X_train_pca,y_train)
print('Random Forrest Train Accuracy:',rf.score(X_train_pca,y_train))
print('Random Forrest Prediction Accuracy:',rf.score(X_test_pca,y_test))
print('Random Forrest Model for Testing Data\n',confusion_matrix(y_test,rf.predict(X_test_pca)))
fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,rf.predict(X_test_pca))).values,
                                colorbar=True,
                                show_absolute=False,
                                show_normed=True)
plt.show()



#LDA
for c in comp:
    X_train_pca = pca.transform(X_train)[:, :c]
    lda = LinearDiscriminantAnalysis()
    cvscorespca_lda.append([c, np.mean(cross_val_score(lda, X_train_pca, y_train, cv=cv))])

cvscorespca_lda = pd.DataFrame(cvscorespca_lda)
cvscorespca_lda = cvscorespca_lda.sort_values(1,ascending = False )
#the best parameters are c=9

ldapca=LinearDiscriminantAnalysis()
X_train_pca = pca.transform(X_train)[:,:10]
X_test_pca = pca.transform(X_test)[:,:10]
ldapca.fit(X_train_pca,y_train)
print('LDA-PCA Train Accuracy:',ldapca.score(X_train_pca,y_train))
print('LDA-PCA Prediction Accuracy:',ldapca.score(X_test_pca,y_test))
print('LDA-PCA Model for Testing Data\n',confusion_matrix(y_test,ldapca.predict(X_test_pca)))
#confusion_matrix plot
fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,ldapca.predict(X_test_pca))).values,
                                colorbar=True,
                                show_absolute=False,
                                show_normed=True)
plt.show()


#QDA
for c in comp:
    X_train_pca = pca.transform(X_train)[:, :c]
    qda = QuadraticDiscriminantAnalysis()
    cvscorespca_qda.append([c, np.mean(cross_val_score(qda, X_train_pca, y_train, cv=cv))])

cvscorespca_qda = pd.DataFrame(cvscorespca_qda)
cvscorespca_qda = cvscorespca_qda.sort_values(1,ascending = False )
#the best parameters are c=8

qdapca=QuadraticDiscriminantAnalysis()
X_train_pca = pca.transform(X_train)[:,:9]
X_test_pca = pca.transform(X_test)[:,:9]
qdapca.fit(X_train_pca,y_train)
print('QDA-PCA Train Accuracy:',qdapca.score(X_train_pca,y_train))
print('QDA-PCA Prediction Accuracy:',qdapca.score(X_test_pca,y_test))
print('QDA-PCA Model for Testing Data\n',confusion_matrix(y_test,qdapca.predict(X_test_pca)))
#confusion_matrix plot
fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,qdapca.predict(X_test_pca))).values,
                                colorbar=True,
                                show_absolute=False,
                                show_normed=True)
plt.show()



#Logestic Regression
for c in comp:
    X_train_pca = pca.transform(X_train)[:, :c]
    logreg = LogisticRegression(multi_class="multinomial",solver="newton-cg")
    cvscorespca_logreg.append([c, np.mean(cross_val_score(logreg, X_train_pca, y_train, cv=cv))])

cvscorespca_logreg = pd.DataFrame(cvscorespca_logreg)
cvscorespca_logreg = cvscorespca_logreg.sort_values(1,ascending = False )
#the best parameters are c=7

logreg = LogisticRegression(multi_class="multinomial",solver="newton-cg")
X_train_pca = pca.transform(X_train)[:,:8]
X_test_pca = pca.transform(X_test)[:,:8]
logreg.fit(X_train_pca,y_train)
print('Logistic Regression Train Accuracy:',logreg.score(X_train_pca,y_train))
print('Logistic Regression Accuracy:',logreg.score(X_test_pca,y_test))
print('Logistic Regression Model for Testing Data\n',confusion_matrix(y_test,logreg.predict(X_test_pca)))
#confusion_matrix plot
fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,logreg.predict(X_test_pca))).values,
                                colorbar=True,
                                show_absolute=False,
                                show_normed=True)
plt.show()



#Naive Bayes

for c in comp:
    X_train_pca = pca.transform(X_train)[:, :c]
    gnb = GaussianNB()
    cvscorespca_NV.append([c, np.mean(cross_val_score(gnb, X_train_pca, y_train, cv=cv))])

cvscorespca_NV = pd.DataFrame(cvscorespca_NV)
cvscorespca_NV = cvscorespca_NV.sort_values(1,ascending = False )
#the best parameters are c=5

gnb = GaussianNB()
X_train_pca = pca.transform(X_train)[:,:6]
X_test_pca = pca.transform(X_test)[:,:6]
gnb.fit(X_train_pca,y_train)
print('Naive Bayes Train Accuracy:',gnb.score(X_train_pca,y_train))
print('Naive Bayes Accuracy:',gnb.score(X_test_pca,y_test))
print('Naive Bayes Model for Testing Data\n',confusion_matrix(y_test,gnb.predict(X_test_pca)))
#confusion_matrix plot
fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,gnb.predict(X_test_pca))).values,
                                colorbar=True,
                                show_absolute=False,
                                show_normed=True)
plt.show()







#Random Forest with two optimization
#nest = np.arange(100,2000,100)
#for k in nest:
#    for c in comp:
#        X_train_pca = pca.transform(X_train)[:,:c]
#        rf = RandomForestClassifier(n_estimators=k,oob_score=True,max_features='auto')
#        cvscorespca_RF.append([k,c,np.mean(cross_val_score(rf, X_train_pca, y_train,cv=cv))])

#cvscorespca_RF = pd.DataFrame(cvscorespca_RF)
#cvscorespca_RF = cvscorespca_RF.sort_values(1,ascending = False )
#the best parameters are c=9

#rf = RandomForestClassifier(n_estimators=1000,oob_score=True,max_features='auto')
#X_train_pca = pca.transform(X_train)[:,:10]
#X_test_pca = pca.transform(X_test)[:,:10]
#rf.fit(X_train_pca,y_train)
#print('Random Forrest Train Accuracy:',rf.score(X_train_pca,y_train))
#print('Random Forrest Prediction Accuracy:',rf.score(X_test_pca,y_test))
#print('Random Forrest Model for Testing Data\n',confusion_matrix(y_test,rf.predict(X_test_pca)))
#confusion_matrix plot
#fig, ax = plot_confusion_matrix(conf_mat=pd.DataFrame(confusion_matrix(y_test,rf.predict(X_test_pca))).values,
#                                colorbar=True,
#                                show_absolute=False,
#                                show_normed=True)
#plt.show()
