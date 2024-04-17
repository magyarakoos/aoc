g = Dict()
map(l -> map(a -> push!(g[a[1]], a[2]), split(l, "-")[1:2]), readlines("input"))

println(g)