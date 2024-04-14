f::Vector{String} = readlines("input")
n::Vector{Int} = map(x -> parse(Int, x), split(f[1], ","))
