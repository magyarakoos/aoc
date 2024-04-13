a = map(x -> [x[i] for i in eachindex(x)], readlines("input"))
println(a)