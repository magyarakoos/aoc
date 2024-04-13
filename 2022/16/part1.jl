
f = map(a -> [
        string(a[1]), 
        parse(Int, a[2]), 
        map(s -> string(s), split(a[3], ", "))], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
keys = Vector{String}()
for (key, rate, values) in f
    i = findfirst(keys, key)
    if isnothing(i)
        push!(keys, key)
        i = length(keys)
    end
    rates[i] = rate
    g[i] = Vector{String}()
    for value in values
        j = findfirst(keys, value)
        if isnothing(j)
            push!(keys, value)
            j = length(keys)
        end
        push!(g[i], j)
    end
    global i += 1
end
for i in eachindex(g)
    println(g[i])
end