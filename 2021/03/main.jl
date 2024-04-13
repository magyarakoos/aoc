a = [parse.(Int, split(l, "")) for l in eachline("input")]
res = Vector{Vector{Int}}(undef, length(a))
for j in eachindex(a[1]), i in eachindex(a)
    res[]
end