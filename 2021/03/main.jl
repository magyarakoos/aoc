a = map(x -> [parse(Int, x[i]) for i in eachindex(x)], readlines("input"))
for i in 