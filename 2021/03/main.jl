# Open the file and read lines
file = open("input", "r")
lines = readlines(file)
close(file)

# Create a 2D vector of characters
a::Vector{Vector} = [collect(line) for line in lines]

# Transpose the 2D vector
a_tr = transpose(a)

# Print the transposed 2D vector
println(a_tr)
