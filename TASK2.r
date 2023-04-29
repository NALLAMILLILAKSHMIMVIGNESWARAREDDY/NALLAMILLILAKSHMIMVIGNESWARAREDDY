#write a r program for addition of two vectors
#case1:vector same length
#case2:vector of different lengths
#case3:vector of multiple length
#case4:vector of non multiple lenths
vec1 <- c(1, 2, 3, 4, 5)
vec2 <- c(6, 7, 8, 9, 10)
result <- vec1 + vec2
print("Case 1: Vectors of the Same Length\n")
print(result)
vec1 <- c(1, 2, 3)
vec2 <- c(4, 5, 6, 7, 8)
result <- vec1 + vec2
print("\nCase 2: Vectors of Different Lengths\n")
print(result)
vec1 <- c(1, 2, 3)
vec2 <- c(4, 5, 6, 7)
vec3 <- c(8, 9, 10, 11, 12, 13)
result <-vec1+vec2+vec3
print("\nCase 3: Vectors of Multiple Lengths\n")
print(result)
vec1 <- c(1, 2, 3, 4, 5)
vec2 <- c(6, 7, 8, 9)
if(length(vec1) > length(vec2)) {
  vec2 <- c(vec2, rep(0, length(vec1) - length(vec2)))
} else if (length(vec2) > length(vec1)) {
  vec1 <- c(vec1, rep(0, length(vec2) - length(vec1)))
}
result <- vec1 + vec2
print("\nCase 4: Vectors of Non-Multiple Lengths\n")
print(result)
