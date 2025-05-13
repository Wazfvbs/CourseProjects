#!/usr/bin/env python
# coding: utf-8

# In[2]:


import pandas as pd


# In[4]:


filepath=r"C:\Users\86138\Desktop\实验8 数据\实验8 数据\木材剩余物.csv"
df=pd.read_csv(filepath,sep=",",index_col=0)
columns=["剩余物","采伐量"]
df.columns=columns
df.head()


# In[5]:


X=df[["采伐量"]]
Y=df["剩余物"]
X.head()


# In[6]:


import matplotlib.pyplot as plt
plt.scatter(X,Y)


# In[7]:


from sklearn.linear_model import LinearRegression
regr=LinearRegression()
regr.fit (X, Y)
regr.coef_,regr.intercept_


# In[10]:


regr.predict([[20]])


# In[11]:


import statsmodels.api as sm
X2=sm.add_constant(X)
est=sm.OLS(Y,X2).fit()
print(est.summary())


# In[12]:


X2


# In[14]:


plt.scatter(X,Y)
plt.plot(X, regr.predict(X),color='r')
plt.text(20,20,"y={:.3f}x{:+.3f}" .format(regr.coef_[0],regr.intercept_), fontsize=15)
plt.show()


# In[15]:


df["预测剩余物"]=regr.predict(X)
df["误差"]=df["预测剩余物"]-df["剩余物"]
df


# In[16]:


plt.rcParams["font.sans-serif"]=["SimHei"]
plt.rcParams["axes.unicode_minus"] = False
sm.qqplot(est.resid,line='r')
plt.show()


# In[23]:


fig=plt.figure(figsize=(8,8))
fig=sm.graphics.plot_regress_exog(est,"采伐量",fig=fig)


# In[24]:


est=sm.OLS(Y,X).fit()
est.summary()


# In[2]:


est.predict(20)


# In[1]:


y_pred=est.predict(20)
plt.scatter(X,Y)
plt.plot(X,y_pred,color='green')
for i in df.index:
    p1t.plot([df.loc[i,"采伐量"],df.loc[i,"采伐量"]],[df.loc[i,"剩余物"],df.loc[i,"预测剩余物"]],color='r ')
plt.text(20, 20,"y={:.3f}x".format(0.3855),fontsize=15)
plt.scatter(20,yp,marker='*',color="blue",s=300)
plt.text(18,10,s="{:.3f}".format(yp[0]),fontsize=12)
plt.xlim(10,70)
plt.ylim(0,30)
plt.xlabel("采伐量")
plt.ylabel("木材剩余物")
plt.show()


# In[34]:


from sklearn.preprocessing import PolynomialFeatures
poly=PolynomialFeatures(degree=2) #二次项模型
Xpoly=poly.fit_transform(X)
poly3=PolynomialFeatures(degree=3)#三次项模型
Xpoly3=poly3.fit_transform(X)
poly_reg2=sm.OLS(endog=Y,exog=Xpoly).fit()  #一元二次多项式回归
Y_pre2=poly_reg2.predict(Xpoly)
poly_reg3=sm.OLS(endog=Y,exog=Xpoly3).fit()#一元三次多项式回归
Y_pre3=poly_reg3.predict(Xpoly3)
plt.scatter(X,Y)
plt.plot(X,regr.predict(X),color='green',label="linear")
plt.plot(X,Y_pre2,color="r",label="poly_degree=2")
plt.plot(X,Y_pre3,color="b",label="poly_degree=3")
plt.legend( )
from sklearn.preprocessing import PolynomialFeatures
poly=PolynomialFeatures(degree=2) #二次项模型
Xpoly=poly.fit_transform(X)
poly3=PolynomialFeatures(degree=3)#三次项模型
Xpoly3=poly3.fit_transform(X)
poly_reg2=sm.OLS(endog=Y,exog=Xpoly).fit()  #一元二次多项式回归
Y_pre2=poly_reg2.predict(Xpoly)
poly_reg3=sm.OLS(endog=Y,exog=Xpoly3).fit()#一元三次多项式回归
Y_pre3=poly_reg3.predict(Xpoly3)
plt.scatter(X,Y)
plt.plot(X,regr.predict(X),color='green',label="linear")
plt.plot(X,Y_pre2,color="r",label="poly_degree=2")
plt.plot(X,Y_pre3,color="b",label="poly_degree=3")
plt.legend( )


# In[35]:


poly_reg2.summary()


# In[36]:


poly_reg3.summary()


# In[39]:


import matplotlib.pyplot as plt
import pandas as pd
from sklearn.linear_model import LinearRegression
df=pd.read_csv(r"C:\Users\86138\Desktop\实验8 数据\实验8 数据\Advertising.csv")
df


# In[40]:


x=df.iloc[:,:-1]
Y=df["sales"]


# In[41]:


df.describe()


# In[54]:


import numpy as np
import matplotlib.pyplot as plt
plt.figure(figsize=(15,5))
plt.subplot(1,3,1)
plt.scatter(x["TV"],Y)
plt.xticks(np.arange(0,300,30))
plt.subplot(1,3,2)
plt.scatter(x["radio"],Y)
plt.xticks(np.arange(1,50,3))
plt.subplot(1,3,3)
plt.scatter(x["newspaper"],Y)
plt.show()


# In[56]:


import statsmodels.api as sm
X2=sm.add_constant(x)
est=sm.OLS(Y,X2).fit()
print(est.summary())


# In[58]:


fig=plt.figure(figsize=(8,8))
fig=sm.graphics.plot_regress_exog(est,"TV",fig=fig)


# In[60]:


fig=plt.figure(figsize=(8,8))
fig=sm.graphics.plot_regress_exog(est,"radio",fig=fig)


# In[1]:


a=input()
b=int(a[-1::-1])
print(b)

