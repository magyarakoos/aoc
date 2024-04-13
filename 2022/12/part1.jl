f = open("input", "r")
a = []
for l in eachline(f)
    rx = r"Card \d+: ((?:\s)+)"
    push!(a, parse.(Int, split(l)))
end
