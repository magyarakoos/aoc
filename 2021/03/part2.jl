f = open("input", "r")
a = []; w = 0
for l in eachline(f)
    x = 0; w = length(l)
    for i in eachindex(l)
        x |= ((l[i] == '1') << (length(l) - i))
    end
    push!(a, x)
end
Ψ = ()