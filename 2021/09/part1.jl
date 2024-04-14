f = map(l -> split(l, ""), readlines("input"))
m = zeros(Int, length(f), length(f[1]))
for i in eachindex(f), j in eachindex(f[1])
    