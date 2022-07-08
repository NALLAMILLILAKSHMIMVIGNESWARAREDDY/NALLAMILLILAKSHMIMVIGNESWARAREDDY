class ageerror(Exception):
     pass
try:
     
     age=int(input("Enter Age"))
     if(age<=0) or (age>120):
           raise ageerror
except ageerror:
     print("Age must be >0 and <120")
except valueerror:
     print("Age must be integer Only")
else:
     print("Age",age)
finally:
     print("Good Bye...........")
     
