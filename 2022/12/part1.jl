f = open("input", "r")
(a = [], b = [])
for l in eachline(f)
    rx = r"Card \d+: ((?:\d+\s+)+)\| ((?:\d+\s+)+)"
    push!(a, parse.(Int, split(l)))
end
