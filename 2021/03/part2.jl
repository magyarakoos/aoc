f = open("input", "r")
a = []; w = 0
for l in eachline(f)
    x = 0; global w = length(l)
    for i in eachindex(l)
        x |= ((l[i] == '1') << (length(l) - i))
    end
    push!(a, x)
end
ω = (i) -> begin
    if (i == -1)
end
Ψ = (i, a, λ) -> begin
    if length(a) == 1 return a[1] end
    o = count(x -> (x >> i) & 1 == 1, a)
    return Ψ(i - 1, filter(x -> (x >> i) & 1 == λ(length(a) - o, o), a), λ)
end
println(Ψ(w - 1, a, (z, o) -> z <= o) * Ψ(w - 1, a, (z, o) -> z > o))