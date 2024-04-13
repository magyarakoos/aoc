f = open("input", "r")
a = []
for l in eachline(f)
    push!(a, parse(Int, split(l)))