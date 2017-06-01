## General
?seq # show function documentation in Help
View(myfirstfn) # view function implementation
summary(mtcars) # statistical information of the variable

# c for concatenate
arr <- c(1,2,3); arr
x <- c(1,2,3);

# See which objects are already created
ls()

# Removing an object
rm("arr")

## Working with vectors
y = c(x, 5, x); y

# Sum and roots
sum(x)

sqrt(x)

# Values at a given position within the vector
x[1]

newobject <- x < 5; newobject

## Functions: seq, paste, rep
?seq # starting with the seq function

seq() # just using the default settings

# simple sequence from 3 to 5
seq(3, 5)

seq(from = 3, to = 5)

# using length
seq(from = 3, length = 3)

# step manipulations
seq(from = 3, length = 3, by = 0.5)

seq(from = 3, by = 0.5, length = 3) # changed order

?paste # next function

paste(1:4)

class(paste(1:4)) # checking the class

paste("xyz", 1:10)

paste("xyz", c(2,5,7,"test", 4.5)) # random vector with numbers and characters

paste("xyz", 1:10, sep = "") # modifying the seperator

?rep # next function

rep(c(3,4,5), 3)

rep(1:10, times = 3)

x = c(1,2,3) # creating x

rep(x, each = 3) # using each

rep(x, each = 3, times = 3) # combining arguments

## Working with index positions

x = 4:20 # our data

which(x == 10) # double equal sign, logical operation

x[3]

## Functions in R
# Brief description: R functions are OBJECTS
# They do calculations for you
# R function structure: name <- function (argument) {statements}
# The arguments specify the components to be used in the function

myfirstfn <- function(x) {x+x}
myfirstfn(10)
View(myfirstfn)

## Loops - loops and functions are a crucial part in programming
# FOR loops allow a certain operation to be repeated a fixed nr of times
# This is opposed to the While loop where the rep nr is not prefixed
# The syntax looks like this: for (name in vector) {commands}

for (i in 1:15) {print (i)}

## Working with data.frames

?airmiles

head(airmiles) # first 6 rows

tail(airmiles) # last 6 rows

summary(mtcars)

plot(mtcars) # simple xy plot function of R Base

hist(airmiles) # histogram

head(mtcars)

sum(mtcars$wt)

attach(mtcars) # attach to R session environment

sum(wt) # now R knows which data.frame to use since it is attached

detach(mtcars) # remove it from environment

sum(wt) # error message since mtcars it not attached any more

mtcars[2,6]

mtcars[c(2,5,8),6]

## Graphs in R Base
# 3 main data viz systems: 
# ggplot2, lattice and R Base

# simple scatterplot
x=5:7 # 3 data points, integers
y=8:10

# default plot output here is a scatterplot
plot(x,y)

# data is a time series, default here is a line plot
plot(lynx)

# title, color, title color, title magnification
plot(lynx, main="Lynx Trappings", col="red",
     col.main=52, cex.main=1.5)

# label names
plot(lynx, ylab="Lynx Trappings", xlab="")

# label orientation
plot(lynx, ylab="Lynx Trappings", xlab="", las=2)

# las - 0:3, scale orientation

# changing the session paramter, 2*2 plot matrix
par(mfrow=c(2,2), col.axis="red")

plot(1:8, las=0, xlab="xlab", ylab="ylab", main="LAS = 0")

# color manipulation
colors()

?pch

# Create a list.
list1 <- list(c(2,5,3),21.3,sin)

# Print the list.
print(list1)

# Create a matrix.
M = matrix( c('a','a','b','c','b','a'), nrow = 2, ncol = 3, byrow = TRUE)
print(M)

# Create array with any number of dimensions
a <- array(c('green','yellow'),dim = c(3,3,2))
print(a)

# Factors are the r-objects which are created using a vector. 
# It stores the vector along with the distinct values of the elements
# in the vector as labels.

# Data frames are tabular data objects. Unlike a matrix in data frame each 
# column can contain different modes of data.

R variables




