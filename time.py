class Time:
    def convert_to_minutes(self,n):
        self.minutes=n//60
        self.seconds=n%60
        s=str(self.minutes)+":"+str(self.seconds)
        return s
    def convert_to_hours(self,n):
        self.hours=n//3600
        self.rem_sec=n%3600
        self.minutes=self.rem_sec//60
        self.hours=self.rem_sec%60
        s=str(self.hours)+":"+str(self.minutes)+":"+str(self.seconds)
        return s
sec=int(input("enter numbers"))
T=Time()
s=T.convert_to_minutes(sec)
print(s)
s1=T.convert_to_hours(sec)
print(s1)
