a = map(x -> [x[i] for i in eachindex(x)], readlines("input"))
a = transpose(a)
println(a)