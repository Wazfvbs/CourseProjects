#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
from sklearn.neighbors import KNeighborsTransformer
from sklearn.neighbors import (NeighborhoodComponentsAnalysis,KNeighborsClassifier)
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix,accuracy_score,precision_score,recall_score,f1_score,classification_report


# In[2]:


filepath="C:/Users/CCEC/Desktop/forest/"
filename="train.csv"


# In[3]:


df=pd.read_csv(filepath+filename,index_col=0)
X,y=df.iloc[:,:-1],df.iloc[:,-1]
X.head()


# In[4]:


X_train, X_test, y_train, y_test = train_test_split(X, y,test_size=0.2, random_state=0)
y_test.head()


# In[5]:


knn = KNeighborsClassifier(n_neighbors=5,weights="distance")
knn.fit(X_train,y_train)
y_pred=knn.predict(X_test)
y_pred


# In[6]:


knn.score(X_test,y_test)


# In[7]:


knn.score(X_train,y_train)


# In[8]:


print(classification_report(y_test,y_pred))


# In[9]:


confusion_matrix(y_test,y_pred)


# In[12]:


import numpy as np
from PIL import Image
import pandas as pd
import matplotlib.pyplot as plt
import os


# In[13]:


filepath="C:/Users/CCEC/Desktop/water/"
filenames=os.listdir(filepath)
filenames[0:5]


# In[14]:


nsize =20
n=1
plt.figure(figsize= ((nsize//4)*5, 4*7))
for i in range(1, nsize+1):
    img=Image.open(filepath+filenames[i-1])
    plt. subplot (nsize//4+1, 4, n)
    plt. axis("off")
    plt. title (filenames[i-1])
    plt. imshow (img)
    n+=1
plt.show()


# In[15]:


temp=Image. open(filepath+"1_24.jpg" )
temp=np. array(temp)
plt. figure (figsize=(12, 4))
plt. subplot(1, 3, 1)
plt. hist(temp[:, :, 0]. flatten(), bins=255, color="r")
plt. subplot(1, 3, 2)
plt. hist(temp[:, :,1]. flatten(), bins=255, color="g")
plt. subplot(1,3, 3)
plt. hist(temp[:, :, 2]. flatten(), bins=255, color="b")
plt. show ()


# In[16]:


def info (arimg):
    jieju1=np.mean (arimg)
    jieju2=np.std(arimg)
    fh=1
    jieju3 =np.sum(np. power (arimg- jieju1,3))
    if jieju3<0:
        fh=-1
        jieju3=-jieju3
    jieju3=np. power (jieju3, 1/3)
    jieju3 = jieju3*fh
    return jieju1, jieju2, jieju3


# In[19]:


columns=["level","xh","r一阶矩","g一阶矩","b一阶矩","r二阶矩","g二阶矩","b二阶矩","r三阶矩","g三阶矩","b三阶矩"] 
df=pd.DataFrame (columns=columns)
n=0
for i in filenames:
    
    if os.path.isfile(filepath+i) and i[-3:]=="jpg": 
        level=int(i[0]) 
        xh=i[0:-4]
        img= np. array (Image. open(filepath+i)) 
        rows, cols=img. shape[0:2]
        subimg=img [rows//2-25:rows//2+26, cols//2- 25:cols//2+26]
        Image. fromarray(subimg).save(filepath+"sub/"+i)
        subimg=subimg/255
        r1, r2, r3=info(subimg[:,:,0])
        g1, g2, g3=info(subimg[:,:,1])
        b1, b2, b3=info(subimg[:,:,2])
        df.loc[n]=[level,xh,r1,g1,b1,r2,g2,b2,r3,g3,b3] 
        n+=1
df["level"]=df ["level"].astype(int) 
df.head()


# In[20]:


df.to_csv(filepath+"imagefeatures.csv")
print("%s"%(filepath+"imagefeatures.csv"))


# In[21]:


df=pd.read_csv(filepath+"imagefeatures.csv",encoding="utf-8",index_col=0)
df.head()


# In[22]:


y=df["level"]
X=df.iloc[:,2:]
y


# In[23]:


from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.2)
X_test.shape,y_test.shape


# In[24]:


from sklearn.neighbors import KNeighborsClassifier
knc=KNeighborsClassifier(n_neighbors=5)
knc.fit(X_train,y_train)
y_kncpred=knc.predict(X_test)
y_kncpred


# In[25]:


from sklearn import svm
svc=svm.SVC()
svc.fit(X_train,y_train)
y_svcpred=svc.predict(X_test)
y_svcpred


# In[26]:


from sklearn.metrics import classification_report,confusion_matrix,accuracy_score
from sklearn.metrics import recall_score, precision_score


# In[27]:


print("KNN模型的准确率:",accuracy_score(y_test,y_kncpred).round(4))
print("SVM模型的准确率:",accuracy_score(y_test,y_svcpred).round(4))


# In[28]:


confusion_matrix(y_test,y_kncpred)


# In[29]:


confusion_matrix(y_test,y_svcpred)


# In[30]:


from sklearn.ensemble import RandomForestClassifier
rfc=RandomForestClassifier(n_estimators=100)
rfc.fit(X_train,y_train)
y_rfcpred=rfc.predict(X_test)
y_rfcpred


# In[31]:


accuracy_score(y_test,y_rfcpred).round(4)


# In[ ]:




