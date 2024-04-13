a = map(x -> [x[i] for i in eachindex(x)], readlines("input"))
a_tr = a'
println(a_tr)