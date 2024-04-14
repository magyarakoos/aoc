f = open("input", "r")
a = []; w = 0
for l in eachline(f)
    x = 0; global w = length(l)
    for i in eachindex(l)
        x |= ((l[i] == '1') << (length(l) - i))
    end
    push!(a, x)
end
Σ = (x, i, a) -> o = count(x -> (x >> i) & 1 == 1, a)
ω = (i) -> begin
    if (i == -1) return 0 end

end
Ψ = (i, a, λ) -> begin
    if length(a) == 1 return a[1] end
    return Ψ(i - 1, filter(x -> (x >> i) & 1 == λ(length(a), Σ(x, i ,a)), a), λ)
end
println(Ψ(w - 1, a, (z, o) -> z <= o * 2) * Ψ(w - 1, a, (z, o) -> z > o * 2))