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
#> #write a r program for addition of two vectors
#> #case1:vector same length
#> #case2:vector of different lengths
#> #case3:vector of multiple length
#> #case4:vector of non multiple lenths
#> vec1 <- c(1, 2, 3, 4, 5)
#> vec2 <- c(6, 7, 8, 9, 10)
#> result <- vec1 + vec2
#> print("Case 1: Vectors of the Same Length\n")
#[1] "Case 1: Vectors of the Same Length\n"
#> print(result)
#[1]  7  9 11 13 15
#> vec1 <- c(1, 2, 3)
#> vec2 <- c(4, 5, 6, 7, 8)
#> result <- vec1 + vec2
#Warning message:
#In vec1 + vec2 :
 # longer object length is not a multiple of shorter object length
> #print("\nCase 2: Vectors of Different Lengths\n")
#[1] "\nCase 2: Vectors of Different Lengths\n"
># print(result)
#[1]  5  7  9  8 10
># vec1 <- c(1, 2, 3)
> #vec2 <- c(4, 5, 6, 7)
> #vec3 <- c(8, 9, 10, 11, 12, 13)
#> re#sult <-vec1+vec2+vec3
#Warning messages:
#1: In vec1 + vec2 :
 # longer object length is not a multiple of shorter object length
#2: In vec1 + vec2 + vec3 :
#  longer object length is not a multiple of shorter object length
#> print("\nCase 3: Vectors of Multiple Lengths\n")
#[1] "\nCase 3: Vectors of Multiple Lengths\n"
#> print(result)
#[1] 13 16 19 19 17 20
#> vec1 <- c(1, 2, 3, 4, 5)
#># vec2 <- c(6, 7, 8, 9)
#># if(length(vec1) > length(vec2)) {
#+#   vec2 <- c(vec2, rep(0, length(vec1) - length(vec2)))
#+# } else if (length(vec2) > length(vec1)) {
#+#   vec1 <- c(vec1, rep(0, length(vec2) - length(vec1)))
#+# }
#># result <- vec1 + vec2
#># print("\nCase 4: Vectors of Non-Multiple Lengths\n")
#[#1] "\nCase 4: Vectors of Non-Multiple Lengths\n"
># print(result)
##[1]  7  9 11 13  5
##
