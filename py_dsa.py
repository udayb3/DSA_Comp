import pandas as pd

x=input('Enter the first string:')
y=input('Enter the second string')

a=len(x); b=len(y)

r=[];  s=[]
for i in range(a+1):
  temp=[];  temp2=[]
  for j in range(b+1):
    temp.append(0); temp2.append('.')
  r.append(temp); s.append(temp2)

for i in range(1,a+1,1):
  for j in range(1,b+1,1):
    if(x[i-1]==y[j-1]):
      r[i][j]=r[i-1][j-1]+1; 
      s[i][j]="%"
    elif(r[i-1][j]>=r[i][j-1]):
      r[i][j]=r[i-1][j]
      s[i][j]='^'
    else:
      r[i][j]=r[i][j-1]
      s[i][j]='<'

dfr=pd.DataFrame(r);  dfs=pd.DataFrame(s)
print("This is s\n",dfs,"\n\nThis is r\n",dfr)