#!/usr/bin/env python
# coding: utf-8

# In[1]:


from PIL import Image
import numpy as np
import matplotlib.pyplot as plt


# In[2]:


filename="change.tif"
filename1="im1.tif"
filename2="im2.tif"
imgch=Image.open(filename)
im1=Image.open(filename1)
im2=Image.open(filename2)


# In[4]:


plt.figure(figsize=(15,5))
plt.subplot(1,3,1)
plt.imshow(im1)
plt.subplot(1,3,2)
plt.imshow(im2)
plt.subplot(1,3,3)
plt.imshow(imgch)


# In[8]:


imgch=np.array(imgch)
im1=np.array(im1,dtype=np.int16)
im2=np.array(im2,dtype=np.int16)


# In[6]:


im1.shape,im2.shape,imgch.shape


# In[7]:


im1.max(),im1.min(),im1.mean(),im2.max(),im2.min(),im2.mean()


# In[9]:


plt.figure(figsize=(8,6))
plt.subplot(2,2,1)
plt.imshow(im1)
plt.subplot(2,2,2)
plt.imshow(im1[:,:,0],cmap="gray")
plt.subplot(2,2,3)
plt.imshow(im1[:,:,1],cmap="gray")
plt.subplot(2,2,4)
plt.imshow(im1[:,:,2],cmap="gray")
plt.show()


# In[10]:


plt.figure(figsize=(12,8))
plt.subplot(2,3,1)
plt.hist(im1[:,:,0].flatten(),bins=256,color="r")
plt.subplot(2,3,2)
plt.hist(im1[:,:,0].flatten(),bins=256,color="g")
plt.title("im1")
plt.subplot(2,3,3)
plt.hist(im1[:,:,0].flatten(),bins=256,color="b")
plt.subplot(2,3,4)
plt.hist(im2[:,:,0].flatten(),bins=256,color="r")
plt.subplot(2,3,5)
plt.title("im2")
plt.hist(im2[:,:,0].flatten(),bins=256,color="g")
plt.subplot(2,3,6)
plt.hist(im2[:,:,0].flatten(),bins=256,color="b")
plt.show()


# In[11]:


im1


# In[12]:


im2


# In[13]:


imchange=np.abs(im1-im2)
plt.imshow(imchange)
plt.show()


# In[14]:


plt.figure(figsize=(8,6))
plt.subplot(2,2,1)
plt.axis("off")
plt.imshow(im1)
plt.subplot(2,2,2)
plt.axis("off")
plt.imshow(im2)
plt.subplot(2,2,3)
plt.axis("off")
plt.imshow(imgch)
plt.subplot(2,2,4)
plt.axis("off")
plt.imshow(imchange)
plt.show()


# In[15]:


rows,cols=imchange.shape[0:2]
X=imchange.reshape(-1,3)
X[0:5]


# In[16]:


from sklearn.cluster import KMeans
kmc=KMeans(n_clusters=2,random_state=0)
kmc.fit(X)
y_pred=kmc.predict(X)
y_pred


# In[17]:


kmc.cluster_centers_


# In[21]:


if kmc.cluster_centers_[0].sum()>kmc.cluster_centers_[1].sum():
    y_pred[y_pred==0]=2
    y_pred[y_pred==1]=0
    y_pred[y_pred==2]=1
imresult=y_pred.reshape(rows,cols)
plt.imshow(imresult,cmap="gray")


# In[29]:


result=y_pred.reshape(rows,cols)
result=np.array(result,dtype=np.uint8)
result[result==1]=255
imgresult=Image.fromarray(result)
imgresult.save("C:/Users/CCEC/Desktop/变化检测结果.jpg")
imgresult


# In[30]:


y_true=imgch[:,:,0].flatten()
y_true[y_true==255]=1
y_true[0:5]


# In[31]:


from sklearn.metrics import classification_report,confusion_matrix,accuracy_score
accuracy_score(y_true,y_pred).round(4)*100


# In[32]:


confusion_matrix(y_true,y_pred)


# In[33]:


from sklearn.metrics import recall_score, precision_score
precision_score(y_true,y_pred).round(4)*100, recall_score(y_true, y_pred).round(4)*100


# In[34]:


plt.figure(figsize=(8,4))
plt.subplot(1,2,1)
plt.imshow (imgch)
plt.subplot(1,2,2)
plt.imshow (imresult,cmap='gray')


# In[40]:


cuojian,loujian=np.zeros((rows,cols)),np.zeros((rows,cols))
cuojian[ (imgch[:, :,0]==0) & (imresult==1) ]=255
loujian[ (imgch[:, :,0]==255) & (imresult==0) ]=255
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.figure(figsize=(8, 4))
plt.subplot(1,2,1)
plt.title("虚警像元")
plt.imshow (cuojian,cmap='gray' )
plt.title("漏检像元")
plt.imshow(loujian,cmap='gray' )


# In[43]:


plt.figure(figsize=(15,4))
plt.subplot(1,3,1)
plt.hist(X[:,0].flatten(),bins=256,color="r")
plt.subplot(1,3,2)
plt.hist(X[:,1].flatten(),bins=256,color="g")
plt.subplot(1,3,3)
plt.hist(X[:,1].flatten(),bins=256,color="b")
plt.show()


# In[45]:


resultbetter=result.copy()
kersize=3
size=kersize//2
for i in range(size,rows-size):
    for j in range(size,cols-size):
        resultbetter[i,j]=np.median(result[i-size:i+size+1,j-size:j+size+1])


# In[47]:


plt.subplot(1,2,1)
plt.imshow(imresult,cmap='gray' )
plt.subplot(1,2,2)
plt.imshow(resultbetter,cmap='gray')
plt.show()


# In[49]:


y_better=resultbetter.flatten()
y_better[y_better==255]=1
print("kersize=3时优化结果为: ")
print("准确率%.2f"%(accuracy_score(y_true,y_better)*100))
print("精确率%.2f"%(precision_score(y_true,y_better)*100))
print("召回率%.2f"%(recall_score(y_true,y_better)*100))


# In[50]:


print(classification_report(y_true,y_better))


# In[51]:


resultbetter=result.copy()
kersize=5
size=kersize//2
for i in range(size,rows-size):
    for j in range(size,cols-size):
        resultbetter[i,j]=np.median(result[i-size:i+size+1, j-size:j+size+1])
y_better=resultbetter.flatten()
y_better[y_better==255]=1
print("kersize=5时优化结果为: ")
print("准确率%.2f"%(accuracy_score(y_true,y_better)*100))
print("精确率%.2f"%(precision_score(y_true,y_better)*100))
print("召回率%.2f"%(recall_score(y_true,y_better)*100))


# In[52]:


imgresult=Image.fromarray(resultbetter)
imgresult.save("C:/Users/CCEC/Desktop/变化检测优化结果.jpg")
imgresult


# In[ ]:




