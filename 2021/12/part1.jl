g = Dict()
λ = (a) push!(g[a[1]], 
map(l -> split(l, "-")[1:2], readlines("input"))