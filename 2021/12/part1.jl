g = Dict()
λ = (a) -> begin
    if !haskey(g, a[1])
    push!(g[a[1]], a[2])

end
map(l -> map(a -> , split(l, "-")[1:2]), readlines("input"))

println(g)