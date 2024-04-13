# Read lines from the file
lines = readlines("input")

# Split each line into individual characters and collect them into a 2D array
a = [collect(line) for line in lines]

# Transpose the array of characters
a_tr = transpose(a)

# Print the transposed array
println(a_tr)
