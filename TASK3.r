#write a r program to add individual elements of vector 
#case1:By acessing through the address
#case2:using for loop
# Case 1: By accessing through the address
vec <- c(1, 52, 13, 4, 5)
(vec[1])
(vec[2])
(vec[3])
(vec[4])
(vec[5])
sum1 <- vec[1]+vec[2]+vec[3]+vec[4]+vec[5]
print(sum1)
vec <- c(1, 2, 3, 4, 5)
sum2 <- 0
for (i in vec) {
  sum2 <- sum2 + i
}
print("Sum using for loop:")
print(sum2)
