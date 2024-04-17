g = Dict()
λ = (a) -> begin
    if !haskey(g, string(a[1])) 
        g[string(a[1])] = Vector{String}() 
    end
    push!(string(g[a[1]]), string(a[2]))
end
map(l -> map(λ, split(l, "-")), readlines("input"))

println(g)