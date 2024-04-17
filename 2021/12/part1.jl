g = Dict()
λ = (a) -> begin
    if !haskey(g, a[1]) 
        g[a[1]] = Vector{String}() 
    end
    push!(g[a[1]], a[2])
end
map(l -> map(λ, split(l, "-")[1:2]), readlines("input"))

println(g)